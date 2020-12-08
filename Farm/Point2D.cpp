// Point2D.cpp
#include "Point2D.h"

// Hàm dựng
Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}


//Hàm nhập tọa độ  cho 1 điểm (thuộc lớp Point2D)
void Point2D::Nhap()
{
	cout << "Nhap hoanh do (x): ";
	cin >> x;
	cout << "Nhap tung do (y): ";
	cin >> y;
}

//Hàm xuất tọa độ của 1 điểm (thuộc lớp Point2D)
void Point2D::Xuat()
{
	cout << "(" << x << "," << y << ")";
}

//Hàm tính khoảng cách giữa 2 điểm (thuộc lớp Point2D)
// Truyền vào hàm là 1 tham số thuộc kiểu Point2D
// Trả về kiểu thực khoảng cách giữa 2 điểm
float Point2D::KhoangCach(Point2D p)
{
	float kq;
	kq = static_cast<float>(sqrt(double((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y))));
	return kq;
}

void Point2D::SetPoint2D(Point2D P)
{
	this->x = P.x;
	this->y = P.y;
}

float Point2D::GetX()
{
	return this->x;
}

float Point2D::GetY()
{
	return this->y;
}

