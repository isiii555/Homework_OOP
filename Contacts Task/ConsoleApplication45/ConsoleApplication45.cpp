#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Contact {

public:

	string name = "";
	string surname = "";
	string number = "";

	Contact(string n,string s,string num) {

		name = n;
		surname = s;
		number = num;
	}

};

class Database {

	vector<Contact> contacts;

public:

	void AddContact(Contact& val) {
		contacts.push_back(val);
		fstream file("Contacts.txt", ios::app);
		if (!file.is_open()) {
			file.open("Contacts.txt", ios::app);
		}

		file << val.name << endl;
		file << val.surname << endl;
		file << val.number << endl;

		file.close();

	}

	bool SearchByName(string name) {
		fstream file("Contacts.txt",ios::in);
		string temp;
		if (file.is_open()) {
			while (!file.eof()) {
				file >> temp;
				if (temp == name) {
					file.close();
					return true;
				}
				else {
					file.close();
					return false;
				}
			}
		}
	}

	void DeleteByName(string name) {
		string temp;
		if (SearchByName(name)) {
			fstream temp("temp.txt", ios::app);
			for (int i = 0; i < contacts.size(); i++)
			{
				if (contacts[i].name == name) {
					contacts.erase(contacts.begin() + i);
					break;
				}
			}
			for (int i = 0; i < contacts.size() ; i++)
			{
				temp << contacts[i].name << endl;
				temp << contacts[i].surname << endl;
				temp << contacts[i].number << endl;
				temp.close();
			}
			temp.close();
			remove("Contacts.txt");
			int num = rename("temp.txt", "Contacts.txt");
		}
		else
			throw "There is no file with this name";
	}


};

int main() {
	Contact islam("islam", "salamzade", "0707260043");

	Database dt;
	dt.AddContact(islam);
	cout << dt.SearchByName("islam");
	dt.AddContact(islam);
	cout << dt.SearchByName("islam");
	dt.DeleteByName("islam");
	dt.DeleteByName("islam");
	cout << dt.SearchByName("islam");
	dt.AddContact(islam);
}