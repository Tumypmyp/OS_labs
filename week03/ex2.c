#include <stdio.h>


void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void bubble_sort(int *a, size_t n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n - 1; ++j)
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
}

int main() {
	printf("Please write integer n and array of n integers:\n");
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
		bubble_sort(a, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}