#include "Notes_List.h"

Color nl_cr;

int Notes_List::Notes(int count, int start, int state, int hight) {
	int notes_x = 1600;
	int notes_y;
	int NOTES;//画像用変数
	if (state == LEFT) {
		//	画像を用意してここに張り付ける
		NOTES = LoadGraph(PIC_PLAY_NOTES_LEFT);
	}
	else if (state == RIGHT) {
		//	画像を用意してここに張り付ける
	}
	else if (state == DOWN) {
		//	画像を用意してここに張り付ける
	}

	if (hight == UP) {
		notes_y = 300;
	}
	else if (hight == MID) {
		notes_y = 500;
	}
	else if (hight == UNDER) {
		notes_y = 700;
	}
	/*****ここから下でノーツの動きを指示******/
	
	if (count >= start) {
		notes_x = notes_x - (count - start);
		DrawExtendGraph(notes_x, notes_y, notes_x + 100, notes_y + 100, NOTES, TRUE);
	}

	return 0;

}

void Notes_List::List_A(int count) {
	Notes(count, 0, LEFT, UP);
	
}