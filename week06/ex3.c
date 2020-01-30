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

int main(int argc, char const *argv[]) {
	signal(SIGINT, child_handler);
	while (1) {
	}

	return 0;
}
