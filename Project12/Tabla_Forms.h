#pragma once
#include <iostream>
#include "Table.h"

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
	public: System::Windows::Forms::DataGridView^ Tabla;
	public: System::Windows::Forms::Label^ TitleTable;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	protected:

	protected:

	private:
		Table* table;
		System::ComponentModel::Container ^components;

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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->BeginInit();
			this->SuspendLayout();
			// 
			// Tabla
			// 
			this->Tabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla->Location = System::Drawing::Point(12, 123);
			this->Tabla->Name = L"Tabla";
			this->Tabla->RowHeadersWidth = 51;
			this->Tabla->RowTemplate->Height = 24;
			this->Tabla->Size = System::Drawing::Size(1357, 348);
			this->Tabla->TabIndex = 0;
			this->Tabla->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Tabla_Forms::Table_KeyDown);
			// 
			// TitleTable
			// 
			this->TitleTable->AutoSize = true;
			this->TitleTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TitleTable->Location = System::Drawing::Point(670, 9);
			this->TitleTable->Name = L"TitleTable";
			this->TitleTable->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->TitleTable->Size = System::Drawing::Size(40, 17);
			this->TitleTable->TabIndex = 1;
			this->TitleTable->Text = L"Title";
			this->TitleTable->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Options:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Tabla_Forms::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(96, 53);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(96, 82);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(177, 53);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(177, 82);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// Tabla_Forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1381, 483);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleTable);
			this->Controls->Add(this->Tabla);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			this->Load += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Tabla_Forms_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void Table_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
		   public: void setTable(Table *t){
			   table = t;
		   }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			table->Comprobar();

}
};
}
