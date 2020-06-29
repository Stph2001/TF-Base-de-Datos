#pragma once
#include "ArrayColumn.h"
#include <conio.h>
using namespace System;
class Table
{
private:
	ArrayColumn* columns;

public:
	Table(){
		columns = new ArrayColumn();
	}
	~Table(){
	}
	void AddColumn(string type){
		columns->AddColumn(type);
	}
	void PrintColumn(int pos) {
		columns->getColumn(pos)->Print();
	}
	void Comprobar() {

		int op = 3;
		while (op != 0) {
			Console::Clear();
			cout << "Ingrese opcion: ";
			cout << "\n\n[1] Agregar Columna";
			cout << "\n\n[2] Agregar Dato";
			cout << "\n\n[3] Imprimir Columna\n\n";
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
					columns->getColumn(indice)->Add(tipo2);
				}
				else if (tipo == "words"){
					cin >> tipo;
					columns->getColumn(indice)->Add(tipo);
				}
				else{
					cin >> tipo1;
					columns->getColumn(indice)->Add(tipo1);
				}
				
			}
			else {
				int indice = -1;
				cout << "Ingrese indice de columna: ";
				cin >> indice;
				PrintColumn(indice);
				_getch();
			}
		}
	}
	ArrayColumn* getColumns() { return columns; }
};

