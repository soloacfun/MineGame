#include "stdafx.h"
#include "Snake.h"
#include "scence.h"
#include "food.h"

Pos snake[30000] = {};
Pos array;
int len = 1;
int score = 0;
char str[10] = {};
IMAGE snake_head,snake_body;
IMAGE head_mask;


void snake_create() {
	srand((unsigned)time(NULL));
	snake[0].x = rand() % 80 * 5;    //�����ȡ��ͷ��x����
	snake[0].y = rand() % 80 * 5;    //�����ȡ��ͷ��y����
	array.x = pow(-1, rand());       //�����ȡ�ߵĳ�ʼ�˶�����
	array.y = 0;
}

void snake_show() {
	loadimage(&snake_head, _T("Snake_head.jpg"));
	loadimage(&snake_body, _T("Snake_body.jpg"));
	loadimage(&head_mask, _T("head_mask.jpg"));

	putimage(snake[0].x, snake[0].y, &head_mask,NOTSRCERASE);
	putimage(snake[0].x, snake[0].y, &snake_head,SRCINVERT);
	if (len > 1) {
		for (int i = 1; i < len; i++) {
			putimage(snake[i].x, snake[i].y, &snake_body);   ///ÿһ�������һ��ͼƬ
		}
	}

	setbkcolor(RGB(255, 240, 221));
	settextcolor(BLUE);
	outtextxy(535, 20, "�ܷ�:");
	
	_itoa_s(score, str, 10);
	outtextxy(570, 20, str);   //������ڵĵ÷�
}

void snake_move(int dt) {
	for (int i = len - 1; i > 0; i--) {
		snake[i].x = snake[i - 1].x;   //���һ�������x������ǰһ��
		snake[i].y = snake[i - 1].y;   //���һ�������y������ǰһ��
	}
	snake[0].x += array.x * dt;   //��ͷ��x�����ƶ��ٶ�
	snake[0].y += array.y * dt;   //��ͷ��y�����ƶ��ٶ�

	if (snake[0].x > 520)  //�����ǽ�򴩹�
		snake[0].x = 0;
	else if (snake[0].x < 0)
		snake[0].x = 520;
	else if (snake[0].y < 0)
		snake[0].y = 390;
	else if (snake[0].y > 390)
		snake[0].y = 0;
}

void command() {  //�������ƶ��ķ���
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (array.x != 1 || array.y != 0) {
				array.x = -1;
				array.y = 0;
			}
			break;
		case 'd':
			if (array.x != -1 || array.y != 0) {
				array.x = 1;
				array.y = 0;
			}
			break;
		case'w':
			if (array.x != 0 || array.y != 1) {
				array.x = 0;
				array.y = -1;
			}
			break;
		case's':
			if (array.x != 0 || array.y != -1) {
				array.x = 0;
				array.y = 1;
			}
			break;
		}
	}
}


void eat_food() {
	int x = food_get_x();   //��ȡʳ���x����
	int y = food_get_y();   //��ȡʳ���y����

	if (fabs(snake[0].x - x) <= 20 && fabs(snake[0].y - y) <= 20) {

		food_creat();   //����ʳ��������´���ʳ��
		len += 1;       //�ߵĳ��ȼ�1
		for (int i = len - 1; i > 0; i--) {
			snake[i].x = snake[i - 1].x;   //����һ������
			snake[i].y = snake[i - 1].y;
		}
		snake[0].x += array.x * 15;
		snake[0].y += array.y * 15;
		score++;  //��������
	}
}

int eat_self(int p) {

	if (len == 1)return 0;

	for (int i = 1; i < len; i++) {
		if (fabs(snake[i].x - snake[0].x) <= 5 && fabs(snake[i].y - snake[0].y) <= 5) {   //�������Լ����ж�����
			return 1;
		}
	}

	return 0;
}


//int snake_get_x(int i) {
//	int x = i;
//	return snake[x].x;
//}
//int snake_get_y(int i) {
//	int y = i;
//	return snake[y].y;
//}
//int snake_get_len() {
//	return len;
//}