#include "Block.h"

Color bl_cr;

int operation = 0; //ミノの操作を番号で指定（後々定義してわかりやすくする）
int Position[10][20] = {};
int Block_Size = 55;
int x = 7;
int y = 2;

void Block::Get_operation(int op){
	operation = op;
	DrawFormatString(580, 160, bl_cr.Black, "op:%d", operation);
	DrawFormatString(580, 120, bl_cr.Black, "x:%d", x);
	DrawFormatString(580, 140, bl_cr.Black, "y:%d", y);
}


void Block::Draw_ALLBlock() { 
	int Block_White = LoadGraph(PIC_PLAY_BLOCK);
	for (int y = 0; y < 20; y++ ) {
		for (int x = 0; x < 10; x++) {
			switch (Position[x][y]) {
			case 0:
				break;
			case 1:
				DrawExtendGraph(1000 + x * Block_Size, 40 + y * Block_Size,1000 + (x+1) * Block_Size,40 + (y+1) * Block_Size,Block_White,TRUE);
				break;
			}
			
		}
	}

}


void Block::Mino_move(int mino_direction , int x, int y) {
	switch (operation)
	{case 0://何もしない
		break;
	case 1://右に移動
		x++;
		break;
	case 2://左に移動
		x--;
		break;
	case 3://右回転
		if (mino_direction < 7){
			mino_direction = mino_direction + 2;
		}
		else if (mino_direction > 6) {
			mino_direction = mino_direction - 6;
		}
		
		break;
	case 4://左回転
		if (mino_direction > 3) {
			mino_direction = mino_direction - 2;
		}
		else if (mino_direction < 2) {
			mino_direction = mino_direction + 6;
		}
		break;
	case 5://落下
		break;
	default:
		break;
	}
	switch (mino_direction) {
	case 0:
		break;
	case 1:
		x--;
		y--;
		break;
	case 2:
		y--;
		break;
	case 3:
		x++;
		y--;
		break;
	case 4:
		x++;
		break;
	case 5:
		x++;
		y++;
		break;
	case 6:
		y++;
		break;
	case 7:
		x--;
		y++;
		break;
	case 8:
		x--;
		break;
	}

	Position[x][y] = 1;
}

void Block::Mino(Mino_State mino) {
	switch (mino)
	{
	case T:
		Mino_move(0, x, y);
		Mino_move(4, x, y);
		Mino_move(6, x, y);
		Mino_move(8, x, y);
		
		break;
	case S:
		break;
	case Z:
		break;
	case L:
		break;
	case J:
		break;
	case O:
		break;
	case I:
		break;
	default:
		break;
	}
}