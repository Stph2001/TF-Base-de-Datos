#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Archive
{
private:
	ofstream arch;

public:
	Archive(){}
	~Archive(){}
	void Save(double dato) {
		if (arch.is_open())
			arch << dato << endl;
	}
	void Save(char dato) {
		if (arch.is_open())
			arch << dato << endl;
	}
	void Save(string dato) {
		if (arch.is_open())
			arch << dato << endl;
	}
	void OpenArchive() {
		arch.open("tabla.txt");
	}
	void CloseArchive() {
		arch.close();
	}

};
