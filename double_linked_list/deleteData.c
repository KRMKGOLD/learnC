#include "function.h"

void deleteNode() {
	int inData;

	printf("1. Head 다음 삭제\n");
	printf("2. Tail 전 삭제\n");
	printf("3. 원하는 부분 삭제\n");
	printf("Input Number : ");
	scanf("%d", &inData);

	switch (inData) {
	case 1: deleteHeadNode(); break;
	case 2: deleteTailNode(); break;
	case 3: deleteAnyNode(); break;
	}
}

void deleteHeadNode() {
	if (head->right == tail) {
		printf("삭제할 노드가 없습니다.\n\n");
		return;
	}
	else {
		head->right->right->left = head;
		head->right = head->right->right;
		printf("삭제가 완료되었습니다.\n\n");
	}
}

void deleteTailNode() {
	if (tail->left == head) {
		printf("삭제할 노드가 없습니다.\n\n");
		return;
	}
	else {
		tail->left->left->right = tail;
		tail->left = tail->left->left;
		printf("삭제가 완료되었습니다.\n\n");
	}
}

void deleteAnyNode() {
	Node* tempNode = head;
	int index;
	printf("What index location do you want to delete? : ");
	scanf("%d", &index);
	for (int i = 0; i < index - 1; i++) {
		if (tempNode->right == tail) {
			printf("현재 있는 자료의 수보다 index의 값이 많습니다.\n\n");
			return;
		}
		else {
			tempNode = tempNode->right;
		}
	}
	tempNode->right->right->left = tempNode;
	tempNode->right = tempNode->right->right;
	printf("삭제가 완료되었습니다\n\n");
}