#pragma once
#include <iostream>
#include <conio.h>
#include <string>

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
			//
			//TODO: Add the constructor code here
			//
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
	public: System::Windows::Forms::DataGridView^ Table;
	public: System::Windows::Forms::Label^ TitleTable;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Table = (gcnew System::Windows::Forms::DataGridView());
			this->TitleTable = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->BeginInit();
			this->SuspendLayout();
			// 
			// Table
			// 
			this->Table->AllowUserToDeleteRows = false;
			this->Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table->Location = System::Drawing::Point(12, 29);
			this->Table->Name = L"Table";
			this->Table->ReadOnly = true;
			this->Table->RowHeadersWidth = 51;
			this->Table->RowTemplate->Height = 24;
			this->Table->Size = System::Drawing::Size(1357, 348);
			this->Table->TabIndex = 0;
			// 
			// TitleTable
			// 
			this->TitleTable->AutoSize = true;
			this->TitleTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TitleTable->Location = System::Drawing::Point(12, 9);
			this->TitleTable->Name = L"TitleTable";
			this->TitleTable->Size = System::Drawing::Size(40, 17);
			this->TitleTable->TabIndex = 1;
			this->TitleTable->Text = L"Title";
			// 
			// Tabla_Forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1381, 389);
			this->Controls->Add(this->TitleTable);
			this->Controls->Add(this->Table);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			this->Load += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Tabla_Forms_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
