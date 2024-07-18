#include "Notes_List.h"


int Notes_List::Notes(int count, int start, Notes_State state, Notes_Hight hight) {
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
		notes_y = 350;
	}
	else if (hight == MID) {
		notes_y = 550;
	}
	else if (hight == DOWN) {
		notes_y = 750;
	}
	/*****ここから下でノーツの動きを指示******/

	if (count >= start) {
		notes_x = notes_x - (count - start);
			DrawExtendGraph(notes_x, notes_y, notes_x+50, notes_y+50, NOTES, TRUE);
	}



	return 0;

}

void Notes_List::List_A(int count) {
	Notes(count, 0, LEFT, UP);
}