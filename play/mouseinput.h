#pragma once
#include <stdio.h> 
#include <Windows.h>

int be_input();
int get_input(WORD* vkey, COORD* pos);
void gotoxy(int x, int y);
void mouseinput();