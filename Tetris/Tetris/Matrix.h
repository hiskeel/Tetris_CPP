#pragma once
#include"Console.h"
class Matrix {
	int speed;
	int score;
	short wight;
	short heigth;
	Shape sI;
	vector<Point> points;
	
public:
	Matrix():speed(0),score(0),wight(0),heigth(0),sI(){}
	void Gotoxy(int x, int y);
	Shape InitShape();
	void ShowBoard();

	void DrawShape(Shape shape);
};