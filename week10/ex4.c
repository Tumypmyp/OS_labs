#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char dir_name[] = "tmp";
	if (argc >= 2)
		strcpy(dir_name, argv[1]);

	DIR *dir = opendir(dir_name);
	if (dir == NULL) {
		perror("opendir failed");
		return 1;
	};
	printf("ok\n");
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {

	}
	

	closedir(dir);

}