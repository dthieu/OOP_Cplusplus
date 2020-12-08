#include "Farm.h"
#include "Point2D.h"

int main()
{
	Farm farm;
	int ichon;
	while (true)
	{
		system("cls");
		farm.Menu();
		while (true)
		{
			cout << "\n\tMOI CHON: ";
			cin >> ichon;
			if (ichon < 1 || ichon > 8)
				cout << "Vui long nhap lai...\n";
			else
				break;
		}
		switch (ichon)
		{
		case 1:
			cout << "\tTHEM CON VAT VAO TRANG TRAI\n";
			farm.ThemConVat();
			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 2:
			cout << "\tDANH SACH CAC CON VAT CO TRONG TRANG TRAI\n";
			farm.XuatDanhSachConVat();
			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 3:
			cout << "\t\"GIET\" MOT CON VAT TRONG TRANG TRAI\n";
			farm.Giet1ConVat();
			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 4:
			float gio;
			cout << "\tTHONG TIN CAC CON VAT SAU t GIO\n";
			while (true)
			{
				cout << "Nhap so gio: ";
				cin >> gio;
				if (gio <= 0)
					cout << "Error!\n";
				else
					break;
			}
			farm.ThongTinSautGio(gio);
			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 5:


			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 6:

			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 7:

			cout << "\nNhan phim bat ki de quay lai menu... ";
			std::cin.get();
			break;
		case 8:
			exit(0);
		}
	}

	return 0;
}

