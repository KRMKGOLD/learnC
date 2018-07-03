#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
}node;

typedef struct node Node;

Node* head = NULL;

int insertNode() {
	int indata;
	Node* newNode = malloc(sizeof(Node));
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &indata);

	newNode->data = indata;
	newNode->link = head;
	head = newNode;

	printf("���ڰ� ���ԵǾ����ϴ�.\n\n");
}

int deleteNode() {
	Node* delNode;
	if (head) {
		printf("%d ��带 �����߽��ϴ�.\n\n", head->data);
		delNode = head;
		head = head->link;
	}
	else {
		printf("������ ��尡 �����ϴ�.\n\n");
	}
}

int printNode() {
	Node* curr = head;

	if (curr == NULL) printf("���Ե� ��尡 �����ϴ�.");
	else {
		while (curr) {
			printf("%d -> ", curr->data);
			curr = curr->link;
		}
	}
	putchar('\n');
	free(curr);
}

int display() {

	int num = 0;

	while (1) {

		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("Input Number : ");
		scanf("%d", &num);

		switch (num) {
			case 1: insertNode(); break;
			case 2: deleteNode(); break;
			case 3: printNode(); break;
			case 4: return 0;
			default: return 0;
		}
	}

}

int main() {
	
	display();
	
}
