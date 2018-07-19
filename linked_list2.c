#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char id[15];
	int number;
	int age;
	char name[10];
	struct node* link;
};

typedef struct node Node;

Node* head = NULL;

int insertNode() {
	Node* newNode = malloc(sizeof(Node));

	printf("id, �̸�, ��ȣ, ���̸� �޸�(,) ���� ������� �Է����ּ���.\n");
	scanf("%s %s %d %d", newNode->id, newNode->name, &newNode->number, &newNode->age);
	
	newNode->link = head;
	head = newNode;
}

int printNode() {
	Node* curr = head;

	if (curr == NULL) printf("���Ե� ��尡 �����ϴ�.");
	else {
		while (curr) {
			printf("(%s, %s, %d, %d)", curr->id, curr->name, curr->number, curr->age);
			if (curr->link != NULL) {
				printf(" -> ");
			}
			curr = curr->link;
		}
	}
}
int deleteNode() {
	Node* delNode;
	if (head) {
		printf("��带 �����߽��ϴ�.\n\n");
		delNode = head;
		head = head->link;
	}
	else {
		printf("������ ��尡 �����ϴ�.\n\n");
	}
}

void InsertList(Node** head2, Node* node, int n) {
	Node* tmp = *head2;
	Node* tmpb = NULL;
	switch (n) {
	case 1:
		while (tmp && strcmp(tmp->id, node->id) == -1) {
			// strcmp(str1, str2) str1�� �� ũ�� 1, ������ 0, str2�� �� ũ�� -1�� ��ȯ
			tmpb = tmp;
			tmp = tmp->link;
			// head(tmpb) -> tmp -> anyNode
			// head -> tmpb -> tmp(anyNode)
		}
		if (tmpb) {
			tmpb->link = node;
			node->link = tmp;
		}
		else {
			*head2 = node;
			node->link = tmp;
		}
		break;
	case 2:
		while (tmp && strcmp(tmp->name, node->name) == -1) {
			tmpb = tmp;
			tmp = tmp->link;
		}
		if (tmpb) {
			tmpb->link = node;
			node->link = tmp;
		}
		else {
			*head2 = node;
			node->link = tmp;
		}
		break;
	case 3:
		while (tmp && tmp->number < node->number) {
			tmpb = tmp;
			tmp = tmp->link;
		}
		if (tmpb) {
			tmpb->link = node;
			node->link = tmp;
		}
		else {
			*head2 = node;
			node->link = tmp;
		}
		break;
	case 4:
		while (tmp && tmp->age < node->age) {
		tmpb = tmp;
		tmp = tmp->link;
		}
		   if (tmpb) {
			   tmpb->link = node;
			   node->link = tmp;
		   }
		   else {
			   *head2 = node;
			   node->link = tmp;
		   }
		break;
	}	

}

void sortingList(int n) {
	Node* tmp = head;
	Node* head2 = NULL;
	while (tmp) {
		head = tmp->link;
		InsertList(&head2, tmp, n);
		tmp = head;
	}
	head = head2;
}

int sortNode() {
	int num;
	printf("���� ����� �����ϼ���.\n");
	printf("1. id, 2. �̸�, 3. ��ȣ, 4. ����\n");
	printf("Insert Number : ");
	scanf("%d", &num);

	sortingList(num);
}

int main() {
	int num;

	while (1) {
		printf("1. ����\n");
		printf("2. ���\n");
		printf("3. ����\n");
		printf("4. ����\n");
		printf("Input Number : ");
		scanf("%d", &num);

		printf("\n");

		switch (num) {
		case 1: insertNode(); break;
		case 2: printNode(); break;
		case 3: deleteNode(); break;
		case 4: sortNode(); break;
		default: return 0;
		}
		printf("\n\n");
	}
}
