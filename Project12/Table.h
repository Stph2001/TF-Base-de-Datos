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
	void AddColumn(string type) {
		if (type == "letters") {
			if (charColumns == nullptr) 
				generateCharColumn();
			charColumns->AddColumn();
		}
		else if (type == "words") {
			if (stringColumns == nullptr) 
				generateStringColumn();
			stringColumns->AddColumn();
		}
		else if (type == "numbers") {
			if (doubleColumns == nullptr) 
				generateDoubleColumn();
			doubleColumns->AddColumn();
		}
	}
	void PrintColumn(string type, int pos) {
		if (type == "letters")
			charColumns->getColumn(pos)->Print();
		if (type == "words")
			stringColumns->getColumn(pos)->Print();
		if (type == "numbers")
			doubleColumns->getColumn(pos)->Print();
	}


	char Search(char elem, int pos){ return charColumns->Search(elem, pos); }
	string Search(string elem, int pos) { return stringColumns->Search(elem, pos); }
	double Search(double elem, int pos) { return doubleColumns->Search(elem, pos); }

	list<char>* Equals(char elem, int pos){ return charColumns->Equals(elem, pos); }
	list<string>* Equals(string elem, int pos) { return stringColumns->Equals(elem, pos); }
	list<double>* Equals(double elem, int pos) { return doubleColumns->Equals(elem, pos); }

	list<char>* GreaterThan(char elem, int pos){ return charColumns->GreaterThan(elem, pos); }
	list<string>* GreaterThan(string elem, int pos) { return stringColumns->GreaterThan(elem, pos); }
	list<double>* GreaterThan(double elem, int pos) { return doubleColumns->GreaterThan(elem, pos); }

	list<char>* LessThan(char elem, int pos){ return charColumns->LessThan(elem, pos); }
	list<string>* LessThan(string elem, int pos) { return stringColumns->LessThan(elem, pos); }
	list<double>* LessThan(double elem, int pos) { return doubleColumns->LessThan(elem, pos); }

	list<char>* ContainsChar(string searcher, int pos) { return charColumns->Contains(searcher, pos); }
	list<string>* ContainsString(string searcher, int pos) { return stringColumns->Contains(searcher, pos); }
	list<double>* ContainsDouble(string searcher, int pos) { return doubleColumns->Contains(searcher, pos); }

	list<char>* NotContainsChar(string searcher, int pos) { return charColumns->NotContains(searcher, pos); }
	list<string>* NotContainsString(string searcher, int pos) { return stringColumns->NotContains(searcher, pos); }
	list<double>* NotContainsDouble(string searcher, int pos) { return doubleColumns->NotContains(searcher, pos); }

	list<char>* StartWithChar(string searcher, int pos) { return charColumns->StartWith(searcher, pos); }
	list<string>* StartWithString(string searcher, int pos) { return stringColumns->StartWith(searcher, pos); }
	list<double>* StartWithDouble(string searcher, int pos) { return doubleColumns->StartWith(searcher, pos); }

	list<char>* EndWithChar(string searcher, int pos) { return charColumns->EndWith(searcher, pos); }
	list<string>* EndWithString(string searcher, int pos) { return stringColumns->EndWith(searcher, pos); }
	list<double>* EndWithDouble(string searcher, int pos) { return doubleColumns->EndWith(searcher, pos); }

	list<char>* InOrderChar(int pos) { return charColumns->InOrder(pos); }
	list<string>* InOrderString(int pos) { return stringColumns->InOrder(pos); }
	list<double>* InOrderDouble(int pos) { return doubleColumns->InOrder(pos); }

	list<char>* InReverseChar(int pos) { return charColumns->InReverse(pos); }
	list<string>* InReverseString(int pos) { return stringColumns->InReverse(pos); }
	list<double>* InReverseDouble(int pos) { return doubleColumns->InReverse(pos); }

	void Index(string type, int pos){
		if (type == "letters")
			charColumns->IndexColumn(pos, 
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
			stringColumns->IndexColumn(pos, 
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
			doubleColumns->IndexColumn(pos, 
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
	void RemoveIndex(string type, int pos){
		if (type == "letters")
			charColumns->RemoveIndexColumn(pos);
		if (type == "words")
			stringColumns->RemoveIndexColumn(pos);
		if (type == "numbers")
			doubleColumns->RemoveIndexColumn(pos);
	}
	void Comprobar() {

		int op = 3;
		while (op != 0) {
			Console::Clear();
			cout << "Ingrese opcion: ";
			cout << "\n\n[1] Agregar Columna";
			cout << "\n\n[2] Agregar Dato";
			cout << "\n\n[3] Imprimir Columna";
			cout << "\n\n[4] Indexar";
			cout << "\n\n[5] Quitar indexado:";
			cout << "\n\n[6] Buscar Dato";
			cout << "\n\n[7] Buscar todos los datos iguales a";
			cout << "\n\n[8] Buscar todos los datos mayores a:";
			cout << "\n\n[9] Buscar todos los datos menores a:";
			cout << "\n\n[10] Buscar todos los datos que contienen:";
			cout << "\n\n[11] Buscar todos los datos que no contienen:";
			cout << "\n\n[12] Buscar todos los datos que empiezan con:";
			cout << "\n\n[13] Buscar todos los datos que finalizan con:";
			cout << "\n\n[14] Ordenar ascendentemente:";
			cout << "\n\n[15] Ordenar descendentemente:\n\n";

			cin >> op;
			Console::Clear();
			if (op == 1) {
				string tipo;
				cout << "Ingrese tipo de columna: ";
				cin >> tipo;
				AddColumn(tipo);
			}
			else if (op == 2) {
				double tipo1;
				string tipo;
				char tipo2;
				int indice;
				cout << "Ingrese Indice: ";
				cin >> indice;
				cout << "Ingrese tipo de columna: ";
				cin >> tipo;
				cout << "Ingrese dato nuevo: ";
				if (tipo == "letters"){
					cin >> tipo2;
					charColumns->getColumn(indice)->Add(tipo2);
				}
				else if (tipo == "words"){
					cin >> tipo;
					stringColumns->getColumn(indice)->Add(tipo);
				}
				else{
					cin >> tipo1;
					doubleColumns->getColumn(indice)->Add(tipo1);
				}
				
			}
			else if (op == 3) {
				int indice = -1;
				string tipo;
				cout << "Ingrese indice de columna: ";
				cin >> indice;
				cout << "Ingrese tipo de columna: ";
				cin >> tipo;
				PrintColumn(tipo, indice);
				_getch();
			}
			else if (op == 4) {
				string ty;
				int p;
				char t;
				cout << "Desea indexar? (S / N) ";
				cin >> t; t = toupper(t);
				if (t == 'S') {
					cout << "Ingrese tipo de columna: ";
					cin >> ty;
					cout << "Ingrese indice de columna: ";
					cin >> p;
					Index(ty, p);
				}
				_getch();
			}
			else if (op == 5) {
				string ty;
				int p;
				char t;
				cout << "Desea quitar indexado? (S / N) ";
				cin >> t; t = toupper(t);
				if (t == 'S') {
					cout << "Ingrese tipo de columna: ";
					cin >> ty;
					cout << "Ingrese indice de columna: ";
					cin >> p;
					RemoveIndex(ty, p);
				}
				_getch();
			}
			else if (op == 6){
				string tipo;
				int p;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese indice de la columna: ";
				cin >> p;
				cout << "Ingrese dato: ";
				if (tipo == "words"){
					string t;
					cin >> t;
					cout<<"\n"<<Search(t, p);
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					cout<<"\n"<<Search(c, p);
				}
				else{
					double d;
					cin >> d;
					cout<<"\n"<<Search(d, p);
				}
				_getch();
			}
			else if (op == 7){
				string tipo;
				int p;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese indice de la columna: ";
				cin >> p;
				cout << "Ingrese dato: ";
				if (tipo == "words"){
					string t;
					cin >> t;
					for (string s : *Equals(t, p)){
						cout << s << " ";
					}
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					for (char s : *Equals(c, p)){
						cout << s << " ";
					}
				}
				else{
					double d;
					cin >> d;
					for (double s : *Equals(d, p)){
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 8){
				string tipo;
				int p;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese indice de la columna: ";
				cin >> p;
				cout << "Ingrese dato para buscar mayores: \n";
				if (tipo == "words"){
					string t;
					cin >> t;
					for (string s : *GreaterThan(t, p)){
						cout << s << " ";
					}
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					for (char s : *GreaterThan(c, p)){
						cout << s << " ";
					}
				}
				else{
					double d;
					cin >> d;
					for (double s : *GreaterThan(d, p)){
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 9){
				string tipo;
				int p;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese indice de la columna: ";
				cin >> p;
				cout << "Ingrese dato para buscar menores: \n";
				if (tipo == "words"){
					string t;
					cin >> t;
					for (string s : *LessThan(t, p)){
						cout << s << " ";
					}
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					for (char s : *LessThan(c, p)){
						cout << s << " ";
					}
				}
				else{
					double d;
					cin >> d;
					for (double s : *LessThan(d, p)){
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 10) {
			string tipo;
			int p;
			cout << "Ingrese tipo de dato a buscar: ";
			cin >> tipo;
			cout << "Ingrese indice de la columna: ";
			cin >> p;
			cout << "Ingrese el dato para buscar si esta contenido entre los otros datos: \n";
			if (tipo == "words") {
				string t;
				cin >> t;
				for (string s : *ContainsString(t, p)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				string c;
				cin >> c;
				for (char s : *ContainsChar(c, p)) {
					cout << s << " ";
				}
			}
			else {
				string d;
				cin >> d;
				for (double s : *ContainsDouble(d, p)) {
					cout << s << " ";
				}
			}
			_getch();
			}
			else if (op == 11) {
			string tipo;
			int p;
			cout << "Ingrese tipo de dato a buscar: ";
			cin >> tipo;
			cout << "Ingrese indice de la columna: ";
			cin >> p;
			cout << "Ingrese el dato para buscar si no esta contenido entre los otros datos: \n";
			if (tipo == "words") {
				string t;
				cin >> t;
				for (string s : *NotContainsString(t, p)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				string c;
				cin >> c;
				for (char s : *NotContainsChar(c, p)) {
					cout << s << " ";
				}
			}
			else {
				string d;
				cin >> d;
				for (double s : *NotContainsDouble(d, p)) {
					cout << s << " ";
				}
			}
			_getch();
			}
			else if (op == 12) {
			string tipo;
			int p;
			cout << "Ingrese tipo de dato a buscar: ";
			cin >> tipo;
			cout << "Ingrese indice de la columna: ";
			cin >> p;
			cout << "Ingrese el dato inicial para buscar entre los datos: \n";
			if (tipo == "words") {
				string t;
				cin >> t;
				for (string s : *StartWithString(t, p)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				string c;
				cin >> c;
				for (char s : *StartWithChar(c, p)) {
					cout << s << " ";
				}
			}
			else {
				string d;
				cin >> d;
				for (double s : *StartWithDouble(d, p)) {
					cout << s << " ";
				}
			}
			_getch();
			}
			else if (op == 13) {
				string tipo;
				int p;
				cout << "Ingrese tipo de dato a buscar: ";
				cin >> tipo;
				cout << "Ingrese indice de la columna: ";
				cin >> p;
				cout << "Ingrese el dato final para buscar entre los datos: \n";
				if (tipo == "words") {
					string t;
					cin >> t;
					for (string s : *EndWithString(t, p)) {
						cout << s << " ";
					}
				}
				else if (tipo == "letters") {
					string c;
					cin >> c;
					for (char s : *EndWithChar(c, p)) {
						cout << s << " ";
					}
				}
				else {
					string d;
					cin >> d;
					for (double s : *EndWithDouble(d, p)) {
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 14) {
				string tipo;
				int p;
				cout << "Ingrese tipo de columna a ordenar: ";
				cin >> tipo;
				cout << "Ingrese indice de la columna: ";
				cin >> p;
				cout << "\n";
				if (tipo == "words") {
					for (string s : *InOrderString(p)) {
						cout << s << " ";
					}
				}
				else if (tipo == "letters") {
					for (char s : *InOrderChar(p)) {
						cout << s << " ";
					}
				}
				else {
					for (double s : *InOrderDouble(p)) {
						cout << s << " ";
					}
				}
				_getch();
			}
			else if (op == 15) {
			string tipo;
			int p;
			cout << "Ingrese tipo de columna a ordenar: ";
			cin >> tipo;
			cout << "Ingrese indice de la columna: ";
			cin >> p;
			cout << "\n";
			if (tipo == "words") {
				for (string s : *InReverseString(p)) {
					cout << s << " ";
				}
			}
			else if (tipo == "letters") {
				for (char s : *InReverseChar(p)) {
					cout << s << " ";
				}
			}
			else {
				for (double s : *InReverseDouble(p)) {
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

