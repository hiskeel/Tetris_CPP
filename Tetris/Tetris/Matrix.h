#pragma once
#include"Console.h"
#include <ctime>

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
	void CheckRows();
	bool CheckOver();
	Point GetRotationCenter(Shape& shape);
	bool IsCollision( Shape& newPoints);
	void RotateShape(Shape& shape);
	void DrawEmptySpaces( Shape& shape);
	void ClearRow(int rowIndex);
	void DrawShape( Shape& shape);
    void FallShape(Shape& shape);
	void MoveShapeRight(Shape& shape);
	bool CanMoveLeft(Shape& shape);
	bool CanMoveRight(Shape& shape);
	void MoveShapeLeft(Shape& shape);
    void Play();
    bool CanMoveDown(Shape& shape);
	void ClearBoard();
    void ClearShape(Shape& shape);

    void MergeShape(Shape& shape);

	bool IsOccupied(int x, int y);

    
};