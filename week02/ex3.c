#include <stdio.h>

void triangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; ++j)
			printf("*");
		printf("\n");
	}
}


int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Please write integer values as command line parameters\n");
		return 1;
	}

	int n, type = 0;
	sscanf(argv[1], "%d", &n);
	triangle(n);

	return 0;
}