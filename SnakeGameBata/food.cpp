#include "stdafx.h"
#include "food.h"
#include "Snake.h"

Pos food;  //����ʳ��Ľṹ��
IMAGE food_image;

void food_creat() {

	srand((unsigned)time(NULL));
	food.x = rand() % 40 * 5 + 100;  //�����ȡʳ���X����
	food.y = rand() % 40 * 5 + 100;  //�漦��ȡʳ���Y����

}

void food_show() {
	loadimage(&food_image, _T("mouse.jpg"));
	putimage(food.x, food.y, &food_image);
}

int food_get_x() {
	return food.x;  //����ʳ���x����
}
int food_get_y() {
	return food.y;  //����ʳ���y����
}