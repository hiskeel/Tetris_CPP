#pragma once
#include <vector>

struct Point {
	int x;
	int y;
	Point(int x, int y) :x(x), y(y) {}
	bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}

};
class Shape {
protected:
	vector<Point> points;
	
public:
	
	vector<Point> GetShape() {
		return points;
	}
	void ShapeMoveDown();
	void MoveRight() {
		for (auto& point : points) {
			point.x++;
		}
	}
	virtual Point GetRotationCenter() const {
		// За замовчуванням повертаємо перший елемент як центр обертання
		if (!points.empty()) {
			return points[0];
		}
		// Якщо немає точок, повертаємо (0, 0) як центр
		return Point(0, 0);
	}

	

	virtual void SetShape(const vector<Point>& newPoints) {
		// Встановлення нових координат фігури
		points = newPoints;
	}
	void MoveLeft() {
		for (auto& point : points) {
			point.x--;
		}
	}

 };
class I:public Shape {
	
public:
	I() {
		for (int i = 0;i <= 3;i++) {
			points.push_back(Point(5, i));
		}
	}
};
class L :public Shape {
public:
	L() {
		for(int i =0; i <= 2;i++)
		{
			points.push_back(Point(5, i));
			if (i == 2) {
				points.push_back(Point(6, i));
			}
		}
	}
};
class Dot :public Shape {
public:
	Dot() {
		points.push_back(Point(5, 1));
	}
};
class Z :public Shape {
public:
	Z() {
		points.push_back(Point(4, -1));
		points.push_back(Point(5, -1));
		points.push_back(Point(5, 0));
		points.push_back(Point(6, 0));
		
	}
};
class T :public Shape {
public:
	T() {
		for (int i = 0;i < 3;i++) {
			points.push_back(Point(i+4, -1));
		}
		points.push_back(Point(5, 0));
	}
};

