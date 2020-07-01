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


	char Search(string type, char elem, int pos){
			return charColumns->Search(elem, pos);
	}
	string Search(string type, string elem, int pos) {
		return stringColumns->Search(elem, pos);
	}
	double Search(string type, double elem, int pos) {
		return doubleColumns->Search(elem, pos);
	}
	void Index(string type, int pos){
		if (type == "letters")
			charColumns->IndexColumn(pos);
		if (type == "words")
			stringColumns->IndexColumn(pos);
		if (type == "numbers")
			doubleColumns->IndexColumn(pos);
	}
	void Comprobar() {

		int op = 3;
		while (op != 0) {
			Console::Clear();
			cout << "Ingrese opcion: ";
			cout << "\n\n[1] Agregar Columna";
			cout << "\n\n[2] Agregar Dato";
			cout << "\n\n[3] Imprimir Columna";
			cout << "\n\n[4] Imprimir Indexar";
			cout << "\n\n[5] Buscar Dato";
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
			else if (op == 5){
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
					cout<<"\n"<<Search(tipo, t, p);
				} 
				else if (tipo == "letters"){
					char c;
					cin >> c;
					cout<<"\n"<<Search(tipo, c, p);
				}
				else{
					double d;
					cin >> d;
					cout<<"\n"<<Search(tipo, d, p);
				}
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

