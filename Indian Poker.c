#pragma warning(disable : 4996)
#pragma warning(disable : 4244)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main() {


	int cardyou = 0, cardme = 0, num1, battingmoney, again;
	unsigned int batting;
	int havemoneyme;
	int havemoneyyou;
	int diffculty;

	srand(time(NULL));

	while (1) {

		cardyou = rand() % 10 + 1;
		cardme = rand() % 10 + 1;

		system("cls");
		printf("---------------------�ε����Ŀ---------------------\n");
		printf("1. ���� ����\n");
		printf("2. ���� ���\n");
		printf("3. ���� ����\n");
		printf("Num : ");
		scanf("%d", &num1);

		
		if (num1 == 1) {
			printf("���̵� ������ �����մϴ�.\n");
			Sleep(1000);
			printf("���̵��� �����ϼ���.");
			printf("\n1. �ʺ�, 2. �߼�, 3. ���\n");
			printf("Input Numebr : ");
			scanf("%d", &diffculty);

			if (diffculty==1){
				havemoneyme = 100000;
				havemoneyyou = 100000;
				printf("�ʺ� ���̵��� �����Ǿ����ϴ�.");
			}
			else if (diffculty == 2) {
				havemoneyme = 80000;
				havemoneyyou = 500000;
				printf("�߼� ���̵��� �����Ǿ����ϴ�.");
			}
			else if (diffculty == 3) {
				havemoneyme = 50000;
				havemoneyyou = 1000000;
				printf("��� ���̵��� �����Ǿ����ϴ�.");
			}

			Sleep(1000);
			system("cls");

			{system("cls");
			printf("-----------------�ε����Ŀ ������ �����մϴ�.-----------------\n");
			again:
			printf("���� �ݾ� : %d, ��� ���� �ݾ� : %d, �⺻ ���� �ݾ� : 1000\n", havemoneyme, havemoneyyou);
			batting:
			printf("������ ī�带 ���� �ֽ��ϴ�.\n");
			Sleep(2000);
			printf("������ ī�带 �������ϴ�.\n\n");
			Sleep(300);
			printf("����� ī��� %d�Դϴ�. �����Ͻðڽ��ϱ�?\n", cardyou);
			printf("1. �����Ѵ�.\n�̿��� ����. �������� �ʴ´�.\n");
			scanf("%d", &battingmoney);
			if (battingmoney == 1) {}
			else {
				printf("�������� �ʽ��ϴ�.\n");
				printf("ī�带 Ȯ�� ���Դϴ�...\n");
				Sleep(1000);
				printf("�ڽ��� ī��� %d, ����� ī��� %d�Դϴ�.\n", cardme, cardyou);
				printf("����� �����߱� ������ ����� �¸��Դϴ�.");
				printf("�⺻ ���� �ݾ��� ����ϴ�\n");
				havemoneyme -= 1000;
				havemoneyyou += 1000;
				if (cardme == 10) {
					printf("�ڽ��� ī�尡 10�̾��� ������ 10 �г�Ƽ�� 10���� �⺻ ���� �ݾ��� �߰��� ���ѱ�ϴ�.\n");
					havemoneyme -= 10000;
					havemoneyyou += 10000;
				}
				if (havemoneyme <= 0) {
					printf("������ �̾ �÷����� �� �����ϴ�. ������ �����մϴ�.\n");
					return 0;
				}
				else if (havemoneyme > 0) {
					printf("\n������ �̾ �÷����Ͻ÷��� 1���� �����ֽð�, �÷������� �������� �ٸ� ���ڸ� �����ּ���.\n");
					scanf("%d", &again);
					if (again == 1) {
					}
					else {
						break;
					}
				}
				Sleep(2000);
				system("cls");
				cardyou = rand() % 10 + 1;
				cardme = rand() % 10 + 1;
				goto again;
			}
			printf("���� �ݾ��� �����ϼ���.\n");

		rebatting:

			printf("������ �ݾ� : ");
			scanf("%d", &batting);
			if (batting > havemoneyme || batting == 0) { // �����ݾ��� ���� �߻� 
				printf("������ �ݾ׺��� ���ñݾ��� ���ų� ������ �����߰ų�, 0���� �����Ͽ����ϴ�.. �ٽ� �����ϼ���.\n");
				goto rebatting;
			}
			printf("-----------------------------------------------\n");
			printf("ī�带 Ȯ�� ���Դϴ�...\n");
			Sleep(1000);
			printf("�ڽ��� ī��� %d, ����� ī��� %d�Դϴ�.\n", cardme, cardyou);

			if (cardme > cardyou) {
				printf("����� �¸�!, ����� ��뿡�� �¸��Ͽ� ��뿡�Լ� %d���� ������ϴ�!\n\n", batting);
				havemoneyme += batting;
				havemoneyyou -= batting;
				if (havemoneyyou <= 0) {
					printf("������ �̾ �÷����� �� �����ϴ�. ������ �����մϴ�.\n");
					return 0;
				}
				
				else if (havemoneyme > 0) {
					printf("\n������ �̾ �÷����Ͻ÷��� 1���� �����ֽð�, �÷������� �������� �ٸ� ���ڸ� �����ּ���.\n");
					scanf("%d", &again);
					if (again == 1) {
					}
					else {
						break;
					}
				}
				Sleep(2000);
				system("cls");
				cardyou = rand() % 10 + 1;
				cardme = rand() % 10 + 1;
				goto again;
			}

			else if (cardme == cardyou) {
				printf("�����ϴ�. �ٽ� �����ϼ���!\n\n");

				cardyou = rand() % 10 + 1;
				cardme = rand() % 10 + 1;

				Sleep(2000);
				system("cls");
				goto batting;


			}
			else if (cardme < cardyou) {
				printf("�����ϴ�. ����� %d���� �Ҿ����ϴ�!\n", batting);
				havemoneyme -= batting;
				havemoneyyou += batting * 2;
				if (havemoneyme <= 0) {
					printf("������ �̾ �÷����� �� �����ϴ�. ������ �����մϴ�.\n");
					return 0;
				}
				else if (havemoneyme > 0) {
					printf("\n������ �̾ �÷����Ͻ÷��� 1���� �����ֽð�, �÷������� �������� �ٸ� ���ڸ� �����ּ���.\n");
					scanf("%d", &again);
					if (again == 1) {
					}
					else {
						break;
					}
				}
				Sleep(2000);
				cardyou = rand() % 10 + 1;
				cardme = rand() % 10 + 1;
				system("cls");
				goto again;
				}
			}
		}
		else if (num1 == 2) {
			printf("----------------------�ε����Ŀ ���� ����---------------------\n");
			printf("�ڽŰ� ���� �� ���� ī�带 ������.\n");
			printf("�� ī��� 1���� 10 ������ ���ڸ� ������ �ִ� ī���.\n");
			printf("�ڱ� �ڽ��� ī�带 �����δ� �� �� ����, ������ ī�常�� �� �� �ִ�.\n");
			printf("�¸� ������ �ڽ��� ī��� ����� ī���� ���� ���� �� ū ����� �̱��.\n");
			printf("����� ī�带 ���� ���ϴ� ���� ���� �����Ѵ�.(�⺻ ���� �ݾ��� 1000)\n");
			printf("���� �� ������ ī�带 ���Ͽ� �¸� ���ǿ� ���߾� �¸��ڸ� �����Ѵ�.\n");
			printf("---------------------------------------------------------------\n");

			Sleep(5000);
			system("cls");
		}
		else if (num1 == 3) { //���� �� 
			printf("������ �����մϴ�.");
			return 0;
		}
		else { // �ٸ����� �ۼ� 
			printf("�ٸ� ���ڸ� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���.\n");
			Sleep(100);
			system("cls");
			continue;
		}
	}
}
