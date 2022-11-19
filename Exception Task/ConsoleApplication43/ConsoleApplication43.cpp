#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstring>

using namespace std;

class Exception {
	string text;
	int line;
	string source;
	time_t now = time(0);
#pragma warning(disable: 4996)
	char* d = asctime(localtime(&now));
	
public:

	Exception(string txt, int line, string source) {
		text = txt;
		this->line = line;
		source = source;
	}

	void Message() const { 
		cout << text << " " << line << " " << source << d << endl;
	}
};

class DatabaseException :public Exception {

public:
	DatabaseException(string txt, int line, string source) : Exception(txt, line, source) {
	}
};
class InvalidArgumentException :public Exception {

public:
	InvalidArgumentException(string txt, int line, string source) : Exception(txt, line, source) {
	}
};

class User {
	string username;
	string password;
	string name;
	string surname;

public:
	User() {
	}

	User(string user, string pass, string namee, string surnamee) {
		username = user;
		password = pass;
		name = namee;
		surname = surnamee;
	}

	string GetUsername() const{
		return username;
	}

	string GetName() const {
		return name;
	}

	string GetPassword() const {
		return password;
	}

	string GetSurname() const {
		return surname;
	}

	void Show() const {
		cout << "Username : " << username
			<< "\nName : " << name
			<< "\nSurname : " << surname << endl;
	}

	bool operator==(User& oth) {
		if (oth.GetName() == name && oth.GetPassword() == password && oth.GetUsername() == username && oth.GetSurname() == surname)
		{
			return true;
		}
		else
			return false;
	}
};

class Database {
	User** users = nullptr;
	int user_count = 0;
public:
	void AddUser(const User& user) {
		User** temp = new User * [user_count + 1];
		for (int i = 0; i < user_count; i++)
		{
			temp[i] = users[i];
		}
		temp[user_count] = new User(user.GetUsername(), user.GetPassword(), user.GetName(), user.GetSurname());
		user_count++;
		users = temp;
		temp = nullptr;
	}

	void ShowUsers() {
		for (int i = 0; i < user_count; i++)
		{
			users[i]->Show();
		}
	}
	User& GetUserByUsername(string username) {
		if (user_count > 0)
		{
			for (int i = 0; i < user_count; i++)
			{
				if (username == users[i]->GetUsername()) {
					return *users[i];
				}
				else
					throw DatabaseException("Bazada istifadeci yoxdur", __LINE__, "GetUserByUsername");
			}
		}
		else
		{
			throw DatabaseException("Bazada istifadeci yoxdur", __LINE__, "GetUserByUsername");
		}
	}

	void UpdateUser(User& olduser, const User& newuser) {
		for (int i = 0; i < user_count; i++)
		{
			if (*users[i] == olduser)
			{
				delete users[i];
				users[i] = new User(newuser.GetUsername(),newuser.GetPassword(),newuser.GetName(),newuser.GetSurname());
			}
		}
	}

	void DeleteUserById(const int& id) {
		if (id < user_count + 1 && user_count != 0) {
			User** temp = new User * [user_count - 1];
			for (int i = 0; i < id - 1; i++)
			{
				temp[i] = users[i];
			}
			for (int i = id - 1; i < user_count; i++)
			{
				temp[i] = users[i + 1];
			}
			user_count--;
			users = temp;
			temp = nullptr;
		}
		else
			throw InvalidArgumentException("Daxil etdiyiniz ID bazada tapilmadi!", __LINE__, "DeleteUserById");
	}

	void hashUserDataById(const int& id) {
		if (id < user_count + 1 && user_count != 0) {
			User temphash((users[id - 1]->GetUsername()).append("hashed"), (users[id - 1]->GetPassword()).append("hashed"), (users[id - 1]->GetName()).append("hashed"), (users[id - 1]->GetSurname()).append("hashed"));
			UpdateUser(*users[id - 1], temphash);
		}
		else
			throw InvalidArgumentException("Daxil etdiyiniz ID bazada tapilmadi!", __LINE__, "DeleteUserById");
	}

	bool FindUserByUsername(string username) {
		if (user_count > 0)
		{
			for (int i = 0; i < user_count; i++)
			{
				if (username == users[i]->GetUsername()) {
					return true;
				}
				else
					return false;
			}
		}
		else
		{
			return false;
		}
	}
};

class Registration {
	Database _database;
public:
	Registration(const Database& database) {
		_database = database;
	}

	Database& getDatabase() {
		return _database;
	}

	void SignIn(string username, string password) {
		if (_database.FindUserByUsername(username)) {

			User temp = _database.GetUserByUsername(username);
			if (temp.GetPassword() == password)
			{
				cout << "Success!";
			}
			else
				throw DatabaseException("Password yalnishdir", __LINE__, "SignIn");
		}
		else {
			cout << "Username yalnishdir!";
		}
	}

	void SignUp(string username, string password, string name, string surname) {
		if (_database.FindUserByUsername(username)) {
			throw DatabaseException("Bele username movcuddur!", __LINE__, "SignUp");
		}
		if (username.length() < 6)
		{
			throw InvalidArgumentException("Username xarakter sayi 6dan kichik ola bilmez !", __LINE__, "SignUp");
		}
		if (username[0] != toupper(username[0])) {
			throw InvalidArgumentException("Usernamenin ilk herfi boyuk olmalidir!", __LINE__, "SignUp");
		}
		if (password.length() < 6) {
			throw InvalidArgumentException("Passwordun xarakter sayi 6dan kichik ola bilmez!", __LINE__, "SignUp");
		}
		if (name.length() < 4) {
			throw InvalidArgumentException("Namenin xarakter sayi 4den kichik ola bilmez!", __LINE__, "SignUp");
		}
		if (surname.length() < 4) {
			throw InvalidArgumentException("Surnamenin xarakter sayi 4den kichik ola bilmez ", __LINE__, "SignUp");
		}
	}
};

class System {
public:
	static void Control() {
		try {
			Database db;
			User Islam("Isii555", "islam123", "Islam", "Salamzade");
			Registration twitter(db);
			twitter.getDatabase().AddUser(Islam);
			twitter.SignIn("Isii555", "islam124");
		}
		catch (Exception& ex) {
			ex.Message();
		}
	}

};


int main() {
	System::Control();
}