#include "Cow.h"

void Cow::Talk()
{
	cout << "Um bo...Um bo...\n";
}

void Cow::ChoAn(float kg)
{
	float mucdono = this->GetMucDoNo();
	mucdono += kg * 20; // độ no tăng 20% / 1kg thức ăn
	if (mucdono >= 100)
	{
		int _kg = Random(1, 3); // cân nặng tăng từ 1 - 3 kg
		this->SetWeight(this->GetWeight() + _kg);
		mucdono = 100; // max của mức độ no la 100%
	}
	this->SetMucDoNo(mucdono);
}

void Cow::Move(Point2D P)
{
	// Khoảng cách con vật sau khi di chuyển
	// Di chuyển => độ no giảm
	float distance = this->GetPos().KhoangCach(P); // (đơn vị: m)
	float mucdono = this->GetMucDoNo();
	mucdono -= distance * 5; // mỗi mét di chuyển độ no giảm 5%
	
	// Kiểm tra mức độ no nếu < 50 thì con vật sẽ kêu
	if (mucdono < 50 && mucdono >= 10)
		this->Talk();
	this->SetMucDoNo(mucdono);

	this->SetPos(P); // Đặt lại vị trí của con vật
}

