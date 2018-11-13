#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

int main() {
	char str[1000] = { 0, };
	char a[100];

	printf("단어 입력 : ");
	scanf("%s", a);
	while ((strcmp(a, "end")) != 0) {
		strcat(str, a);
		strcat(str, " ");
		printf("문자열 : %s\n", str);
		printf("단어 입력 : ");
		scanf("%s", a);
	}
}