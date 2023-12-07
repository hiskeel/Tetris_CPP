#pragma once
#include <vector>
struct Point {
	int x;
	int y;
	Point(int x, int y) :x(x), y(y) {}

};
class Shape {
protected:
	vector<Point> points;
	/*struct Point {
		int x;
		int y;
		Point(int x,int y):x(x),y(y){}

	};*/
	/*vector<Point> points;*/
public:
	vector<Point> GetShape() {
		return points;
	}

 };
class I:public Shape {
	
public:
	I() {
		for (int i = -4;i < 0;i++) {
			points.push_back(Point(5, i));
		}
	}
};
class L :public Shape {
public:
	L() {
		for(int i =-3; i < 0;i++)
		{
			points.push_back(Point(5, i));
			if (i == -1) {
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

