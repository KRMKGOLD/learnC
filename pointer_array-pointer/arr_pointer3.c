#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void input_nums(int* lotto_nums) {
	int temp;

	for (int i = 0; i < 6; i++) {
		printf("��ȣ �Է� : ");
		scanf("%d", &temp);

		lotto_nums[i] = temp;

		for (int j = 0; j < i; j++) {
			if (lotto_nums[j] == temp) {
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				i--;
				break;
			}
		}

	}
}

void print_nums(int* lotto_nums) {
	for (int i = 0; i < 6; i++)
		printf("%d ", lotto_nums[i]);
}

int main() {
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);

	system("pause");
}