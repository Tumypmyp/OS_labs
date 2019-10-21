#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

void triangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; ++j)
			printf("*");
		printf("\n");
	}
}

void triangle1(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j)
			printf("*");
		printf("\n");
	}
}

void triangle2(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < min(i, n - i + 1); ++j)
			printf("*");
		printf("\n");
	}
}

void rectangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
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
	if (argc > 2)
		sscanf(argv[2], "%d", &type);

	switch (type) {
		case 0:
			triangle(n);
			break;
		case 1:
			triangle1(n);
			break;
		case 2:
			triangle2(n);
			break;
		case 3:
			rectangle(n);
			break;
	}

	return 0;
}