// SnakeGameBata.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "scence.h"
#include "food.h"
#include "Snake.h"

#define DELTA_TIME 15

int p = 0;
int dead = 0;

void startup() {  ///数据的初始化
	scence_init();
	food_creat();
	snake_create();

	BeginBatchDraw();
}

void updateWithoutInput(int dt) {  
	snake_move(dt);
	dead = eat_self(dead);

}

void updateWithInput()
{
	command();
	eat_food();
}

void show() {
	if (p == 0) {
		menu_show();
	}
	
	if (_kbhit())p = 1;

	if (p == 1) {
		scence_show();
		food_show();
		snake_show();
	}
	FlushBatchDraw();
	Sleep(50);
}

void Exit_show() {

	exit_show();
	FlushBatchDraw();

}



void gameover() {
	EndBatchDraw();
}

int main()
{
	startup();
	while (dead == 0) {
		show();
		if (p == 1) {
			updateWithoutInput(DELTA_TIME);
			updateWithInput();
		}
	}
	Exit_show();
	_getch();
	gameover();	
    return 0;
}

