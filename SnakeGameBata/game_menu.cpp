#include "stdafx.h"
#include "game_menu.h"


#define WIDTH 700
#define HEIGHT 900

void game_menu()
{
	cleardevice();//����


	settextstyle(70, 0, "�����кڼ���");//��������
	RECT r1 = { 0,0,WIDTH,HEIGHT / 3 };
	drawtext("��ӭ����2048������", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



	settextstyle(30, 0, "΢���ź�");
	RECT r2 = { WIDTH / 2 - 45,HEIGHT / 3,WIDTH / 2 + 45,HEIGHT / 3 + 30 };
	drawtext("��ʼ��Ϸ", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { WIDTH / 2 - 45,HEIGHT / 3 + 30,WIDTH / 2 + 45,HEIGHT / 3 + 60 };

	drawtext("��Ϸ����", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = { WIDTH / 2 - 45,HEIGHT / 3 + 60,WIDTH / 2 + 45,HEIGHT / 3 + 90 };
	drawtext("����˵��", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = { WIDTH / 2 - 45,HEIGHT / 3 + 90,WIDTH / 2 + 45,HEIGHT / 3 + 120 };
	drawtext("�˳���Ϸ", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



	setfillcolor(RGB(244, 186, 1));//���õ�ǰ�������ɫ
	solidroundrect(216, 478, 484, 746, 50, 50);
	settextstyle(145, 0, "Microsoft Yahei UI Bold");//��������
	settextcolor(RGB(254, 253, 249));
	setbkcolor(RGB(244, 186, 1));//����ɫ
	outtextxy(216, 535, "2048");//����ַ���2048