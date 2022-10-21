#include <iostream>
using namespace std;

class MyString {

#pragma region Fields


	char* string = nullptr;

	int GetSize(const char* str) {
		int size = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}
#pragma endregion

public:

#pragma region Constructors


	MyString() = default;

	MyString(const char* str) {
		SetString(str);
	}

#pragma endregion

#pragma region Setter&Getter

	void SetString(const char* str) {
		delete[] string;
		int len = strlen(str) + 1;
		string = new char[len];
		strcpy_s(string, len, str);
	}

	const char* GetString() const {
		return string;
	}


#pragma endregion

#pragma region Methods

	char FirstChar() const {
		return string[0];
	}

	char LastChar() const {
		int size = 0;
		for (int i = 0; string[i] != '\0'; i++)
		{
			size++;
		}
		return string[size - 1];
	}

	void Append(const char* s){
		if (string != nullptr)
		{
			int size = GetSize(string);
			int sizes = GetSize(s);
			char* temp = new char[size + sizes];
			for (int i = 0; i < size; i++)
			{
				temp[i] = string[i];
			}
			int j = 0;
			for (int i = size; i < size + sizes; i++)
			{
				temp[i] = s[j];
				j++;
			}
			temp[size + sizes] = '\0';
			SetString(temp);
		}
		else{
			SetString(s);
		}
	}

	int rFind(const char s) {
		int size = GetSize(string) - 1;
		int j = 0;
		for (int i = size; i >= 0; i--)
		{
			if (s == string[i]) {
				return j;
			}
			j++;
		}
	}

	int Find(const char s) {
		int size = GetSize(string) - 1;
		for (int i = 0; i <= size; i++)
		{
			if (s == string[i]) {
				return i;
			}
		}
	}

	void Clear() {
		delete[] string;
	}

#pragma endregion


};


//int main() {
//	MyString o;
//	o.Append("mandarin");
//}

// Task 2

//class IntArray {
//	int size = 5;
//	int* arr = new int[size]{1,2,3,4,5};
//public:
//
//#pragma region Constructors
//
//	IntArray() = default;
//
//	IntArray(int s)
//	{
//		size = s;
//		arr = new int[s]{};
//	}
//
//	IntArray(const IntArray& obj)
//	{
//		delete[] arr;
//		size = obj.size;
//		arr = new int[size]{};
//		for (int i = 0; i < size; i++) {
//			arr[i] = obj.arr[i];
//		}
//	}
//	
//#pragma endregion
//
//#pragma region Methods
//
//	void AppendBefore(int num) {
//		int* temp = new int[size++]{};
//		temp[0] = num;
//		for (int i = 1; i < size; i++)
//		{
//			temp[i] = arr[i - 1];
//		}
//		/*delete[] arr;*/
//		arr = temp;
//	}
//
//	void AppendAfter(int num) {
//		int* temp = new int[size+1]{};
//		for (int i = 0; i < size; i++)
//		{
//			temp[i] = arr[i];
//		}
//		temp[size] = num;
//		size++;
//	/*	delete[] arr;*/
//		arr = temp;
//	}
//
//	void Print() {
//		for (int i = 0; i < size; i++)
//		{
//			cout << arr[i] << " ";
//		}
//	}
//
//#pragma endregion
//
//};
//
//int main() {
//	IntArray arr;
//	arr.AppendBefore(1);
//	arr.AppendBefore(2);
//	IntArray arr2 = arr;
//	arr.AppendBefore(1);
//	arr.Print();
//	cout << endl;
//	arr2.Print();
//}
class IntArray {
	int size = 5;
	int* arr = new int[size]{1,2,3,4,5};
public:

#pragma region Constructors

	IntArray() = default;

	IntArray(int s)
	{
		size = s;
		arr = new int[s]{};
	}

	IntArray(const IntArray& obj)
	{
		delete[] arr;
		size = obj.size;
		arr = new int[size]{};
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}

#pragma endregion

#pragma region Methods

	void AppendBefore(int num) {
		int* temp = new int[size+1]{};
		temp[0] = num;
		for (int i = 0; i <= size; i++)
		{
			temp[i+1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		temp = nullptr;
		size++;
	}

	void AppendAfter(int num) {
		int* temp = new int[size+1]{};
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = num;
	    delete[] arr;
		arr = temp;
		temp = nullptr;
		size++;
	}

	void Print() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}

#pragma endregion

};

void main () {
	IntArray arr;
	/*arr.AppendBefore(1);
	arr.AppendBefore(2);
	arr.AppendBefore(1);*/
	arr.AppendBefore(1);
	arr.AppendBefore(2);
	arr.AppendBefore(3);
	arr.Print();
}
