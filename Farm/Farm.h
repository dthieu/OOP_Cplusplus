#pragma once
#include "Animal.h"
#include "Chicken.h"
#include "Cow.h"
#include "Pig.h"
#include "Sheep.h"
#include <memory>

class Farm
{
private:
    vector
	vector<std::unique_ptr<Animal>> arr_animal;
public:
    enum {
        COW,    // 0
        SHEEP,  // 1
        PIG,    // 2
        CHICKEN // 3
    };
	// Các hàm trả về chỉ số (số thứ tự các con vật) nếu tìm thấy
	// ngược lại trả về -1
	int CheckID(string str);

	// Menu chương trình chính
	void Menu();

	// Menu Nhập con vật
	void MenuNhapConVat();

	void ThemConVat();
	void XuatDanhSachConVat();
	void Giet1ConVat();
	void ThongTinSautGio(float t);
	void ChoAnDongLoat(float kg);

	// Cho con vật có mã số X (do người dùng nhập vào) ăn.
	void ChoIDXAn(float kg);
	void DiChuyenConVat(Point2D P);
	void DocFile(char* FileName);
	void XuatFile(char* FileName);
};

/*
class Farm
{
private:
	vector<Cow> COW;
	vector<Sheep> SHEEP;
	vector<Pig> PIG;
	vector<Chicken> CHICKEN;
public:
	// Các hàm kiểm tra ID các con vật trong mỗi nhóm: Cow, Sheep, Pig, Chicken
	// Các hàm trả về chỉ số (số thứ tự các con vật) nếu tìm thấy
	// ngược lại trả về -1
	int CheckIDCow(string str);
	int CheckIDSheep(string str);
	int CheckIDPig(string str);
	int CheckIDChicken(string str);

	// Menu chương trình chính
	void Menu();

	// Menu Nhập con vật
	void MenuNhapConVat();

	void ThemConVat();
	void XuatDanhSachConVat();
	void Giet1ConVat();
	void ThongTinSautGio(float t);
	void ChoAnDongLoat(float kg);

	// Cho con vật có mã số X (do người dùng nhập vào) ăn.
	void ChoIDXAn(float kg);
	void DiChuyenConVat(Point2D P);
	void DocFile(char* FileName);
	void XuatFile(char* FileName);
};
*/
