#include "Animal.h"

Animal::Animal() : MucDoNo(100) {// Để con vật không bị chết
}

Animal::~Animal()
{
}

// Getter / Setter
string Animal::GetID()
{
	return ID;
}
float Animal::GetAge()
{
	return Age;
}
float Animal::GetWeight()
{
	return Weight;
}
Point2D Animal::GetPos()
{
	return Pos;
}
float Animal::GetMucDoNo()
{
	return MucDoNo;
}
void Animal::SetPos(Point2D P)
{
	this->Pos.SetPoint2D(P);
}
void Animal::SetMucDoNo(float MucDoNo)
{
	this->MucDoNo = MucDoNo;
}
void Animal::SetID(string ID)
{
	this->ID = ID;
}
void Animal::SetAge(float Age)
{
	this->Age = Age;
}
void Animal::SetWeight( float Weight )
{
	this->Weight = Weight;
}

ostream & operator << (ostream &out, const std::unique_ptr<Animal> &a) {
	out.width(20); out << right << a->ID;
    out.width(10); out << right << a->Age;
    out.width(10); out << right << a->Weight;
    out.width(10); out << right << a->MucDoNo;
	return out;
}

// Kiểm tra Mã số con vật có tồn tại trong danh sách các mã số con vật có trong trang trại
bool Animal::CheckID(const string& ID)
{
	for (int i = 0; i < ID_ALL_ANIMAL.size(); ++i)
		if (ID.compare(ID_ALL_ANIMAL[i]) == 0)
			return true;
	return false;
}

int Animal::Random(int start, int end)
{
	srand(unsigned(time(NULL)));
	int kq = start + rand() % end;
	return kq;
}
