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
    SetGraphMode(1600, 900, 32);//������������Ȃ�S���̍��W����������o�債�ĂˁI

    if (DxLib_Init() == -1)
    {
        return -1;
    }
    //�������牺�A�Q�[���R���g���[���֘A

    while (1) {

        switch (get_State()) {
        case HOME:
            switch (get_Action())
            {
            case ENTRY: //�����Ń^�C�g���A�ӂ�[�ށA�{�^���̕`��  
          
                hm.Make_Home();
                break;
            case DO: //�{�^���̑���͂�����
                break;
            case EXIT:
                return 0;
            }
            break;


        case PLAY:
            switch (get_Action())
            {
            case ENTRY: //�����Ń^�C�g���A�ӂ�[�ށA�{�^���̕`��      

                setStateAction(HOME, DO);
                break;
            case DO: //�{�^���̑���͂�����

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