#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class DynamicArray {
	int size = 0;
	T* dynamicArray = new T[size];
public:

#pragma region Constructors&Destructor

	DynamicArray() = default;

	DynamicArray(const DynamicArray& oth) {
		delete[] dynamicArray;
		size = oth.size;
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = oth.dynamicArray[i];
		}
	}

	~DynamicArray() {
		delete[] dynamicArray;
	}

#pragma endregion

#pragma region OperatorOverloadings

	DynamicArray& operator=(const DynamicArray& oth) {
		delete[] dynamicArray;
		size = oth.size;
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = oth.dynamicArray[i];
		}
		return *this;
	}

	T& operator[](int index) {
		assert(0 <= index && index < size && "index out of range");
		return dynamicArray[index];
	}

#pragma endregion

#pragma region Methods

	void AddElementToEnd(T elem) {

		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = dynamicArray[i];
		}
		temp[size] = elem;
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size++;
	}

	void AddElementToHead(T elem) {

		T* temp = new T[size + 1];
		temp[0] = elem;
		for (int i = 0; i < size; i++)
		{
			temp[i + 1] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size++;

	}

	void AddElementByIndex(int index, T elem) {

		T* temp = new T[size + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = dynamicArray[i];
		}
		temp[index] = elem;
		for (int i = index; i < size; i++)
		{
			temp[i + 1] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size++;

	}

	void DeleteElementByIndex(int index) {

		T* temp = new T[size - 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = dynamicArray[i];
		}
		for (int i = index + 1; i < size; i++)
		{
			temp[i - 1] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size--;

	}

	void Print() {

		for (int i = 0; i < size; i++)
		{
			cout << dynamicArray[i] << " ";
		}

	}
#pragma endregion


};

int main() {

	DynamicArray<int> arr;
	DynamicArray<int> arr2;
	arr.AddElementToEnd(1);
	arr.AddElementToEnd(3);
	arr.AddElementToEnd(2);
	arr.AddElementByIndex(2, 5);
	cout << arr[5];

}
