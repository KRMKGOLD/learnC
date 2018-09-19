#include "menu.h"

int firstNumber, firstKor, firstEng, firstMath;
char firstName[10];

int stuNum = 0;

int checkDataIndex = 1;

void showMenu() {
	int i = 0;

	inputFirstData();
	while (1) {
		printf("1> �ο��� �Է�\n");
		printf("2> �߰� ���\n");
		printf("3> ���� ����\n");
		printf("4> ����\n");
		printf("5> ���\n");
		printf("Input Number : ");
		scanf("%d", &i);

		switch (i) {
		case 1: inputStuNum(); break;
		case 2: inputData(); break;
		case 3: searchData(); break;
		case 4: deleteData(); break;
		case 5: printData(); break;
		default:
			system("pause");
			exit(0);
		}
	}
}

void inputFirstData() {
	printf("�й��� �Է��ϼ���. : ");
	scanf("%d", &firstNumber);
	printf("�̸��� �Է��ϼ���. : ");
	scanf("%s", firstName);
	printf("���� ������ �Է��ϼ���. : ");
	scanf("%d", &firstKor);
	printf("���� ������ �Է��ϼ���. : ");
	scanf("%d", &firstEng);
	printf("���� ������ �Է��ϼ���. : ");
	scanf("%d", &firstMath);
	printf("\n");
}

void inputStuNum() {
	static bool checkStuNum = false;
	if (checkStuNum == true) {
		printf("�̹� �ο����� �Է��߽��ϴ�.\n\n");
		return;
	}
	printf("�ο����� �Է��ϼ���. : ");
	scanf("%d", &stuNum);
	stuArr = (Student*)malloc(sizeof(Student) * stuNum);

	stuArr[0].number = firstNumber;
	strcpy(stuArr[0].name, firstName);
	// stuArr[0].name = firstName;
	stuArr[0].kor = firstKor;
	stuArr[0].eng = firstEng;
	stuArr[0].math = firstMath;

	checkStuNum = true;
	putchar('\n');
}

void inputData() {
	printf("�й��� �Է��ϼ���. : ");
	scanf("%d", &stuArr[checkDataIndex].number);
	printf("�̸��� �Է��ϼ���. : ");
	scanf("%s", stuArr[checkDataIndex].name);
	if (checkOverLap(stuArr[checkDataIndex].number, stuArr[checkDataIndex].name) == -1) {
		printf("�й��� �̸��� �ߺ��˴ϴ�. �ٽ� �Է����ּ���.\n\n");
		return;
	}
	printf("���� ������ �Է��ϼ���. : ");
	scanf("%d", &stuArr[checkDataIndex].kor);
	printf("���� ������ �Է��ϼ���. : ");
	scanf("%d", &stuArr[checkDataIndex].eng);
	printf("���� ������ �Է��ϼ���. : ");
	scanf("%d", &stuArr[checkDataIndex].math);
	putchar('\n');
	checkDataIndex++;
}

int checkOverLap(int number, char name[]) {
	for (int i = 0; i < checkDataIndex; i++) {
		if (strcmp(name, stuArr[i].name) == 0 && number == stuArr[i].number) {
			return -1;
		}
		else return 0;
	}
}

void deleteData() {
	int indexNum = 0;
	int overlapNum = 0;
	char name[10];

	printf("������� �ϴ� �л��� �̸��� �Է��ϼ���.");
	scanf("%s", name);

	for (int i = 0; i < checkDataIndex; i++) {
		if (strcmp(name, stuArr[i].name) == 0) {
			printf("%d. \n", ++indexNum);
			printf("�й� : %d\n", stuArr[i].number);
			printf("�̸� : %s\n", stuArr[i].name);
			printf("���� ���� : %d\n", stuArr[i].kor);
			printf("���� ���� : %d\n", stuArr[i].math);
			printf("���� ���� : %d\n\n", stuArr[i].eng);
		}
	}

	if (indexNum == 0) {
		printf("�����Ϸ��� �ϴ� ����� �����ϴ�.\n\n");
		return;
	}
	else if (indexNum == 1) {
		int checkNum;
		printf("�����Ϸ��� �ϴ� ����� ���� �����ϴ�. �����Ͻðڽ��ϱ�? \n");
		printf("1. ��, 2. �ƴϿ� : ");
		scanf("%d", &checkNum);
		if (checkNum == 1) {
			for (int i = 0; i < checkDataIndex; i++) {
				if (strcmp(name, stuArr[i].name) == 0) {
					while (i < checkDataIndex) 
					{
						stuArr[i] = stuArr[i + 1];
						i++;
					}
				}
			}
		}
	}
	else if (indexNum > 1) {
		int k = 0;
		printf("�����Ϸ��� ����� �� �� �̻��Դϴ�. �����Ϸ��� �ϴ� ����� ��ȣ�� �Է��ϼ���.\n");
		scanf("%d", &overlapNum);
		for (int i = 0; i <= checkDataIndex; i++) {
			if (strcmp(name, stuArr[i].name) == 0) {
				k++;
				if (overlapNum == k) {
					while (i < checkDataIndex) {
						stuArr[i] = stuArr[i + 1];
						i++;
					}
				}
			}
		}
	}

	checkDataIndex--;
}

void searchData() {
	int indexNum = 0;
	char searchName[10];
	printf("ã�� �ִ� �л��� �̸��� �Է��ϼ���. : ");
	scanf("%s", searchName);
	for (int i = 0; i < checkDataIndex; i++) {
		if (strcmp(searchName, stuArr[i].name) == 0) {
			printf("%d. \n", ++indexNum);
			printf("�й� : %d\n", stuArr[i].number);
			printf("�̸� : %s\n", stuArr[i].name);
			printf("���� ���� : %d\n", stuArr[i].kor);
			printf("���� ���� : %d\n", stuArr[i].math);
			printf("���� ���� : %d\n\n", stuArr[i].eng);
		}
	}
}

void printData() {
	int indexNum = 0;
	for (int i = 0; i < checkDataIndex; i++) {
		printf("=========================\n");
		printf("%d. \n", ++indexNum);
		printf("�й� : %d\n", stuArr[i].number);
		printf("�̸� : %s\n", stuArr[i].name);
		printf("���� ���� : %d\n", stuArr[i].kor);
		printf("���� ���� : %d\n", stuArr[i].math);
		printf("���� ���� : %d\n", stuArr[i].eng);
		printf("=========================\n\n");
	}
}