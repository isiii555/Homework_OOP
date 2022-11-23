#pragma once
#include "ClassExceptions.h"

class Disc {
	double current_size = 0;

	class File {

		double file_size;

	public:

		string filename;
		string content;

		File(string name, string cont = "") {
			filename = name;
			content = cont;
			file_size = cont.length();
		}

		double getfile_size() {
			return file_size;
		}
	};

	vector<File> files;
	int file_count = 0;

public:
	const static double max_size;
	double write_speed = 0;

	File& GetFile(string filename) {
		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				return files[i];
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

	virtual bool IsExistsFile(string filename) {
		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				return true;
			}
		}
		return false;
	}

	virtual void CreateFile(string filename, string content = "") {
		if (IsExistsFile(filename)) {
			throw FileAlreadyExistsException("Bele fayl movcuddur", __LINE__, "CreateFile");
		}
		else if (current_size + content.length() <= max_size)
		{
			File newFile(filename, content);
			files.push_back(newFile);
			file_count++;
			current_size += content.length();
			write_speed = double(content.length()) / 10;
			cout << "Fayl yaradilir" << "Yukleme sureti :" << write_speed;
			for (int i = 0; i < 4; i++)
			{
				Sleep(1000);
				cout << ".";
			}

		}
		else
			throw MemoryFullException("Diskde yer yoxdur", __LINE__, "CreateFile");

	}

	virtual void SetFileContent(string filename, string content = "") {
		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				current_size -= files[i].content.length();
				if (current_size + content.length() > max_size)
				{
					throw MemoryFullException("Diskde yer yoxdur", __LINE__, "CreateFile");
				}
				files[i].content = content;
				current_size += files[i].content.length();
				cout << "Fayl deyishdirilir," << "Yukleme sureti :" << write_speed;
				for (int i = 0; i < 4; i++)
				{
					Sleep(1000);
					cout << ".";
				}
				return;
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

	virtual void DeleteFileContent(string filename) {

		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				current_size -= files[i].content.length();
				files[i].content = "";
				return;
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

	virtual double CurrentSize() {
		return current_size;
	}

	virtual void ShowAllFiles() {
		for (int i = 0; i < files.size(); i++) {
			cout << "File Name : " << files[i].filename << endl
				<< "Content : " << files[i].content;
		}
	}

	virtual void DeleteByFileName(string filename) {
		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				current_size -= files[i].content.length();
				files.erase(files.begin() + i);
				return;
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

	virtual void UpdateFilename(string oldfilename, string newfilename) {
		for (int i = 0; i < files.size(); i++) {
			if (oldfilename == files[i].filename) {
				files[i].filename = newfilename;
				return;
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

	virtual void hashFile(string filename) {
		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				files[i].content.append("hash");
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

	virtual ~Disc() = 0 {
	}

};

const double Disc::max_size = 1024;
