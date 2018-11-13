#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

int main() {
	char a[100];
	char b[100];
	char c[100];

	scanf("%s %s %s", a, b, c);

	char tmp[100];
	if (strcmp(a, b) > 0) {
		strcpy(tmp, a);
		strcpy(a, b);
		strcpy(b, tmp);
	}

	if (strcmp(b, c) > 0) {
		strcpy(tmp, b);
		strcpy(b, c);
		strcpy(c, tmp);
	}

	if (strcmp(a, c) > 0) {
		strcpy(tmp, a);
		strcpy(a, c);
		strcpy(b, c);
	}

	printf("%s %s %s\n", a, b, c);

	system("pause");
}