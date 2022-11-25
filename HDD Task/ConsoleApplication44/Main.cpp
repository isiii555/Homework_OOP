#include <iostream>
#include <ctime>
#include <cstring>
#include <vector>
#include <Windows.h>
using namespace std;
#include "ClassExceptions.h"
#include "SSD.h"
#include "HDD.h"

const double HDD::max_size = 1024;
const double SSD::max_size = 1024;

class OperationSystem {
	OperationSystem() {}
public:
	static void controlPC();
};

void OperationSystem::controlPC() {
	HDD hd;
	SSD ssd;
	try
	{
		hd.CreateFile("newtext.txt", "hello world");
		hd.hashFile("newtext.txt");
		hd.ShowAllFiles();
		ssd.CreateFile("newtext.txt", "hello");
		ssd.DeleteByFileName("newtext.txt");
		ssd.ShowAllFiles();
	}
	catch (Exception& ex)
	{
		ex.Message();
	}


}

int main() {
	OperationSystem::controlPC();
}
