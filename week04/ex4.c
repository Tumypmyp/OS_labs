#include <stdio.h>
#include <unistd.h> 

int main(int argc, char const *argv[]) {
	if (argc <= 1) {
		printf("Enter command as a parameter\n");
		return 0;
	}
	char* const *argv2 = argv + 1;
	char* envp[] = {NULL};
	if (fork() == 0) {
		execve(argv[1], argv2, envp);	
		perror("Could not execve");
		return 1;
	}
	return 0;

}