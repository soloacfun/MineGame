#pragma once

int eat_self(int p);

void snake_create();  //蛇的创建
void snake_move(int dt);  //蛇的移动
void snake_show();  //蛇的画图
void eat_food();  //吃食
void command();  //蛇的运动方向

//int snake_get_x(int i);
//int snake_get_y(int i);
//int snake_get_len();