#include "Animal.h"

Animal::Animal() : MucDoNo(50) {// Để con vật không bị chết
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

istream & operator >> (istream& in, std::unique_ptr<Animal> &a){
	while (1)
	{
		cout << "-> Nhap MA SO (ID) con vat: ";
		in >> a->ID;
		if(CheckID(a->ID))
			cout << "Error! MA SO nay da co trong du lieu. Vui long nhap lai...\n";
		else break;
	}
	ID_ALL_ANIMAL.push_back(a->ID); // Sau khi nhập Mã số, đẩy nó vào vector ID_ALL_ANIMAL
	cout << "-> Nhap TUOI (Age) con vat: ";
	in >> a->Age;
	cout << "-> Nhap CAN NANG (Weight) cua con vat: ";
	in >> a->Weight;
	cout << endl;
	return in
}

ostream & operator << (ostream &out, const std::unique_ptr<Animal> &a) {
	out << "\t- Ma so (ID): " << a->ID << endl;
	out << "\t- Tuoi (Age): " << a->Age << endl;
	out << "\t- Can nang (Weight): " << a->Weight << endl;
	out << "\t- Muc do no hien tai: " << a->MucDoNo << endl;
	return out;
}

// Kiểm tra Mã số con vật có tồn tại trong danh sách các mã số con vật có trong trang trại
bool Animal::CheckID(string ID)
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
