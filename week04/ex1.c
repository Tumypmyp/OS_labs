#include <stdio.h>
#include <unistd.h> 

int main() {
	int n = 0, pid = 0;
	if ((pid = fork()) != 0) {
		printf("Hello from parent [%d - %d]\n", pid, n);
	} else {
		printf("Hello from child [%d - %d]\n", pid, n);
	}
	return 0;
}