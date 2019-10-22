#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int val;
	struct node* next;
} Node;

void print_list(Node* list) {
	if (list == NULL) {
		printf("- the list now\n");
		return;
	}
	printf("%d ", list->val);
	print_list(list->next);
}

// insert after Node* v
Node* insert_node(Node* list, Node* v, Node* x) {
	if (list == NULL)
		return x;
	x->next = v->next;
	v->next = x;
	return list;
}

// delete after Node* v
Node* delete_node(Node* list, Node* v) {
	if (v->next != NULL) {
		Node* v2 = v->next;
		v->next = v->next->next;
		free(v2);
	}
	return list;
}

// get k-th Node* (head is number 0)
Node* get_node(Node* list, int k) {
	for (int i = 0; i < k && list != NULL && list->next != NULL; ++i)
		list = list->next;
	return list;
}

int main() {
	printf("Please insert nodes by index and value or delete by index.\n");
	char s[10];
	int x, y;
	Node* list = NULL;
	while (1) {
		print_list(list);
		scanf("%s %d", s, &x);
		// printf("\"%s\" - string, %d - int\n", s, x);
		if (s[0] == 'i') {
			scanf("%d", &y);
			Node* v = malloc(sizeof(Node));
			v->val = y;
			list = insert_node(list, get_node(list, x), v);
		} else {
			list = delete_node(list, get_node(list, x));	
		}
	}
	return 0;
}