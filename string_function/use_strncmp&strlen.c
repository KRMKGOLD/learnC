#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

int main() {
	char arr[1000];
	char searchArr[100];
	int a = 0;
	
	printf("���� �Է� : ");
	gets_s(arr, sizeof(arr));

	while (1) {
		printf("�˻��� ���ڿ� �Է�(����� end) : ");
		gets_s(searchArr, sizeof(searchArr));

		char checkingArr[100] = { 0, };

		if (strcmp(searchArr, "end") == 0) return;

		for (int i = 0; i < strlen(arr); i++) {
			for (int j = 0; j < strlen(searchArr); j++) {
				checkingArr[j] = arr[i + j];
			}

			if (strncmp(searchArr, checkingArr, strlen(searchArr)) == 0) {
				a++;
				i += strlen(checkingArr) - 1;
			}
		}

		printf("�˻� ��� : %d��\n", a);
		a = 0;
	}
}