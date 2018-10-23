#include "stdafx.h"
#include "scence.h"
#pragma comment(lib,"Winmm.lib")

IMAGE background,Snake_menu;
IMAGE Game_exit;

void scence_init() {

	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	loadimage(&background, _T("background.jpg"));
	loadimage(&Snake_menu, _T("Snake_menu.jpg"));
	loadimage(&Game_exit, _T("Game_exit.jpg"));

	mciSendString("open 背景音乐1.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("play mymusic", NULL, 0, NULL);
}

void scence_show() {
	putimage(0, 0, &background);
}

void menu_show() {
	putimage(0, 0, &Snake_menu);

	setbkcolor(RGB(251, 194, 53));
	settextcolor(BLUE);
	outtextxy(260, 380, "任意键开始游戏");
}

void exit_show() {
	putimage(0, 0, &Game_exit);
	setbkcolor(WHITE);
	settextcolor(BLACK);
	settextstyle(80, 0, "宋体");
	outtextxy(103, 120, "菜鸡");
}