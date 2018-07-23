#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum{INPUT = 1, SHOWALL, QUIT};

int main(void) {
	int inputMenu = 0;
	int i = 0;

	while (1) {
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
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
			puts("�̿��� �ּż� �����մϴ�.");
			system("pause");
			break;
		}
	}
	return 0;
}