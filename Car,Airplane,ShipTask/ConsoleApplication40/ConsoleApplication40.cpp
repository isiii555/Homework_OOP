#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Engine {

    int engineNo;
    string company;
    double volume;

public:

    Engine() {

        engineNo = 0;
        company = "";
        volume = 0;

    }

    Engine(int engineNo, string company, double volume) {

        this->engineNo = engineNo;
        this->company = company;
        this->volume = volume;

    }

    void SetEngineNo(int engineNo) {

        this->engineNo = engineNo;

    }

    void SetCompany(string company) {
        this->company = company;
    }

    void SetVolume(double volume) {
        this->volume = volume;
    }

    int GetEngineNo() {

        return engineNo;

    }

    string GetCompany() {
        return company;
    }

    double GetVolume() {
        return volume;
    }


    void Show() {
        cout << "Engine no : " << engineNo
            << "\nCompany : " << company
            << "\nVolume : " << volume << endl;
    }
};

class Car{

    int id;
    string model;
    string vendor;
    bool hasSpoiler;
    Engine engine;

public:

    Car(int id, string model, string vendor, int engineNo, string company, double volume, bool hasSpoiler) {

        engine.SetEngineNo(engineNo);
        engine.SetCompany(company);
        engine.SetVolume(volume);
        this->id = id;
        this->model = model;
        this->vendor = vendor;
        this->hasSpoiler = hasSpoiler;

    }

    void Show() {

        cout << "Id : " << id
            << "\nModel : " << model
            << "\nVendor : " << vendor
            << "\nSpoiler : " << hasSpoiler << endl;
            engine.Show();
    }

    Car& operator=(Car& oth) {

        id = oth.id;
        model = oth.model;
        vendor = oth.vendor;
        hasSpoiler = oth.hasSpoiler;
        engine.SetEngineNo(oth.engine.GetEngineNo());
        engine.SetCompany(oth.engine.GetCompany());
        engine.SetVolume(oth.engine.GetVolume());
        return *this;
    }

    friend ostream& operator<<(ostream& out, Car& oth) {

        cout << "Id : " << oth.id
            << "\nModel : " << oth.model
            << "\nVendor : " << oth.vendor
            << "\nSpoiler : " << oth.hasSpoiler << endl;
        oth.engine.Show();
        return out;

    }
};

class Ship {

    int id;
    string model;
    string vendor;
    bool hasSail;
    Engine engine; 

public:

    Ship(int id, string model, string vendor, int engineNo, string company, double volume, bool hasSail) {

        engine.SetEngineNo(engineNo);
        engine.SetCompany(company);
        engine.SetVolume(volume);
        this->id = id;
        this->model = model;
        this->vendor = vendor;
        this->hasSail = hasSail;

    }

    void Show() {

        cout << "Id : " << id
            << "\nModel : " << model
            << "\nVendor : " << vendor
            << "\nSail : " << hasSail << endl;
        engine.Show();
    }

    Ship& operator=(Ship& oth) {

        id = oth.id;
        model = oth.model;
        vendor = oth.vendor;
        hasSail = oth.hasSail;
        engine.SetEngineNo(oth.engine.GetEngineNo());
        engine.SetCompany(oth.engine.GetCompany());
        engine.SetVolume(oth.engine.GetVolume());
        return *this;
    }

    friend ostream& operator<<(ostream& out, Ship& oth) {

        cout << "Id : " << oth.id
            << "\nModel : " << oth.model
            << "\nVendor : " << oth.vendor
            << "\nSail : " << oth.hasSail << endl;
        oth.engine.Show();
        return out;

    }
};

class Airplane {

    int id;
    string model;
    string vendor;
    Engine engine;
    int passengerCapacity;
    int engineCount;

public:

    Airplane(int id, string model, string vendor, int engineNo, string company, double volume,int passenger,int count) {

        engine.SetEngineNo(engineNo);
        engine.SetCompany(company);
        engine.SetVolume(volume);
        this->id = id;
        this->model = model;
        this->vendor = vendor;
        passengerCapacity = passenger;
        engineCount = count;

    }

    void Show() {

        cout << "Id : " << id
            << "\nModel : " << model
            << "\nVendor : " << vendor
            << "\nPassenger capacity : " << passengerCapacity
            << "\nEngine count : " << engineCount << endl;
        engine.Show();
    }

    Airplane& operator=(Airplane& oth) {

        id = oth.id;
        model = oth.model;
        vendor = oth.vendor;
        passengerCapacity = oth.passengerCapacity;
        engineCount = oth.engineCount;
        engine.SetEngineNo(oth.engine.GetEngineNo());
        engine.SetCompany(oth.engine.GetCompany());
        engine.SetVolume(oth.engine.GetVolume());
        return *this;

    }

    friend ostream& operator<<(ostream& out, Airplane& oth) {

        cout << "Id : " << oth.id
            << "\nModel : " << oth.model
            << "\nVendor : " << oth.vendor
            << "\nPassenger capacity : " << oth.passengerCapacity
            << "\nEngine count : " << oth.engineCount << endl;
        oth.engine.Show();
        return out;

    }
};

template<class T>
class Stack {

	T* arr;
	int capacity;
	int top;

public:

	Stack(const int size) {
		capacity = size;
		arr = new T[capacity];
		top = -1;
	}
	
	bool IsFull() { return capacity - 1 == top; }
	bool IsEmpty() { return top == -1; }

	void Push(T value) {
		assert(!IsFull() && "Stack overflow");
		arr[++top] = value;
	}

	void Pop() {
		assert(!IsEmpty() && "Stack is empty");
		top--;
	}

	T Top(){ 
		assert(!IsEmpty() && "Stack is empty");
		return arr[top];
	}

	~Stack() { delete[] arr; }
};

class VehicleDepo {
public:
    stack<Car> cars;
    stack<Airplane> airplanes;
    stack<Ship> ships;

    void ShowAllVehicle() {
        while (!cars.empty()) {
            cout << cars.top() << endl;
            cars.pop();
        }
        while (!airplanes.empty()) {
            cout << airplanes.top() << endl;
            airplanes.pop();
        }
        while (!ships.empty()) {
            cout << ships.top() << endl;
            ships.pop();
        }
    }

};

int main()
{

    Car bmw(1, "f30", "bmw", 2, "bmw", 2.3, 1);
    Airplane bayraktar(2,"bayraktar", "tb2", 2, "bayraktar", 1021,1,1);
    Ship yaxta(3, "islam", "isi", 3, "isii555", 2323, 1);
    VehicleDepo depo;
    depo.cars.push(bmw);
    depo.airplanes.push(bayraktar);
    depo.ships.push(yaxta);
    depo.ShowAllVehicle();

}

