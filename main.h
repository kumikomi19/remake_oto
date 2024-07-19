#pragma once
#include"DxLib.h"
//*************Å´âÊëúì«Ç›çûÇ›Å´*************
#define PIC_HOME_Start "pic/Home_Start.png" 
#define PIC_HOME_End "pic/Home_End.png"
#define PIC_PLAY_Line "pic/Play_notes_line.png"
#define PIC_PLAY_NOTES_LEFT "pic/Play_Notes_L.png"
#define PIC_PLAY_HITBOX "pic/Play_notes_hit.png"

//*************Å´HOMEä÷òAÅ´*************
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
//*************Å´Playä÷òAÅ´*************
#define PLAY_HITBOX_x1 180
#define PLAY_HITBOX_x2 280
#define PLAY_Notes_Line_x1 400
#define PLAY_Notes_Line_x2 1600
#define PLAY_Notes_Line_UP_y1 300
#define PLAY_Notes_Line_UP_y2 400
#define PLAY_Notes_Line_MID_y1 500 
#define PLAY_Notes_Line_MID_y2 600
#define PLAY_Notes_Line_BTM_y1 700
#define PLAY_Notes_Line_BTM_y2 800

#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define UP 1
#define MID 2
#define UNDER 3
#define NOTES_SPEED 5
//*************Å´OPTIONä÷òAÅ´*************
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
