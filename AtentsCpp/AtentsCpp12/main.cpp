#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
	int _x, _y;

public:
	Point(int x, int y)
		: _x(x), _y(y) {}

	int GetX() {
		return _x;
	}

	int GetY() {
		return _y;
	}

	void Info() {
		cout << "x: " << _x << ", y:" << _y << endl;
	}
};

class Line {
private:
	Point _leftPt, _rightPt;

public:
	Line(int leftX, int leftY, int rightX, int rightY)
		: _leftPt(leftX, leftY), _rightPt(rightX, rightY) {}

	Line(Point leftPt, Point rightPt)
		: _leftPt(leftPt), _rightPt(rightPt) {}

	float GetLength() {
		int base = _rightPt.GetX() - _leftPt.GetX();
		int height = _leftPt.GetY() - _rightPt.GetY();

		float length = sqrt(pow(base, 2) + pow(height, 2));

		return length;
	}
};


// 직각삼각형 클래스 만들고 면적 구해서 출력해보기

class Triangle {
private:
	Point _Pt1, _Pt2, _Pt3;

public:
	Triangle(int X1, int Y1, int X2, int Y2, int X3, int Y3)
		: _Pt1(X1, Y1), _Pt2(X2, Y2), _Pt3(X3, Y3) {}

	Triangle(Point Pt1, Point Pt2, Point Pt3)
		: _Pt1(Pt1), _Pt2(Pt2), _Pt3(Pt3) {}

	float GetArea1() {
		Line baseLine(_Pt1, _Pt2);
		Line heightLine(_Pt1, _Pt3);

		return 0.5 * baseLine.GetLength() * heightLine.GetLength();
	}

	// 신발끈 공식 사용
	float GetArea2()
	{
		return 0.5 * abs(_Pt1.GetX() * _Pt2.GetY() + _Pt2.GetX() * _Pt3.GetY()
			+ _Pt3.GetX() * _Pt1.GetY() - _Pt2.GetX() * _Pt1.GetY()
			+ _Pt3.GetX() * _Pt2.GetY());
	}
};

// 직사각형 클래스 만들고 면적 구해서 출력해보기

class Rectangle {
private:
	Point _leftTopPt, _rightTopPt, _leftBottomPt, _rightBottomPt;

public:
	Rectangle(int leftTopX, int leftTopY, int rightTopX, int rightTopY,
		int leftBottomX, int leftBottomY, int rightBottomX, int rightBottomY)
		: _leftTopPt(leftTopX, leftTopY), _rightTopPt(rightTopX, rightTopY),
		_leftBottomPt(leftBottomX, leftBottomY), _rightBottomPt(rightBottomX, rightBottomY) {}

	Rectangle(Point leftTopPt, Point rightTopPt, Point leftBottomPt, Point rightBottomPt)
		: _leftTopPt(leftTopPt), _rightTopPt(rightTopPt), _leftBottomPt(leftBottomPt), _rightBottomPt(rightBottomPt) {}

	float getArea()
	{
		Line heightLine(_leftTopPt, _leftBottomPt);
		Line widthLine(_leftTopPt, _rightTopPt);

		return heightLine.GetLength() * widthLine.GetLength();
	}
};

// 원 클래스 만들고 면적 구해서 출력해보기

class Circle {
private:
	Point _centerPt;
	int _radius;

public:
	Circle(int centerX, int centerY, int radius)
		: _centerPt(centerX, centerY), _radius(radius) {}

	Circle(Point centerPt, int radius)
		: _centerPt(centerPt), _radius(radius) {}

	float getArea()
	{
		return _radius * _radius * 3.14;
	}
};

int main() {
	Line line1(0, 10, 10, 10);
	Triangle triangle1(0, 0, 10, 0, 0, 10);
	Triangle triangle2(0, 10, 10, 10, 0, 0);

	cout << "Triangle1 Area1 = " << triangle1.GetArea1() << endl;
	cout << "Triangle1 Area2 = " << triangle1.GetArea2() << endl;
	cout << "Triangle2 Area1 = " << triangle2.GetArea1() << endl;
	cout << "Triangle2 Area2 = " << triangle2.GetArea2() << endl;

	Rectangle rectangle1(0, 5, 5, 5, 0, 0, 5, 0);

	cout << "Rectangle1 Area = " << rectangle1.getArea() << endl;

	Circle circle(0, 0, 3);

	cout << "Circlue Area = " << circle.getArea() << endl;

	return 0;
}