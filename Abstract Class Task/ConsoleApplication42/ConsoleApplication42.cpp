#include <iostream>
using namespace std;

class Car {

public:

	string vendor;
	string model;
	double engine_volume;
	bool hasSpoiler;

	Car(string ven,string mod,double engine,bool hass) {

		vendor = ven;
		model = mod;
		engine_volume = engine;
		hasSpoiler = hass;

	}

	virtual ~Car() = 0 {
	}

};

class Lada : public Car {

public:
	Lada(string vendor, string model, double engine, bool hass) : Car(vendor, model, engine, hass) {
	}
};

class Mercedes : public Car {

public:
	Mercedes(string vendor, string model, double engine, bool hass) : Car(vendor, model, engine, hass) {
	}
};

class BMW : public Car {

public:
	BMW(string vendor, string model, double engine, bool hass) : Car(vendor, model, engine, hass) {
	}
};

class Person {

public:

	void Drive(Car& obj) {
		cout << "I am driving " << obj.vendor << " " << obj.model << " !!!" << endl;
	}

};

int main() {

	Person islam;
	Lada nolyeddi("Vaz","Nolyeddi",1.5,true);
	Mercedes w124("Mercedes", "W124", 5.5, true);
	BMW f30("BMW", "F30", 3.2, true);
	islam.Drive(w124);
	islam.Drive(nolyeddi);
	islam.Drive(f30);

}
