#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>


typedef struct pair{
	long int i;
	char s[128];
} Pair;

int len;
Pair files[1024];

int comp(const void* p, const void* q) { 
	return ((Pair*)p)->i < ((Pair*)q)->i; 
}

int main(int argc, char *argv[]) {
	char dir_name[] = "tmp";
	if (argc >= 2)
		strcpy(dir_name, argv[1]);

	DIR *dir = opendir(dir_name);
	if (dir == NULL) {
		perror("opendir failed");
		return 1;
	};
	
	struct dirent *entry;
	struct stat stats;

	while ((entry = readdir(dir)) != NULL) {
		// Make path to the file
		char path[128];
		strcpy(path, dir_name);
		strcat(path, "/");
		strcat(path, entry->d_name);

		// Make stat structure
		if (stat(path, &stats) < 0) {
			perror("stat failed");
			return 1;
		}

		// Add to array
		if (stats.st_nlink > 1) {
			strcpy(files[len].s, entry->d_name);
			files[len].i = entry->d_ino;
			++len;
		}
	}
	
	// Sort array
	qsort(files, len, sizeof(Pair), comp);
	for (int i = 0; i < len; ++i) 
		printf("Name: \"%s\", i-node: %ld\n", files[i].s, files[i].i);

	closedir(dir);
	return 0;
}