#include"song.h"
#include"Notes_List.h"


Notes_List sc_nl;
Color sc_cr;

int Song_composition::Song(){

	int notes_line = LoadGraph(PIC_PLAY_Line);
	int notes_hitbox = LoadGraph(PIC_PLAY_HITBOX);
	int Hit_position = MID;
	bool move_qualification = FALSE;
	SetDrawScreen(DX_SCREEN_BACK);
	for (int count = 0; count < 50000; count++) {
		if (ProcessMessage() != 0) { // メッセージ処理
			break;//ウィンドウの×ボタンが押されたらループを抜ける
		}
		
		ClearDrawScreen();
		//↓上中下のノーツライン
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_UP_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_UP_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_MID_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_MID_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_BTM_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_BTM_y2, notes_line, TRUE);
		//↓上中下のヒットボックス
		DrawExtendGraph(PLAY_HITBOX_x1, PLAY_Notes_Line_UP_y1, PLAY_HITBOX_x2, PLAY_Notes_Line_UP_y2, notes_hitbox, TRUE);
		DrawExtendGraph(PLAY_HITBOX_x1, PLAY_Notes_Line_MID_y1, PLAY_HITBOX_x2, PLAY_Notes_Line_MID_y2, notes_hitbox, TRUE);
		DrawExtendGraph(PLAY_HITBOX_x1, PLAY_Notes_Line_BTM_y1, PLAY_HITBOX_x2, PLAY_Notes_Line_BTM_y2, notes_hitbox, TRUE);
		//↓ヒットボックス移動
	
		if (CheckHitKeyAll() == 0) {
			move_qualification = TRUE;
		}
		
		if (move_qualification == TRUE) {
			if (CheckHitKey(KEY_INPUT_UP) == 1) {
				if (Hit_position == MID) {
					Hit_position = UP;
				}
				else if (Hit_position == UNDER) {
					Hit_position = MID;
				}
				move_qualification = FALSE;
			}
			else if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
				if (Hit_position == MID) {
					Hit_position = UNDER;
				}
				else if (Hit_position == UP) {
					Hit_position = MID;
				}
				move_qualification = FALSE;
			}
		}
			
		switch (Hit_position) {
		case UP:
			DrawExtendGraph(PLAY_HITBOX_x1, PLAY_Notes_Line_UP_y1, PLAY_HITBOX_x2, PLAY_Notes_Line_UP_y2, notes_line, TRUE);
			break;
		case MID:
			DrawExtendGraph(PLAY_HITBOX_x1, PLAY_Notes_Line_MID_y1, PLAY_HITBOX_x2, PLAY_Notes_Line_MID_y2, notes_line, TRUE);
			break;
		case UNDER:
			DrawExtendGraph(PLAY_HITBOX_x1, PLAY_Notes_Line_BTM_y1, PLAY_HITBOX_x2, PLAY_Notes_Line_BTM_y2, notes_line, TRUE);
			break;
		}
		

		//↓ノーツ編成を決める関数
		sc_nl.List_A(count, Hit_position);
		DrawFormatString(180, 180, sc_cr.Black, "Count:%d", count);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			count = 50000;
		}
		ScreenFlip();
		WaitTimer(1);
	}
		
	


	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
		return 2;
	}

	return 0;
}