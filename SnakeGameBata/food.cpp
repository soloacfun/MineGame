#include "stdafx.h"
#include "food.h"
#include "Snake.h"

Pos food;  //创建食物的结构体
IMAGE food_image;

void food_creat() {

	srand((unsigned)time(NULL));
	food.x = rand() % 40 * 5 + 100;  //随机获取食物的X坐标
	food.y = rand() % 40 * 5 + 100;  //随鸡获取食物的Y坐标

}

void food_show() {
	loadimage(&food_image, _T("mouse.jpg"));
	putimage(food.x, food.y, &food_image);
}

int food_get_x() {
	return food.x;  //返回食物的x坐标
}
int food_get_y() {
	return food.y;  //返回食物的y坐标
}