#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

#define SIZE 10

int main(int argc, char const *argv[]) {
	
	char* a = "new string";
	char ans[SIZE]; 
	int p[2];
	if (pipe(p) < 0)
		return 1;

	write(p[1], a, SIZE);	
	read(p[0], ans, SIZE);
	printf("%s\n", ans);
	
	return 0;
}

