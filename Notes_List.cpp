#include "Notes_List.h"


int Notes_List::Notes(int count, int start, Notes_State state, Notes_Hight hight) {
	int notes_x = 1600;
	int notes_y;
	int NOTES;//�摜�p�ϐ�
	if (state == LEFT) {
		//	�摜��p�ӂ��Ă����ɒ���t����
		NOTES = LoadGraph(PIC_PLAY_NOTES_LEFT);
	}
	else if (state == RIGHT) {
		//	�摜��p�ӂ��Ă����ɒ���t����
	}
	else if (state == DOWN) {
		//	�摜��p�ӂ��Ă����ɒ���t����
	}

	if (hight == UP) {
		notes_y = 350;
	}
	else if (hight == MID) {
		notes_y = 550;
	}
	else if (hight == DOWN) {
		notes_y = 750;
	}
	/*****�������牺�Ńm�[�c�̓������w��******/

	DrawExtendGraph(Home_Tilte_x1, Home_Tilte_y1, Home_Tilte_x2, Home_Tilte_y2,NOTES , TRUE);





}

void Notes_List::List_A(int count) {
	
}