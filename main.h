#pragma once
#include"DxLib.h"
//*************«‰æ‘œ“Ç‚İ‚İ«*************
#define PIC_HOME_Start "pic/Home_Start.png" 
#define PIC_HOME_End "pic/Home_End.png"
#define PIC_PLAY_Line "pic/Play_notes_line.png"
#define PIC_PLAY_NOTES_LEFT "pic/Play_Notes_L.png"

//*************«HOMEŠÖ˜A«*************
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
//*************«PlayŠÖ˜A«*************
#define PLAY_Notes_Line_x1 400
#define PLAY_Notes_Line_x2 1600
#define PLAY_Notes_Line_UP_y1 300
#define PLAY_Notes_Line_UP_y2 400
#define PLAY_Notes_Line_MID_y1 500 
#define PLAY_Notes_Line_MID_y2 600
#define PLAY_Notes_Line_BTM_y1 700
#define PLAY_Notes_Line_BTM_y2 800
//*************«OPTIONŠÖ˜A«*************
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
