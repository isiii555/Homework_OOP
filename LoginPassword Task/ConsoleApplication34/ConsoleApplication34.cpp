#include <iostream>
using namespace std;

class Database;

class User {

	string username;
	string password;

public:

	friend class Database;

#pragma region Constructors & Destructors

	User() {

		username = "default";
		password = "default";

	}

	User(string user,string pass) {

		username = user;
		password = pass;

	}

	User(const User& oth) {
		username = oth.username;
		password = oth.password;
	}

	User& operator=(User& other) {

		username = other.username;
		password = other.password;
		return *this;

	}

#pragma endregion

	friend istream& operator>>(istream& in, User& oth) {

		cout << "Enter username : " << endl;
		in >> oth.username;
		cout << "Enter password : " << endl;
		in >> oth.password;
		cout << "You are successfully registered.\n";
		return in;
	}

};

class Database {
	int size = 0;
	User* users = nullptr;

public:

	bool SignIn(User& user) {
		for (int i = 0; i < size; i++)
		{
			if (user.username == users->username) {
				if (user.password == users->password)
				{
					cout << "Your login was successful. You are being redirected to the main page...\n";
					return true;
				}
				else
				{
					cout << "Your password is not correct.Please check your password.\n";
					return false;
				}
			}
			else
			{
				cout << "Your username is not correct.Please check your username.\n";
				return false;
			}
		}
	}

	bool SignUp(User& user) {
		if (size != 0) {
			for (int i = 0; i < size; i++)
			{
				if (user.username == users->username)
				{
					cout << "Such username already exists.";
					return false;
				}
				else
				{
					User* temp = new User[size + 1];
					for (int i = 0; i < size; i++)
					{
						temp[i] = users[i];
					}
					temp[size] = user;
					delete[] users;
					users = temp;
					temp = nullptr;
					size++;
				}
			}
		}
		else {
			User* temp = new User[size + 1];
			for (int i = 0; i < size; i++)
			{
				temp[i] = users[i];
			}
			temp[size] = user;
			delete[] users;
			users = temp;
			temp = nullptr;
			size++;
		}
	}
};

int main() {

	Database server;
	User isi("isi555","islam191");
	User ismayil;
	cin >> ismayil;
	cout << "\n\n";
	server.SignUp(isi);
	server.SignIn(ismayil);

}

