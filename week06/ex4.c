#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <signal.h> 

#define SIGINT 2


void child_handler(int sig) {
	if (sig == SIGINT)
		printf("Interrupt signal caught\n");
	else
		exit(0);
}

void sigkill_handler(int sig) {
	printf("Interrupt signal caught\n");
}
void sigstop_handler(int sig) {
	printf("Stop signal caught\n");
}
void sigusr1_handler(int sig) {
	printf("Kill signal caught\n");
}

int main(int argc, char const *argv[]) {
	signal(SIGINT, child_handler);
	signal(SIGKILL, sigkill_handler);
	signal(SIGSTOP, sigstop_handler);
	signal(SIGUSR1, sigusr1_handler);
	while (1) {
	}

	return 0;
}
