#include "Home.h"
Color ho_cr;
//テスト、反映されるかな？
void Home::Make_Home() {
	int Start = LoadGraph(PIC_Start);
	SetBackgroundColor(255, 255, 255);//ホーム画面の背景色設定
	ClearDrawScreen();
	DrawExtendGraph(Home_Tilte_x1, Home_Tilte_y1, Home_Tilte_x2, Home_Tilte_y2, Start, TRUE);//タイトル画像
	DrawExtendGraph(Home_Start_x1, Home_Start_y1, Home_Start_x2, Home_Start_y2, Start, TRUE);//スタートボタン
	DrawExtendGraph(Home_End_x1, Home_End_y1, Home_End_x2, Home_End_y2, Start, TRUE);//終了ボタン
    while (1)
    {
        // マウスの位置を取得&座標の表示
        GetMousePoint(&Mouse_X, &Mouse_Y);
        DrawBox(180, 180, 400, 300, ho_cr.White, TRUE);
        DrawFormatString(180, 180, ho_cr.Green, "座標Ｘ %d　　座標Ｙ %d", Mouse_X, Mouse_Y);
        // スタートボタンにカーソルがあるときの処理
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
        // 終了ボタンにカーソルがあるときの処理
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

        // メッセージ処理
        if (ProcessMessage() == -1)
        {
            break;    // エラーが起きたらループを抜ける
        }

        // 一定時間待つ
        WaitTimer(100);
    }


}