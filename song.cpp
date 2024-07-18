#include"song.h"

Notes_List so_nl;

int Song_composition::Song(int counter) {
	int notes_line = LoadGraph(PIC_PLAY_Line);
	if (counter == 0) {
		//ここでバックグラウンドで曲流す
	}
	else{
		//ここから下にノーツの構成を描く
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_UP_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_UP_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_MID_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_MID_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_BTM_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_BTM_y2, notes_line, TRUE);

		so_nl.List_A(counter);

		//キャラクタークラスを読み込む

	}

	if (KEY_INPUT_ESCAPE) {
		return 2;
	}

	return 0;
}