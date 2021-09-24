#pragma once
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL],int row,int col);
//�������Ƿ�ʤ��
int CheckPlayer(char board[ROW][COL]);
//�������Ƿ�ʤ��
int CheckCom(char board[ROW][COL]);
//������
int CheckDraw(char board[ROW][COL]);
//�����������λ���Ƿ�Ϊ��λ��
int CheckPlaceP(char board[ROW][COL], int x, int y);
//�����������λ���Ƿ�Ϊ��λ��
int CheckPlaceC(char board[ROW][COL], int x, int y);
//��������
void ComMove(char board[ROW][COL]);
//�������
void PlayerMove(char board[ROW][COL]);