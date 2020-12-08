#include "Sheep.h"

void Sheep::Talk()
{
	cout << "Be...Be...!\n";
}

void Sheep::ChoAn(float kg)
{
	float mucdono = this->GetMucDoNo();
	mucdono += kg * 20; // độ no tăng 20% / 1kg thức ăn
	if (mucdono >= 100)
	{
		int _kg = Random(1, 2); // cân nặng tăng từ 1 - 2 kg
		this->SetWeight(this->GetWeight() + _kg);
		mucdono = 100; // max của mức độ no la 100%
	}
	this->SetMucDoNo(mucdono);
}

void Sheep::Move(Point2D P)
{
	// Khoảng cách con vật sau khi di chuyển
	// Di chuyển => độ no giảm
	float distance = this->GetPos().KhoangCach(P); // (đơn vị: m)
	float mucdono = this->GetMucDoNo();
	mucdono -= distance * 6; // mỗi mét di chuyển độ no giảm 6%

	// nen xoa no ra khoi danh sach con sheep

	// Kiểm tra mức độ no nếu < 50 thì con vật sẽ kêu
	if (mucdono < 50 && mucdono >= 10)
		this->Talk();
	this->SetMucDoNo(mucdono);

	this->SetPos(P); // Đặt lại vị trí của con vật
}