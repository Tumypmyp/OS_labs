#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h> 

int main() {
	int n = 0, pid = 0;
	if ((pid = fork()) != 0) {
		sleep(10);
		printf("Hello from parent [%d - %d]\n", pid, n);
		kill(pid, SIGTERM);
	} else {
		while(1){
			sleep(1);
			printf("I'm alive\n");
		}
	}
	return 0;
}