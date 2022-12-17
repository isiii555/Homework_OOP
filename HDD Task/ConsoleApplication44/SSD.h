#pragma once
#include "Disc.h"

class SSD : public Disc {
	const static double max_size;
public:

	void CreateFile(string filename, string content = "") override{
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
			cout << "Fayl yaradilir" << endl << "Yukleme sureti(SSD) : " << write_speed * 10<< " MB/s ";
			for (int i = 0; i < 4; i++)
			{
				Sleep(1000);
				cout << ".";
			}
			cout << endl;
		}
		else
			throw MemoryFullException("Diskde yer yoxdur", __LINE__, "CreateFile");

	}

	void SetFileContent (string filename, string content = "") override {
		for (int i = 0; i < files.size(); i++) {
			if (filename == files[i].filename) {
				current_size -= files[i].content.length();
				if (current_size + content.length() > max_size)
				{
					throw MemoryFullException("Diskde yer yoxdur", __LINE__, "CreateFile");
				}
				files[i].content = content;
				current_size += files[i].content.length();
				cout << "Fayl deyishdirilir" << endl << "Yukleme sureti(SSD) : " << write_speed * 10 << " MB/s ";
				for (int i = 0; i < 4; i++)
				{
					Sleep(1000);
					cout << ".";
				}
				cout << endl;
				return;
			}
		}
		throw FileNotFoundException("File tapilmadi", __LINE__, "GetFile");
	}

};