#include "Home.h"
Color ho_cr;
//�e�X�g�A���f����邩�ȁH
void Home::Make_Home() {
	int Start = LoadGraph(PIC_Start);
	SetBackgroundColor(255, 255, 255);//�z�[����ʂ̔w�i�F�ݒ�
	ClearDrawScreen();
	DrawExtendGraph(Home_Tilte_x1, Home_Tilte_y1, Home_Tilte_x2, Home_Tilte_y2, Start, TRUE);//�^�C�g���摜
	DrawExtendGraph(Home_Start_x1, Home_Start_y1, Home_Start_x2, Home_Start_y2, Start, TRUE);//�X�^�[�g�{�^��
	DrawExtendGraph(Home_End_x1, Home_End_y1, Home_End_x2, Home_End_y2, Start, TRUE);//�I���{�^��
    while (1)
    {
        // �}�E�X�̈ʒu���擾&���W�̕\��
        GetMousePoint(&Mouse_X, &Mouse_Y);
        DrawBox(180, 180, 400, 300, ho_cr.White, TRUE);
        DrawFormatString(180, 180, ho_cr.Green, "���W�w %d�@�@���W�x %d", Mouse_X, Mouse_Y);
        // �X�^�[�g�{�^���ɃJ�[�\��������Ƃ��̏���
        if (Mouse_X >= Home_Start_x1 && Mouse_X <= Home_Start_x2 && Mouse_Y >= Home_Start_y1 && Mouse_Y >= Home_Start_y2) {
            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
          
                break;
            }
            else {
                DrawBox(Home_Start_x1 +5, Home_Start_y1 +5, Home_Start_x2 +5, Home_Start_y2 +5, ho_cr.Red, FALSE);
                DrawBox(Home_Start_x1 +10, Home_Start_y1 +10, Home_Start_x2 +10, Home_Start_y2 +10, ho_cr.Red, FALSE);
                DrawBox(Home_Start_x1 +15, Home_Start_y1 +15, Home_Start_x2 +15, Home_Start_y2 +15, ho_cr.Red, FALSE);
                break;
            }
        }
        // �I���{�^���ɃJ�[�\��������Ƃ��̏���
        else if (Mouse_X >= Home_End_x1 && Mouse_X <= Home_End_x2 && Mouse_Y >= Home_End_y1 && Mouse_Y >= Home_End_y2) {

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
                DxLib_End();
            }
            else {
                
                break;
            }
        }
        else {
            
            break;
        }

        // ���b�Z�[�W����
        if (ProcessMessage() == -1)
        {
            break;    // �G���[���N�����烋�[�v�𔲂���
        }

        // ��莞�ԑ҂�
        WaitTimer(100);
    }


}