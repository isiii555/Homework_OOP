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

class Vehicle {
public:
    static int staticId;
    int id;
    string model;
    string vendor;
    Engine engine;

    Vehicle(string _vendor, string _model, Engine _engine) {

        id = staticId++;
        vendor = _vendor;
        model = _model;
        engine = _engine;

    }

    virtual void Show() {
        cout << "Id : " << id
            << "\nModel : " << model
            << "\nVendor : " << vendor << endl;
        engine.Show();
    }

};

int Vehicle::staticId = 1;

class Car : public Vehicle {
public:

    bool hasSpoiler;

    Car(string model, string vendor, Engine engine, bool hasSpoiler) : Vehicle(vendor,model,engine) {
        this->hasSpoiler = hasSpoiler;
    }

    void Show() override {

        
        cout << "*********Car*********" << endl;
        Vehicle::Show();
        cout << "Spoiler : " << (hasSpoiler ? "var" : "yox" ) << endl;

    }
};

class Ship : public Vehicle {
public:

    bool hasSail;

    Ship(bool hasSail) : Vehicle(vendor, model, engine) {

        this->hasSail = hasSail;

    }

    void Show() override {

        cout << "*********Ship*********" << endl;
        Vehicle::Show();
        cout << "Spoiler : " << (hasSail ? "var" : "yox") << endl;

    }

};

class Airplane : public Vehicle {


    int passengerCapacity;
    int engineCount;

public:

    Airplane(int passenger, int count) : Vehicle(vendor, model, engine) {

        passengerCapacity = passenger;
        engineCount = count;

    }

    void Show() override {

        cout << "*********Airplane*********" << endl;
        Vehicle::Show();
        cout << "Passenger Capacity : " << passengerCapacity
            << "Engine Count : " << engineCount << endl;
    }

    
};

class VehicleDepo {
public:
    stack<Vehicle*> vehicles;

    void AddVehicle(Vehicle* vehicle) {

        vehicles.push(vehicle);

    }

    void ShowAllVehicle() {

        while (!vehicles.empty()) {
            vehicles.top()->Show();
            vehicles.pop();
        }

    }

};

int main()
{

    Vehicle* Garage(new Car("Lada", "2107", Engine(2, "VAZ", 2.3), 1));
    VehicleDepo depo;

    depo.AddVehicle(Garage);
    depo.ShowAllVehicle();


}
