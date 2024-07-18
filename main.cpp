#include "main.h"
#include "DxLib.h"
#include "Home.h"
#include "Song.h"

Color cr;
Home hm;
Song_composition sc;

volatile Mode_State m_state = HOME;
volatile int Ms_Counter = 0;
Mode_State GetState(){
  return m_state;
}

void SetState(Mode_State m) {
    m_state = m;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);
    SetGraphMode(1600, 900, 32);//������������Ȃ�S���̍��W����������o�債�ĂˁI
    SetBackgroundColor(255, 255, 255);//�z�[����ʂ̔w�i�F�ݒ�
    if (DxLib_Init() == -1)
    {
        return -1;
    }
    //�������牺�A�Q�[���R���g���[���֘A
    SetDrawScreen(DX_SCREEN_BACK);
    while (1) {
        
        switch (GetState())
        {
        case HOME:

            Ms_Counter = 0;
            hm.Make_Home();
            if (hm.Make_Home() == 1) {
                SetState(PLAY);
            }
            else if (hm.Make_Home() == 2) {
                
                DxLib_End();
            }
            
            break;
        case PLAY:
            ClearDrawScreen();
            sc.Song(Ms_Counter);
            Ms_Counter ++;
            if (sc.Song(Ms_Counter) == 1) {
                SetState(HOME);
            }
            else if (sc.Song(Ms_Counter) == 2) {

                SetState(OPTION);
            }
            break;

        case OPTION:
            break;
        default:
            break;
        }
        
        
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
            break;
        }
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}