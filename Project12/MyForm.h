#pragma once
#include "Tabla_Forms.h"
#include "Table.h"

namespace Project12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			Nro_column = 0;
			formsTabla = gcnew Tabla_Forms();
			table = new Table;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ ColumnName;
	private: System::Windows::Forms::ComboBox^ ComboTipo;
	protected:

	private: System::Windows::Forms::Label^ ColumnType;
	private: System::Windows::Forms::TextBox^ TxtColumnName;
	private: System::Windows::Forms::Button^ ButtonColumnName;
	private: System::Windows::Forms::Label^ nameTable;
	private: System::Windows::Forms::TextBox^ TxtTableName;
	private: System::Windows::Forms::Button^ ButtonTableName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ TxtNroColumn;
	private: System::Windows::Forms::Button^ button1;

	private: System::ComponentModel::IContainer^ components;



	protected:




	private:
		Table* table;
		int Nro_column;

	private: System::Windows::Forms::Label^ SavedTitle;
	private: System::Windows::Forms::TextBox^ Dato;




		   Tabla_Forms^ formsTabla;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ColumnName = (gcnew System::Windows::Forms::Label());
			this->ComboTipo = (gcnew System::Windows::Forms::ComboBox());
			this->ColumnType = (gcnew System::Windows::Forms::Label());
			this->TxtColumnName = (gcnew System::Windows::Forms::TextBox());
			this->ButtonColumnName = (gcnew System::Windows::Forms::Button());
			this->nameTable = (gcnew System::Windows::Forms::Label());
			this->TxtTableName = (gcnew System::Windows::Forms::TextBox());
			this->ButtonTableName = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TxtNroColumn = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SavedTitle = (gcnew System::Windows::Forms::Label());
			this->Dato = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ColumnName
			// 
			this->ColumnName->AutoSize = true;
			this->ColumnName->Location = System::Drawing::Point(144, 68);
			this->ColumnName->Name = L"ColumnName";
			this->ColumnName->Size = System::Drawing::Size(96, 17);
			this->ColumnName->TabIndex = 0;
			this->ColumnName->Text = L"Column Name";
			// 
			// ComboTipo
			// 
			this->ComboTipo->FormattingEnabled = true;
			this->ComboTipo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"numbers", L"words", L"letters" });
			this->ComboTipo->Location = System::Drawing::Point(12, 88);
			this->ComboTipo->Name = L"ComboTipo";
			this->ComboTipo->Size = System::Drawing::Size(121, 24);
			this->ComboTipo->TabIndex = 1;
			// 
			// ColumnType
			// 
			this->ColumnType->AutoSize = true;
			this->ColumnType->Location = System::Drawing::Point(13, 68);
			this->ColumnType->Name = L"ColumnType";
			this->ColumnType->Size = System::Drawing::Size(40, 17);
			this->ColumnType->TabIndex = 2;
			this->ColumnType->Text = L"Type";
			// 
			// TxtColumnName
			// 
			this->TxtColumnName->Location = System::Drawing::Point(147, 88);
			this->TxtColumnName->Name = L"TxtColumnName";
			this->TxtColumnName->Size = System::Drawing::Size(154, 22);
			this->TxtColumnName->TabIndex = 3;
			// 
			// ButtonColumnName
			// 
			this->ButtonColumnName->Location = System::Drawing::Point(434, 88);
			this->ButtonColumnName->Name = L"ButtonColumnName";
			this->ButtonColumnName->Size = System::Drawing::Size(75, 23);
			this->ButtonColumnName->TabIndex = 4;
			this->ButtonColumnName->Text = L"Add";
			this->ButtonColumnName->UseVisualStyleBackColor = true;
			this->ButtonColumnName->Click += gcnew System::EventHandler(this, &MyForm::ButtonColumnName_Click);
			// 
			// nameTable
			// 
			this->nameTable->AutoSize = true;
			this->nameTable->Location = System::Drawing::Point(10, 13);
			this->nameTable->Name = L"nameTable";
			this->nameTable->Size = System::Drawing::Size(93, 17);
			this->nameTable->TabIndex = 5;
			this->nameTable->Text = L"Table\'s name";
			// 
			// TxtTableName
			// 
			this->TxtTableName->Location = System::Drawing::Point(14, 34);
			this->TxtTableName->Name = L"TxtTableName";
			this->TxtTableName->Size = System::Drawing::Size(206, 22);
			this->TxtTableName->TabIndex = 6;
			// 
			// ButtonTableName
			// 
			this->ButtonTableName->Location = System::Drawing::Point(226, 33);
			this->ButtonTableName->Name = L"ButtonTableName";
			this->ButtonTableName->Size = System::Drawing::Size(75, 23);
			this->ButtonTableName->TabIndex = 7;
			this->ButtonTableName->Text = L"Add";
			this->ButtonTableName->UseVisualStyleBackColor = true;
			this->ButtonTableName->Click += gcnew System::EventHandler(this, &MyForm::ButtonTableName_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(515, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"N Columns:";
			// 
			// TxtNroColumn
			// 
			this->TxtNroColumn->Location = System::Drawing::Point(605, 91);
			this->TxtNroColumn->Name = L"TxtNroColumn";
			this->TxtNroColumn->Size = System::Drawing::Size(84, 18);
			this->TxtNroColumn->TabIndex = 8;
			this->TxtNroColumn->Text = L"0";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Location = System::Drawing::Point(12, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(798, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Create Table";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// SavedTitle
			// 
			this->SavedTitle->AutoSize = true;
			this->SavedTitle->Location = System::Drawing::Point(345, 22);
			this->SavedTitle->Name = L"SavedTitle";
			this->SavedTitle->Size = System::Drawing::Size(83, 17);
			this->SavedTitle->TabIndex = 10;
			this->SavedTitle->Text = L"Saved Title:";
			// 
			// Dato
			// 
			this->Dato->Location = System::Drawing::Point(317, 88);
			this->Dato->Name = L"Dato";
			this->Dato->Size = System::Drawing::Size(100, 22);
			this->Dato->TabIndex = 11;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 169);
			this->Controls->Add(this->Dato);
			this->Controls->Add(this->SavedTitle);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->TxtNroColumn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ButtonTableName);
			this->Controls->Add(this->TxtTableName);
			this->Controls->Add(this->nameTable);
			this->Controls->Add(this->ButtonColumnName);
			this->Controls->Add(this->TxtColumnName);
			this->Controls->Add(this->ColumnType);
			this->Controls->Add(this->ComboTipo);
			this->Controls->Add(this->ColumnName);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void time1(System::Object^ sender, System::EventArgs^ e) {


	}
private: System::Void ButtonColumnName_Click(System::Object^ sender, System::EventArgs^ e) {
	Nro_column += 1;
	TxtNroColumn->Text = Nro_column.ToString();
	DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
	CHeader->HeaderText = TxtColumnName->Text;
	formsTabla->Tabla->Columns->Add(CHeader);
	string type;
	string dato;
	MarshalString(ComboTipo->Text, type);
	MarshalString(Dato->Text, dato);
	table->AddColumn(type);
	table->getColumns()->getColumn(Nro_column - 1)->Add(dato);
	TxtColumnName->Text = "";
	ComboTipo->Text = "";
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
	formsTabla->setTable(this->table);
	formsTabla->Show();
}
private: System::Void ButtonTableName_Click(System::Object^ sender, System::EventArgs^ e) {
	SavedTitle->Text = "Saved Title:";
	formsTabla->TitleTable->Text = TxtTableName->Text;
	SavedTitle->Text = SavedTitle->Text + " " + TxtTableName->Text;
	TxtTableName->Text = "";
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: void MarshalString ( String ^ s, string& os ) {
   using namespace Runtime::InteropServices;
   const char* chars =
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

};
}
