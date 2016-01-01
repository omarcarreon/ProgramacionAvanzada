#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HINSTANCE hCodigoDll;
typedef BOOL _stdcall TipoRutina_EnumProcesses(DWORD *, DWORD , DWORD *);
TipoRutina_EnumProcesses *pEnumProcesses;

typedef BOOL _stdcall TipoRutina_EnumProcessModules(HANDLE,HMODULE *,DWORD,LPDWORD);
TipoRutina_EnumProcessModules *pEnumProcessModules;

typedef DWORD _stdcall TipoRutina_GetModuleBaseName(HANDLE,HMODULE,LPTSTR,DWORD);
TipoRutina_GetModuleBaseName *pGetModuleBaseName;

HANDLE hProcess;
HMODULE hMod;
DWORD cbNeeded;
char szProcessName[100];

void main() {
	DWORD array[1024];
	DWORD sizeOfArray=sizeof(array);
	DWORD bytesNeeded=13;
	int i;

	hCodigoDll=LoadLibrary("psapi.dll");
	if (hCodigoDll) {
		pEnumProcesses=(TipoRutina_EnumProcesses *)GetProcAddress(hCodigoDll,"EnumProcesses");
		pEnumProcessModules=(TipoRutina_EnumProcessModules *)GetProcAddress(hCodigoDll,"EnumProcessModules");
		pGetModuleBaseName=(TipoRutina_GetModuleBaseName *)GetProcAddress(hCodigoDll,"GetModuleBaseNameA");
		if (pEnumProcesses && pEnumProcessModules && pGetModuleBaseName) {
			(*pEnumProcesses)(&array[0],sizeOfArray,&bytesNeeded);
			printf("Cantidad de procesos ---> %d\n",bytesNeeded/4);

			for (i = 0; i < bytesNeeded / 4; i++) {
				hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, array[i]);

				// Get the process name.

				if (hProcess) {
					if ((*pEnumProcessModules)(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
						(*pGetModuleBaseName)(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
						printf("Proceso %s (%d)\n", szProcessName, array[i]);
					}
					CloseHandle(hProcess);
				}
			}
		}
		FreeLibrary(hCodigoDll);
	}
	printf("Fin!\n");
}