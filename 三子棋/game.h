#pragma once
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL],int row,int col);
//检查玩家是否胜利
int CheckPlayer(char board[ROW][COL]);
//检查电脑是否胜利
int CheckCom(char board[ROW][COL]);
//检查和棋
int CheckDraw(char board[ROW][COL]);
//检查玩家下棋的位置是否为空位置
int CheckPlaceP(char board[ROW][COL], int x, int y);
//检查电脑下棋的位置是否为空位置
int CheckPlaceC(char board[ROW][COL], int x, int y);
//电脑下棋
void ComMove(char board[ROW][COL]);
//玩家下棋
void PlayerMove(char board[ROW][COL]);