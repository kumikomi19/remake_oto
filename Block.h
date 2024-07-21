#pragma once
#include"DxLib.h"
#include"main.h"

class Block {



public:
	void Get_operation(int op);
	void Draw_ALLBlock();
	void Mino_move(int mino_direction, int x, int y);
	void Mino(Mino_State mino);
	
};