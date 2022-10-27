#include <iostream> 
#include <assert.h> 
#include <queue>
#include <vector>

using namespace std;

// Priority queue template
// class student template
// ortalamasi en yuxari olan telebe novbeden cixir

class Student {

    string name;
    string surname;
    int age;
    double averageScore;

public:

    Student() {

        name = "";
        surname = "";
        age = 0;
        averageScore = 0;

    }

    Student(string n, string s, int a, int av) {

        name = n;
        surname = s;
        age = a;
        averageScore = av;

    }

    Student(const Student& oth) {

        name = oth.name;
        surname = oth.surname;
        age = oth.age;
        averageScore = oth.averageScore;

    }

    string GetName() {
        return name;
    }

    string GetSurname() {
        return surname;
    }

    int GetAge() {
        return age;
    }

    double GetAverageScore() {

        return averageScore;

    }

    bool operator>(const Student& oth) {
        return averageScore > oth.averageScore;
    }

    Student& operator=(const Student& oth) {

        name = oth.name;
        surname = oth.surname;
        age = oth.age;
        averageScore = oth.averageScore;
        return *this;

    }

    friend ostream& operator<<(ostream& out, const Student& oth) {

        cout << "Name : " << oth.name
            << "\nSurname : " << oth.surname
            << "\nAge : " << oth.age
            << "\nAveraga Score : " << oth.averageScore
            << endl;
        return out;

    }

};

template <typename T>
class PriorityQueue {

    T* arr;
    int capacity;
    int count;
    int rear;
    int GetMaxIndex() {
        int maxIndex = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        return maxIndex;
    }
public:
    PriorityQueue(int size) {

        arr = new T[size];
        capacity = size;
        count = 0;
        rear = -1;

    }
    bool IsFull() const { return capacity == count; }

    bool IsEmpty() const { return 0 == count; }

    void Push(T value) {
        assert(!IsFull());
        arr[++rear] = value;
        count++;
    }

    void Pop() {
        assert(!IsEmpty());
        int index = GetMaxIndex();
        for (int i = index; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void Print() {
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~PriorityQueue()
    {
        delete[] arr;
    }
};

int main() {
    Student Rustem("Rustem", "Memmedov", 31, 56);
    Student Islam("Islam", "Salamzade", 42, 100);
    Student Namiq("Namiq", "Rasullu", 56, 98);
    PriorityQueue<Student> sira(5);
    sira.Push(Rustem);
    sira.Push(Islam);
    sira.Push(Namiq);
    sira.Print();
    sira.Pop();
    sira.Print();
    sira.Pop();
    sira.Print();

}