#include "Farm.h"
#include "Point2D.h"

int main()
{
	std::unique_ptr<Farm> farm = std::make_unique<Farm>();
	int ichon;
	string id;
	float gio;
	float kg_thuc_an;
	string infile  = "input.txt";
	string outfile = "output.txt";
    Point2D place;
	while (true)
	{
		system("cls");
		farm->Menu();
        std::cout << "\n\tMOI CHON: ";
        cin >> ichon;

		switch (ichon)
		{
		case 1:
			std::cout << "\n\tTHEM CON VAT VAO TRANG TRAI";
			farm->ThemConVat();
			system("pause");
			break;
		case 2:
			std::cout << "\n\tDANH SACH CAC CON VAT CO TRONG TRANG TRAI\n";
			farm->XuatDanhSachConVat();
			system("pause");
			break;
		case 3:
			std::cout << "\n\t\"GIET\" MOT CON VAT TRONG TRANG TRAI\n";
			std::cout << "\n\tDANH SACH CAC CON VAT\n";
            farm->XuatDanhSachConVat();
            std::cout << "Nhap ID con vat muon giet: ";
            cin >> id;
			farm->Giet1ConVat(id);
			system("pause");
			break;
		case 4:
			std::cout << "\n\tTHONG TIN CAC CON VAT SAU t GIO\n";
			std::cout << "\n\tDANH SACH CAC CON VAT\n";
            farm->XuatDanhSachConVat();
            std::cout << "Nhap so gio: ";
            cin >> gio;
			farm->ThongTinSautGio(gio);
			system("pause");
			break;
		case 5:
            std::cout << "\n\tCHO DONG LOAT TAT CA CAC CON VAT AN ";
            std::cout << "\n\tDANH SACH CAC CON VAT\n";
            farm->XuatDanhSachConVat();
            std::cout << "Nhap so luong thuc an (kg): ";
            std::cin >> kg_thuc_an;
            if (kg_thuc_an > 0){
                farm->ChoAnDongLoat(kg_thuc_an);
                std::cout << "Cho cac con vat an xong roi!\n";
                std::cout << "\n\tDANH SACH CAC CON VAT SAU KHI DUOC CHO AN\n";
                farm->XuatDanhSachConVat();
            } else {
                std::cout << "So luong thuc an (kg) khong hop le!\n";
            }
			system("pause");
			break;
		case 6:
			std::cout << "\n\tCHO MOT CON CO MA SO NHAT DINH AN ";
			std::cout << "\n\tDANH SACH CAC CON VAT\n";
            farm->XuatDanhSachConVat();
            std::cout << "Nhap id con vat can cho an: ";
            std::cin >> id;
            std::cout << "Nhap so luong thuc an (kg): ";
            std::cin >> kg_thuc_an;
            farm->ChoIDXAn(id, kg_thuc_an);
			std::cout << "\n\tDANH SACH CAC CON VAT SAU KHI DUOC CHO AN\n";
			farm->XuatDanhSachConVat();
			system("pause");
			break;
		case 7:
			std::cout << "\n\tCHO CON VAT DI CHUYEN TOI VI TRI (x, y) ";
			std::cout << "\n\tDANH SACH CAC CON VAT\n";
            farm->XuatDanhSachConVat();
            std::cout << "Nhap toa do vi tri can di chuyen toi: ";
            std::cin >> place;
            farm->DiChuyenConVat(place);
			system("pause");
			break;
        case 8:
            std::cout << "\n\tLAY DU LIEU CON VAT TU FILE ";
            if (farm->getSoLuongConVat() != 0) {
                std::cout << "\nXoa danh sach cac con vat hien co va \ndoc danh sach cac con vat tu file!\n";
                farm->ClearAnimalList();
            }
            farm->LayThongTinConVatTuFile(infile);
            std::cout << "Done!\n";
            system("pause");
            break;
		case 9:
		    std::cout << "\n\tXUAT THONG TIN CON VAT RA FILE ";
            farm->XuatThongTinConVatRaFile(outfile);
            std::cout << "Done!\n";
            system("pause");
            break;
        case 0:
			exit(0);
        default:
            std::cout << "\n\tInvalid choice! Please choose again!\n";
            system("pause");
            break;
		}
	}
	return 0;
}

