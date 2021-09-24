#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu() {
	printf("**********************\n");
	printf("******1.开始游戏******\n");
	printf("******2.退出游戏******\n");
	printf("**********************\n");
	printf("你好！请输入对应的数字进行选择:");
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
			printf("再见");
			break;
		}
	} while (input !=2);
	return 0;
}