#include "function.h"

void insertNode() {
	int inData;

	printf("1. Head에 삽입\n");
	printf("2. Tail에 삽입\n");
	printf("3. 원하는 곳에 삽입\n");
	printf("Input Number : ");
	scanf("%d", &inData);

	switch (inData) {
	case 1: insertHeadNode(); break;
	case 2: insertTailNode(); break;
	case 3: insertAnyNode(); break;
	}
}

void insertHeadNode() {
	Node* newNode = malloc(sizeof(Node));
	printf("\nInput you want to insert number : ");
	scanf("%d", &(newNode->data));

	newNode->left = head;
	newNode->right = head->right;
	head->right->left = newNode;
	head->right = newNode;

	putchar('\n');
}

void insertTailNode() {
	Node* newNode = malloc(sizeof(Node));

	printf("\nInput you want to insert number : ");
	scanf("%d", &(newNode->data));

	if (head->right == tail && tail->left == head) {
		tail->left = newNode;
		head->right = newNode;
		newNode->right = tail;
		newNode->left = head;
	}
	else {
		newNode->right = tail;
		newNode->left = tail->left;
		tail->left->right = newNode;
		tail->left = newNode;
	}

	putchar('\n');
}

void insertAnyNode() {
	Node* newNode = malloc(sizeof(Node));
	Node* tempNode = head;
	int index;
	printf("What index location do you want to add? : ");
	scanf("%d", &index);
	printf("\nInput you want to insert number : ");
	scanf("%d", &(newNode->data));
	for (int i = 0; i < index; i++) {
		if (tempNode->right == tail) {
			printf("현재 있는 자료의 수보다 index의 값이 많습니다.");
			return;
		}
		else {
			tempNode = tempNode->right;
		}
	}
	newNode->right = tempNode->right;
	newNode->left = tempNode;
	tempNode->right->left = newNode;
	tempNode->right = newNode;

	putchar('\n');
}