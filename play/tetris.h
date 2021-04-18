#pragma once
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define left 75
#define right 77
#define down 80
#define full_down 115
#define change 97
#define stop 27
#define reset 122

typedef struct block_xy
{
    int x;
    int y;
}block_xy;

void tgotoxy(int x, int y);
void mouse();

//��� ���
void print_background();
void block_start(block_xy start_xy, int* block_type);

//�� ������ �� �ִ��� üũ
int block_chack(block_xy start_xy, int* block_type);

//�� ���
void block_print(block_xy start_xy, int* block_type);
//�� ����
void block_delete(block_xy start_xy, int* block_type);

//�� �̵�
block_xy block_move(block_xy start_xy, int* block_type);

void block_stop(block_xy start_xy, int* block_type);
void line_chack_and_remove();

void next_block(block_xy start_xy, int* next_type);
void next_block_background();
void clear_next_block();
void esc_remove();

void key_check();

int tetris_start();