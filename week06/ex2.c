#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

#define SIZE 10

int main(int argc, char const *argv[]) {
	
	int p[2];
	if (pipe(p) < 0)
		return 1;
	
	if (fork() != 0) {	
		printf("Hello from parent\n");
		char* a = "new string";
		write(p[1], a, SIZE);	
	} else {
		printf("Hello from child\n");
		char ans[SIZE]; 
		read(p[0], ans, SIZE);
		printf("%s\n", ans);
	
	}

	return 0;
}
