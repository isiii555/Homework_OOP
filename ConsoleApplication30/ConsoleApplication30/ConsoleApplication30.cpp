// Kechilenlerin her biri istifade olunsun
// Initializer list, Delegate, getter setter

//class : Product
//	fields : id, name, description, price, discount
//	methods : ShowProduct(), GetPriceWithDiscount()
//
//
//	Stock{
//	   char* name
//	   Product *// array
//	   Print()// show all product in Stock
//	   Product GetProduct(int id);
//}
#include <iostream>
using namespace std;

class Product {

	int id;
	char* name;
	char* description;
	int price;
	int discount;

public:

#pragma region Initializer list

	Product() : id(0),name(nullptr),description(nullptr),price(0),discount(0) {
	}

	Product(int id) : Product() {
		this->id = id;
	}

	Product(int id, const char* name) : Product(id) {
		SetName(name);
	}

	Product(int id, const char* name, const char* description) : Product(id,name) {
		SetDescription(description);
	}

	Product(int id, const char* name, const char* description, int price) : Product(id,name,description) {
		this->price = price;
	}

	Product(int id,const char* name,const char* description,int price,int discount) : Product(id,name,description,price) {
		this->discount = discount;
	}

#pragma endregion

#pragma region Setters & Getters

	void SetName(const char* name) {
		delete this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetDescription(const char* description) {
		delete this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	float GetPriceWithDiscount() {
		float tempprice;
		tempprice = float(price) - (float(price) / discount);
		return tempprice;
	}

#pragma endregion

	void ShowProduct() {
		cout << "Product Id: " << id << endl;
		if (name != nullptr)
		{
			cout << "Product Name: " << name << endl;
		}
		else
			cout << "Product Name: " << "No name" << endl;
		if (description != nullptr)
		{
			cout << "Product Description: " << description << endl;
		}
		else
			cout << "Product Description: " << "No description" << endl;
		cout << "Product Price: " << price << " $" <<  endl;
		cout << "Product Discount: " << discount << " %" << endl;
	}
};

class Stock {
	char* name;
	Product* stock = new Product[3];
public:
	Stock() {
		for (int i = 0; i < 3; i++)
		{
			stock[i] = Product();
		}
	}
	void Print() {
		for (int i = 0; i < 3; i++)
		{
			stock[i].ShowProduct();
		}
	}
	Product GetProduct(int id) {
		if (id > 2) {
			cout << "No product found for this id number";
		}
		else
			return stock[id];
	}
};

int main() {
	Stock Fruits;

	Product Fruit = Fruits.GetProduct(1);
	Fruit.ShowProduct();
}