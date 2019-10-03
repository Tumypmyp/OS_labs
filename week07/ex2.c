#include <stdlib.h>
#include <stdio.h>

int main() {
	size_t N = 10 * (1 << 20);
	int *array;
	for (int i = 0; i < 10; i++) {
		array = malloc(N);
		memset(array, 0, N);
		sleep(1);
	}
	return 0;
}