#include "Home.h"
Color ho_cr;

int Button = 0;//1でスタート、２で終了

int Home::Make_Home() {
	int Start = LoadGraph(PIC_Start);
	
	DrawExtendGraph(Home_Tilte_x1, Home_Tilte_y1, Home_Tilte_x2, Home_Tilte_y2, Start, TRUE);//タイトル画像
	DrawExtendGraph(Home_Start_x1, Home_Start_y1, Home_Start_x2, Home_Start_y2, Start, TRUE);//スタートボタン
	DrawExtendGraph(Home_End_x1, Home_End_y1, Home_End_x2, Home_End_y2, Start, TRUE);//終了ボタン
    

    /*D、Kを押すとプレイに、C、Mを押すと終了に、spaseで決定*/

    if (CheckHitKey(KEY_INPUT_UP) == 1) {
        Button = 1;
        DrawBox(Home_End_x1 - 3, Home_End_y1 - 3, Home_End_x2 + 3, Home_End_y2 + 3, ho_cr.White, FALSE);
        DrawBox(Home_End_x1 - 6, Home_End_y1 - 6, Home_End_x2 + 6, Home_End_y2 + 6, ho_cr.White, FALSE);
        DrawBox(Home_End_x1 - 9, Home_End_y1 - 9, Home_End_x2 + 9, Home_End_y2 + 9, ho_cr.White, FALSE);

        DrawBox(Home_Start_x1 - 3, Home_Start_y1 - 3, Home_Start_x2 + 3, Home_Start_y2 + 3, ho_cr.Blue, FALSE);
        DrawBox(Home_Start_x1 - 6, Home_Start_y1 - 6, Home_Start_x2 + 6, Home_Start_y2 + 6, ho_cr.Red, FALSE);
        DrawBox(Home_Start_x1 - 9, Home_Start_y1 - 9, Home_Start_x2 + 9, Home_Start_y2 + 9, ho_cr.Yellow, FALSE);
        if (Button == 1 && CheckHitKey(KEY_INPUT_SPACE)) {
            return 1;
        }
        
    }
    else if (CheckHitKey(KEY_INPUT_DOWN) == 1 ) {
        Button = 2;
        DrawBox(Home_Start_x1 - 3, Home_Start_y1 - 3, Home_Start_x2 + 3, Home_Start_y2 + 3, ho_cr.White, FALSE);
        DrawBox(Home_Start_x1 - 6, Home_Start_y1 - 6, Home_Start_x2 + 6, Home_Start_y2 + 6, ho_cr.White, FALSE);
        DrawBox(Home_Start_x1 - 9, Home_Start_y1 - 9, Home_Start_x2 + 9, Home_Start_y2 + 9, ho_cr.White, FALSE);

        DrawBox(Home_End_x1 - 3, Home_End_y1 - 3, Home_End_x2 + 3, Home_End_y2 + 3, ho_cr.Blue, FALSE);
        DrawBox(Home_End_x1 - 6, Home_End_y1 - 6, Home_End_x2 + 6, Home_End_y2 + 6, ho_cr.Red, FALSE);
        DrawBox(Home_End_x1 - 9, Home_End_y1 - 9, Home_End_x2 + 9, Home_End_y2 + 9, ho_cr.Yellow, FALSE);
        if (Button == 2 && CheckHitKey(KEY_INPUT_SPACE)) {
            return 2;
        }
    }
    else {
        return 0;
    }

        WaitTimer(100);
       
}