#include "main.h"
#include "DxLib.h"
#include "Home.h"
#include "Song.h"

Color cr;
Home hm;
Song_composition sc;

Mode_State m_state = HOME;
Mode_State GetState(){
  return m_state;
}

void SetState(Mode_State m) {
    m_state = m;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);
    SetGraphMode(1600, 900, 32);//ここをいじるなら全部の座標が狂うから覚悟してね！
    SetBackgroundColor(255, 255, 255);//ホーム画面の背景色設定
    if (DxLib_Init() == -1)
    {
        return -1;
    }
    //ここから下、ゲームコントロール関連
    SetDrawScreen(DX_SCREEN_BACK);
    while (1) {
        switch (GetState())
        {
        case HOME:

            hm.Make_Home();
            if (hm.Make_Home() == 1) {
                SetState(PLAY);
            }
            else if (hm.Make_Home() == 2) {
                
                DxLib_End();
            }
            ScreenFlip();
            break;
        case PLAY:
            ClearDrawScreen();
            sc.Song();
           
            if (sc.Song() == 1) {
                SetState(HOME);
            }
            else if (sc.Song() == 2) {

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
        
    }

    DxLib_End();
    return 0;
}