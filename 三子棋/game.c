#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void InitBoard(char board[ROW][COL],int row,int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}

}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ",board[i][j]);
			if (j!=col-1) {
				printf("|");
			}
			else {
				printf("\n");
			}
		}
		if (i != row-1) {
			for (int k = 1; k < col;k++) {
				printf("---|");
			}
			printf("---\n");
		}

	}
}
int CheckPlayer(char board[ROW][COL]) {
	int flag = 1;
	for (int i = 0; i < ROW; i++) {
		if (board[i][0] == '*' && board[i][1] == '*' && board[i][2] == '*') {
			flag = 0;
			printf("���ʤ��\n");
			break;
		}
	}
	for (int j = 0; j < COL; j++) {
		if (board[0][j] == '*' && board[1][j] == '*' && board[2][j] == '*') {
			flag = 0;
			printf("���ʤ��\n");
		}
	}
	if (board[0][0] == '*' && board[1][1] == '*' && board[2][2] == '*') {
		flag = 0;
		printf("���ʤ��\n");
	}
	if (board[0][2] == '*' && board[1][1] == '*' && board[2][0] == '*') {
		flag = 0;
		printf("���ʤ��\n");
	}
	return flag;
}
int CheckCom(char board[ROW][COL]) {
	int flag = 1;
	for (int i = 0; i < ROW; i++) {
		if (board[i][0] == '#' && board[i][1] == '#' && board[i][2] == '#') {
			flag = 0;
			printf("����ʤ��\n");
		}
	}
	for (int j = 0; j < COL; j++) {
		if (board[0][j] == '#' && board[1][j] == '#' && board[2][j] == '#') {
			flag = 0;
			printf("����ʤ��\n");
		}
	}
	if (board[0][0] == '#' && board[1][1] == '#' && board[2][2] == '#') {
		flag = 0;
		printf("����ʤ��\n");
	}
	if (board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#') {
		flag = 0;
		printf("����ʤ��\n");
	}
	if (CheckDraw(board)) {
		flag = 0;
		printf("����\n");
	}
	return flag;
}
int CheckDraw(char board[ROW][COL]) {
	int sum=0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (board[i][j] != ' ') {
				sum++;
			}
		}
	}
	if (sum == 9) {
		return 1;
	}
	else {
		return 0;
	}
}
void PlayerMove(char board[ROW][COL]){
	int x, y;
	printf("�������,����Ҫ�ߵ�����:x y(�м����ÿո����)");
	scanf("%d %d",&x,&y);
	x--; y--;
	while(CheckPlaceP(board, x, y)) {
		scanf("%d %d", &x, &y);
		x--; y--;
	}
	board[x][y] = '*';
	DisplayBoard(board,ROW,COL);
	
}
void ComMove(char board[ROW][COL]) {
	if (CheckDraw(board) == 0) {
		printf("�������\n");
		int a = rand() % ROW;
		int b = rand() % COL;
		while (CheckPlaceC(board, a, b)) {
			a = rand() % ROW;
			b = rand() % COL;	
		}
		if (CheckDraw(board) == 0) {
			board[a][b] = '#';
			DisplayBoard(board, ROW, COL);
		}
	}
}
int CheckPlaceP(char board[ROW][COL], int x, int y) {
	if (x<0 || x>ROW || y<0 || y>COL) {
		printf("��������ȷ������");
		return 1;
	}
	else if(board[x][y] == '*' || board[x][y] == '#') {
		printf("��λ���ѱ�ռ�ݣ�������\n");
		if (CheckDraw(board)) {
			return 0;
		}
		return 1;
	}
	else if (board[x][y] == ' ') {
		return 0;
	}
}
int CheckPlaceC(char board[ROW][COL], int x, int y) {
	/*if (x<0 || x>ROW || y<0 || y>COL) {
		//printf("��������ȷ������");
		return 1;
	}
	*/
	if (board[x][y] == '*' || board[x][y] == '#') {
		//printf("��λ���ѱ�ռ�ݣ�������\n");
		if (CheckDraw(board)) {
			return 0;
		}
		return 1;
	}
	else if (board[x][y] == ' ') {
		return 0;
	}
}