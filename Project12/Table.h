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

public:
	Table(){
		charColumns = nullptr;
		stringColumns = nullptr;
		doubleColumns = nullptr;
	}
	~Table(){
	}
	void AddColumn(string type, string nameColumn) {
		if (type == "letters") {
			if (charColumns == nullptr) 
				generateCharColumn();
			charColumns->AddColumn(nameColumn);
		}
		else if (type == "words") {
			if (stringColumns == nullptr) 
				generateStringColumn();
			stringColumns->AddColumn(nameColumn);
		}
		else if (type == "numbers") {
			if (doubleColumns == nullptr) 
				generateDoubleColumn();
			doubleColumns->AddColumn(nameColumn);
		}
	}
	void PrintColumn(string type, string nameColumn) {
		if (type == "letters")
			charColumns->getColumn(nameColumn)->Print();
		if (type == "words")
			stringColumns->getColumn(nameColumn)->Print();
		if (type == "numbers")
			doubleColumns->getColumn(nameColumn)->Print();
	}


	char Search(char elem, string nameColumn){ return charColumns->Search(elem, nameColumn); }
	string Search(string elem, string nameColumn) { return stringColumns->Search(elem, nameColumn); }
	double Search(double elem, string nameColumn) { return doubleColumns->Search(elem, nameColumn); }

	list<char>* Equals(char elem, string nameColumn){ return charColumns->Equals(elem, nameColumn); }
	list<string>* Equals(string elem, string nameColumn) { return stringColumns->Equals(elem, nameColumn); }
	list<double>* Equals(double elem, string nameColumn) { return doubleColumns->Equals(elem, nameColumn); }

	list<char>* GreaterThan(char elem, string nameColumn){ return charColumns->GreaterThan(elem, nameColumn); }
	list<string>* GreaterThan(string elem, string nameColumn) { return stringColumns->GreaterThan(elem, nameColumn); }
	list<double>* GreaterThan(double elem, string nameColumn) { return doubleColumns->GreaterThan(elem, nameColumn); }

	list<char>* LessThan(char elem, string nameColumn){ return charColumns->LessThan(elem, nameColumn); }
	list<string>* LessThan(string elem, string nameColumn) { return stringColumns->LessThan(elem, nameColumn); }
	list<double>* LessThan(double elem, string nameColumn) { return doubleColumns->LessThan(elem, nameColumn); }

	list<char>* ContainsChar(string searcher, string nameColumn) { return charColumns->Contains(searcher, nameColumn); }
	list<string>* ContainsString(string searcher, string nameColumn) { return stringColumns->Contains(searcher, nameColumn); }
	list<double>* ContainsDouble(string searcher, string nameColumn) { return doubleColumns->Contains(searcher, nameColumn); }

	list<char>* NotContainsChar(string searcher, string nameColumn) { return charColumns->NotContains(searcher, nameColumn); }
	list<string>* NotContainsString(string searcher, string nameColumn) { return stringColumns->NotContains(searcher, nameColumn); }
	list<double>* NotContainsDouble(string searcher, string nameColumn) { return doubleColumns->NotContains(searcher, nameColumn); }

	list<char>* StartWithChar(string searcher, string nameColumn) { return charColumns->StartWith(searcher, nameColumn); }
	list<string>* StartWithString(string searcher, string nameColumn) { return stringColumns->StartWith(searcher, nameColumn); }
	list<double>* StartWithDouble(string searcher, string nameColumn) { return doubleColumns->StartWith(searcher, nameColumn); }

	list<char>* EndWithChar(string searcher, string nameColumn) { return charColumns->EndWith(searcher, nameColumn); }
	list<string>* EndWithString(string searcher, string nameColumn) { return stringColumns->EndWith(searcher, nameColumn); }
	list<double>* EndWithDouble(string searcher, string nameColumn) { return doubleColumns->EndWith(searcher, nameColumn); }

	list<char>* InOrderChar(string nameColumn) { return charColumns->InOrder(nameColumn); }
	list<string>* InOrderString(string nameColumn) { return stringColumns->InOrder(nameColumn); }
	list<double>* InOrderDouble(string nameColumn) { return doubleColumns->InOrder(nameColumn); }

	list<char>* InReverseChar(string nameColumn) { return charColumns->InReverse(nameColumn); }
	list<string>* InReverseString(string nameColumn) { return stringColumns->InReverse(nameColumn); }
	list<double>* InReverseDouble(string nameColumn) { return doubleColumns->InReverse(nameColumn); }

	void Index(string type, string nameColumn){
		if (type == "letters")
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
		if (type == "words")
			stringColumns->IndexColumn(nameColumn,
			[](string s1,string s)->int {	//compare
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
			);
		if (type == "numbers")
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
		);
	}
	void RemoveIndex(string type, string nameColumn){
		if (type == "letters")
			charColumns->RemoveIndexColumn(nameColumn);
		if (type == "words")
			stringColumns->RemoveIndexColumn(nameColumn);
		if (type == "numbers")
			doubleColumns->RemoveIndexColumn(nameColumn);
	}
	void Comprobar() {
		Console::SetWindowSize(100, 35);
		int op = 3;
		while (op != 0) {
			Console::Clear();
			cout << "Ingrese opcion: ";
			cout << "\n\n[1] Agregar Columna";
			cout << "\n[2] Agregar Dato";
			cout << "\n[3] Imprimir Columna";
			cout << "\n[4] Indexar";
			cout << "\n[5] Quitar indexado:";
			cout << "\n[6] Buscar Dato";
			cout << "\n[7] Buscar todos los datos iguales a";
			cout << "\n[8] Buscar todos los datos mayores a:";
			cout << "\n[9] Buscar todos los datos menores a:";
			cout << "\n[10] Buscar todos los datos que contienen:";
			cout << "\n[11] Buscar todos los datos que no contienen:";
			cout << "\n[12] Buscar todos los datos que empiezan con:";
			cout << "\n[13] Buscar todos los datos que finalizan con:";
			cout << "\n[14] Ordenar ascendentemente:";
			cout << "\n[15] Ordenar descendentemente:\n\n";

			cin >> op;
			Console::Clear();
			if (op == 1) {
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de columna: ";
				cin >> tipo;
				cout << "Ingrese nombre de columna: ";
				cin >> nameColumn;
				AddColumn(tipo, nameColumn);
			}
			else if (op == 2) {
				double tipo1;
				string tipo;
				char tipo2;
				string nameColumn;
				cout << "Ingrese nombre de columna: ";
				cin >> nameColumn;
				cout << "Ingrese tipo de columna: ";
				cin >> tipo;
				cout << "Ingrese dato nuevo: ";
				if (tipo == "letters"){
					cin >> tipo2;
					charColumns->getColumn(nameColumn)->Add(tipo2);
				}
				else if (tipo == "words"){
					cin >> tipo;
					stringColumns->getColumn(nameColumn)->Add(tipo);
				}
				else{
					cin >> tipo1;
					doubleColumns->getColumn(nameColumn)->Add(tipo1);
				}
				
			}
			else if (op == 3) {
				string nameColumn;
				string tipo;
				cout << "Ingrese nombre de columna: ";
				cin >> nameColumn;
				cout << "Ingrese tipo de columna: ";
				cin >> tipo;
				PrintColumn(tipo, nameColumn);
				_getch();
			}
			else if (op == 4) {
				string ty;
				string nameColumn;
				char t;
				cout << "Desea indexar? (S / N) ";
				cin >> t; t = toupper(t);
				if (t == 'S') {
					cout << "Ingrese tipo de columna: ";
					cin >> ty;
					cout << "Ingrese nombre de columna: ";
					cin >> nameColumn;
					Index(ty, nameColumn);
				}
				_getch();
			}
			else if (op == 5) {
				string ty;
				string nameColumn;
				char t;
				cout << "Desea quitar indexado? (S / N) ";
				cin >> t; t = toupper(t);
				if (t == 'S') {
					cout << "Ingrese tipo de columna: ";
					cin >> ty;
					cout << "Ingrese nombre de columna: ";
					cin >> nameColumn;
					RemoveIndex(ty, nameColumn);
				}
				_getch();
			}
			else if (op == 6){
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese nombre de la columna: ";
				cin >> nameColumn;
				cout << "Ingrese dato: ";
				if (tipo == "words"){
					string t;
					cin >> t;
					cout<<"\n"<<Search(t, nameColumn);
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					cout<<"\n"<<Search(c, nameColumn);
				}
				else{
					double d;
					cin >> d;
					cout<<"\n"<<Search(d, nameColumn);
				}
				_getch();
			}
			else if (op == 7){
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese nombre de la columna: ";
				cin >> nameColumn;
				cout << "Ingrese dato: ";
				if (tipo == "words"){
					string t;
					cin >> t;
					for (string s : *Equals(t, nameColumn)){
						cout << s << " ";
					}
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					for (char s : *Equals(c, nameColumn)){
						cout << s << " ";
					}
				}
				else{
					double d;
					cin >> d;
					for (double s : *Equals(d, nameColumn)){
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 8){
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese nombre de la columna: ";
				cin >> nameColumn;
				cout << "Ingrese dato para buscar mayores: \n";
				if (tipo == "words"){
					string t;
					cin >> t;
					for (string s : *GreaterThan(t, nameColumn)){
						cout << s << " ";
					}
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					for (char s : *GreaterThan(c, nameColumn)){
						cout << s << " ";
					}
				}
				else{
					double d;
					cin >> d;
					for (double s : *GreaterThan(d, nameColumn)){
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 9){
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese nombre de la columna: ";
				cin >> nameColumn;
				cout << "Ingrese dato para buscar menores: \n";
				if (tipo == "words"){
					string t;
					cin >> t;
					for (string s : *LessThan(t, nameColumn)){
						cout << s << " ";
					}
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					for (char s : *LessThan(c, nameColumn)){
						cout << s << " ";
					}
				}
				else{
					double d;
					cin >> d;
					for (double s : *LessThan(d, nameColumn)){
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 10) {
			string tipo;
			string nameColumn;
			cout << "Ingrese tipo de dato a buscar: ";
			cin >> tipo;
			cout << "Ingrese nombre de la columna: ";
			cin >> nameColumn;
			cout << "Ingrese el dato para buscar si esta contenido entre los otros datos: \n";
			if (tipo == "words") {
				string t;
				cin >> t;
				for (string s : *ContainsString(t, nameColumn)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				string c;
				cin >> c;
				for (char s : *ContainsChar(c, nameColumn)) {
					cout << s << " ";
				}
			}
			else {
				string d;
				cin >> d;
				for (double s : *ContainsDouble(d, nameColumn)) {
					cout << s << " ";
				}
			}
			_getch();
			}
			else if (op == 11) {
			string tipo;
			string nameColumn;
			cout << "Ingrese tipo de dato a buscar: ";
			cin >> tipo;
			cout << "Ingrese nombre de la columna: ";
			cin >> nameColumn;
			cout << "Ingrese el dato para buscar si no esta contenido entre los otros datos: \n";
			if (tipo == "words") {
				string t;
				cin >> t;
				for (string s : *NotContainsString(t, nameColumn)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				string c;
				cin >> c;
				for (char s : *NotContainsChar(c, nameColumn)) {
					cout << s << " ";
				}
			}
			else {
				string d;
				cin >> d;
				for (double s : *NotContainsDouble(d, nameColumn)) {
					cout << s << " ";
				}
			}
			_getch();
			}
			else if (op == 12) {
			string tipo;
			string nameColumn;
			cout << "Ingrese tipo de dato a buscar: ";
			cin >> tipo;
			cout << "Ingrese nombre de la columna: ";
			cin >> nameColumn;
			cout << "Ingrese el dato inicial para buscar entre los datos: \n";
			if (tipo == "words") {
				string t;
				cin >> t;
				for (string s : *StartWithString(t, nameColumn)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				string c;
				cin >> c;
				for (char s : *StartWithChar(c, nameColumn)) {
					cout << s << " ";
				}
			}
			else {
				string d;
				cin >> d;
				for (double s : *StartWithDouble(d, nameColumn)) {
					cout << s << " ";
				}
			}
			_getch();
			}
			else if (op == 13) {
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese nombre de la columna: ";
				cin >> nameColumn;
				cout << "Ingrese el dato final para buscar entre los datos: \n";
				if (tipo == "words") {
					string t;
					cin >> t;
					for (string s : *EndWithString(t, nameColumn)) {
						cout << s << " ";
					}
				}
				else if (tipo == "letters") {
					string c;
					cin >> c;
					for (char s : *EndWithChar(c, nameColumn)) {
						cout << s << " ";
					}
				}
				else {
					string d;
					cin >> d;
					for (double s : *EndWithDouble(d, nameColumn)) {
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 14) {
				string tipo;
				string nameColumn;
				cout << "Ingrese tipo de columna a ordenar: ";
				cin >> tipo;
				cout << "Ingrese nombre de la columna: ";
				cin >> nameColumn;
				cout << "\n";
				if (tipo == "words") {
					for (string s : *InOrderString(nameColumn)) {
						cout << s << " ";
					}
				}
				else if (tipo == "letters") {
					for (char s : *InOrderChar(nameColumn)) {
						cout << s << " ";
					}
				}
				else {
					for (double s : *InOrderDouble(nameColumn)) {
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 15) {
			string tipo;
			string nameColumn;
			cout << "Ingrese tipo de columna a ordenar: ";
			cin >> tipo;
			cout << "Ingrese nombre de la columna: ";
			cin >> nameColumn;
			cout << "\n";
			if (tipo == "words") {
				for (string s : *InReverseString(nameColumn)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				for (char s : *InReverseChar(nameColumn)) {
					cout << s << " ";
				}
			}
			else {
				for (double s : *InReverseDouble(nameColumn)) {
					cout << s << " ";
				}
			}
			_getch();
			}
		}
	}
	ArrayColumn<char>* getCharColumns() { return charColumns; }
	ArrayColumn<string>* getStringColumns() { return stringColumns; }
	ArrayColumn<double>* getDoubleColumns() { return doubleColumns; }

private:
	void generateCharColumn() { charColumns = new ArrayColumn<char>(); }
	void generateStringColumn() { stringColumns = new ArrayColumn<string>(); }
	void generateDoubleColumn() { doubleColumns = new ArrayColumn<double>(); }
};

