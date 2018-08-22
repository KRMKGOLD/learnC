#include "function.h"

void main() {
	void(*selectMenu[5])() = { insertNode, deleteNode, printNode, sortNode, reSortNode };
	int select;

	initHeadTailNode();

	while (1) {
		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 정렬\n");
		printf("5. 역정렬\n");
		printf("6. 종료\n");
		printf("Input Number : ");
		scanf("%d", &select);
		printf("\n");
		
		if (select == 6) return 0;
		
		selectMenu[select - 1]();
	}
	freeNode();
}