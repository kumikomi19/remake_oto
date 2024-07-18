#pragma once
#include "DxLib.h"

class Notes_List {
private:
	typedef enum {
		LEFT,
		RIGHT,
		DOWN,
	}Notes_State;
public:
	int Notes(int count, int start, Notes_State notes, int hight);
	void List_A(int count);
};