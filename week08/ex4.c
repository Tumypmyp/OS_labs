#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
	struct rusage usage;
	size_t N = 10 * (1 << 20);
	int *array;
	for (int i = 0; i < 10; i++) {
		array = malloc(N);
		memset(array, 0, N);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}