#include"song.h"
#include"Notes_List.h"

<<<<<<< HEAD
Notes_List sc_nl;
Color sc_cr;

int Song_composition::Song() {
=======
Notes_List so_nl;

int Song_composition::Song(int counter) {
>>>>>>> 6fb9482d060f5d260353a894f8765ae1e337112c
	int notes_line = LoadGraph(PIC_PLAY_Line);
	SetDrawScreen(DX_SCREEN_BACK);
	for (int count = 0; count < 50000; count++) {
		if (ProcessMessage() != 0) { // メッセージ処理
			break;//ウィンドウの×ボタンが押されたらループを抜ける
		}
		//ここから下にノーツの構成を描く
		ClearDrawScreen();
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_UP_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_UP_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_MID_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_MID_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_BTM_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_BTM_y2, notes_line, TRUE);

<<<<<<< HEAD
		
=======
		so_nl.List_A(counter);
>>>>>>> 6fb9482d060f5d260353a894f8765ae1e337112c

		sc_nl.List_A(count);
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