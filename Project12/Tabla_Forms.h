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
	private: System::Windows::Forms::DataGridView^ TableDgv;
	protected:

	private: System::Windows::Forms::Label^ TitleTableTxt;

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
	private: System::Windows::Forms::Button^ AddDataColumnBtn;

	private: System::Windows::Forms::TextBox^ DataColumnTbx;
	private: System::Windows::Forms::Button^ CreateTableBtn;




	private: System::Windows::Forms::Label^ NroColumnTxt;
	private: System::Windows::Forms::Label^ NColumnsTxt;



	private: System::Windows::Forms::Button^ AddTableNameBtn;
	private: System::Windows::Forms::TextBox^ TableNameTbx;




	private: System::Windows::Forms::Label^ TableNameTxt;
	private: System::Windows::Forms::Button^ AddColumnBtn;



	private: System::Windows::Forms::TextBox^ ColumnNameTbx;


	private: System::Windows::Forms::Label^ TypeTxt;
	private: System::Windows::Forms::ComboBox^ TypeCbx;
	private: System::Windows::Forms::Label^ ColumnNameTxt;
	private: System::Windows::Forms::Label^ DataColumnTxt;
	private: System::Windows::Forms::PictureBox^ LoadingPbx;






		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Tabla_Forms::typeid));
			this->TableDgv = (gcnew System::Windows::Forms::DataGridView());
			this->TitleTableTxt = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Filtrar = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LoadingPbx = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->DataColumnTxt = (gcnew System::Windows::Forms::Label());
			this->AddDataColumnBtn = (gcnew System::Windows::Forms::Button());
			this->DataColumnTbx = (gcnew System::Windows::Forms::TextBox());
			this->CreateTableBtn = (gcnew System::Windows::Forms::Button());
			this->NroColumnTxt = (gcnew System::Windows::Forms::Label());
			this->NColumnsTxt = (gcnew System::Windows::Forms::Label());
			this->AddTableNameBtn = (gcnew System::Windows::Forms::Button());
			this->TableNameTbx = (gcnew System::Windows::Forms::TextBox());
			this->TableNameTxt = (gcnew System::Windows::Forms::Label());
			this->AddColumnBtn = (gcnew System::Windows::Forms::Button());
			this->ColumnNameTbx = (gcnew System::Windows::Forms::TextBox());
			this->TypeTxt = (gcnew System::Windows::Forms::Label());
			this->TypeCbx = (gcnew System::Windows::Forms::ComboBox());
			this->ColumnNameTxt = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadingPbx))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// TableDgv
			// 
			this->TableDgv->AllowUserToAddRows = false;
			this->TableDgv->AllowUserToDeleteRows = false;
			this->TableDgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TableDgv->Location = System::Drawing::Point(9, 74);
			this->TableDgv->Margin = System::Windows::Forms::Padding(2);
			this->TableDgv->Name = L"TableDgv";
			this->TableDgv->RowHeadersWidth = 51;
			this->TableDgv->RowTemplate->Height = 24;
			this->TableDgv->Size = System::Drawing::Size(1018, 240);
			this->TableDgv->TabIndex = 0;
			this->TableDgv->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Tabla_Forms::Table_KeyDown);
			// 
			// TitleTableTxt
			// 
			this->TitleTableTxt->AutoSize = true;
			this->TitleTableTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TitleTableTxt->Location = System::Drawing::Point(447, 41);
			this->TitleTableTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TitleTableTxt->Name = L"TitleTableTxt";
			this->TitleTableTxt->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->TitleTableTxt->Size = System::Drawing::Size(71, 31);
			this->TitleTableTxt->TabIndex = 1;
			this->TitleTableTxt->Text = L"Title";
			this->TitleTableTxt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 2);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Options:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 20);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 19);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Comprobar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Tabla_Forms::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(203, 20);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 19);
			this->button2->TabIndex = 4;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Filtrar
			// 
			this->Filtrar->Location = System::Drawing::Point(82, 20);
			this->Filtrar->Margin = System::Windows::Forms::Padding(2);
			this->Filtrar->Name = L"Filtrar";
			this->Filtrar->Size = System::Drawing::Size(56, 19);
			this->Filtrar->TabIndex = 5;
			this->Filtrar->Text = L"Filtrar";
			this->Filtrar->UseVisualStyleBackColor = true;
			this->Filtrar->Click += gcnew System::EventHandler(this, &Tabla_Forms::Filtrar_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(264, 20);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(56, 19);
			this->button4->TabIndex = 6;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(142, 20);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(56, 19);
			this->button5->TabIndex = 7;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(325, 20);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(56, 19);
			this->button6->TabIndex = 8;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->LoadingPbx);
			this->panel1->Controls->Add(this->TableDgv);
			this->panel1->Controls->Add(this->TitleTableTxt);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->Filtrar);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 70);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1028, 322);
			this->panel1->TabIndex = 9;
			// 
			// LoadingPbx
			// 
			this->LoadingPbx->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadingPbx.Image")));
			this->LoadingPbx->Location = System::Drawing::Point(986, 39);
			this->LoadingPbx->Name = L"LoadingPbx";
			this->LoadingPbx->Size = System::Drawing::Size(30, 30);
			this->LoadingPbx->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LoadingPbx->TabIndex = 9;
			this->LoadingPbx->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->DataColumnTxt);
			this->panel2->Controls->Add(this->AddDataColumnBtn);
			this->panel2->Controls->Add(this->DataColumnTbx);
			this->panel2->Controls->Add(this->CreateTableBtn);
			this->panel2->Controls->Add(this->NroColumnTxt);
			this->panel2->Controls->Add(this->NColumnsTxt);
			this->panel2->Controls->Add(this->AddTableNameBtn);
			this->panel2->Controls->Add(this->TableNameTbx);
			this->panel2->Controls->Add(this->TableNameTxt);
			this->panel2->Controls->Add(this->AddColumnBtn);
			this->panel2->Controls->Add(this->ColumnNameTbx);
			this->panel2->Controls->Add(this->TypeTxt);
			this->panel2->Controls->Add(this->TypeCbx);
			this->panel2->Controls->Add(this->ColumnNameTxt);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1028, 109);
			this->panel2->TabIndex = 10;
			// 
			// DataColumnTxt
			// 
			this->DataColumnTxt->AutoSize = true;
			this->DataColumnTxt->Location = System::Drawing::Point(430, 15);
			this->DataColumnTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->DataColumnTxt->Name = L"DataColumnTxt";
			this->DataColumnTxt->Size = System::Drawing::Size(104, 13);
			this->DataColumnTxt->TabIndex = 27;
			this->DataColumnTxt->Text = L"Datos de la columna";
			// 
			// AddDataColumnBtn
			// 
			this->AddDataColumnBtn->Location = System::Drawing::Point(576, 31);
			this->AddDataColumnBtn->Margin = System::Windows::Forms::Padding(2);
			this->AddDataColumnBtn->Name = L"AddDataColumnBtn";
			this->AddDataColumnBtn->Size = System::Drawing::Size(56, 19);
			this->AddDataColumnBtn->TabIndex = 26;
			this->AddDataColumnBtn->Text = L"Add";
			this->AddDataColumnBtn->UseVisualStyleBackColor = true;
			this->AddDataColumnBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::button7_Click);
			// 
			// DataColumnTbx
			// 
			this->DataColumnTbx->Location = System::Drawing::Point(429, 31);
			this->DataColumnTbx->Margin = System::Windows::Forms::Padding(2);
			this->DataColumnTbx->Name = L"DataColumnTbx";
			this->DataColumnTbx->Size = System::Drawing::Size(144, 20);
			this->DataColumnTbx->TabIndex = 25;
			// 
			// CreateTableBtn
			// 
			this->CreateTableBtn->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->CreateTableBtn->Location = System::Drawing::Point(688, 24);
			this->CreateTableBtn->Margin = System::Windows::Forms::Padding(2);
			this->CreateTableBtn->Name = L"CreateTableBtn";
			this->CreateTableBtn->Size = System::Drawing::Size(254, 52);
			this->CreateTableBtn->TabIndex = 23;
			this->CreateTableBtn->Text = L"Create Table";
			this->CreateTableBtn->UseVisualStyleBackColor = false;
			this->CreateTableBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::button8_Click);
			// 
			// NroColumnTxt
			// 
			this->NroColumnTxt->Location = System::Drawing::Point(361, 72);
			this->NroColumnTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NroColumnTxt->Name = L"NroColumnTxt";
			this->NroColumnTxt->Size = System::Drawing::Size(63, 15);
			this->NroColumnTxt->TabIndex = 22;
			this->NroColumnTxt->Text = L"0";
			// 
			// NColumnsTxt
			// 
			this->NColumnsTxt->Location = System::Drawing::Point(293, 71);
			this->NColumnsTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NColumnsTxt->Name = L"NColumnsTxt";
			this->NColumnsTxt->Size = System::Drawing::Size(63, 15);
			this->NColumnsTxt->TabIndex = 13;
			this->NColumnsTxt->Text = L"N Columns:";
			// 
			// AddTableNameBtn
			// 
			this->AddTableNameBtn->Location = System::Drawing::Point(172, 24);
			this->AddTableNameBtn->Margin = System::Windows::Forms::Padding(2);
			this->AddTableNameBtn->Name = L"AddTableNameBtn";
			this->AddTableNameBtn->Size = System::Drawing::Size(56, 19);
			this->AddTableNameBtn->TabIndex = 21;
			this->AddTableNameBtn->Text = L"Add";
			this->AddTableNameBtn->UseVisualStyleBackColor = true;
			this->AddTableNameBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::ButtonTableName_Click);
			// 
			// TableNameTbx
			// 
			this->TableNameTbx->Location = System::Drawing::Point(13, 24);
			this->TableNameTbx->Margin = System::Windows::Forms::Padding(2);
			this->TableNameTbx->Name = L"TableNameTbx";
			this->TableNameTbx->Size = System::Drawing::Size(156, 20);
			this->TableNameTbx->TabIndex = 20;
			// 
			// TableNameTxt
			// 
			this->TableNameTxt->AutoSize = true;
			this->TableNameTxt->Location = System::Drawing::Point(10, 7);
			this->TableNameTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TableNameTxt->Name = L"TableNameTxt";
			this->TableNameTxt->Size = System::Drawing::Size(70, 13);
			this->TableNameTxt->TabIndex = 19;
			this->TableNameTxt->Text = L"Table\'s name";
			// 
			// AddColumnBtn
			// 
			this->AddColumnBtn->Location = System::Drawing::Point(232, 68);
			this->AddColumnBtn->Margin = System::Windows::Forms::Padding(2);
			this->AddColumnBtn->Name = L"AddColumnBtn";
			this->AddColumnBtn->Size = System::Drawing::Size(56, 19);
			this->AddColumnBtn->TabIndex = 18;
			this->AddColumnBtn->Text = L"Add";
			this->AddColumnBtn->UseVisualStyleBackColor = true;
			this->AddColumnBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::ButtonColumnName_Click);
			// 
			// ColumnNameTbx
			// 
			this->ColumnNameTbx->Location = System::Drawing::Point(112, 68);
			this->ColumnNameTbx->Margin = System::Windows::Forms::Padding(2);
			this->ColumnNameTbx->Name = L"ColumnNameTbx";
			this->ColumnNameTbx->Size = System::Drawing::Size(116, 20);
			this->ColumnNameTbx->TabIndex = 17;
			// 
			// TypeTxt
			// 
			this->TypeTxt->AutoSize = true;
			this->TypeTxt->Location = System::Drawing::Point(12, 52);
			this->TypeTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TypeTxt->Name = L"TypeTxt";
			this->TypeTxt->Size = System::Drawing::Size(31, 13);
			this->TypeTxt->TabIndex = 16;
			this->TypeTxt->Text = L"Type";
			// 
			// TypeCbx
			// 
			this->TypeCbx->FormattingEnabled = true;
			this->TypeCbx->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"numbers", L"words", L"letters" });
			this->TypeCbx->Location = System::Drawing::Point(11, 68);
			this->TypeCbx->Margin = System::Windows::Forms::Padding(2);
			this->TypeCbx->Name = L"TypeCbx";
			this->TypeCbx->Size = System::Drawing::Size(92, 21);
			this->TypeCbx->TabIndex = 15;
			// 
			// ColumnNameTxt
			// 
			this->ColumnNameTxt->AutoSize = true;
			this->ColumnNameTxt->Location = System::Drawing::Point(110, 52);
			this->ColumnNameTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ColumnNameTxt->Name = L"ColumnNameTxt";
			this->ColumnNameTxt->Size = System::Drawing::Size(73, 13);
			this->ColumnNameTxt->TabIndex = 14;
			this->ColumnNameTxt->Text = L"Column Name";
			// 
			// Tabla_Forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 392);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadingPbx))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Table_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Comprobar();
	}
	private: System::Void ButtonColumnName_Click(System::Object^ sender, System::EventArgs^ e) {
		nColumn += 1;
		NroColumnTxt->Text = nColumn.ToString();
		DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
		CHeader->HeaderText = ColumnNameTbx->Text;
		this->TableDgv->Columns->Add(CHeader);
		string type;
		MarshalString(TypeCbx->Text, type);
		table->AddColumn(type);
		ColumnNameTbx->Text = "";
		DataColumnTxt->Text = "Datos de la Columna " + nColumn;
	}
	private: System::Void ButtonTableName_Click(System::Object^ sender, System::EventArgs^ e) {
		this->TitleTableTxt->Text = TableNameTbx->Text;
		TableNameTbx->Text = "";
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
			MarshalString(DataColumnTbx->Text, d);

			if (TypeCbx->Text == "letters"){
				char data = d[0];
				n = (TableDgv->RowCount <= table->getCharColumns()->getColumn(table->getCharColumns()->Length() - 1)->Length() ?
					TableDgv->Rows->Add() : table->getCharColumns()->getColumn(table->getCharColumns()->Length() - 1)->Length());
				table->getCharColumns()->getColumn(table->getCharColumns()->Length() - 1)->Add(data);
			}
			else if (TypeCbx->Text == "words"){
				n = (TableDgv->RowCount <= table->getStringColumns()->getColumn(table->getStringColumns()->Length() - 1)->Length() ?
					TableDgv->Rows->Add() : table->getStringColumns()->getColumn(table->getStringColumns()->Length() - 1)->Length());
				table->getStringColumns()->getColumn(table->getStringColumns()->Length() - 1)->Add(d);
			}
			else{
				double data = atoi(d.c_str());
				n = (TableDgv->RowCount <= table->getDoubleColumns()->getColumn(table->getDoubleColumns()->Length() - 1)->Length() ?
					TableDgv->Rows->Add() : table->getDoubleColumns()->getColumn(table->getDoubleColumns()->Length() - 1)->Length());
				table->getDoubleColumns()->getColumn(table->getDoubleColumns()->Length() - 1)->Add(data);
			}
			TableDgv->Rows[n]->Cells[nColumn - 1]->Value = DataColumnTbx->Text;
			DataColumnTbx->Text = "";
		}
	}

private: System::Void Filtrar_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
