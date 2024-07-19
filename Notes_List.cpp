#include "Notes_List.h"

Color nl_cr;
volatile int combo = 0;
volatile int Hit_qualification = 1; //0:判定なし　1:判定あり 2:ヒット
int Notes_List::Notes(int count, int start, int notes, int hight , int Hit_position) {
	
	int notes_x = 1600;
	int notes_y;
	int NOTES;//画像用変数

	if (notes == LEFT) {
		//	画像を用意してここに張り付ける
		NOTES = LoadGraph(PIC_PLAY_NOTES_LEFT);
	}
	else if (notes == RIGHT) {
		//	画像を用意してここに張り付ける
	}
	else if (notes == DOWN) {
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

	//ノーツの座標
	if (count >= start) {
		notes_x = notes_x - (count - start) * NOTES_SPEED;
		DrawExtendGraph(notes_x, notes_y, notes_x + 100, notes_y + 100, NOTES, TRUE);
	}

	//ノーツのヒット判定
	//Hit_qualification　== 0:判定なし　1:判定あり 2:ヒット（一フレームのみ）
	if (hight == Hit_position && notes_x + 50 >= PLAY_HITBOX_x1 && notes_x + 50 <= PLAY_HITBOX_x2  )  {
		
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && Hit_qualification == 1) {
			
			Hit_qualification = 2;
		}

		if (Hit_qualification == 2) {
			combo++;
			Hit_qualification = 0;
		}

		if (notes_x + 50 == PLAY_HITBOX_x1 && Hit_qualification == 0) {
			Hit_qualification = 1;
		}
		else if (notes_x + 50 == PLAY_HITBOX_x1 && Hit_qualification == 1) {
			combo = 0;
		}
	}

	//ヒットエフェクトの表示
	if (hight == Hit_position && combo > 0 && Hit_qualification == 0) {
		switch (hight) {
			case UP:
				DrawFormatString(250, 280, nl_cr.Red, "HIT!!");
				break;
			case MID:
				DrawFormatString(250, 480, nl_cr.Red, "HIT!!");
				break;
			case UNDER:
				DrawFormatString(250, 680, nl_cr.Red, "HIT!!");
				break;
		}
		
	}
	
	//コンボエフェクトの表示
	DrawFormatString(180, 270, nl_cr.Blue, "%dCOMBO!!",combo);

	return 0;

}

void Notes_List::List_A(int count, int Hit_position) {
	Notes(count, 0, LEFT, UP, Hit_position);
	Notes(count, 50, LEFT, UNDER, Hit_position);
	Notes(count, 100, LEFT, MID, Hit_position);
	Notes(count, 150, LEFT, UP, Hit_position);
	Notes(count, 200, LEFT, MID, Hit_position);
	Notes(count, 250, LEFT, UNDER, Hit_position);
}