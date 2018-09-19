#include "menu.h"

int firstNumber, firstKor, firstEng, firstMath;
char firstName[10];

int stuNum = 0;

int checkDataIndex = 1;

void showMenu() {
	int i = 0;

	inputFirstData();
	while (1) {
		printf("1> 인원수 입력\n");
		printf("2> 추가 등록\n");
		printf("3> 석차 보기\n");
		printf("4> 삭제\n");
		printf("5> 출력\n");
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
	printf("학번을 입력하세요. : ");
	scanf("%d", &firstNumber);
	printf("이름을 입력하세요. : ");
	scanf("%s", firstName);
	printf("국어 성적을 입력하세요. : ");
	scanf("%d", &firstKor);
	printf("영어 성적을 입력하세요. : ");
	scanf("%d", &firstEng);
	printf("수학 성적을 입력하세요. : ");
	scanf("%d", &firstMath);
	printf("\n");
}

void inputStuNum() {
	static bool checkStuNum = false;
	if (checkStuNum == true) {
		printf("이미 인원수를 입력했습니다.\n\n");
		return;
	}
	printf("인원수를 입력하세요. : ");
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
	printf("학번을 입력하세요. : ");
	scanf("%d", &stuArr[checkDataIndex].number);
	printf("이름을 입력하세요. : ");
	scanf("%s", stuArr[checkDataIndex].name);
	if (checkOverLap(stuArr[checkDataIndex].number, stuArr[checkDataIndex].name) == -1) {
		printf("학번과 이름이 중복됩니다. 다시 입력해주세요.\n\n");
		return;
	}
	printf("국어 성적을 입력하세요. : ");
	scanf("%d", &stuArr[checkDataIndex].kor);
	printf("영어 성적을 입력하세요. : ");
	scanf("%d", &stuArr[checkDataIndex].eng);
	printf("수학 성적을 입력하세요. : ");
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

	printf("지우려고 하는 학생의 이름을 입력하세요.");
	scanf("%s", name);

	for (int i = 0; i < checkDataIndex; i++) {
		if (strcmp(name, stuArr[i].name) == 0) {
			printf("%d. \n", ++indexNum);
			printf("학번 : %d\n", stuArr[i].number);
			printf("이름 : %s\n", stuArr[i].name);
			printf("국어 성적 : %d\n", stuArr[i].kor);
			printf("수학 성적 : %d\n", stuArr[i].math);
			printf("영어 성적 : %d\n\n", stuArr[i].eng);
		}
	}

	if (indexNum == 0) {
		printf("삭제하려고 하는 대상이 없습니다.\n\n");
		return;
	}
	else if (indexNum == 1) {
		int checkNum;
		printf("삭제하려고 하는 대상이 위와 같습니다. 삭제하시겠습니까? \n");
		printf("1. 예, 2. 아니오 : ");
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
		printf("삭제하려는 대상이 두 개 이상입니다. 삭제하려고 하는 사람의 번호를 입력하세요.\n");
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
	printf("찾고 있는 학생의 이름을 입력하세요. : ");
	scanf("%s", searchName);
	for (int i = 0; i < checkDataIndex; i++) {
		if (strcmp(searchName, stuArr[i].name) == 0) {
			printf("%d. \n", ++indexNum);
			printf("학번 : %d\n", stuArr[i].number);
			printf("이름 : %s\n", stuArr[i].name);
			printf("국어 성적 : %d\n", stuArr[i].kor);
			printf("수학 성적 : %d\n", stuArr[i].math);
			printf("영어 성적 : %d\n\n", stuArr[i].eng);
		}
	}
}

void printData() {
	int indexNum = 0;
	for (int i = 0; i < checkDataIndex; i++) {
		printf("=========================\n");
		printf("%d. \n", ++indexNum);
		printf("학번 : %d\n", stuArr[i].number);
		printf("이름 : %s\n", stuArr[i].name);
		printf("국어 성적 : %d\n", stuArr[i].kor);
		printf("수학 성적 : %d\n", stuArr[i].math);
		printf("영어 성적 : %d\n", stuArr[i].eng);
		printf("=========================\n\n");
	}
}