#include "function.h"

void deleteNode() {
	int inData;

	printf("1. Head ���� ����\n");
	printf("2. Tail �� ����\n");
	printf("3. ���ϴ� �κ� ����\n");
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
		printf("������ ��尡 �����ϴ�.\n\n");
		return;
	}
	else {
		head->right->right->left = head;
		head->right = head->right->right;
		printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
	}
}

void deleteTailNode() {
	if (tail->left == head) {
		printf("������ ��尡 �����ϴ�.\n\n");
		return;
	}
	else {
		tail->left->left->right = tail;
		tail->left = tail->left->left;
		printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
	}
}

void deleteAnyNode() {
	Node* tempNode = head;
	int index;
	printf("What index location do you want to delete? : ");
	scanf("%d", &index);
	for (int i = 0; i < index - 1; i++) {
		if (tempNode->right == tail) {
			printf("���� �ִ� �ڷ��� ������ index�� ���� �����ϴ�.\n\n");
			return;
		}
		else {
			tempNode = tempNode->right;
		}
	}
	tempNode->right->right->left = tempNode;
	tempNode->right = tempNode->right->right;
	printf("������ �Ϸ�Ǿ����ϴ�\n\n");
}