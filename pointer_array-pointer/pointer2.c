#include <stdio.h>

void swap(int *pa, int *pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void rotate(int* pa, int* pb, int* pc) {
	swap(pa, pc);
	swap(pa, pb);
}

int main() {
	int a = 1, b = 2, c = 3;

	printf("%d %d %d", a, b, c);

	while (getchar() == '\n') {
		rotate(&a, &b, &c);
		printf("%d %d %d", a, b, c);
	}
}