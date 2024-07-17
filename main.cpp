#include "main.h"
#include "DxLib.h"
#include "Home.h"

Color cr;
Home hm;
volatile State m_state = HOME;
volatile Action m_action = ENTRY;



void set_State(State sta) {
    m_state = sta;
}
State get_State() {
    return m_state;
}
void set_Action(Action act) {
    m_action = act;
}
Action get_Action() {
    return m_action;
}
void setStateAction(State sta, Action act) {
    set_State(sta);
    set_Action(act);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);
    SetGraphMode(1600, 900, 32);//ここをいじるなら全部の座標が狂うから覚悟してね！

    if (DxLib_Init() == -1)
    {
        return -1;
    }
    //ここから下、ゲームコントロール関連

    while (1) {

        switch (get_State()) {
        case HOME:
            switch (get_Action())
            {
            case ENTRY: //ここでタイトル、ふれーむ、ボタンの描写  
          
                hm.Make_Home();
                break;
            case DO: //ボタンの操作はここで
                break;
            case EXIT:
                return 0;
            }
            break;


        case PLAY:
            switch (get_Action())
            {
            case ENTRY: //ここでタイトル、ふれーむ、ボタンの描写      

                setStateAction(HOME, DO);
                break;
            case DO: //ボタンの操作はここで

                break;
            case EXIT:

                return 0;
            }
            break;
        }
    }

    WaitKey();
    DxLib_End();
    return 0;
}