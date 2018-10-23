#include "stdafx.h"
#include "game_menu.h"


#define WIDTH 700
#define HEIGHT 900

void game_menu()
{
	cleardevice();//清屏


	settextstyle(70, 0, "方正行黑简体");//字体设置
	RECT r1 = { 0,0,WIDTH,HEIGHT / 3 };
	drawtext("欢迎来到2048的世界", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



	settextstyle(30, 0, "微软雅黑");
	RECT r2 = { WIDTH / 2 - 45,HEIGHT / 3,WIDTH / 2 + 45,HEIGHT / 3 + 30 };
	drawtext("开始游戏", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { WIDTH / 2 - 45,HEIGHT / 3 + 30,WIDTH / 2 + 45,HEIGHT / 3 + 60 };

	drawtext("游戏介绍", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = { WIDTH / 2 - 45,HEIGHT / 3 + 60,WIDTH / 2 + 45,HEIGHT / 3 + 90 };
	drawtext("操作说明", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = { WIDTH / 2 - 45,HEIGHT / 3 + 90,WIDTH / 2 + 45,HEIGHT / 3 + 120 };
	drawtext("退出游戏", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



	setfillcolor(RGB(244, 186, 1));//设置当前的填充颜色
	solidroundrect(216, 478, 484, 746, 50, 50);
	settextstyle(145, 0, "Microsoft Yahei UI Bold");//设置字体
	settextcolor(RGB(254, 253, 249));
	setbkcolor(RGB(244, 186, 1));//背景色
	outtextxy(216, 535, "2048");//输出字符串2048