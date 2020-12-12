#include "Chicken.h"

istream& Chicken::getInputInfo(istream& in, std::unique_ptr<Animal> &a) {
    cout << "\n-> Nhap MA SO (ID) con vat: CHICKEN_";
    in >> a->ID;
    a->ID = "CHICKEN_" + a->ID;
    a->ID_ALL_ANIMAL.push_back(a->ID); // Sau khi nhập Mã số, đẩy nó vào vector ID_ALL_ANIMAL
    cout << "-> Nhap TUOI (Age) con vat: ";
    in >> a->Age;
    cout << "-> Nhap CAN NANG (Weight) cua con vat: ";
    in >> a->Weight;
    return in;
}

void Chicken::Talk()
{
	cout << " Cuc tac...Cuc tac...\n";
}

void Chicken::ChoAn(float kg)
{
	float mucdono = this->GetMucDoNo();
	mucdono += (kg * 100) / 0.2; // độ no tăng 100% / 0.2kg thức ăn

	//float _kg = 0.2;
	default_random_engine e(time(NULL));
	uniform_real_distribution<> d(0.01, 0.2); // cân nặng tăng từ 0.01 - 0.2 kg
    if (mucdono >= 100)
	{
	    float _kg = d(e) + 0.00001; // để cho số ngẫu nhiên gần tới 0.2
        this->SetWeight(this->GetWeight() + _kg);
        mucdono = 100; // max của mức độ no la 100%
	}
	this->SetMucDoNo(mucdono);
}

void Chicken::Move(Point2D P)
{
	// Khoảng cách con vật sau khi di chuyển
	// Di chuyển => độ no giảm
	float distance = this->GetPos().KhoangCach(P); // (đơn vị: m)
	float mucdono = this->GetMucDoNo();
	mucdono -= distance * 10; // mỗi mét di chuyển độ no giảm 7%

	// Kiểm tra mức độ no nếu < 50 thì con vật sẽ kêu
	if (mucdono < 50 && mucdono >= 10) {
        std::cout << "[" << this->GetID() << "] <doi qua! doi qua!> ";
		this->Talk();
    }
	this->SetMucDoNo(mucdono);

	this->SetPos(P); // Đặt lại vị trí của con vật
}
