#include"Matrix.h"
Shape Matrix::InitShape() {
	T sI;
	
	return sI;
}
void Matrix::Gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Matrix::ShowBoard() {
	for (int i = 0; i < 20;i++)
	{
		points.push_back(Point(11, i));

	}
	for (int i = 0; i < 10;i++)
	{
		points.push_back(Point(i, 21));
	}
	for (int i = 0; i < points.size(); i++) {

		if (i < 20)
		{
			Gotoxy(points[i].x, points[i].y);
			cout << "|";
		}
		else {
			Gotoxy(points[i].x, points[i].y);
			cout << "_";
		}
	}
}
void Matrix::DrawShape(Shape shape) {
	for (int i = 0; i < shape.GetShape().size(); i++) {
		Gotoxy(shape.GetShape()[i].x, shape.GetShape()[i].y+3);
		cout << char(254);
	}
}