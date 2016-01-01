#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void signalHandler(int signalNumber) {
	switch(signalNumber) {
		case SIGUSR1:
				printf("SIGUSR1 recibido!!!\n");
				break;
		case SIGUSR2:
				printf("SIGUSR2 recibido!!!\n");
				break;
		case SIGINT:
				printf("Hey!!!, presionaste <CTRL>-<C>\n");
				break;
		case SIGALRM:
				printf("ALARMA!!!\n");
				break;
		case SIGQUIT:
				printf("Bye!!!\n");
				break;
	}
}

int main() {
	if (signal(SIGUSR1,signalHandler) == SIG_ERR) {
		printf("Error en SIGUSR1\n");
		exit(1);
	}
	if (signal(SIGUSR2,signalHandler) == SIG_ERR) {
		printf("Error en SIGUSR2\n");
		exit(1);
	}
	if (signal(SIGINT,signalHandler) == SIG_ERR) {
		printf("Error en SIGINT\n");
		exit(1);
	}
	if (signal(SIGALRM,signalHandler) == SIG_ERR) {
		printf("Error en SIGINT\n");
		exit(1);
	}
	if (signal(SIGQUIT,signalHandler) == SIG_ERR) {
		printf("Error en SIGQUIT\n");
		exit(1);
	}
	for ( ; ; )
		pause();
	return(0);
}
