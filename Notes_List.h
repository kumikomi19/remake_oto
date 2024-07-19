#pragma once
#include "DxLib.h"
#include "main.h"
class Notes_List {
private:
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define UP 1
#define MID 2
#define UNDER 3

public:
	int Notes(int count, int start, int notes, int hight);
	void List_A(int count);
};