#pragma once

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

class MemoryFullException :public Exception {

public:
	MemoryFullException(string txt, int line, string source) : Exception(txt, line, source) {
	}
};

class FileNotFoundException :public Exception {

public:
	FileNotFoundException(string txt, int line, string source) : Exception(txt, line, source) {
	}
};

class FileAlreadyExistsException :public Exception {

public:
	FileAlreadyExistsException(string txt, int line, string source) : Exception(txt, line, source) {
	}
};



