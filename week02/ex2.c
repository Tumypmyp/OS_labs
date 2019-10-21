#include <stdio.h>
#include <string.h>

int main() {
	char a[1024];
	fgets(a, sizeof(a), stdin);
	// printf("%ld", strlen(a));
	
	// String a includes symbol '\n' in the end
	int sz = (int)strlen(a) - 1;

	for (int i = 0; i < sz; ++i)
		printf("%c", a[sz - 1 - i]);
	printf("\n");
	return 0;
}