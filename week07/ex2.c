#include <stdlib.h>
#include <stdio.h>

int main (){
	int N;
	scanf("%d", &N);
	int *array = malloc(N * sizeof(int));
	for (int i = 0; i < N; ++i) {
		array[i] = i;
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}