#pragma once
#include"DxLib.h"
//âÊëúÇÕå„Ç≈ç∑Çµë÷Ç¶
#define PIC_Start "pic/Home_Start.png" 
#define PIC_End "pic/Home_End.png"

#define Home_Tilte_x1 300
#define Home_Tilte_y1 200
#define Home_Tilte_x2 1300
#define Home_Tilte_y2 400
#define Home_Start_x1 500
#define Home_Start_y1 500
#define Home_Start_x2 1100
#define Home_Start_y2 600
#define Home_End_x1 500
#define Home_End_y1 700
#define Home_End_x2 1100
#define Home_End_y2 800

#define OPSION_BOX_x1 500
#define OPSION_BOX_y1 700
#define OPSION_BOX_x2 1100
#define OPSION_BOX_y2 800

class Color {
public:
	int Black = GetColor(0, 0, 0);
	int Red = GetColor(255, 0, 0);
	int Blue = GetColor(0, 0, 255);
	int Green = GetColor(0, 255, 0);
	int Yellow = GetColor(255, 255, 0);
	int White = GetColor(255, 255, 255);
	int Play_Flame_01 = GetColor(130, 108, 128);
};


typedef enum {
	HOME,
	PLAY,
	OPTION
}Mode_State;

typedef enum {
	ZERO,
	T,
	S,
	Z,
	L,
	J,
	O,
	I,
}Mino_State;
