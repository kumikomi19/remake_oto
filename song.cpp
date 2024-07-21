#include"song.h"


Notes_List sc_nl;
Color sc_cr;
Block sc_bl;

int Song_composition::Song(){

	//バックグラウンドで音楽を再生
	PlaySoundFile(SONG_A, DX_PLAYTYPE_BACK);

	//各種画像の読み込み
	int notes_line = LoadGraph(PIC_PLAY_Line);
	int notes_hitbox = LoadGraph(PIC_PLAY_HITBOX);
	int flame = LoadGraph(PIC_PLAY_BLOCK_FLAME);

	//当たり判定の初期化
	int Hit_position = MID;
	bool move_qualification = FALSE;
	SetDrawScreen(DX_SCREEN_BACK);

	int start_count = GetNowCount();
	while (1)
	{
		int count = GetNowCount() - start_count; //開始時刻-現在時刻をms単位で取得
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

		//テトリスゾーン
		DrawExtendGraph(Play_flame_Top_x1, Play_flame_Top_y1, Play_flame_Top_x2, Play_flame_Top_y2,flame, TRUE);
		DrawExtendGraph(Play_flame_R_x1, Play_flame_R_y1, Play_flame_R_x2, Play_flame_R_y2,flame, TRUE);
		DrawExtendGraph(Play_flame_L_x1, Play_flame_L_y1, Play_flame_L_x2, Play_flame_L_y2,flame, TRUE);
		sc_bl.Mino(T);
		sc_bl.Draw_ALLBlock();
		
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
		ScreenFlip();
		WaitTimer(1);
	}
		
	


	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
		return 2;
	}

	return 0;
}