#include <stdio.h>
#include <malloc.h>
#include <sys/types.h>
#include <winsock2.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/stat.h>
#include <sys/types.h>


char dirStr[]="C:\\Users\\ProgAva\\Temp";
char dirFileStr[]="C:\\Users\\ProgAva\\Temp\\Algo.txt";
char dirFileStr2[]="C:\\Users\\ProgAva\\Temp\\Algo2.txt";
HANDLE changeNotifHandle;
HANDLE fileHandle;

char chr = 0;
DWORD waitResult;
int flag=0;
FILETIME lastWriteTime,t1,t2,t3;
DWORD lastError;

long estado=0;	//Indicador para rastrear la actividad del servicio
FILE *arch;

SERVICE_STATUS_HANDLE interfaz_al_SCM;
SERVICE_STATUS serviceStatus;
SERVICE_TABLE_ENTRY tabla;
char nombreServicio[]="ProgAva_Srv";

HANDLE elThread;
DWORD elThreadID;

VOID WINAPI ServiceMain(DWORD dwArgc,LPTSTR *lpszArgv);
VOID WINAPI mainHandle(DWORD fdwControl);

void main(void)
{

	tabla.lpServiceName=nombreServicio;	
	tabla.lpServiceProc=&ServiceMain;
	StartServiceCtrlDispatcher(&tabla);
}

//***********************************************************************

void setServiceStatusState(unsigned int state) {
	serviceStatus.dwServiceType=SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwCurrentState=state;
	serviceStatus.dwControlsAccepted=SERVICE_CONTROL_INTERROGATE
										|SERVICE_ACCEPT_STOP
										|SERVICE_ACCEPT_PAUSE_CONTINUE
										|SERVICE_ACCEPT_SHUTDOWN;
	serviceStatus.dwWin32ExitCode=NO_ERROR;
	serviceStatus.dwServiceSpecificExitCode=0;
	serviceStatus.dwCheckPoint=estado++;
	serviceStatus.dwWaitHint=100;	
}

DWORD WINAPI corre(LPVOID lpParameter) {
	setServiceStatusState(SERVICE_RUNNING);	//Avisar que YA ESTAMOS CORRIENDO!!!
	SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

	while(TRUE){
		if (!flag)
		{
			changeNotifHandle=FindFirstChangeNotification(dirStr,FALSE,FILE_NOTIFY_CHANGE_LAST_WRITE);
		}
		else
		{
			FindNextChangeNotification(changeNotifHandle);
		}
		waitResult = WaitForSingleObject(changeNotifHandle,500);	//Esperar hasta 500 mseg.
		flag=1;
		switch(waitResult) {
			case WAIT_OBJECT_0:
				printf("Cambio algun archivo\n");
				Sleep(50);	//Dar un tiempo para evitar el "LOCK" cuando se esta grabando el archivo
				fileHandle=CreateFile(dirFileStr,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
				if (fileHandle!=INVALID_HANDLE_VALUE) {
					if(GetFileTime(fileHandle,&t1,&t2,&t3)) {
						if ((t3.dwHighDateTime!=lastWriteTime.dwHighDateTime)||(t3.dwLowDateTime!=lastWriteTime.dwLowDateTime)) {
							printf("El archivo cambio\n");
							memcpy(&lastWriteTime,&t3,sizeof(FILETIME));
							CopyFile(dirFileStr,dirFileStr2,FALSE);
						} else {
							printf("El archivo NO cambio\n");
						}
					}
					CloseHandle(fileHandle);
				} else { 
					lastError=GetLastError();
					if (lastError == ERROR_SHARING_VIOLATION)	//¡Ups!, que mala suerte el archivo cambio y esta LOCKED
						printf("El archivo cambio!\n");
					else if (lastError == ERROR_FILE_NOT_FOUND) {
						printf("Borraron el achivo ... que hacemos?\n");
						return;		//Por lo pronto finalizar este programa
					} else
						printf("INVALID_HANDLE_VALUE! ... %ld\n",lastError);
				}
				break;
			case WAIT_TIMEOUT:
				printf(".");
				break;
			default:
				printf("ERROR!!!\n");
				break;
		}
		Sleep(1000);	//Duérmete 1 seg.
	}
}

VOID WINAPI mainHandle(DWORD fdwControl) {
	switch(fdwControl) {
		case SERVICE_CONTROL_STOP:
					setServiceStatusState(SERVICE_STOP_PENDING);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

					if (TerminateThread(elThread,0)) {
						setServiceStatusState(SERVICE_STOPPED);
						SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					}
					break;
		case SERVICE_CONTROL_PAUSE:
					setServiceStatusState(SERVICE_PAUSE_PENDING);	//Avisar que YA ESTAMOS CORRIENDO!!!
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

					SuspendThread(elThread);
					
					setServiceStatusState(SERVICE_PAUSED);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					break;
		case SERVICE_CONTROL_CONTINUE:
					setServiceStatusState(SERVICE_CONTINUE_PENDING);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios

					ResumeThread(elThread);

					setServiceStatusState(SERVICE_RUNNING);	//Avisar que YA ESTAMOS CORRIENDO!!!
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					break;
		default:
					setServiceStatusState(SERVICE_RUNNING);
					SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Enviar mensaje al manejador de servicios
					break;
	}
}

VOID WINAPI ServiceMain(DWORD dwArgc,LPTSTR *lpszArgv) {
	interfaz_al_SCM=RegisterServiceCtrlHandler(nombreServicio,mainHandle);

	setServiceStatusState(SERVICE_START_PENDING);
	SetServiceStatus(interfaz_al_SCM,&serviceStatus);	//Avisar que estamos "alive and kicking!"

	//Asegurar tiempos de facto para el archivo
	lastWriteTime.dwHighDateTime=0;	//Asignar los 32bits HIGH
	lastWriteTime.dwLowDateTime=0;	//Asignar los 32bits LOW
	//Abrir un "handle" con el archivo para obtener (inicialmente) el tiempo de ultima escritura
	fileHandle=CreateFile(dirFileStr,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
	//Si el archivo no es valido
	if (fileHandle!=INVALID_HANDLE_VALUE) {
		if(GetFileTime(fileHandle,&t1,&t2,&t3))
			memcpy(&lastWriteTime,&t3,sizeof(FILETIME));
		CloseHandle(fileHandle);
	} else {
		lastError=GetLastError();
		if (lastError==ERROR_FILE_NOT_FOUND)
			return;	//Archivo no localizado, quizas lo borraron ... terminar el programa
		//Otra posibilidad del error es que el archivo este abierto y LOCKED ...
		// ... habrá que decidir como proceder (terminar el programa también o ciclarse esperando)
		// ... pero esto no lo vamos a hacer aquí simplemente tomamos valores de tiempo en ceros.
	}

	elThread=CreateThread(NULL,0,corre,NULL,0,&elThreadID);
	FindCloseChangeNotification(changeNotifHandle);
	printf("Listo\n");
}
