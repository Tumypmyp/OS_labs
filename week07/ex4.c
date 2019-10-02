#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void* my_realloc(void* ptr, size_t new_size) {
	void *new_ptr = malloc(new_size);
	if (ptr == NULL) {
		return new_ptr;
	}
	if (new_size == 0) {
		free(ptr);
		return NULL;
	}
	size_t size = ((size_t*)ptr)[-1];
	memcpy(new_ptr, ptr, (size < new_size ? size : new_size));
}

// Checking with exercise3 code
int main() {
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1 = 0;
	scanf("%d", &n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for (i = 0; i < n1; i++) {
		//Set each value in a1 to 100
		a1[i] = 100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	//Dynamically change the array to size n2
	a1 = realloc(a1, n2 * sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	for (i = n1; i < n2; i++) {
		a1[i] = 0;
	}

	for (i = 0; i < n2; i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	return 0;
}