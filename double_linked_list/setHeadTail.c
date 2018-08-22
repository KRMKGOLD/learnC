#include "function.h"

void initHeadTailNode() {
	head = malloc(sizeof(Node));
	tail = malloc(sizeof(Node));
	head->left = head;
	head->right = tail;
	tail->left = head;
	tail->right = tail;
}

void freeNode() {
	Node* temp = head->right;
	Node* temp2 = NULL;
	while (temp != tail) {
		temp2 = temp;
		temp = temp->right;
		free(temp2);
	}
	free(head);
	free(tail);
}