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
	printf("숫자를 입력하세요 : ");
	scanf("%d", &indata);

	newNode->data = indata;
	newNode->link = head;
	head = newNode;

	printf("숫자가 삽입되었습니다.\n\n");
}

int deleteNode() {
	Node* delNode;
	if (head) {
		printf("%d 노드를 삭제했습니다.\n\n", head->data);
		delNode = head;
		head = head->link;
	}
	else {
		printf("삭제할 노드가 없습니다.\n\n");
	}
}

int printNode() {
	Node* curr = head;

	if (curr == NULL) printf("삽입된 노드가 없습니다.");
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

		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 종료\n");
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
