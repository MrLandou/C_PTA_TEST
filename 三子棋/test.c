#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu() {
	printf("**********************\n");
	printf("******1.��ʼ��Ϸ******\n");
	printf("******2.�˳���Ϸ******\n");
	printf("**********************\n");
	printf("��ã��������Ӧ�����ֽ���ѡ��:");
}
void InitGame() {
	char board[ROW][COL];
	
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	while (CheckPlayer(board) && CheckCom(board)) {
		PlayerMove(board);
		ComMove(board);
	}
}
int main() {
	int input;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf("%d",&input);
		switch (input) {
		case 1:
			InitGame();
			break;
		case 2:
			printf("�ټ�");
			break;
		}
	} while (input !=2);
	return 0;
}