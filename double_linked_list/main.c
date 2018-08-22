#include "function.h"

void main() {
	void(*selectMenu[5])() = { insertNode, deleteNode, printNode, sortNode, reSortNode };
	int select;

	initHeadTailNode();

	while (1) {
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("5. ������\n");
		printf("6. ����\n");
		printf("Input Number : ");
		scanf("%d", &select);
		printf("\n");
		
		if (select == 6) return 0;
		
		selectMenu[select - 1]();
	}
	freeNode();
}