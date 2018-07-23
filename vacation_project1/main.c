#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT = 1, SHOWALL, QUIT};

int main(void) {
	int inputMenu = 0;
	int i = 0;

	while (1) {
		ShowMenu();
		fputs("선택하세요 : ", stdout);
		scanf("%d", &inputMenu);
		fflush(stdin);

		switch (inputMenu) {
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowAllData();
			break;
		}

		if (inputMenu == QUIT) {
			puts("이용해 주셔서 감사합니다.");
			system("pause");
			break;
		}
	}
	return 0;
}