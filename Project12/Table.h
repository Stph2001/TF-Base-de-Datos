#pragma once
#include "ArrayColumn.h"
#include <conio.h>
using namespace System;

class Table
{
private:
	ArrayColumn<char>* charColumns;
	ArrayColumn<string>* stringColumns;
	ArrayColumn<double>* doubleColumns;
	Archive* os;

public:
	Table(){
		charColumns = nullptr;
		stringColumns = nullptr;
		doubleColumns = nullptr;
		os = new Archive();
	}
	~Table(){
	}
	void AddColumn(string type, string nameColumn) {
		if (type == "Letras") {
			if (charColumns == nullptr) 
				generateCharColumn();
			charColumns->AddColumn(nameColumn);
		}
		else if (type == "Palabras") {
			if (stringColumns == nullptr) 
				generateStringColumn();
			stringColumns->AddColumn(nameColumn);
		}
		else if (type == "Numeros") {
			if (doubleColumns == nullptr) 
				generateDoubleColumn();
			doubleColumns->AddColumn(nameColumn);
		}
	}
	int AddData(string nameColumn, string elem) {
		if (charColumns != nullptr) {
			if (charColumns->getColumn(nameColumn) != nullptr) {
				char e = elem[0];
				charColumns->getColumn(nameColumn)->Add(e);
				return charColumns->getColumn(nameColumn)->Length();
			}
		}
		if (stringColumns != nullptr) {
			if (stringColumns->getColumn(nameColumn) != nullptr) {
				stringColumns->getColumn(nameColumn)->Add(elem);
				return stringColumns->getColumn(nameColumn)->Length();
			}
		}
		if (doubleColumns != nullptr) {
			if (doubleColumns->getColumn(nameColumn) != nullptr) {
				double e = stod(elem.c_str());
				doubleColumns->getColumn(nameColumn)->Add(e);
				return doubleColumns->getColumn(nameColumn)->Length();
			}
		}
		return -1;
	}
	void PrintColumn(string type, string nameColumn) {
		if (type == "Letras" && charColumns != nullptr)
			charColumns->getColumn(nameColumn)->Print();
		if (type == "Palabras" && stringColumns != nullptr)
			stringColumns->getColumn(nameColumn)->Print();
		if (type == "Numeros" && doubleColumns != nullptr)
			doubleColumns->getColumn(nameColumn)->Print();
	}
	void Index(string nameColumn) {
		if (charColumns != nullptr) {
			if (charColumns->getColumn(nameColumn) != nullptr) {
				charColumns->IndexColumn(nameColumn,
					[](char c1, char c)->int {	//compare
						//-1 izq / 1 der / 0 igual
						if (c1 > c) return 1;
						else if (c1 < c) return -1;
						else return 0;
					},
					[](string s, char c1)->bool {	//contains
						return c1 == s[0];
					},
						[](string s, char c1)->bool {	//start with
						return c1 == s[0];
					},
						[](string s, char c1)->bool {	//end with
						return c1 == s[0];
					}
					);
				return;
			}
		}
		if (stringColumns != nullptr) {
			if (stringColumns->getColumn(nameColumn) != nullptr) {
				stringColumns->IndexColumn(nameColumn,
					[](string s1, string s)->int {	//compare
						function<int(string, string, int)> search = [&](string s3, string s4, int i)->int {
							//-1 izq / 1 der / 0 igual
							if (i > s.size() && i > s1.size()) return 0;
							else if (i > s.size()) return 1;
							else if (i > s1.size()) return -1;
							if (s1[i] > s[i]) {
								return 1;
							}
							else if (s1[i] < s[i]) {
								return -1;
							}
							else {
								return search(s1, s, ++i);
							}
						};
						return search(s1, s, 0);
					},
					[](string s1, string s)->bool {	//contains
						if (s.size() < s1.size()) return false;
						return (s.find(s1) != string::npos);
					},
						[](string s1, string s)->bool {	//start with
						if (s.size() < s1.size()) return false;
						return (s.find(s1) == 0);
					},
						[](string s1, string s)->bool {	//end with
						if (s.size() < s1.size()) return false;
						//return (s.find(s1) == s.length() - s1.length());
						return (0 == s.compare(s.length() - s1.length(), s1.length(), s1));
					}
					); return;
			}
		}
		if (doubleColumns != nullptr) {
			if (doubleColumns->getColumn(nameColumn) != nullptr) {
				doubleColumns->IndexColumn(nameColumn,
					[](double d1, double d2)->int {	//compare
						//-1 izq / 1 der / 0 igual
						if (d1 > d2) return 1;
						else if (d1 < d2) return -1;
						else return 0;
					},
					[](string s, double d1)->bool {	//contains
						string s1 = to_string(d1);
						if (s1.size() < s.size()) return false;
						return (s1.find(s) != string::npos);
					},
						[](string s, double d1)->bool {	//start with
						string s1 = to_string(d1);
						if (s1.size() < s.size()) return false;
						return (s1.find(s) == 0);
					},
						[](string s, double d1)->bool {	//end with
						int a = (int)round(d1);
						string s1;
						if (d1 - a == 0) s1 = to_string(a);
						else {	//convert from 9.458000 to 9.458
							s1 = to_string(d1);
							int lastDecimal = -1;
							for (int i = 0; i < s1.size(); i++) {
								if (s1[i] != '0') lastDecimal = -1;
								else if (s1[i] == '0' && lastDecimal == -1) lastDecimal = i;
							}
							if (lastDecimal != -1) {
								//cortar string
								char aux[50];
								strncpy(aux, s1.c_str(), lastDecimal);
								s1 = aux;
							}
						}
						if (s1.size() < s.size()) return false;
						/*return (s1.find(s) == s1.length() - s.length());*/
						return (0 == s1.compare(s1.length() - s.length(), s.length(), s));
					}
					); return;
			}
		}
	}
	void RemoveIndex(string type, string nameColumn) {
		if (type == "Letras")
			charColumns->RemoveIndexColumn(nameColumn);
		if (type == "Palabras")
			stringColumns->RemoveIndexColumn(nameColumn);
		if (type == "Numeros")
			doubleColumns->RemoveIndexColumn(nameColumn);
	}

	void Remove(char elem, string nameColumn){  charColumns->Remove(elem, nameColumn); }
	void Remove(string elem, string nameColumn) {  stringColumns->Remove(elem, nameColumn); }
	void Remove(double elem, string nameColumn) {  doubleColumns->Remove(elem, nameColumn); }

	int Search(string searcher, string nameColumn){ 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr) {
				char c = searcher[0];
				return charColumns->Search(c, nameColumn);
			}
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->Search(searcher, nameColumn);
		if(doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) {
				double d = stod(searcher.c_str());
				return doubleColumns->Search(d, nameColumn);
			}
		return -1;
	}

	list<int>* Equals(string searcher, string nameColumn){ 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr) {
				char c = searcher[0];
				return charColumns->Equals(c, nameColumn);
			}
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->Equals(searcher, nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) {
				double d = stod(searcher.c_str());
				return doubleColumns->Equals(d, nameColumn);
			}
		return new list<int>(); 
	}
	list<int>* GreaterThan(string searcher, string nameColumn){ 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr) {
				char c = searcher[0];
				return charColumns->GreaterThan(c, nameColumn);
			}
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->GreaterThan(searcher, nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) {
				double d = stod(searcher.c_str());
				return doubleColumns->GreaterThan(d, nameColumn);
			}
		return new list<int>();
	}
	list<int>* LessThan(string searcher, string nameColumn){
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr){
				char c = searcher[0];
				return charColumns->LessThan(c, nameColumn);
			}
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->LessThan(searcher, nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) {
				double d = stod(searcher.c_str());
				return doubleColumns->LessThan(d, nameColumn);
			}
		return new list<int>();
	}
	list<int>* Contains(string searcher, string nameColumn) { 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr)
				return charColumns->Contains(searcher, nameColumn);
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->Contains(searcher, nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr)
				return doubleColumns->Contains(searcher, nameColumn);
		return new list<int>();
	}
	list<int>* NotContains(string searcher, string nameColumn) { 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr)
				return charColumns->NotContains(searcher, nameColumn);
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->NotContains(searcher, nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) 
				return doubleColumns->NotContains(searcher, nameColumn);
		return new list<int>();
	 }

	list<int>* StartWith(string searcher, string nameColumn) { 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr)
				return charColumns->StartWith(searcher, nameColumn);
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->StartWith(searcher, nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) 
				return doubleColumns->StartWith(searcher, nameColumn);
		return new list<int>();
	}

	list<int>* EndWith(string searcher, string nameColumn) { 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr)
				return charColumns->EndWith(searcher, nameColumn); 
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->EndWith(searcher, nameColumn); 
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) 
				return doubleColumns->EndWith(searcher, nameColumn); 
		return new list<int>();
	}

	list<int>* InOrder(string nameColumn) { 
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr)
				return doubleColumns->InOrder(nameColumn);
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->InOrder(nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr) 
				return doubleColumns->InOrder(nameColumn);
		return new list<int>();
	}

	list<int>* InReverse(string nameColumn) {
		if (charColumns != nullptr)
			if (charColumns->getColumn(nameColumn) != nullptr)
				return charColumns->InReverse(nameColumn);
		if (stringColumns != nullptr)
			if (stringColumns->getColumn(nameColumn) != nullptr)
				return stringColumns->InReverse(nameColumn);
		if (doubleColumns != nullptr)
			if (doubleColumns->getColumn(nameColumn) != nullptr)
				return doubleColumns->InReverse(nameColumn);
		return new list<int>();
	}
	void SaveTable() {
		bool opened = false;
		if (charColumns != nullptr) {
			os->OpenArchive(); opened = true;
			charColumns->SaveDataColumn(os);
		}
		if (stringColumns != nullptr) {
			if (!opened) { os->OpenArchive(); opened = true; }
			stringColumns->SaveDataColumn(os);
		}
		if (doubleColumns != nullptr) {
			if (!opened) { os->OpenArchive(); opened = true; }
			doubleColumns->SaveDataColumn(os);
		}
		if (opened) os->CloseArchive();
	}
	ArrayColumn<char>* getCharColumns() { return charColumns; }
	ArrayColumn<string>* getStringColumns() { return stringColumns; }
	ArrayColumn<double>* getDoubleColumns() { return doubleColumns; }

private:
	void generateCharColumn() { charColumns = new ArrayColumn<char>(); }
	void generateStringColumn() { stringColumns = new ArrayColumn<string>(); }
	void generateDoubleColumn() { doubleColumns = new ArrayColumn<double>(); }
};

