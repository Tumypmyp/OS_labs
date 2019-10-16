#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct page_frame{
	unsigned char prior;
	int page_id;
	bool ref;
} default_page_frame = {0, -1, 0};

// Update array with default values
void init_default_aray(struct page_frame *res, int size) {
	for (int i = 0; i < size; ++i)
		res[i] = default_page_frame;
}

// Update prior by ref bit
void update(struct page_frame *p) {
	p->prior = (p->ref << 8) | (p->prior >> 1);
}

// Return true if page frame is not used
bool is_empty(struct page_frame *p) {
	return p->page_id == default_page_frame.page_id
		&& p->prior == default_page_frame.prior
		&& p->ref == default_page_frame.ref;
}

// Replace old page by new one
void put_page(struct page_frame *p, int frame_id) {
	p->page_id = frame_id;
	p->prior = 0;
	p->ref = 1;
}

void push_next_page(int frame_id, struct page_frame *pages, int pSize, int *nmiss, int *nhit) {
	// Checking if it's hit case
	for (int i = 0; i < pSize; ++i)
		if (pages[i].page_id == frame_id) {
			pages[i].ref = 1;
			++(*nhit);
			return;
		}

	// Miss case otherwise
	++(*nmiss);

	// Find not used page
	for (int i = 0; i < pSize; ++i)
		if (is_empty(&pages[i])) {
			put_page(&pages[i], frame_id);
			return;
		}

	// Find page with the lowest priority
	int min_ind = 0;
	for (int i = 0; i < pSize; ++i)
		if (pages[i].prior < pages[min_ind].prior)
			min_ind = i;

	// Replace with new page
	put_page(&pages[min_ind], frame_id);
}

void simulate_next_tick(struct page_frame *pages, int pSize) {
	for (int i = 0; i < pSize; ++i)
		if (pages[i].ref)
			update(&pages[i]);
}

int main(int argc, char *argv[]) {
	// Default parameters are
	int pSize = 10;
	char filename[] = "Lab 09 input.txt";

	// Change to user parameters if given
	if (argc >= 2)
		pSize = atoi(argv[1]);
	if (argc >= 3)
		strcpy(filename, argv[2]);

	printf("Number of page frames: %d\n", pSize);
	printf("Input filename is: \"%s\"\n", filename);

	// Initialization of variables
	struct page_frame pages[pSize];
	init_default_aray(pages, pSize);
	int id, nmiss = 0, nhit = 0;

	// Open file
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error while opening the file.\n");
		return 1;  
	}

	// Read all integers from file
	fscanf(file, "%d", &id);
	while (!feof(file)) {
		// printf("%d\n", id);
		push_next_page(id, pages, pSize, &nmiss, &nhit);
		simulate_next_tick(pages, pSize);
		fscanf(file, "%d", &id);
	}
	fclose (file);

	printf("Hit: %d, Miss: %d\n", nhit, nmiss);
	printf("Hit/Miss: %f\n", (double)nhit / nmiss);
	return 0;
}