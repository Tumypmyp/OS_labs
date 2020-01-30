#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 

int main(int argc, char const *argv[]) {
	if (argc <= 1) {
		printf("Enter command as a parameter\n");
		return 0;
	}
	if (system(argv[1])) 		
		printf("No such command\n");
	else
		printf("Command executed\n");


	return 0;
}