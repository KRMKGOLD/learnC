#include <stdio.h>

void print_graph(int *ps, int size) {
	for (int i = 0; i < size; i++) {
		int k = ps[i];

		printf("(%3d) : ", ps[i]);

		while (k >= 5) {
			printf("*");
			k -= 5;
		}

		printf("\n");
	}
}

int main() {
	int score[5] = {72, 88, 95, 64, 100};

	print_graph(score, 5);
}