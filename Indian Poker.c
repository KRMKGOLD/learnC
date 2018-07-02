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
		printf("---------------------인디언포커---------------------\n");
		printf("1. 게임 시작\n");
		printf("2. 게임 방법\n");
		printf("3. 게임 종료\n");
		printf("Num : ");
		scanf("%d", &num1);

		
		if (num1 == 1) {
			printf("난이도 설정을 시작합니다.\n");
			Sleep(1000);
			printf("난이도를 선택하세요.");
			printf("\n1. 초보, 2. 중수, 3. 고수\n");
			printf("Input Numebr : ");
			scanf("%d", &diffculty);

			if (diffculty==1){
				havemoneyme = 100000;
				havemoneyyou = 100000;
				printf("초보 난이도로 설정되었습니다.");
			}
			else if (diffculty == 2) {
				havemoneyme = 80000;
				havemoneyyou = 500000;
				printf("중수 난이도로 설정되었습니다.");
			}
			else if (diffculty == 3) {
				havemoneyme = 50000;
				havemoneyyou = 1000000;
				printf("고수 난이도로 설정되었습니다.");
			}

			Sleep(1000);
			system("cls");

			{system("cls");
			printf("-----------------인디언포커 게임을 시작합니다.-----------------\n");
			again:
			printf("보유 금액 : %d, 상대 보유 금액 : %d, 기본 배팅 금액 : 1000\n", havemoneyme, havemoneyyou);
			batting:
			printf("딜러가 카드를 섞고 있습니다.\n");
			Sleep(2000);
			printf("딜러가 카드를 섞었습니다.\n\n");
			Sleep(300);
			printf("상대의 카드는 %d입니다. 배팅하시겠습니까?\n", cardyou);
			printf("1. 배팅한다.\n이외의 숫자. 배팅하지 않는다.\n");
			scanf("%d", &battingmoney);
			if (battingmoney == 1) {}
			else {
				printf("배팅하지 않습니다.\n");
				printf("카드를 확인 중입니다...\n");
				Sleep(1000);
				printf("자신의 카드는 %d, 상대의 카드는 %d입니다.\n", cardme, cardyou);
				printf("당신은 포기했기 때문에 상대의 승리입니다.");
				printf("기본 배팅 금액을 뺏깁니다\n");
				havemoneyme -= 1000;
				havemoneyyou += 1000;
				if (cardme == 10) {
					printf("자신의 카드가 10이었기 때문에 10 패널티로 10배의 기본 배팅 금액을 추가로 빼앗깁니다.\n");
					havemoneyme -= 10000;
					havemoneyyou += 10000;
				}
				if (havemoneyme <= 0) {
					printf("게임을 이어서 플레이할 수 없습니다. 게임을 종료합니다.\n");
					return 0;
				}
				else if (havemoneyme > 0) {
					printf("\n게임을 이어서 플레이하시려면 1번을 눌러주시고, 플레이하지 않으려면 다른 숫자를 눌러주세요.\n");
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
			printf("배팅 금액을 선택하세요.\n");

		rebatting:

			printf("배팅할 금액 : ");
			scanf("%d", &batting);
			if (batting > havemoneyme || batting == 0) { // 보유금액의 문제 발생 
				printf("보유한 금액보다 배팅금액이 많거나 음수를 배팅했거나, 0원을 배팅하였습니다.. 다시 배팅하세요.\n");
				goto rebatting;
			}
			printf("-----------------------------------------------\n");
			printf("카드를 확인 중입니다...\n");
			Sleep(1000);
			printf("자신의 카드는 %d, 상대의 카드는 %d입니다.\n", cardme, cardyou);

			if (cardme > cardyou) {
				printf("당신의 승리!, 당신은 상대에게 승리하여 상대에게서 %d원을 얻었습니다!\n\n", batting);
				havemoneyme += batting;
				havemoneyyou -= batting;
				if (havemoneyyou <= 0) {
					printf("게임을 이어서 플레이할 수 없습니다. 게임을 종료합니다.\n");
					return 0;
				}
				
				else if (havemoneyme > 0) {
					printf("\n게임을 이어서 플레이하시려면 1번을 눌러주시고, 플레이하지 않으려면 다른 숫자를 눌러주세요.\n");
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
				printf("비겼습니다. 다시 배팅하세요!\n\n");

				cardyou = rand() % 10 + 1;
				cardme = rand() % 10 + 1;

				Sleep(2000);
				system("cls");
				goto batting;


			}
			else if (cardme < cardyou) {
				printf("졌습니다. 당신은 %d원을 잃었습니다!\n", batting);
				havemoneyme -= batting;
				havemoneyyou += batting * 2;
				if (havemoneyme <= 0) {
					printf("게임을 이어서 플레이할 수 없습니다. 게임을 종료합니다.\n");
					return 0;
				}
				else if (havemoneyme > 0) {
					printf("\n게임을 이어서 플레이하시려면 1번을 눌러주시고, 플레이하지 않으려면 다른 숫자를 눌러주세요.\n");
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
			printf("----------------------인디언포커 게임 설명---------------------\n");
			printf("자신과 상대는 한 개의 카드를 가진다.\n");
			printf("각 카드는 1에서 10 사이의 숫자를 가지고 있는 카드다.\n");
			printf("자기 자신의 카드를 스스로는 볼 수 없고, 상대방의 카드만을 볼 수 있다.\n");
			printf("승리 조건은 자신의 카드와 상대의 카드의 수를 비교해 더 큰 사람이 이긴다.\n");
			printf("상대의 카드를 보고 원하는 돈의 수를 배팅한다.(기본 배팅 금액은 1000)\n");
			printf("배팅 후 서로의 카드를 비교하여 승리 조건에 맞추어 승리자를 결정한다.\n");
			printf("---------------------------------------------------------------\n");

			Sleep(5000);
			system("cls");
		}
		else if (num1 == 3) { //게임 종 
			printf("게임을 종료합니다.");
			return 0;
		}
		else { // 다른숫자 작성 
			printf("다른 숫자를 입력하였습니다. 다시 입력하세요.\n");
			Sleep(100);
			system("cls");
			continue;
		}
	}
}
