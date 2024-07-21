#include "Notes_List.h"

Color nl_cr;
Block nl_bl;

int combo = 0;
int Hit_qualification[1023] = {1}; //0:判定あり　1:判定なし 2:ヒット(最大1024個のノーツを管理)

int set_operation = 0;

int tempo = 500;//ここはｂｐｍによって変更できるようにする

void Notes_List::Notes(int count, int start, int notes, int hight , int Hit_position) {
	
	int notes_x = 1600;
	int notes_y;
	int NOTES;//画像用変数
	if (notes == LEFT) {
		//	画像を用意してここに張り付ける
		NOTES = LoadGraph(PIC_PLAY_NOTES_LEFT);
	}
	else if (notes == RIGHT) {
		//	画像を用意してここに張り付ける
		NOTES = LoadGraph(PIC_PLAY_NOTES_LEFT);
	}
	else if (notes == DOWN) {
		//	画像を用意してここに張り付ける
		NOTES = LoadGraph(PIC_PLAY_NOTES_LEFT);
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
	if (count >= start* tempo) {
		notes_x = notes_x - (count - start * tempo) * NOTES_SPEED;
		DrawExtendGraph(notes_x, notes_y, notes_x + 100, notes_y + 100, NOTES, TRUE);
	}

	//ノーツのヒット判定
	//Hit_qualification　== 0:判定あり　1:判定なし 2:ヒット（一フレームのみ）
	if (hight == Hit_position && notes_x + 50 >= PLAY_HITBOX_x1 - 100 && notes_x + 50 <= PLAY_HITBOX_x2 +100  )  {
		
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && Hit_qualification[start] == 0) {
		
			Hit_qualification[start] = 2;
		}


		if (Hit_qualification[start] == 2) {//ヒット時の処理
			combo++;
			Hit_qualification[start] = 1;
			Hit_qualification[start + 1] = 0;
			nl_bl.Get_operation(notes);
		}
		

	}

	//コンボの途切れを検出
	if (notes_x + 50 == PLAY_HITBOX_x1 - 101 && Hit_qualification[start] == 0) {
		combo = 0;

	}

	//ヒットエフェクトの表示
	if (hight == Hit_position && combo > 0 && Hit_qualification[start] == 0) {
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


	
	//返り値…0:特に何もない　1:ミス　2:ヒット
}

void Notes_List::List_A(int count, int Hit_position) {
	if (count == 0) {
		Hit_qualification[0] = 0;
	}
	Notes(count, 0, LEFT, UP, Hit_position);
	Notes(count, 1 , RIGHT, UNDER, Hit_position);
	Notes(count, 2 , RIGHT, MID, Hit_position);
	Notes(count, 3 , LEFT, UP, Hit_position);
	Notes(count, 4 , LEFT, MID, Hit_position);
	Notes(count, 5 , LEFT, UNDER, Hit_position);
	DrawFormatString(580, 180, nl_cr.Black, "hq1:%d", Hit_qualification[0]);
	DrawFormatString(680, 180, nl_cr.Black, "hq2:%d", Hit_qualification[1]);
	DrawFormatString(780, 180, nl_cr.Black, "hq3:%d", Hit_qualification[2]);
	DrawFormatString(580, 200, nl_cr.Black, "hq4:%d", Hit_qualification[3]);
	DrawFormatString(680, 200, nl_cr.Black, "hq5:%d", Hit_qualification[4]);
	DrawFormatString(780, 200, nl_cr.Black, "hq6:%d", Hit_qualification[5]);
	
}