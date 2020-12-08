#include "Farm.h"

void Farm::Menu()
{
	cout << "-------------------------------------------------------\n";
	cout << "                        MENU                          -\n";
	cout << "-------------------------------------------------------\n";
	cout << "-  1. THEM CAC CON VAT VAO TRANG TRAI                 -\n";
	cout << "-  2. LIET KE DANH SACH CAC CON VAT TRONG TRANG TRAI  -\n";
	cout << "-  3. KILL MOT CON VAT TRONG TRANG TRAI               -\n";
	cout << "-  4. THONG TIN CAC CON VAT SAU t GIO                 -\n";
	cout << "-  5. CHO DONG LOAT TAT CA CAC CON VAT AN             -\n";
	cout << "-  6. CHO MOT CON CO MA SO NHAT DINH AN               -\n";
	cout << "-  7. CHO CON VAT DI CHUYEN TOI VI TRI (x, y)         -\n";
	cout << "-  8. THOAT.                                          -\n";
	cout << "-------------------------------------------------------\n";
}

void Farm::MenuNhapConVat()
{
	cout << "\n" << COW << ". Nhap Bo (Cow).\n";
	cout << SHEEP   << ". Nhap Cuu (Sheep).\n";
	cout << PIG     << ". Nhap Heo (Pig).\n";
	cout << CHICKEN << ". Nhap Ga (Chicken).\n";
	cout << "4. Thoat!\n"
	cout << "\tMoi chon: ";
}

void Farm::ThemConVat()
{
	int ichon;
	// Các biến tạm
	std::unique_ptr<Animal> animal;

	while (1)
	{
        MenuNhapConVat();
		cin >> ichon;
		switch (ichon)
		{
		case COW:
            animal = std::make_unique<Cow>();
			cin >> animal;
			arr_animal.push_back(animal);
			break;
		case SHEEP:
			animal = std::make_unique<Cow>();
			cin >> animal;
			arr_animal.push_back(animal);
			break;
		case PIG:
			animal = std::make_unique<Cow>();
			cin >> animal;
			arr_animal.push_back(animal);
			break;
		case CHICKEN:
			animal = std::make_unique<Cow>();
			cin >> animal;
			arr_animal.push_back(animal);
			break;
        case 4:
            return;
        case default:
            std::cout << "Invalid choice!";
            break;
		}
	}
}

void Farm::XuatDanhSachConVat()
{
	int i;

	cout << "\tDanh sach cac con BO (Cow):\n";
	if (COW.size() == 0)
		cout << "Danh sach rong!\n";
	else
	{
		for (i = 0; i < COW.size(); ++i)
		{
			cout << "- Con thu " << i + 1 << ":\n";
			COW[i].Xuat();
			cout << endl;
		}
	}
	//----------------------------------------------
	cout << "\tDanh sach cac con CUU (Sheep):\n";
	if (SHEEP.size() == 0)
		cout << "Danh sach rong!\n";
	else
	{
		for (i = 0; i < SHEEP.size(); ++i)
		{
			cout << "- Con thu " << i + 1 << ":\n";
			SHEEP[i].Xuat();
			cout << endl;
		}
	}
	//-----------------------------------------------
	cout << "\tDanh sach cac con HEO (Pig):\n";
	if (PIG.size() == 0)
		cout << "Danh sach rong!\n";
	else
	{
		for (i = 0; i < PIG.size(); ++i)
		{
			cout << "- Con thu " << i + 1 << ":\n";
			PIG[i].Xuat();
			cout << endl;
		}
	}
		//----------------------------------------------
	cout << "\tDanh sach cac con GA (Chicken):\n";
	if (CHICKEN.size() == 0)
		cout << "Danh sach rong!\n";
	else
	{
		for (i = 0; i < CHICKEN.size(); ++i)
		{
			cout << "- Con thu " << i + 1 << ":\n";
			CHICKEN[i].Xuat();
			cout << endl;
		}
	}
}

void Farm::Giet1ConVat()
{
	// Giết một con vật đầu tiên trong danh sách các con vật
	if (COW.size() != 0)
	{
		COW.erase(COW.begin());
		cout << "Giet thanh cong!\n";
	}
	else
		if (SHEEP.size() != 0)
		{
			SHEEP.erase(SHEEP.begin());
			cout << "Giet thanh cong!\n";
		}
	else
		if (PIG.size() != 0)
		{
			PIG.erase(PIG.begin());
			cout << "Giet thanh cong!\n";
		}
	else
		if (CHICKEN.size() != 0)
		{
			CHICKEN.erase(CHICKEN.begin());
			cout << "Giet thanh cong!\n";
		}
	else
		cout << "Khong co con vat nao de giet!\n";
}

void Farm::ThongTinSautGio(float t)
{
	int i;
	float temp;
	int tuoi = (int)t/24;
	cout << "\n--- DANH SACH CAC CON VAT SAU " << t << " GIO ---\n\n";
	cout << "-> Danh sach cac con BO (Cow):\n";
	if (COW.size() != 0)
	{
		for (i = 0; i < COW.size(); ++i)
		{
			temp = COW[i].GetMucDoNo() - (t * 5) / 8;
			if (temp >= 50)
			{
				COW[i].SetMucDoNo(temp);
				COW[i].Xuat();
			}
			else if (temp < 50 && temp > 10)
			{
				COW[i].Talk();
				COW[i].SetMucDoNo(temp);
				COW[i].Xuat();
			}
			else if (temp < 10) // Nếu con vật có độ no nhỏ hơn 10% tức là nó đã chết => xóa sổ nó khỏi danh sách.
				COW.erase(COW.begin() + i);
			// Cập nhật lại tuổi con vật nếu giờ lớn hơn >= 24
			tuoi += COW[i].GetAge();
			COW[i].SetAge(tuoi);
		}
	}
	else
		cout << "Danh sach rong!\n";
	//////////////////////////////////////////////////////////////////////////

	cout << "-> Danh sach cac con CUU (Sheep):\n";
	if (SHEEP.size() != 0)
	{
		for (i = 0; i < SHEEP.size(); ++i)
		{
			temp = SHEEP[i].GetMucDoNo() - (t * 6) / 8;
			if (temp >= 50)
			{
				SHEEP[i].SetMucDoNo(temp);
				SHEEP[i].Xuat();
			}
			else if (temp < 50 && temp > 10)
			{
				SHEEP[i].Talk();
				SHEEP[i].SetMucDoNo(temp);
				SHEEP[i].Xuat();
			}
			else if (temp < 10) // Nếu con vật có độ no nhỏ hơn 10% tức là nó đã chết => xóa sổ nó khỏi danh sách.
				SHEEP.erase(SHEEP.begin() + i);
			// Cập nhật lại tuổi con vật nếu giờ lớn hơn >= 24
			tuoi += SHEEP[i].GetAge();
			SHEEP[i].SetAge(tuoi);
		}
	}
	else
		cout << "Danh sach rong!\n";
	//////////////////////////////////////////////////////////////////////////

	cout << "-> Danh sach cac con HEO (Pig):\n";
	if (PIG.size() != 0)
	{
		for (i = 0; i < PIG.size(); ++i)
		{
			temp = PIG[i].GetMucDoNo() - (t * 7) / 8;
			if (temp >= 50)
			{
				PIG[i].SetMucDoNo(temp);
				PIG[i].Xuat();
			}
			else if (temp < 50 && temp > 10)
			{
				PIG[i].Talk();
				PIG[i].SetMucDoNo(temp);
				PIG[i].Xuat();
			}
			else if (temp < 10) // Nếu con vật có độ no nhỏ hơn 10% tức là nó đã chết => xóa sổ nó khỏi danh sách.
				PIG.erase(PIG.begin() + i);
			// Cập nhật lại tuổi con vật nếu giờ lớn hơn >= 24
			tuoi += PIG[i].GetAge();
			PIG[i].SetAge(tuoi);
		}
	}
	else
		cout << "Danh sach rong!\n";
	//////////////////////////////////////////////////////////////////////////

	cout << "-> Danh sach cac con GA (Chicken):\n";
	if (CHICKEN.size() != 0)
	{
		for (i = 0; i < CHICKEN.size(); ++i)
		{
			temp = CHICKEN[i].GetMucDoNo() - (t * 10) / 12;
			if (temp >= 50)
			{
				CHICKEN[i].SetMucDoNo(temp);
				CHICKEN[i].Xuat();
			}
			else if (temp < 50 && temp > 10)
			{
				CHICKEN[i].Talk();
				CHICKEN[i].SetMucDoNo(temp);
				CHICKEN[i].Xuat();
			}
			else if (temp < 10) // Nếu con vật có độ no nhỏ hơn 10% tức là nó đã chết => xóa sổ nó khỏi danh sách.
				CHICKEN.erase(CHICKEN.begin() + i);
			// Cập nhật lại tuổi con vật nếu giờ lớn hơn >= 24
			tuoi += CHICKEN[i].GetAge();
			CHICKEN[i].SetAge(tuoi);
		}
	}
	else
		cout << "Danh sach rong!\n";
}

void Farm::ChoAnDongLoat(float kg)
{
	// Cho các con bò ăn
	if (COW.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
			COW[i].ChoAn(kg);
	}
	// Cho các con cừu ăn
	if (SHEEP.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
			SHEEP[i].ChoAn(kg);
	}
	// Cho các con heo ăn
	if (PIG.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
			PIG[i].ChoAn(kg);
	}
	// Cho các con gà ăn
	if (CHICKEN.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
			CHICKEN[i].ChoAn(kg);
	}
}

void Farm::DiChuyenConVat(Point2D P)
{
	// Di chuyển các con bò
	if (COW.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
		{
			COW[i].Move(P);
			// Sau khi di chuyển nếu mức độ no < 10 thì xóa con vật đó khỏi danh sách
			if (COW[i].GetMucDoNo() < 10)
			{
				COW.erase(COW.begin() + i);
			}
		}
	}
	// Di chuyển các con cừu
	if (SHEEP.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
		{
			SHEEP[i].Move(P);
			// Sau khi di chuyển nếu mức độ no < 10 thì xóa con vật đó khỏi danh sách
			if (SHEEP[i].GetMucDoNo() < 10)
			{
				SHEEP.erase(SHEEP.begin() + i);
			}
		}
	}
	// Di chuyển các con heo
	if (PIG.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
		{
			PIG[i].Move(P);
			// Sau khi di chuyển nếu mức độ no < 10 thì xóa con vật đó khỏi danh sách
			if (PIG[i].GetMucDoNo() < 10)
			{
				PIG.erase(PIG.begin() + i);
			}
		}
	}
	// Di chuyển các con gà
	if (CHICKEN.size() != 0)
	{
		for (int i = 0; i < COW.size(); ++i)
		{
			CHICKEN[i].Move(P);
			// Sau khi di chuyển nếu mức độ no < 10 thì xóa con vật đó khỏi danh sách
			if (CHICKEN[i].GetMucDoNo() < 10)
			{
				CHICKEN.erase(CHICKEN.begin() + i);
			}
		}
	}
}

// Cho con vật có mã số X ăn
void Farm::ChoIDXAn(float kg)
{
	int ichon;
	string _ID;
	float ThucAn; // Lượng thức ăn
	cout << "1. Cho Bo (Cow) an! <so luong BO: " << COW.size() << " con>\n";
	cout << "2. Cho Cuu (Sheep) an! <so luong CUU: " << SHEEP.size() << " con>\n";
	cout << "3. Cho Heo (Pig) an! <so luong HEO: " << PIG.size() << " con>\n";
	cout << "4. Cho Ga (Chicken) an! <so luong GA: " << CHICKEN.size() << " con>\n";
	cout << "\tMoi chon: ";
	cin >> ichon;
	switch (ichon)
	{
	case 1:
		if (COW.size() != 0)
		{
			cout << "\tCho Bo (Cow) an.\n";
			cout << "Danh sach cac ID cua Bo (Cow):\n";
			for (int i = 0; i < COW.size(); i++)
			{
				cout << "\t" << COW[i].GetID() << endl;
			}
			while(1)
			{
				cout << "\nMoi nhap ma so (ID): ";
				fflush(stdin);
				getline(cin, _ID);
				if (CheckIDCow(_ID) == -1)
				{
					cout << "Error! Khong ton tai ma so (ID) " << _ID << " trong danh sach Bo (Cow)!\n";
					cout << "Vui long nhap lai...\n";
				}
				else
					break;
			}
			cout << "Nhap khoi luong thuc an (kg): ";
			cin >> ThucAn;
			int result = CheckIDCow(_ID);
			COW[result].ChoAn(ThucAn);
			cout << "\nCho an thanh cong!\n";
		}
		else
			cout << "Khong co con vat nao de cho an!\n";
		break;
	case 2:
		if (SHEEP.size() != 0)
		{
			cout << "\tCho Cuu (Sheep) an.\n";
			cout << "Danh sach cac ID cua Cuu (Sheep):\n";
			for (int i = 0; i < SHEEP.size(); i++)
			{
				cout << "\t" << SHEEP[i].GetID() << endl;
			}
			while(1)
			{
				cout << "\nMoi nhap ma so (ID): ";
				fflush(stdin);
				getline(cin, _ID);
				if (CheckIDSheep(_ID) == -1)
				{
					cout << "Error! Khong ton tai ma so (ID) " << _ID << " trong danh sach Cuu (Sheep)!\n";
					cout << "Vui long nhap lai...\n";
				}
				else
					break;
			}
			cout << "Nhap khoi luong thuc an (kg): ";
			cin >> ThucAn;
			int result = CheckIDSheep(_ID);
			SHEEP[result].ChoAn(ThucAn);
			cout << "\nCho an thanh cong!\n";
		}
		else
			cout << "Khong co con vat nao de cho an!\n";
		break;
	case 3:
		if (PIG.size() != 0)
		{
			cout << "\tCho Heo (Pig) an.\n";
			cout << "Danh sach cac ID cua Heo (Pig):\n";
			for (int i = 0; i < PIG.size(); i++)
			{
				cout << "\t" << PIG[i].GetID() << endl;
			}
			while(1)
			{
				cout << "\nMoi nhap ma so (ID): ";
				fflush(stdin);
				getline(cin, _ID);
				if (CheckIDPig(_ID) == -1)
				{
					cout << "Error! Khong ton tai ma so (ID) " << _ID << " trong danh sach Heo (Pig)!\n";
					cout << "Vui long nhap lai...\n";
				}
				else
					break;
			}
			cout << "Nhap khoi luong thuc an (kg): ";
			cin >> ThucAn;
			int result = CheckIDPig(_ID);
			PIG[result].ChoAn(ThucAn);
			cout << "\nCho an thanh cong!\n";
		}
		else
			cout << "Khong co con vat nao de cho an!\n";
		break;
	case 4:
		if (CHICKEN.size() != 0)
		{
			cout << "\tCho Ga (Chicken) an.\n";
			cout << "Danh sach cac ID cua Ga (Chicken):\n";
			for (int i = 0; i < CHICKEN.size(); i++)
			{
				cout << "\t" << CHICKEN[i].GetID() << endl;
			}
			while(1)
			{
				cout << "\nMoi nhap ma so (ID): ";
				fflush(stdin);
				getline(cin, _ID);
				if (CheckIDChicken(_ID) == -1)
				{
					cout << "Error! Khong ton tai ma so (ID) " << _ID << " trong danh sach Ga (Chicken)!\n";
					cout << "Vui long nhap lai...\n";
				}
				else
					break;
			}
			cout << "Nhap khoi luong thuc an (kg): ";
			cin >> ThucAn;
			int result = CheckIDChicken(_ID);
			CHICKEN[result].ChoAn(ThucAn);
			cout << "\nCho an thanh cong!\n";
		}
		else
			cout << "Khong co con vat nao de cho an!\n";
		break;
	default:
		break;
	}
}

// kiểm tra ID con vat
int Farm::CheckID(string str)
{
	for (int i = 0; i < arr_animal.size(); i++)
	{
		if (str.compare(arr_animal[i]->GetID()) == 0)
			return i;
	}
	return -1;
}

