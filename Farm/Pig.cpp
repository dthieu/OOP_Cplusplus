#include "Pig.h"

istream& Pig::getInputInfo(istream& in, std::unique_ptr<Animal> &a) {
    std::cout << "\n-> Nhap MA SO (ID) con vat: PIG_";
    in >> a->ID;
    a->ID = "PIG_" + a->ID;
    a->ID_ALL_ANIMAL.push_back(a->ID); // Sau khi nhập Mã số, đẩy nó vào vector ID_ALL_ANIMAL
    std::cout << "-> Nhap TUOI (Age) con vat: ";
    in >> a->Age;
    std::cout << "-> Nhap CAN NANG (Weight) cua con vat: ";
    in >> a->Weight;
    return in;
}

void Pig::Talk()
{
	std::cout << " Ut it...Ut it...\n";
}

void Pig::ChoAn(float kg)
{
	float mucdono = this->GetMucDoNo();
	mucdono += kg * 30; // độ no tăng 30% / 1kg thức ăn
	if (mucdono >= 100)
	{
		int _kg = Random(1, 2); // cân nặng tăng từ 1 - 2 kg
		this->SetWeight(this->GetWeight() + _kg);
		mucdono = 100; // max của mức độ no la 100%
	}
	this->SetMucDoNo(mucdono);
}

void Pig::Move(Point2D P)
{
	// Khoảng cách con vật sau khi di chuyển
	// Di chuyển => độ no giảm
	float distance = this->GetPos().KhoangCach(P); // (đơn vị: m)
	float mucdono = this->GetMucDoNo();
	mucdono -= distance * 7; // mỗi mét di chuyển độ no giảm 7%

	// Kiểm tra mức độ no nếu < 50 thì con vật sẽ kêu
	if (mucdono < 50 && mucdono >= 10) {
        std::cout << "[" << this->GetID() << "] <doi qua! doi qua!> ";
		this->Talk();
    }
	this->SetMucDoNo(mucdono);

	this->SetPos(P); // Đặt lại vị trí của con vật
}


