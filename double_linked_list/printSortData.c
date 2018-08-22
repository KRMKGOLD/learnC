#include <stdbool.h>
#include "function.h"

void printNode() {
	Node* currNode = head;
	while (currNode->right != tail) {
		currNode = currNode->right;
		printf("%d ", currNode->data);
	}
	printf("\n\n");
}

void sortNode() {
	Node* currNode = head;
	Node* curr2Node = currNode->right;

	bool checkSort = true;

	while (checkSort != false) {
		checkSort = false;
		currNode = head;
		curr2Node = currNode->right;
		while (curr2Node != tail) {
			if (currNode->data > curr2Node->data) {
				currNode->right = curr2Node->right;
				curr2Node->right->left = currNode;
				curr2Node->left = currNode->left;
				curr2Node->right = currNode;
				currNode->left->right = curr2Node;
				currNode->left = curr2Node;

				checkSort = true;
			}
			currNode = currNode->right;
			curr2Node = currNode->right;
		}
	}
}

void reSortNode() {
	Node* currNode = head;
	Node* curr2Node = currNode->right;

	bool checkSort = true;

	while (checkSort != false) {
		checkSort = false;
		currNode = tail;
		curr2Node = currNode->left;
		while (curr2Node != head) {
			if (currNode->data > curr2Node->data) {
				currNode->left = curr2Node->left;
				curr2Node->left->right = currNode;
				curr2Node->right = currNode->right;
				curr2Node->left = currNode;
				currNode->right->left = curr2Node;
				currNode->right = curr2Node;
				checkSort = true;
			}
			currNode = currNode->left;
			curr2Node = currNode->left;
		}
	}
}