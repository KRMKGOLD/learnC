#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

void InputPhoneData(void) {
	printf("�̸� �Է� : ");
	scanf("%s", phoneList[numOfData].name);
	printf("��ȭ��ȣ �Է� : ");
	scanf("%s", phoneList[numOfData].phoneNum);
	printf("�Է��� �Ϸ�Ǿ����ϴ�.");
	numOfData++;
}

void ShowAllData(void) {
	int curr = 0;
	for (curr = 0; curr < numOfData; curr++) ShowPhoneInfo(phoneList[curr]);
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
	system("pause");
}	