#pragma once
#include "Tabla_Forms.h"
#include <string>

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
			//
			//TODO: Add the constructor code here
			//
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
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
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
		/// <summary>
		/// Required designer variable.
		/// </summary>
	private:
		int Nro_column;
	private: System::Windows::Forms::Label^ SavedTitle;

		   Tabla_Forms^ formsTabla;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ColumnName = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Numbers", L"Words", L"Letters" });
			this->comboBox1->Location = System::Drawing::Point(12, 88);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 1;
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
			this->ButtonColumnName->Location = System::Drawing::Point(307, 87);
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
			this->label1->Location = System::Drawing::Point(388, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"N Columns:";
			// 
			// TxtNroColumn
			// 
			this->TxtNroColumn->Location = System::Drawing::Point(478, 90);
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
			this->button1->Size = System::Drawing::Size(601, 23);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 169);
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
			this->Controls->Add(this->comboBox1);
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
	formsTabla->Table->Columns->Add(CHeader);
	TxtColumnName->Text = "";
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = false;
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
};
}
