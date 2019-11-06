#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Default size
	int size = 20;

	if (argc > 1)
		size = atoi(argv[1]);

	char result[size + 1];
	result[size] = '\0';

	// Open input file
	FILE *input_file = fopen("/dev/random", "r");
	if (input_file == NULL) {
		perror("Error while opening the file.\n");
		return 1;  
	}

 	fread(result, 1, size, input_file);
	fclose(input_file);

	// Open output file
	FILE *output_file = fopen("ex1.txt", "w");
	if (output_file == NULL) {
		perror("Error while opening the file.\n");
		return 1;  
	}
	
	// Write the result
	fprintf(output_file, "%s", result);
	fclose(output_file);
	
	printf("%s\n", result);
	
	return 0;
}