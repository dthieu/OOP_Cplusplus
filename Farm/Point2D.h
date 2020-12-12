//Point2D.h
#ifndef _POINT2D_H_
#define _POINT2D_H_

#include <iostream>
#include <math.h>
using namespace std;

// Khai báo lớp Point2D (không gian 2 chiều)
class Point2D
{
private:
	float x; // Hoành độ
	float y; // Tung độ
public:
	Point2D();
	Point2D(float, float);
	void Nhap();
	void Xuat();
	// If implement friend out of class => no prefix "Point2D::" just write "istream & operator >> (istream &in, Point2D &p){...}"
	friend istream & operator >> (istream &in, Point2D &p);
	friend ostream & operator << (ostream &out, const Point2D &p);

	//Hàm tính khoảng cách giữa 2 điểm
	float KhoangCach(Point2D);
	void SetPoint2D(Point2D P);
	float GetX();
	float GetY();
};

#endif
