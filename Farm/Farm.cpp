#include "Farm.h"

void Farm::SapXepCacConVat(){
    std::sort(arr_animal.begin(),
              arr_animal.end(),
              [](const std::unique_ptr<Animal> &p1, const std::unique_ptr<Animal> &p2) {
                    return (p1->GetID() < p2->GetID());
              });
}

int Farm::getSoLuongConVat() { return arr_animal.size(); }

void Farm::ClearAnimalList(){
    if (arr_animal.size() > 0)
        arr_animal.clear();
}

void Farm::Menu()
{
	cout << "\n-------------------------------------------------------\n";
	cout << "                        MENU                          -\n";
	cout << "-------------------------------------------------------\n";
	cout << "-  1. THEM CAC CON VAT VAO TRANG TRAI                 -\n";
	cout << "-  2. LIET KE DANH SACH CAC CON VAT TRONG TRANG TRAI  -\n";
	cout << "-  3. KILL MOT CON VAT TRONG TRANG TRAI               -\n";
	cout << "-  4. THONG TIN CAC CON VAT SAU t GIO                 -\n";
	cout << "-  5. CHO DONG LOAT TAT CA CAC CON VAT AN             -\n";
	cout << "-  6. CHO MOT CON CO MA SO NHAT DINH AN               -\n";
	cout << "-  7. CHO CON VAT DI CHUYEN TOI VI TRI (x, y)         -\n";
	cout << "-  8. DOC THONG TIN CON VAT TU FILE                   -\n";
	cout << "-  9. XUAT THONG TIN CON VAT RA FILE                  -\n";
	cout << "-  0. THOAT.                                          -\n";
	cout << "-------------------------------------------------------\n";
}

void Farm::LayThongTinConVatTuFile(string filename){
    std::ifstream file(filename);
    std::unique_ptr<Animal> animal;
    std::unique_ptr<AnimalFactory> fac(new AnimalFactory());
    if (file.is_open()){
        string id;
        float age, weight, mucdono;
        while (!file.eof())
        {
            file >> id >> age >> weight >> mucdono;
            if (id.find("COW") == 0) // ID starts with COW_
                animal = fac->createAnimal(AnimalFactory::COW);
            else if (id.find("SHEEP") == 0) // ID starts with SHEEP_
                animal = fac->createAnimal(AnimalFactory::SHEEP);
            else if (id.find("PIG") == 0) // ID starts with PIG_
                animal = fac->createAnimal(AnimalFactory::PIG);
            else if (id.find("CHICKEN") == 0) // ID starts with CHICKEN_
                animal = fac->createAnimal(AnimalFactory::CHICKEN);
            else continue;
            animal->SetID(id);
            animal->SetAge(age);
            animal->SetWeight(weight);
            animal->SetMucDoNo(mucdono);
            arr_animal.push_back(std::move(animal));
        }
        file.close();
        SapXepCacConVat();
    } else {
        std::cout << "Cannot open file " << filename << std::endl;
    }
}

void Farm::ThemConVat()
{
	int ichon;
	// Các biến tạm
	std::unique_ptr<AnimalFactory> animalFac;
    std::unique_ptr<Animal> animal;
    std::cout << "\n\tDANH SACH CAC CON VAT\n";
    XuatDanhSachConVat();
	while (1)
	{
        cout << "\n0. Nhap Bo (Cow).\n";
        cout << "1. Nhap Cuu (Sheep).\n";
        cout << "2. Nhap Heo (Pig).\n";
        cout << "3. Nhap Ga (Chicken).\n";
        cout << "4. Thoat!\n";
        cout << "\tMoi chon: ";
		cin >> ichon;
		switch (ichon)
		{
		case 0: // COW
            animal = animalFac->createAnimal(AnimalFactory::COW);
			cin >> animal;
			if (!existID(animal->GetID()))
                arr_animal.push_back(std::move(animal));
			break;
		case 1: // SHEEP
			animal = animalFac->createAnimal(AnimalFactory::SHEEP);
			cin >> animal;
			if (!existID(animal->GetID()))
                arr_animal.push_back(std::move(animal));
			break;
		case 2: // PIG
			animal = animalFac->createAnimal(AnimalFactory::PIG);
			cin >> animal;
			if (!existID(animal->GetID()))
                arr_animal.push_back(std::move(animal));
			break;
		case 3: // CHICKEN
			animal = animalFac->createAnimal(AnimalFactory::CHICKEN);
			cin >> animal;
			if (!existID(animal->GetID()))
                arr_animal.push_back(std::move(animal));
			break;
        case 4:
            SapXepCacConVat();
            return;
        default:
            std::cout << "Invalid choice!";
            break;
		}
	}
}

void Farm::XuatDanhSachConVat()
{
    cout << std::setw(20) << "ID"
            << std::setw(10) << "Age"
            << std::setw(10) << "Weight"
            << std::setw(15) << "Full_level(%)" << std::endl;
    for (auto &pep : arr_animal) {
        std::cout << pep << std::endl;
    }
}

void Farm::XuatThongTinConVatRaFile(string fileName){
    SapXepCacConVat();
    ofstream file(fileName);
    if (file.is_open()){
        for (auto &animal : arr_animal) {
            file << animal->GetID() << " " << animal->GetAge() << " "
                 << animal->GetWeight() << " " << animal->GetMucDoNo()
                 << "\n";
        }
        file.close();
    } else {
        std::cout << "Cannot write file " << fileName << std::endl;
    }
}

void Farm::Giet1ConVat(const string &id)
{
    int killed = 0;
	// Giết một con vật đầu tiên trong danh sách các con vật
    for (int i = 0; i < arr_animal.size(); i++) {
        if (arr_animal[i]->GetID().compare(id) == 0) { // same
            arr_animal.erase(arr_animal.begin() + i); // kill animal
            std::cout << "Da giet con vat co id " << id << endl;
            killed = 1;
            break;
        }
    }
    if (!killed){
        std::cout << "Khong co con vat [" << id << "] trong danh sach!\n";
    }
}

void Farm::ThongTinSautGio(float t)
{
    if (t <= 0) {
        std::cout << "Hours need to great than 0!\n";
        return;
    }
	float do_no_sau_t_h;
	float tuoi = t/24.;
	vector<int> deleted_idx;
    for (int i = 0; i < arr_animal.size(); ++i)
    {
        if (arr_animal[i]->GetID().find("COW") == 0) // ID starts with COW_
            do_no_sau_t_h = arr_animal[i]->GetMucDoNo() - (t * 5) / 8;
        else if (arr_animal[i]->GetID().find("SHEEP") == 0) // ID starts with SHEEP_
            do_no_sau_t_h = arr_animal[i]->GetMucDoNo() - (t * 6) / 8;
        else if (arr_animal[i]->GetID().find("PIG") == 0) // ID starts with PIG_
            do_no_sau_t_h = arr_animal[i]->GetMucDoNo() - (t * 7) / 8;
        else if (arr_animal[i]->GetID().find("CHICKEN") == 0) // ID starts with CHICKEN_
            do_no_sau_t_h = arr_animal[i]->GetMucDoNo() - (t * 10) / 12;
        else continue;

        if (do_no_sau_t_h >= 50)
        {
            arr_animal[i]->SetMucDoNo(do_no_sau_t_h);
        }
        else if (do_no_sau_t_h < 50 && do_no_sau_t_h > 10)
        {
            arr_animal[i]->SetMucDoNo(do_no_sau_t_h);
            std::cout << "[" << arr_animal[i]->GetID() << "] <doi bung qua!> ";
            arr_animal[i]->Talk();
        }
        else if (do_no_sau_t_h < 10) { // Nếu con vật có độ no nhỏ hơn 10% tức là nó đã chết => xóa sổ nó khỏi danh sách.
            std::cout << "Con vat da chet sau " << t << "h" << std::endl;
            cout << arr_animal[i] << std::endl;
            deleted_idx.push_back(i);
        }
        // Cập nhật lại tuổi con vật nếu giờ lớn hơn >= 24
        tuoi += arr_animal[i]->GetAge();
        arr_animal[i]->SetAge(tuoi);
    }
    // Update animal list
    if (deleted_idx.size()){
        for (int j = deleted_idx.size()-1; j >= 0; j--)
            arr_animal.erase(arr_animal.begin() + j);
    }
    // Xuat thong tin cac con vat sau t gio
    XuatDanhSachConVat();
}

void Farm::ChoAnDongLoat(float kg)
{
    // Cho cac con vat trong trang trai an
    for (auto &pep : arr_animal) {
        pep->ChoAn(kg);
    }
}

void Farm::DiChuyenConVat(const Point2D &P)
{
    std::vector<int> idx_die;
    for (int i = 0; i < arr_animal.size(); i++) {
        arr_animal[i]->Move(P);
        if (arr_animal[i]->GetMucDoNo() < 10) {
            idx_die.push_back(i);
        }
    }
    if (idx_die.size() > 0) {
        for (int j = idx_die.size()-1; j >= 0; j--){
            arr_animal.erase(arr_animal.begin() + j);
        }
    }
    XuatDanhSachConVat();
}

// Cho con vật có mã số X ăn
void Farm::ChoIDXAn(const string &id, float kg)
{
    int flag = 0;
    for (auto &animal : arr_animal) {
        if (id.compare(animal->GetID()) == 0){
            animal->ChoAn(kg);
            std::cout << "Con vat [" << id << "] da duoc cho an!\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        std::cout << "Error: Khong co con vat [" << id << "] trong danh sach!\n";
    }
}

// kiểm tra ID con vat
int Farm::existID(const string &id)
{
	for (auto &animal : arr_animal)
	{
		if (id.compare(animal->GetID()) == 0){
            std::cout << "Error: ID [" << id << "] da ton tai trong danh sach!\n";
			return 1;
			break;
        }
	}
	return 0;
}
