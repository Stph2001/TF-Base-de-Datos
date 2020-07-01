#pragma once
#include <iostream>
#include "Table.h"
#include <functional>
namespace Project12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Tabla_Forms
	/// </summary>
	public ref class Tabla_Forms : public System::Windows::Forms::Form
	{
	public:
		Tabla_Forms(void)
		{
			InitializeComponent();
			table = new Table;
			nColumn = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Tabla_Forms()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ Tabla;
	private: System::Windows::Forms::Label^ TitleTable;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ Filtrar;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	protected:

	protected:

	private:
		Table* table;
		int nColumn;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ Dato;

	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ TxtNroColumn;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ ButtonTableName;
	private: System::Windows::Forms::TextBox^ TxtTableName;
	private: System::Windows::Forms::Label^ nameTable;
	private: System::Windows::Forms::Button^ ButtonColumnName;
	private: System::Windows::Forms::TextBox^ TxtColumnName;
	private: System::Windows::Forms::Label^ ColumnType;
	private: System::Windows::Forms::ComboBox^ ComboTipo;
	private: System::Windows::Forms::Label^ ColumnName;
	private: System::Windows::Forms::Label^ Datos;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Tabla = (gcnew System::Windows::Forms::DataGridView());
			this->TitleTable = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Filtrar = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Datos = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->Dato = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->TxtNroColumn = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ButtonTableName = (gcnew System::Windows::Forms::Button());
			this->TxtTableName = (gcnew System::Windows::Forms::TextBox());
			this->nameTable = (gcnew System::Windows::Forms::Label());
			this->ButtonColumnName = (gcnew System::Windows::Forms::Button());
			this->TxtColumnName = (gcnew System::Windows::Forms::TextBox());
			this->ColumnType = (gcnew System::Windows::Forms::Label());
			this->ComboTipo = (gcnew System::Windows::Forms::ComboBox());
			this->ColumnName = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// Tabla
			// 
			this->Tabla->AllowUserToAddRows = false;
			this->Tabla->AllowUserToDeleteRows = false;
			this->Tabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla->Location = System::Drawing::Point(12, 111);
			this->Tabla->Name = L"Tabla";
			this->Tabla->RowHeadersWidth = 51;
			this->Tabla->RowTemplate->Height = 24;
			this->Tabla->Size = System::Drawing::Size(1357, 276);
			this->Tabla->TabIndex = 0;
			this->Tabla->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Tabla_Forms::Table_KeyDown);
			// 
			// TitleTable
			// 
			this->TitleTable->AutoSize = true;
			this->TitleTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TitleTable->Location = System::Drawing::Point(597, 56);
			this->TitleTable->Name = L"TitleTable";
			this->TitleTable->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->TitleTable->Size = System::Drawing::Size(87, 39);
			this->TitleTable->TabIndex = 1;
			this->TitleTable->Text = L"Title";
			this->TitleTable->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Options:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Comprobar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Tabla_Forms::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(271, 24);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Filtrar
			// 
			this->Filtrar->Location = System::Drawing::Point(109, 24);
			this->Filtrar->Name = L"Filtrar";
			this->Filtrar->Size = System::Drawing::Size(75, 23);
			this->Filtrar->TabIndex = 5;
			this->Filtrar->Text = L"Filtrar";
			this->Filtrar->UseVisualStyleBackColor = true;
			this->Filtrar->Click += gcnew System::EventHandler(this, &Tabla_Forms::Filtrar_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(352, 24);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(190, 24);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(433, 24);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->Tabla);
			this->panel1->Controls->Add(this->TitleTable);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->Filtrar);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 87);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1382, 396);
			this->panel1->TabIndex = 9;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->Datos);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->Dato);
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->TxtNroColumn);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->ButtonTableName);
			this->panel2->Controls->Add(this->TxtTableName);
			this->panel2->Controls->Add(this->nameTable);
			this->panel2->Controls->Add(this->ButtonColumnName);
			this->panel2->Controls->Add(this->TxtColumnName);
			this->panel2->Controls->Add(this->ColumnType);
			this->panel2->Controls->Add(this->ComboTipo);
			this->panel2->Controls->Add(this->ColumnName);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1382, 137);
			this->panel2->TabIndex = 10;
			// 
			// Datos
			// 
			this->Datos->AutoSize = true;
			this->Datos->Location = System::Drawing::Point(573, 18);
			this->Datos->Name = L"Datos";
			this->Datos->Size = System::Drawing::Size(137, 17);
			this->Datos->TabIndex = 27;
			this->Datos->Text = L"Datos de la columna";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(768, 38);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 26;
			this->button7->Text = L"Add";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Tabla_Forms::button7_Click);
			// 
			// Dato
			// 
			this->Dato->Location = System::Drawing::Point(572, 38);
			this->Dato->Name = L"Dato";
			this->Dato->Size = System::Drawing::Size(190, 22);
			this->Dato->TabIndex = 25;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button8->Location = System::Drawing::Point(918, 30);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(338, 64);
			this->button8->TabIndex = 23;
			this->button8->Text = L"Create Table";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Tabla_Forms::button8_Click);
			// 
			// TxtNroColumn
			// 
			this->TxtNroColumn->Location = System::Drawing::Point(481, 88);
			this->TxtNroColumn->Name = L"TxtNroColumn";
			this->TxtNroColumn->Size = System::Drawing::Size(84, 18);
			this->TxtNroColumn->TabIndex = 22;
			this->TxtNroColumn->Text = L"0";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(391, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 18);
			this->label2->TabIndex = 13;
			this->label2->Text = L"N Columns:";
			// 
			// ButtonTableName
			// 
			this->ButtonTableName->Location = System::Drawing::Point(229, 29);
			this->ButtonTableName->Name = L"ButtonTableName";
			this->ButtonTableName->Size = System::Drawing::Size(75, 23);
			this->ButtonTableName->TabIndex = 21;
			this->ButtonTableName->Text = L"Add";
			this->ButtonTableName->UseVisualStyleBackColor = true;
			this->ButtonTableName->Click += gcnew System::EventHandler(this, &Tabla_Forms::ButtonTableName_Click);
			// 
			// TxtTableName
			// 
			this->TxtTableName->Location = System::Drawing::Point(17, 30);
			this->TxtTableName->Name = L"TxtTableName";
			this->TxtTableName->Size = System::Drawing::Size(206, 22);
			this->TxtTableName->TabIndex = 20;
			// 
			// nameTable
			// 
			this->nameTable->AutoSize = true;
			this->nameTable->Location = System::Drawing::Point(13, 9);
			this->nameTable->Name = L"nameTable";
			this->nameTable->Size = System::Drawing::Size(93, 17);
			this->nameTable->TabIndex = 19;
			this->nameTable->Text = L"Table\'s name";
			// 
			// ButtonColumnName
			// 
			this->ButtonColumnName->Location = System::Drawing::Point(310, 84);
			this->ButtonColumnName->Name = L"ButtonColumnName";
			this->ButtonColumnName->Size = System::Drawing::Size(75, 23);
			this->ButtonColumnName->TabIndex = 18;
			this->ButtonColumnName->Text = L"Add";
			this->ButtonColumnName->UseVisualStyleBackColor = true;
			this->ButtonColumnName->Click += gcnew System::EventHandler(this, &Tabla_Forms::ButtonColumnName_Click);
			// 
			// TxtColumnName
			// 
			this->TxtColumnName->Location = System::Drawing::Point(150, 84);
			this->TxtColumnName->Name = L"TxtColumnName";
			this->TxtColumnName->Size = System::Drawing::Size(154, 22);
			this->TxtColumnName->TabIndex = 17;
			// 
			// ColumnType
			// 
			this->ColumnType->AutoSize = true;
			this->ColumnType->Location = System::Drawing::Point(16, 64);
			this->ColumnType->Name = L"ColumnType";
			this->ColumnType->Size = System::Drawing::Size(40, 17);
			this->ColumnType->TabIndex = 16;
			this->ColumnType->Text = L"Type";
			// 
			// ComboTipo
			// 
			this->ComboTipo->FormattingEnabled = true;
			this->ComboTipo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"numbers", L"words", L"letters" });
			this->ComboTipo->Location = System::Drawing::Point(15, 84);
			this->ComboTipo->Name = L"ComboTipo";
			this->ComboTipo->Size = System::Drawing::Size(121, 24);
			this->ComboTipo->TabIndex = 15;
			// 
			// ColumnName
			// 
			this->ColumnName->AutoSize = true;
			this->ColumnName->Location = System::Drawing::Point(147, 64);
			this->ColumnName->Name = L"ColumnName";
			this->ColumnName->Size = System::Drawing::Size(96, 17);
			this->ColumnName->TabIndex = 14;
			this->ColumnName->Text = L"Column Name";
			// 
			// Tabla_Forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1382, 483);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			this->Load += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Tabla_Forms_Load(System::Object^ sender, System::EventArgs^ e) {
		//this->panel2->Dock = DockStyle::Fill;
		//this->panel1->Dock = DockStyle::Fill;
	}

	private: System::Void Table_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Comprobar();
	}
	private: System::Void ButtonColumnName_Click(System::Object^ sender, System::EventArgs^ e) {
		Datos->Text = "Datos de la Columna";
		nColumn += 1;
		TxtNroColumn->Text = nColumn.ToString();
		DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
		CHeader->HeaderText = TxtColumnName->Text;
		this->Tabla->Columns->Add(CHeader);
		string type;
		MarshalString(ComboTipo->Text, type);
		table->AddColumn(type);
		TxtColumnName->Text = "";
		Datos->Text = Datos->Text + " " + nColumn;
	}
	private: System::Void ButtonTableName_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TitleTable->Text = TxtTableName->Text;
		TxtTableName->Text = "";
	}
	private: void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		setActivePanel(panel2->Name);
		panel1->Dock = DockStyle::Fill;
	}
	private: void setActivePanel(String^ panelName) {
		this->panel2->Visible = panel2->Name == panelName;
		this->panel2->Visible = panel1->Name == panelName;
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (nColumn > 0) {
			string d;
			int n = 0;
			MarshalString(Dato->Text, d);

			if (ComboTipo->Text == "letters"){
				char data = d[0];
				n = (Tabla->RowCount <= table->getCharColumns()->getColumn(table->getCharColumns()->Length() - 1)->Length() ?
					Tabla->Rows->Add() : table->getCharColumns()->getColumn(table->getCharColumns()->Length() - 1)->Length());
				table->getCharColumns()->getColumn(table->getCharColumns()->Length() - 1)->Add(data);
			}
			else if (ComboTipo->Text == "words"){
				n = (Tabla->RowCount <= table->getStringColumns()->getColumn(table->getStringColumns()->Length() - 1)->Length() ?
					Tabla->Rows->Add() : table->getStringColumns()->getColumn(table->getStringColumns()->Length() - 1)->Length());
				table->getStringColumns()->getColumn(table->getStringColumns()->Length() - 1)->Add(d);
			}
			else{
				double data = atoi(d.c_str());
				n = (Tabla->RowCount <= table->getDoubleColumns()->getColumn(table->getDoubleColumns()->Length() - 1)->Length() ?
					Tabla->Rows->Add() : table->getDoubleColumns()->getColumn(table->getDoubleColumns()->Length() - 1)->Length());
				table->getDoubleColumns()->getColumn(table->getDoubleColumns()->Length() - 1)->Add(data);
			}
			Tabla->Rows[n]->Cells[nColumn - 1]->Value = Dato->Text;
			Dato->Text = "";
		}
	}

private: System::Void Filtrar_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
