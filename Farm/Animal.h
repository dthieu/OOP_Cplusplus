#pragma once
#include "Point2D.h"
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <memory>  // std::unique_ptr, std::make_unique
#include <iomanip> // setw()
using namespace std;

class Animal
{
public:
	vector<string> ID_ALL_ANIMAL; // Vector lưu các Mã số của con vật (ID)
	const static float MAX;	// lớn nhất là 100% (độ no của con vật)
// private:
	string ID;	// Mã số con vật
	float Age;	// Đơn vị: ngày tuổi
	float Weight;	// Cân nặng
	float MucDoNo; // Mức độ no của con vật
	Point2D Pos; // Vị trí của con vật
public:
	Animal();
	virtual ~Animal();
	// Getter / Setter
	string GetID();
	void SetID(string ID);
	float GetAge();
	void SetAge(float Age);
	float GetWeight();
	void SetWeight(float Weight);
	Point2D GetPos();
	void SetPos(Point2D);
	float GetMucDoNo();
	void SetMucDoNo(float MucDoNo);

	bool CheckID(const string&); // Kiểm tra Mã số của con vật
    virtual istream& getInputInfo(istream& in, std::unique_ptr<Animal>& a){ return in; };

	// Nhập xuất một con vật
	friend istream& operator >> (istream &in, std::unique_ptr<Animal> &animal){
	    return animal->getInputInfo(in, animal);
	}
    friend ostream& operator << (ostream &out, const std::unique_ptr<Animal> &animal);

	virtual void Talk() = 0; // Mỗi con vật có cách kêu khác nhau
	virtual void ChoAn(float kg) = 0; // Cho con vật ăn
	virtual void Move(Point2D) = 0; // Di chuyển con vật tới vị trí có tọa độ P(x2,y2)

	// Hàm phụ: random 1 số trong khoảng đã cho
	int Random(int start, int end);
};
