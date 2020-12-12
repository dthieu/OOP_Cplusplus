#include "Sheep.h"

istream& Sheep::getInputInfo(istream& in, std::unique_ptr<Animal> &a) {
    cout << "\n-> Nhap MA SO (ID) con vat: SHEEP_";
    in >> a->ID;
    a->ID = "SHEEP_" + a->ID;
    cout << "-> Nhap TUOI (Age) con vat: ";
    in >> a->Age;
    cout << "-> Nhap CAN NANG (Weight) cua con vat: ";
    in >> a->Weight;
    return in;
}

void Sheep::Talk()
{
	cout << " Be...Be...!\n";
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
	if (mucdono < 50 && mucdono >= 10) {
        std::cout << "[" << this->GetID() << "] <doi qua! doi qua!> ";
		this->Talk();
    }
	this->SetMucDoNo(mucdono);

	this->SetPos(P); // Đặt lại vị trí của con vật
}
