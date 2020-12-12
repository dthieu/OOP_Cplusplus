#pragma once
#include "Animal.h"
#include "Chicken.h"
#include "Factory.h"
#include "Cow.h"
#include "Pig.h"
#include "Sheep.h"
#include <memory>
#include <fstream>
#include <algorithm>

class Farm
{
private:
	vector<std::unique_ptr<Animal>> arr_animal;
public:
    int getSoLuongConVat();
    enum {
        COW,    // 0
        SHEEP,  // 1
        PIG,    // 2
        CHICKEN // 3
    };
	// Các hàm trả về chỉ số (số thứ tự các con vật) nếu tìm thấy
	// ngược lại trả về -1
	int existID(const string &str);

	// Menu chương trình chính
	void Menu();
    void SapXepCacConVat();
	void ThemConVat();
	void XuatDanhSachConVat();
	void Giet1ConVat(const string &id);
	void ThongTinSautGio(float t);
	void ChoAnDongLoat(float kg);

	// Cho con vật có mã số X (do người dùng nhập vào) ăn.
	void ChoIDXAn(const string &id, float kg);
	void DiChuyenConVat(const Point2D &P);
	void LayThongTinConVatTuFile(string filename);
	void XuatThongTinConVatRaFile(string fileName);
	void ClearAnimalList();
};
