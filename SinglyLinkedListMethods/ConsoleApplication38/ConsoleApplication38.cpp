#include <iostream>

using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node(const string& data) : data(data), next(nullptr) {}
};

class SinglyList {
	Node* head = nullptr;
public:
	void AddFront(const string& value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	void AddEnd(const string& value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;

		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = newNode;
		temp = nullptr;
	}

	void DeleteFront() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void DeleteEnd() {
		if (head != nullptr) {
			Node* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
	}

	void Print() {

		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void AddElementBefore(const string& x, const string value) {
		Node* newNode = new Node(value);
		if (head != nullptr) {
			Node* temp = head;
			if (x == head->data)
			{
				AddFront(value);
				return;
			}
			while (temp->next->data != x) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	void AddElementAfter(const string& x, const string value) {
		Node* newNode = new Node(value);
		if (head != nullptr) {
			Node* temp = head;
			while (temp->data != x) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	void DeleteByValue(const string& value)
	{
		Node* temp = head;
		Node* prev = nullptr;
		if (head->data == value)
		{
			head = temp->next;
			delete temp;
			return;
		}
		while (temp->data != value) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
	}

};
// Bahruz,Nigar,Ayshan,Islam
// Bahruz
void main() {
	SinglyList sl;
	sl.AddFront("Islam");
	sl.AddFront("Ayshan");
	sl.AddFront("Nigar");
	sl.AddFront("Bahruz");
	sl.DeleteByValue("Ayshan");
	cout << endl;
	sl.Print();
}