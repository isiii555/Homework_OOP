#include <iostream>
using namespace std;

class ComputerStore;

class Computer {

	int objectId;
	char* model;
	char* vendor;
	char* videoCard;
	char* monitor;
	double cpu_Hz = 0;
	int core = 0;
	int ram = 0;
	int disk_size = 0;
	bool isSSD = true;
	static int StaticId;

public:
	friend class ComputerStore;

#pragma region Constructors&Destructor


	Computer() {
		objectId = ++StaticId;
	}

	Computer(const char* m, const char* v, const char* vc, const char* mon, double cHz, int c, int r, int ds, bool isS) {

		objectId = ++StaticId;
		SetModel(m);
		SetVendor(v);
		SetVideoCard(vc);
		SetMonitor(mon);
		SetCore(c);
		SetCpuHz(cHz);
		SetRam(r);
		SetDiskSize(ds);
		SetIsSsd(isS);

	}

	~Computer()
	{
		delete[] model;
		delete[] vendor;
		delete[] monitor;
		delete[] videoCard;
	}

#pragma endregion

#pragma region Setters&Getters

	void SetModel(const char* m) {
		delete[] model;
		int len = strlen(m) + 1;
		model = new char[len];
		strcpy_s(model, len, m);
	}

	void SetVendor(const char* v) {
		delete[] vendor;
		int len = strlen(v) + 1;
		vendor = new char[len];
		strcpy_s(vendor, len, v);
	}

	void SetVideoCard(const char* vc) {
		delete[] videoCard;
		int len = strlen(vc) + 1;
		videoCard = new char[len];
		strcpy_s(videoCard, len, vc);
	}

	void SetMonitor(const char* mon) {
		delete[] monitor;
		int len = strlen(mon) + 1;
		monitor = new char[len];
		strcpy_s(monitor, len, mon);
	}
	void SetCpuHz(double cHz) {
		cpu_Hz = cHz;
	}

	void SetCore(int c) {
		core = c;
	}

	void SetRam(int r) {
		ram = r;
	}

	void SetDiskSize(int ds) {
		disk_size = ds;
	}

	void SetIsSsd(bool isS) {
		isSSD = isS;
	}

#pragma endregion

#pragma region Methods

	friend ostream& operator<<(ostream& out, const Computer& obj) {
		out << "=============== Computer Info ===============\n"
			<< "ObjectId:" << obj.objectId
			<< "Vendor: " << obj.vendor
			<< "\nModel: " << obj.model
			<< "\nMonitor: " << obj.monitor
			<< "\nCpu-Hz: " << obj.cpu_Hz
			<< "\nCore: " << obj.core
			<< "\nRam: " << obj.ram
			<< "\nDiskSize: " << obj.disk_size
			<< "\nSSD: " << boolalpha << obj.isSSD;
		return out;
	}

	friend istream& operator>>(istream& in, Computer& obj) {
		char* bf = new char[40];
		cout << "Model: ";
		in.getline(bf, 40);
		obj.SetModel(bf);

		cout << "Vendor: ";
		in.getline(bf, 40);
		obj.SetVendor(bf);

		cout << "Videocard: ";
		in.getline(bf, 40);
		obj.SetVideoCard(bf);

		cout << "Monitor: ";
		in.getline(bf, 40);
		obj.SetMonitor(bf);

		cout << "Cpu-Hz: ";
		double y;
		cin >> y;
		obj.SetCpuHz(y);

		cout << "Core: ";
		int c;
		cin >> c;
		obj.SetCore(c);

		cout << "Ram: ";
		int r;
		cin >> r;
		obj.SetRam(r);

		cout << "Disc Size: ";
		int d;
		cin >> d;
		obj.SetDiskSize(d);

		cout << "is SSD ? (1 = Yes, 0 = No) : ";
		int i;
		cin >> i;
		obj.SetDiskSize(i);

		delete[] bf;
		return in;
	}

#pragma endregion

};

int Computer::StaticId = 0;

class ComputerStore {
	char* storeName;
	char* storeAdress;
	int size = 0;
	Computer** computers = new Computer * [size];
public:

#pragma region Constructors&Destructors

	ComputerStore() = default;

	ComputerStore(const char* name, const char* adress) {
		SetName(name);
		SetAdress(adress);
	}

	~ComputerStore()
	{
		delete[] storeName;
		delete[] storeAdress;
		delete computers;
	}

#pragma endregion

#pragma region Setters&Getters

	void SetName(const char* name) {
		delete[] storeName;
		int len = strlen(name) + 1;
		storeName = new char[len];
		strcpy_s(storeName, len, name);
	}

	void SetAdress(const char* adress) {
		delete[] storeAdress;
		int len = strlen(adress) + 1;
		storeAdress = new char[len];
		strcpy_s(storeAdress, len, adress);
	}

#pragma endregion

#pragma region Methods

	void AddComputer(Computer& obj) {

		Computer** temp = new Computer*[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = computers[i];
		}
		temp[size] = new Computer(obj);
		delete computers;
		computers = temp;
		temp = nullptr;
		size++;

	}

	void DeleteComputer(int id) {
		for (int i = 0; i < size; i++)
		{
			if (id == computers[i]->objectId)
			{
				Computer** temp = new Computer * [size - 1];
				for (int j = 0; j < i; j++)
				{
					temp[j] = computers[j];
				}
				for (int j = i; j < size - 1; j++)
				{
					temp[j + 1] = computers[i + 1];
				}
				size--;
				delete computers;
				computers = temp;
			}
		}
	}

	void PrintComputers() {
		for (int i = 0; i < size; i++)
		{
			cout << *computers[i];
		}
	}

#pragma endregion

};

int main() {
	Computer hp;
	ComputerStore Kontakt;
	cin >> hp;
	Kontakt.AddComputer(hp);
	Kontakt.PrintComputers();
}
