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

	if (count >= start) {
		notes_x = notes_x - (count - start);
			DrawExtendGraph(notes_x, notes_y, notes_x+50, notes_y+50, NOTES, TRUE);
	}



	return 0;

}

void Notes_List::List_A(int count) {
	Notes(count, 0, LEFT, UP);
}