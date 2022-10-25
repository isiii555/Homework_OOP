#include <iostream>
#include <assert.h>
#include <windows.h>
using namespace std;

class Worker {

	int workerId;
	string name;
	string surname;
	int age;

public:
	int pageCount;

	static int Id;

	Worker() {
		workerId = ++Id;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string n, string s, int a, int p) {

		workerId = ++Id;
		name = n;
		surname = s;
		age = a;
		pageCount = p;

	}

	string GetName() {
		return name;
	}

	string GetSurname() {
		return surname;
	}

	int WorkerId() {
		return workerId;
	}

	int WorkerAge() {
		return age;
	}

	int WorkerPageCount() {
		return pageCount;
	}

	Worker& operator=(const Worker& oth) {

		workerId = oth.workerId;
		name = oth.name;
		surname = oth.surname;
		age = oth.age;
		pageCount = oth.pageCount;

		return *this;

	}

	friend ostream& operator<<(ostream& out, const Worker& obj) {
		system("cls");
		cout << "Name : " << obj.name
			<< "\nSurname : " << obj.surname
			<< "\nId : " << obj.Id
			<< "\nAge : " << obj.age
			<< "\nPagecount : " << obj.pageCount;
		for (int i = 0; i < 4; i++)
		{
			Sleep(1000);
			cout << ".";
		}
		return out;
	}

};

int Worker::Id = 0;

class WorkerQueue {

	Worker* arr = nullptr;
	int capacity = 0;
	int count = 0;
	int front = 0;
	int rear = -1; 

public:

	WorkerQueue() = default;

	WorkerQueue(int size) {
		capacity = size;
		arr = new Worker[capacity];
		front = 0;
		rear = -1;
		count = 0;
	}

	bool IsEmpty() { return rear == -1; }
	bool IsFull() { return count == capacity; }

	void Enqueue(Worker& value) {
		assert(!IsFull() && "Queue is full");
		arr[++rear] = value;
		count++;
	}

	void Dequeue() {
		assert(!IsEmpty() && "Queue is empty");
		for (int i = 0; i < count; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
		rear--;
	}

	int Count() {
		return count;
	}

	Worker& Peek() {
		assert(!IsEmpty() && "Queue is empty");
		return arr[front];
	}

	Worker& operator[](int index) {
		return arr[index];
	}

	WorkerQueue& operator=(const WorkerQueue& oth) {
		arr = oth.arr;
		capacity = oth.capacity;
		rear = oth.rear;
		count = oth.count;
		return *this;
	}

	~WorkerQueue() { delete[] arr; }

};

class Printer {

	WorkerQueue queue;

public:

	Printer(WorkerQueue& value) {
		queue = value;
	}

	void Start(){
		for (int i = 0; i < queue.Count(); i++)
		{
			for (; queue[i].pageCount > 0; queue[i].pageCount--)
			{
				cout << queue[i];
			}
			queue.Dequeue();
		}
	}
};

int main() {

	Worker Islam("islam", "salamzade", 19, 5);
	Worker Teymur("teymur", "elisetov", 20, 3);
	Worker Ulvi	("Ulvi", "memmedov", 20, 3);
	WorkerQueue sira(3);
	sira.Enqueue(Islam);
	sira.Enqueue(Teymur);
	sira.Enqueue(Ulvi);
	Printer hp(sira);
	hp.Start();
	
	

}