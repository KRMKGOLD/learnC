#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

int main() {
	char str[1000] = { 0, };
	char a[100];

	printf("�ܾ� �Է� : ");
	scanf("%s", a);
	while ((strcmp(a, "end")) != 0) {
		strcat(str, a);
		strcat(str, " ");
		printf("���ڿ� : %s\n", str);
		printf("�ܾ� �Է� : ");
		scanf("%s", a);
	}
}