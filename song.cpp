#include"song.h"
#include"Notes_List.h"


Notes_List sc_nl;
Color sc_cr;

int Song_composition::Song(){

	int notes_line = LoadGraph(PIC_PLAY_Line);
	SetDrawScreen(DX_SCREEN_BACK);
	for (int count = 0; count < 50000; count++) {
		if (ProcessMessage() != 0) { // ���b�Z�[�W����
			break;//�E�B���h�E�́~�{�^���������ꂽ�烋�[�v�𔲂���
		}
		//�������牺�Ƀm�[�c�̍\����`��
		ClearDrawScreen();
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_UP_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_UP_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_MID_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_MID_y2, notes_line, TRUE);
		DrawExtendGraph(PLAY_Notes_Line_x1, PLAY_Notes_Line_BTM_y1, PLAY_Notes_Line_x2, PLAY_Notes_Line_BTM_y2, notes_line, TRUE);



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