#pragma once
#include <iostream>
#include "Table.h"
#include <functional>
#include <array>
namespace Project12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
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
			currentColum = 0;
			menuSpeed = 10;
			indexEnter = indexExit = -1;

			panelList.Add(AddColumnPnl);
			panelList.Add(AddDataPnl);
			panelList.Add(IndexPnl);
			panelList.Add(FilterPnl);
			panelList.Add(SaveDataPnl);

			for (int i = 0; i < MenuPnl->Controls->Count; i++) {
				MenuPnl->Controls[i]->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::MenuPnl_MouseEnter);
			}
			TableDgv->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_MouseEnter);
			TittleTbx->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_MouseEnter);
			Start();
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


	private:
		Table* table;
		int nColumn;
		int currentColum;
		int menuSpeed, finalX;
		List<Panel^> panelList;
		int indexEnter, indexExit;

	public: System::Windows::Forms::DataGridView^ TableDgv;






























	private: System::Windows::Forms::Panel^ MenuPnl;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnAddColumn;
	private: System::Windows::Forms::Button^ btnFilter;


	private: System::Windows::Forms::Button^ btnIndex;


	private: System::Windows::Forms::Button^ btnAddData;

	private: System::Windows::Forms::Panel^ AddColumnPnl;

	private: System::Windows::Forms::Label^ NameColumnTxt;
	private: System::Windows::Forms::TextBox^ NameColumnTbx;
	private: System::Windows::Forms::ComboBox^ ColumnTypeCbx;

	private: System::Windows::Forms::Label^ ColumnTypeTxt;
	private: System::Windows::Forms::Button^ AddColumnBtn;
	private: System::Windows::Forms::Label^ AddColumnTxt;
	private: System::Windows::Forms::Panel^ AddDataPnl;
	private: System::Windows::Forms::Button^ AddDataBtn;




	private: System::Windows::Forms::Label^ AddDataTxt;
	private: System::Windows::Forms::TextBox^ NameColumnTbx2;




	private: System::Windows::Forms::Label^ NameColumnTxt2;



	private: System::Windows::Forms::Label^ NRowTxt;
	private: System::Windows::Forms::TextBox^ NRowTbx;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::Panel^ IndexPnl;

private: System::Windows::Forms::Button^ IndexBtn;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ NameColumnTbx3;


private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Panel^ SaveDataPnl;

private: System::Windows::Forms::Button^ SaveBtn;


private: System::Windows::Forms::Label^ label3;




private: System::Windows::Forms::Timer^ timer2;
private: System::Windows::Forms::TextBox^ DataTbx;
private: System::Windows::Forms::Label^ DataTxt;
private: System::Windows::Forms::Panel^ FilterPnl;
private: System::Windows::Forms::Button^ FilterBtn;


private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::ComboBox^ FilterTypeCbx;

private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::TextBox^ NameColumnTbx4;

private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ ExtraDataTbx;

private: System::Windows::Forms::Label^ ExtraDataTxt;
private: System::Windows::Forms::TextBox^ TittleTbx;
private: System::Windows::Forms::Button^ btnExport;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TextBox^ ExtraDataTbx2;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::ComboBox^ FilterTypeCbx2;

private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Button^ AddFilterBtn;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::Label^ label10;






	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Tabla_Forms::typeid));
			this->TableDgv = (gcnew System::Windows::Forms::DataGridView());
			this->TittleTbx = (gcnew System::Windows::Forms::TextBox());
			this->AddDataPnl = (gcnew System::Windows::Forms::Panel());
			this->DataTbx = (gcnew System::Windows::Forms::TextBox());
			this->DataTxt = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->NRowTbx = (gcnew System::Windows::Forms::TextBox());
			this->NRowTxt = (gcnew System::Windows::Forms::Label());
			this->AddDataBtn = (gcnew System::Windows::Forms::Button());
			this->AddDataTxt = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx2 = (gcnew System::Windows::Forms::TextBox());
			this->NameColumnTxt2 = (gcnew System::Windows::Forms::Label());
			this->SaveDataPnl = (gcnew System::Windows::Forms::Panel());
			this->SaveBtn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->IndexPnl = (gcnew System::Windows::Forms::Panel());
			this->IndexBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->AddColumnPnl = (gcnew System::Windows::Forms::Panel());
			this->AddColumnBtn = (gcnew System::Windows::Forms::Button());
			this->AddColumnTxt = (gcnew System::Windows::Forms::Label());
			this->ColumnTypeCbx = (gcnew System::Windows::Forms::ComboBox());
			this->ColumnTypeTxt = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx = (gcnew System::Windows::Forms::TextBox());
			this->NameColumnTxt = (gcnew System::Windows::Forms::Label());
			this->MenuPnl = (gcnew System::Windows::Forms::Panel());
			this->btnExport = (gcnew System::Windows::Forms::Button());
			this->btnFilter = (gcnew System::Windows::Forms::Button());
			this->btnIndex = (gcnew System::Windows::Forms::Button());
			this->btnAddData = (gcnew System::Windows::Forms::Button());
			this->btnAddColumn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->FilterPnl = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->AddFilterBtn = (gcnew System::Windows::Forms::Button());
			this->ExtraDataTbx2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FilterTypeCbx2 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->ExtraDataTbx = (gcnew System::Windows::Forms::TextBox());
			this->ExtraDataTxt = (gcnew System::Windows::Forms::Label());
			this->FilterBtn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->FilterTypeCbx = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->BeginInit();
			this->AddDataPnl->SuspendLayout();
			this->SaveDataPnl->SuspendLayout();
			this->IndexPnl->SuspendLayout();
			this->AddColumnPnl->SuspendLayout();
			this->MenuPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->FilterPnl->SuspendLayout();
			this->SuspendLayout();
			// 
			// TableDgv
			// 
			this->TableDgv->AllowUserToAddRows = false;
			this->TableDgv->AllowUserToDeleteRows = false;
			this->TableDgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TableDgv->Location = System::Drawing::Point(47, 63);
			this->TableDgv->Margin = System::Windows::Forms::Padding(2);
			this->TableDgv->Name = L"TableDgv";
			this->TableDgv->RowHeadersWidth = 51;
			this->TableDgv->RowTemplate->Height = 24;
			this->TableDgv->Size = System::Drawing::Size(770, 288);
			this->TableDgv->TabIndex = 0;
			this->TableDgv->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Tabla_Forms::TableDgv_CellClick);
			// 
			// TittleTbx
			// 
			this->TittleTbx->BackColor = System::Drawing::SystemColors::Control;
			this->TittleTbx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TittleTbx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->TittleTbx->Location = System::Drawing::Point(47, 26);
			this->TittleTbx->MaxLength = 40;
			this->TittleTbx->Name = L"TittleTbx";
			this->TittleTbx->Size = System::Drawing::Size(770, 31);
			this->TittleTbx->TabIndex = 10;
			this->TittleTbx->Text = L"Tittle";
			this->TittleTbx->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AddDataPnl
			// 
			this->AddDataPnl->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->AddDataPnl->Controls->Add(this->DataTbx);
			this->AddDataPnl->Controls->Add(this->DataTxt);
			this->AddDataPnl->Controls->Add(this->radioButton2);
			this->AddDataPnl->Controls->Add(this->radioButton1);
			this->AddDataPnl->Controls->Add(this->NRowTbx);
			this->AddDataPnl->Controls->Add(this->NRowTxt);
			this->AddDataPnl->Controls->Add(this->AddDataBtn);
			this->AddDataPnl->Controls->Add(this->AddDataTxt);
			this->AddDataPnl->Controls->Add(this->NameColumnTbx2);
			this->AddDataPnl->Controls->Add(this->NameColumnTxt2);
			this->AddDataPnl->Location = System::Drawing::Point(315, 9);
			this->AddDataPnl->Name = L"AddDataPnl";
			this->AddDataPnl->Size = System::Drawing::Size(54, 40);
			this->AddDataPnl->TabIndex = 13;
			// 
			// DataTbx
			// 
			this->DataTbx->Location = System::Drawing::Point(14, 250);
			this->DataTbx->Name = L"DataTbx";
			this->DataTbx->Size = System::Drawing::Size(187, 20);
			this->DataTbx->TabIndex = 12;
			// 
			// DataTxt
			// 
			this->DataTxt->AutoSize = true;
			this->DataTxt->Location = System::Drawing::Point(11, 234);
			this->DataTxt->Name = L"DataTxt";
			this->DataTxt->Size = System::Drawing::Size(30, 13);
			this->DataTxt->TabIndex = 11;
			this->DataTxt->Text = L"Dato";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(29, 165);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(119, 17);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->Text = L"Agregar en posición";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(29, 142);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(95, 17);
			this->radioButton1->TabIndex = 9;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Agregar al final";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// NRowTbx
			// 
			this->NRowTbx->Enabled = false;
			this->NRowTbx->Location = System::Drawing::Point(14, 206);
			this->NRowTbx->Name = L"NRowTbx";
			this->NRowTbx->Size = System::Drawing::Size(187, 20);
			this->NRowTbx->TabIndex = 8;
			// 
			// NRowTxt
			// 
			this->NRowTxt->AutoSize = true;
			this->NRowTxt->Enabled = false;
			this->NRowTxt->Location = System::Drawing::Point(11, 190);
			this->NRowTxt->Name = L"NRowTxt";
			this->NRowTxt->Size = System::Drawing::Size(78, 13);
			this->NRowTxt->TabIndex = 7;
			this->NRowTxt->Text = L"Número de Fila";
			// 
			// AddDataBtn
			// 
			this->AddDataBtn->Location = System::Drawing::Point(36, 285);
			this->AddDataBtn->Name = L"AddDataBtn";
			this->AddDataBtn->Size = System::Drawing::Size(144, 23);
			this->AddDataBtn->TabIndex = 6;
			this->AddDataBtn->Text = L"Agregar Dato";
			this->AddDataBtn->UseVisualStyleBackColor = true;
			this->AddDataBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::AddDataBtn_Click);
			// 
			// AddDataTxt
			// 
			this->AddDataTxt->AutoSize = true;
			this->AddDataTxt->Font = (gcnew System::Drawing::Font(L"Montserrat", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddDataTxt->Location = System::Drawing::Point(31, 51);
			this->AddDataTxt->Name = L"AddDataTxt";
			this->AddDataTxt->Size = System::Drawing::Size(146, 26);
			this->AddDataTxt->TabIndex = 5;
			this->AddDataTxt->Text = L"Agregar Dato";
			// 
			// NameColumnTbx2
			// 
			this->NameColumnTbx2->Location = System::Drawing::Point(14, 114);
			this->NameColumnTbx2->Name = L"NameColumnTbx2";
			this->NameColumnTbx2->Size = System::Drawing::Size(187, 20);
			this->NameColumnTbx2->TabIndex = 1;
			// 
			// NameColumnTxt2
			// 
			this->NameColumnTxt2->AutoSize = true;
			this->NameColumnTxt2->Location = System::Drawing::Point(11, 97);
			this->NameColumnTxt2->Name = L"NameColumnTxt2";
			this->NameColumnTxt2->Size = System::Drawing::Size(113, 13);
			this->NameColumnTxt2->TabIndex = 0;
			this->NameColumnTxt2->Text = L"Nombre de la columna";
			// 
			// SaveDataPnl
			// 
			this->SaveDataPnl->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->SaveDataPnl->Controls->Add(this->SaveBtn);
			this->SaveDataPnl->Controls->Add(this->label3);
			this->SaveDataPnl->Controls->Add(this->textBox1);
			this->SaveDataPnl->Controls->Add(this->label6);
			this->SaveDataPnl->Location = System::Drawing::Point(529, 12);
			this->SaveDataPnl->Name = L"SaveDataPnl";
			this->SaveDataPnl->Size = System::Drawing::Size(47, 37);
			this->SaveDataPnl->TabIndex = 13;
			// 
			// SaveBtn
			// 
			this->SaveBtn->Location = System::Drawing::Point(36, 239);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->Size = System::Drawing::Size(144, 23);
			this->SaveBtn->TabIndex = 6;
			this->SaveBtn->Text = L"Exportar";
			this->SaveBtn->UseVisualStyleBackColor = true;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::SaveBtn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(54, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 26);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Exportar";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 171);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(187, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 151);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Nombre del archivo";
			// 
			// IndexPnl
			// 
			this->IndexPnl->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->IndexPnl->Controls->Add(this->IndexBtn);
			this->IndexPnl->Controls->Add(this->label2);
			this->IndexPnl->Controls->Add(this->NameColumnTbx3);
			this->IndexPnl->Controls->Add(this->label4);
			this->IndexPnl->Location = System::Drawing::Point(600, 9);
			this->IndexPnl->Name = L"IndexPnl";
			this->IndexPnl->Size = System::Drawing::Size(80, 39);
			this->IndexPnl->TabIndex = 13;
			// 
			// IndexBtn
			// 
			this->IndexBtn->Location = System::Drawing::Point(33, 219);
			this->IndexBtn->Name = L"IndexBtn";
			this->IndexBtn->Size = System::Drawing::Size(144, 23);
			this->IndexBtn->TabIndex = 6;
			this->IndexBtn->Text = L"Indexar";
			this->IndexBtn->UseVisualStyleBackColor = true;
			this->IndexBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::IndexBtn_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 26);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Indexar Columna";
			// 
			// NameColumnTbx3
			// 
			this->NameColumnTbx3->Location = System::Drawing::Point(13, 166);
			this->NameColumnTbx3->Name = L"NameColumnTbx3";
			this->NameColumnTbx3->Size = System::Drawing::Size(187, 20);
			this->NameColumnTbx3->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Nombre de la columna";
			// 
			// AddColumnPnl
			// 
			this->AddColumnPnl->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->AddColumnPnl->Controls->Add(this->AddColumnBtn);
			this->AddColumnPnl->Controls->Add(this->AddColumnTxt);
			this->AddColumnPnl->Controls->Add(this->ColumnTypeCbx);
			this->AddColumnPnl->Controls->Add(this->ColumnTypeTxt);
			this->AddColumnPnl->Controls->Add(this->NameColumnTbx);
			this->AddColumnPnl->Controls->Add(this->NameColumnTxt);
			this->AddColumnPnl->Location = System::Drawing::Point(246, 9);
			this->AddColumnPnl->Name = L"AddColumnPnl";
			this->AddColumnPnl->Size = System::Drawing::Size(51, 34);
			this->AddColumnPnl->TabIndex = 12;
			// 
			// AddColumnBtn
			// 
			this->AddColumnBtn->Location = System::Drawing::Point(36, 262);
			this->AddColumnBtn->Name = L"AddColumnBtn";
			this->AddColumnBtn->Size = System::Drawing::Size(144, 23);
			this->AddColumnBtn->TabIndex = 6;
			this->AddColumnBtn->Text = L"Agregar Columna";
			this->AddColumnBtn->UseVisualStyleBackColor = true;
			this->AddColumnBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::AddColumnBtn_Click);
			// 
			// AddColumnTxt
			// 
			this->AddColumnTxt->AutoSize = true;
			this->AddColumnTxt->Font = (gcnew System::Drawing::Font(L"Montserrat", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddColumnTxt->Location = System::Drawing::Point(11, 24);
			this->AddColumnTxt->Name = L"AddColumnTxt";
			this->AddColumnTxt->Size = System::Drawing::Size(188, 26);
			this->AddColumnTxt->TabIndex = 5;
			this->AddColumnTxt->Text = L"Agregar Columna";
			// 
			// ColumnTypeCbx
			// 
			this->ColumnTypeCbx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ColumnTypeCbx->FormattingEnabled = true;
			this->ColumnTypeCbx->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Ninguno", L"Palabras", L"Letras", L"Numeros" });
			this->ColumnTypeCbx->Location = System::Drawing::Point(13, 184);
			this->ColumnTypeCbx->Name = L"ColumnTypeCbx";
			this->ColumnTypeCbx->Size = System::Drawing::Size(187, 21);
			this->ColumnTypeCbx->TabIndex = 4;
			// 
			// ColumnTypeTxt
			// 
			this->ColumnTypeTxt->AutoSize = true;
			this->ColumnTypeTxt->Location = System::Drawing::Point(10, 162);
			this->ColumnTypeTxt->Name = L"ColumnTypeTxt";
			this->ColumnTypeTxt->Size = System::Drawing::Size(87, 13);
			this->ColumnTypeTxt->TabIndex = 2;
			this->ColumnTypeTxt->Text = L"Tipo de Columna";
			// 
			// NameColumnTbx
			// 
			this->NameColumnTbx->Location = System::Drawing::Point(13, 116);
			this->NameColumnTbx->Name = L"NameColumnTbx";
			this->NameColumnTbx->Size = System::Drawing::Size(187, 20);
			this->NameColumnTbx->TabIndex = 1;
			// 
			// NameColumnTxt
			// 
			this->NameColumnTxt->AutoSize = true;
			this->NameColumnTxt->Location = System::Drawing::Point(10, 96);
			this->NameColumnTxt->Name = L"NameColumnTxt";
			this->NameColumnTxt->Size = System::Drawing::Size(113, 13);
			this->NameColumnTxt->TabIndex = 0;
			this->NameColumnTxt->Text = L"Nombre de la columna";
			// 
			// MenuPnl
			// 
			this->MenuPnl->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->MenuPnl->Controls->Add(this->btnExport);
			this->MenuPnl->Controls->Add(this->btnFilter);
			this->MenuPnl->Controls->Add(this->btnIndex);
			this->MenuPnl->Controls->Add(this->btnAddData);
			this->MenuPnl->Controls->Add(this->btnAddColumn);
			this->MenuPnl->Controls->Add(this->pictureBox1);
			this->MenuPnl->Location = System::Drawing::Point(0, 0);
			this->MenuPnl->Name = L"MenuPnl";
			this->MenuPnl->Size = System::Drawing::Size(228, 392);
			this->MenuPnl->TabIndex = 11;
			this->MenuPnl->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::MenuPnl_MouseEnter);
			// 
			// btnExport
			// 
			this->btnExport->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnExport->FlatAppearance->BorderSize = 0;
			this->btnExport->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Highlight;
			this->btnExport->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExport->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExport->ForeColor = System::Drawing::Color::Black;
			this->btnExport->Location = System::Drawing::Point(0, 236);
			this->btnExport->Margin = System::Windows::Forms::Padding(0);
			this->btnExport->Name = L"btnExport";
			this->btnExport->Size = System::Drawing::Size(228, 39);
			this->btnExport->TabIndex = 5;
			this->btnExport->Text = L"Exportar";
			this->btnExport->UseVisualStyleBackColor = false;
			this->btnExport->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnExport_Click);
			// 
			// btnFilter
			// 
			this->btnFilter->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnFilter->FlatAppearance->BorderSize = 0;
			this->btnFilter->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Highlight;
			this->btnFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFilter->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFilter->ForeColor = System::Drawing::Color::Black;
			this->btnFilter->Location = System::Drawing::Point(0, 190);
			this->btnFilter->Margin = System::Windows::Forms::Padding(0);
			this->btnFilter->Name = L"btnFilter";
			this->btnFilter->Size = System::Drawing::Size(228, 39);
			this->btnFilter->TabIndex = 4;
			this->btnFilter->Text = L"Filtrar Columna";
			this->btnFilter->UseVisualStyleBackColor = false;
			this->btnFilter->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnFilter_Click);
			// 
			// btnIndex
			// 
			this->btnIndex->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnIndex->FlatAppearance->BorderSize = 0;
			this->btnIndex->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Highlight;
			this->btnIndex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIndex->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIndex->ForeColor = System::Drawing::Color::Black;
			this->btnIndex->Location = System::Drawing::Point(0, 142);
			this->btnIndex->Margin = System::Windows::Forms::Padding(0);
			this->btnIndex->Name = L"btnIndex";
			this->btnIndex->Size = System::Drawing::Size(228, 39);
			this->btnIndex->TabIndex = 3;
			this->btnIndex->Text = L"Indexar Columna";
			this->btnIndex->UseVisualStyleBackColor = false;
			this->btnIndex->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnIndex_Click);
			// 
			// btnAddData
			// 
			this->btnAddData->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnAddData->FlatAppearance->BorderSize = 0;
			this->btnAddData->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Highlight;
			this->btnAddData->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddData->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddData->ForeColor = System::Drawing::Color::Black;
			this->btnAddData->Location = System::Drawing::Point(0, 97);
			this->btnAddData->Margin = System::Windows::Forms::Padding(0);
			this->btnAddData->Name = L"btnAddData";
			this->btnAddData->Size = System::Drawing::Size(228, 39);
			this->btnAddData->TabIndex = 2;
			this->btnAddData->Text = L"Agregar Dato";
			this->btnAddData->UseVisualStyleBackColor = false;
			this->btnAddData->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnAddData_Click);
			// 
			// btnAddColumn
			// 
			this->btnAddColumn->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnAddColumn->FlatAppearance->BorderSize = 0;
			this->btnAddColumn->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Highlight;
			this->btnAddColumn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddColumn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddColumn->ForeColor = System::Drawing::Color::Black;
			this->btnAddColumn->Location = System::Drawing::Point(0, 53);
			this->btnAddColumn->Margin = System::Windows::Forms::Padding(0);
			this->btnAddColumn->Name = L"btnAddColumn";
			this->btnAddColumn->Size = System::Drawing::Size(228, 39);
			this->btnAddColumn->TabIndex = 1;
			this->btnAddColumn->Text = L"Agregar Columna";
			this->btnAddColumn->UseVisualStyleBackColor = false;
			this->btnAddColumn->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnAddColumn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(195, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(30, 33);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Tabla_Forms::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Tabla_Forms::timer2_Tick);
			// 
			// FilterPnl
			// 
			this->FilterPnl->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->FilterPnl->Controls->Add(this->textBox2);
			this->FilterPnl->Controls->Add(this->label10);
			this->FilterPnl->Controls->Add(this->AddFilterBtn);
			this->FilterPnl->Controls->Add(this->ExtraDataTbx2);
			this->FilterPnl->Controls->Add(this->label1);
			this->FilterPnl->Controls->Add(this->FilterTypeCbx2);
			this->FilterPnl->Controls->Add(this->label5);
			this->FilterPnl->Controls->Add(this->ExtraDataTbx);
			this->FilterPnl->Controls->Add(this->ExtraDataTxt);
			this->FilterPnl->Controls->Add(this->FilterBtn);
			this->FilterPnl->Controls->Add(this->label7);
			this->FilterPnl->Controls->Add(this->FilterTypeCbx);
			this->FilterPnl->Controls->Add(this->label8);
			this->FilterPnl->Controls->Add(this->NameColumnTbx4);
			this->FilterPnl->Controls->Add(this->label9);
			this->FilterPnl->Location = System::Drawing::Point(823, 0);
			this->FilterPnl->Name = L"FilterPnl";
			this->FilterPnl->Size = System::Drawing::Size(205, 392);
			this->FilterPnl->TabIndex = 13;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 297);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(187, 20);
			this->textBox2->TabIndex = 15;
			this->textBox2->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 278);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(113, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Nombre de la columna";
			this->label10->Visible = false;
			// 
			// AddFilterBtn
			// 
			this->AddFilterBtn->Location = System::Drawing::Point(36, 257);
			this->AddFilterBtn->Name = L"AddFilterBtn";
			this->AddFilterBtn->Size = System::Drawing::Size(144, 23);
			this->AddFilterBtn->TabIndex = 13;
			this->AddFilterBtn->Text = L"Añadir filtro";
			this->AddFilterBtn->UseVisualStyleBackColor = true;
			this->AddFilterBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::AddFilterBtn_Click);
			// 
			// ExtraDataTbx2
			// 
			this->ExtraDataTbx2->Location = System::Drawing::Point(15, 192);
			this->ExtraDataTbx2->Name = L"ExtraDataTbx2";
			this->ExtraDataTbx2->Size = System::Drawing::Size(187, 20);
			this->ExtraDataTbx2->TabIndex = 12;
			this->ExtraDataTbx2->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 178);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Nombre de la columna";
			this->label1->Visible = false;
			// 
			// FilterTypeCbx2
			// 
			this->FilterTypeCbx2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FilterTypeCbx2->FormattingEnabled = true;
			this->FilterTypeCbx2->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"Ninguno", L"Buscar", L"Iguales a", L"Mayores que",
					L"Menores que", L"Contiene", L"No contiene", L"Empieza con", L"Termina con", L"Orden ascendente", L"Orden descendente"
			});
			this->FilterTypeCbx2->Location = System::Drawing::Point(13, 240);
			this->FilterTypeCbx2->Name = L"FilterTypeCbx2";
			this->FilterTypeCbx2->Size = System::Drawing::Size(187, 21);
			this->FilterTypeCbx2->TabIndex = 10;
			this->FilterTypeCbx2->Visible = false;
			this->FilterTypeCbx2->SelectedIndexChanged += gcnew System::EventHandler(this, &Tabla_Forms::FilterTypeCbx2_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 224);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Tipo de filtro 2";
			this->label5->Visible = false;
			// 
			// ExtraDataTbx
			// 
			this->ExtraDataTbx->Location = System::Drawing::Point(15, 209);
			this->ExtraDataTbx->Name = L"ExtraDataTbx";
			this->ExtraDataTbx->Size = System::Drawing::Size(187, 20);
			this->ExtraDataTbx->TabIndex = 8;
			this->ExtraDataTbx->Visible = false;
			// 
			// ExtraDataTxt
			// 
			this->ExtraDataTxt->AutoSize = true;
			this->ExtraDataTxt->Location = System::Drawing::Point(12, 190);
			this->ExtraDataTxt->Name = L"ExtraDataTxt";
			this->ExtraDataTxt->Size = System::Drawing::Size(113, 13);
			this->ExtraDataTxt->TabIndex = 7;
			this->ExtraDataTxt->Text = L"Nombre de la columna";
			this->ExtraDataTxt->Visible = false;
			// 
			// FilterBtn
			// 
			this->FilterBtn->Location = System::Drawing::Point(36, 300);
			this->FilterBtn->Name = L"FilterBtn";
			this->FilterBtn->Size = System::Drawing::Size(144, 23);
			this->FilterBtn->TabIndex = 6;
			this->FilterBtn->Text = L"Filtrar";
			this->FilterBtn->UseVisualStyleBackColor = true;
			this->FilterBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::FilterBtn_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Montserrat", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(25, 51);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(168, 26);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Filtrar Columna";
			// 
			// FilterTypeCbx
			// 
			this->FilterTypeCbx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FilterTypeCbx->FormattingEnabled = true;
			this->FilterTypeCbx->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"Ninguno", L"Buscar", L"Iguales a", L"Mayores que",
					L"Menores que", L"Contiene", L"No contiene", L"Empieza con", L"Termina con", L"Orden ascendente", L"Orden descendente"
			});
			this->FilterTypeCbx->Location = System::Drawing::Point(15, 159);
			this->FilterTypeCbx->Name = L"FilterTypeCbx";
			this->FilterTypeCbx->Size = System::Drawing::Size(187, 21);
			this->FilterTypeCbx->TabIndex = 4;
			this->FilterTypeCbx->SelectedIndexChanged += gcnew System::EventHandler(this, &Tabla_Forms::FilterTypeCbx_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 138);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 13);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Tipo de filtro";
			// 
			// NameColumnTbx4
			// 
			this->NameColumnTbx4->Location = System::Drawing::Point(15, 115);
			this->NameColumnTbx4->Name = L"NameColumnTbx4";
			this->NameColumnTbx4->Size = System::Drawing::Size(187, 20);
			this->NameColumnTbx4->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 99);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(113, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Nombre de la columna";
			// 
			// Tabla_Forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 392);
			this->Controls->Add(this->MenuPnl);
			this->Controls->Add(this->TableDgv);
			this->Controls->Add(this->FilterPnl);
			this->Controls->Add(this->AddDataPnl);
			this->Controls->Add(this->TittleTbx);
			this->Controls->Add(this->AddColumnPnl);
			this->Controls->Add(this->SaveDataPnl);
			this->Controls->Add(this->IndexPnl);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			this->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_MouseEnter);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->EndInit();
			this->AddDataPnl->ResumeLayout(false);
			this->AddDataPnl->PerformLayout();
			this->SaveDataPnl->ResumeLayout(false);
			this->SaveDataPnl->PerformLayout();
			this->IndexPnl->ResumeLayout(false);
			this->IndexPnl->PerformLayout();
			this->AddColumnPnl->ResumeLayout(false);
			this->AddColumnPnl->PerformLayout();
			this->MenuPnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->FilterPnl->ResumeLayout(false);
			this->FilterPnl->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void Start() {
		ColumnTypeCbx->SelectedItem = ColumnTypeCbx->Items[0];
		FilterTypeCbx->SelectedItem = FilterTypeCbx->Items[0];
		for each (Panel^p in panelList)
		{
			p->Location = Point(1040, 0);
			p->Size = Drawing::Size(209, 391);
		}
		MenuPnl->Location = Point(-198, 0);
		ExtraDataTbx->Visible = false;
		ExtraDataTxt->Visible = false;
	}
	private: void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: System::Void IndexBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string nameColumn;
		MarshalString(NameColumnTbx3->Text, nameColumn);
		table->Index(nameColumn);
	}
	private: System::Void TableDgv_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		currentColum = e->ColumnIndex;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (finalX == 0) {
			MenuPnl->Location = Point(MenuPnl->Location.X + menuSpeed, 0);
			if (MenuPnl->Location.X >= finalX) {
				MenuPnl->Location = Point(0, 0);
				timer1->Stop();
			}
		}
		else {
			MenuPnl->Location = Point(MenuPnl->Location.X - menuSpeed, 0);
			if (MenuPnl->Location.X <= finalX) {
				MenuPnl->Location = Point(-198, 0);
				timer1->Stop();
			}
		}
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < panelList.Count; i++) {
			if (i == indexEnter) {
				panelList[indexEnter]->Location = Point(panelList[indexEnter]->Location.X - menuSpeed, 0);
				if (panelList[indexEnter]->Location.X <= 822) {
					panelList[indexEnter]->Location = Point(822, 0);
					indexEnter = -1;
					break;
				}
			}
			else {
				if (indexExit != -1 && i == indexExit) {
					panelList[indexExit]->Location = Point(panelList[indexExit]->Location.X + menuSpeed, 0);
					if (panelList[indexExit]->Location.X >= 1040) {
						panelList[indexExit]->Location = Point(1040, 0);
						indexExit = -1;
						break;
					}
				}
				else {
					panelList[i]->Location = Point(panelList[i]->Location.X + menuSpeed, 0);
					if (panelList[i]->Location.X >= 1040) {
						panelList[i]->Location = Point(1040, 0);
					}
				}
			}
		}
		if (indexEnter == -1 && indexExit == -1) timer2->Stop();
	}
	private: System::Void MenuPnl_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		if (finalX == 0) return;
		finalX = 0;
		timer1->Start();
	}
	private: System::Void Tabla_Forms_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		if (finalX == -198) return;
		finalX = -198;
		timer1->Start();
	}
	private: System::Void AddColumnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//Agregamos a la tabla interna
		string type, nameColumn;
		MarshalString(ColumnTypeCbx->Text, type);	//Convertir de String^ a string	
		MarshalString(NameColumnTbx->Text, nameColumn);	//				System a std
		table->AddColumn(type, nameColumn);

		//Agregamos a, data gried view
		DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
		CHeader->HeaderText = NameColumnTbx->Text;
		this->TableDgv->Columns->Add(CHeader);

		NameColumnTbx->Text = "";
		ColumnTypeCbx->SelectedItem = ColumnTypeCbx->Items[0];
		nColumn++;
	}
	private: System::Void AddDataBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//Agregamos a la tabla interna
		string nameColumn, data;
		MarshalString(NameColumnTbx2->Text, nameColumn);
		MarshalString(DataTbx->Text, data);
		int n = table->AddData(nameColumn, data);

		//Agregamos al data grid view
		if (n != -1) {
			n = (TableDgv->RowCount < n ?
				TableDgv->Rows->Add() : n - 1);
			TableDgv->Rows[n]->Cells[getColumnIndex(NameColumnTbx2->Text)]->Value = DataTbx->Text;
		}
		DataTbx->Text = "";
	}
	private: System::Void IndexBtn_Click_1(System::Object^ sender, System::EventArgs^ e) {
		string nameColumn;
		MarshalString(NameColumnTbx3->Text, nameColumn);
		table->Index(nameColumn);
	}
	private: System::Void btnAddColumn_Click(System::Object^ sender, System::EventArgs^ e) {
		indexExit = indexEnter;
		indexEnter = 0;
		timer2->Start();
	}
	private: System::Void btnAddData_Click(System::Object^ sender, System::EventArgs^ e) {
		indexExit = indexEnter;
		indexEnter = 1;
		timer2->Start();
	}
	private: System::Void btnIndex_Click(System::Object^ sender, System::EventArgs^ e) {
		indexExit = indexEnter;
		indexEnter = 2;
		timer2->Start();
	}
	private: System::Void btnFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		indexExit = indexEnter;
		indexEnter = 3;
		timer2->Start();
	}
	private: System::Void btnExport_Click(System::Object^ sender, System::EventArgs^ e) {
		indexExit = indexEnter;
		indexEnter = 4;
		timer2->Start();
	}
	private: System::Void FilterTypeCbx_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ t = FilterTypeCbx->Text;
		ExtraDataTbx->Visible = true;
		ExtraDataTxt->Visible = true;
		if (t == "Buscar") ExtraDataTxt->Text = "Dato a buscar";
		else if (t == "Orden ascendente" || t == "Orden descendente" || t == "Ninguno") {
			ExtraDataTbx->Visible = false;
			ExtraDataTxt->Visible = false;
			ExtraDataTbx->Text = "";
		}
		else ExtraDataTxt->Text = "Dato a comparar";
	}
	private: System::Void FilterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string nameColumn; string searcher;
		string nameColumn2, searcher2;
		MarshalString(ExtraDataTbx->Text, searcher);
		MarshalString(NameColumnTbx4->Text, nameColumn);
		String^ t = FilterTypeCbx->Text;
		if (t == "Ninguno") return;
		Tabla_Forms^ auxTable = gcnew Tabla_Forms();
		if (t != "Ninguno") {
			auxTable->setTittle(this->TittleTbx->Text);
			if (t == "Buscar") {
				for (int i = 0; i < this->TableDgv->ColumnCount; i++) {	//Copio encabezados
					DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
					CHeader->HeaderText = this->TableDgv->Columns[i]->HeaderText;
					auxTable->TableDgv->Columns->Add(CHeader);
				}
				auxTable->TableDgv->Rows->Add();
				int row = table->Search(searcher, nameColumn);
				if (row != -1) {
					for (int i = 0; i < auxTable->TableDgv->ColumnCount; i++) {
						auxTable->TableDgv->Rows[0]->Cells[i]->Value = this->TableDgv->Rows[row]->Cells[i]->Value;
					}
				}
				else {
					for (int i = 0; i < auxTable->TableDgv->ColumnCount; i++) {
						auxTable->TableDgv->Rows[0]->Cells[i]->Value = "No encontrado";
					}
				}
			}
			else if (t == "Iguales a") {
				for (int i = 0; i < this->TableDgv->ColumnCount; i++) {	//Copio encabezados
					DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
					CHeader->HeaderText = this->TableDgv->Columns[i]->HeaderText;
					auxTable->TableDgv->Columns->Add(CHeader);
				}
				list<int>* rows = table->Equals(searcher, nameColumn);
				if (rows->size() > 0) {
					auxTable->TableDgv->Rows->Add(rows->size());
					for (int i = 0; i < auxTable->TableDgv->RowCount; i++) {
						for (int j = 0; j < auxTable->TableDgv->ColumnCount; j++) {
							auxTable->TableDgv->Rows[i]->Cells[j]->Value = this->TableDgv->Rows[rows->front()]->Cells[j]->Value;
						}
						rows->pop_front();
					}
				}
				else {
					auxTable->TableDgv->Rows->Add();
					for (int i = 0; i < auxTable->TableDgv->ColumnCount; i++) {
						auxTable->TableDgv->Rows[0]->Cells[i]->Value = "No encontrado";
					}
				}
			}
			else if (t == "Mayores que") {
				FilterOf(auxTable->TableDgv, table->GreaterThan(searcher, nameColumn));
			}
			else if (t == "Menores que") {
				FilterOf(auxTable->TableDgv, table->LessThan(searcher, nameColumn));
			}
			else if (t == "Contiene") {
				FilterOf(auxTable->TableDgv, table->Contains(searcher, nameColumn));
			}
			else if (t == "No contiene") {
				FilterOf(auxTable->TableDgv, table->NotContains(searcher, nameColumn));
			}
			else if (t == "Empieza con") {
				FilterOf(auxTable->TableDgv, table->StartWith(searcher, nameColumn));
			}
			else if (t == "Termina con") {
				FilterOf(auxTable->TableDgv, table->EndWith(searcher, nameColumn));
			}
			else if (t == "Orden ascendente") {
				for (int i = 0; i < this->TableDgv->ColumnCount; i++) {	//Copio encabezados
					DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
					CHeader->HeaderText = this->TableDgv->Columns[i]->HeaderText;
					auxTable->TableDgv->Columns->Add(CHeader);
				}
				list<int>* rows = table->InOrder(nameColumn);
				if (rows->size() > 0) {
					auxTable->TableDgv->Rows->Add(rows->size());
					for (int i = 0; i < auxTable->TableDgv->RowCount; i++) {
						for (int j = 0; j < auxTable->TableDgv->ColumnCount; j++) {
							auxTable->TableDgv->Rows[i]->Cells[j]->Value = this->TableDgv->Rows[rows->front()]->Cells[j]->Value;
						}
						rows->pop_front();
					}
				}
				else {
					auxTable->TableDgv->Rows->Add();
					for (int i = 0; i < auxTable->TableDgv->ColumnCount; i++) {
						auxTable->TableDgv->Rows[0]->Cells[i]->Value = "No encontrado";
					}
				}
			}
			else if (t == "Orden descendente") {
				for (int i = 0; i < this->TableDgv->ColumnCount; i++) {	//Copio encabezados
					DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
					CHeader->HeaderText = this->TableDgv->Columns[i]->HeaderText;
					auxTable->TableDgv->Columns->Add(CHeader);
				}
				list<int>* rows = table->InReverse(nameColumn);
				if (rows->size() > 0) {
					auxTable->TableDgv->Rows->Add(rows->size());
					for (int i = 0; i < auxTable->TableDgv->RowCount; i++) {
						for (int j = 0; j < auxTable->TableDgv->ColumnCount; j++) {
							auxTable->TableDgv->Rows[i]->Cells[j]->Value = this->TableDgv->Rows[rows->front()]->Cells[j]->Value;
						}
						rows->pop_front();
					}
				}
				else {
					auxTable->TableDgv->Rows->Add();
					for (int i = 0; i < auxTable->TableDgv->ColumnCount; i++) {
						auxTable->TableDgv->Rows[0]->Cells[i]->Value = "No encontrado";
					}
				}
			}
		}
		ExtraDataTbx->Text = "";
		FilterTypeCbx->SelectedItem = FilterTypeCbx->Items[0];
		auxTable->Show();
	}
	private: int getColumnIndex(String^ columnName) {
		for (int i = 0; i < TableDgv->ColumnCount; i++) {
			if (TableDgv->Columns[i]->HeaderText == columnName)
				return i;
		}
		return -1;
	}
	public: void setTittle(String^ tittle) {
		this->TittleTbx->Text = tittle + " (copia)";
	}
	private: void FilterOf(DataGridView^aux, list<int>* ro) {
		for (int i = 0; i < this->TableDgv->ColumnCount; i++) {	//Copio encabezados
			DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
			CHeader->HeaderText = this->TableDgv->Columns[i]->HeaderText;
			aux->Columns->Add(CHeader);
		}
		list<int>* rows = ro;
		if (rows->size() > 0) {
			aux->Rows->Add(rows->size());
			for (int i = 0; i < aux->RowCount; i++) {
				for (int j = 0; j < aux->ColumnCount; j++) {
					aux->Rows[i]->Cells[j]->Value = this->TableDgv->Rows[rows->front()]->Cells[j]->Value;
				}
				rows->pop_front();
			}
		}
		else {
			aux->Rows->Add();
			for (int i = 0; i < aux->ColumnCount; i++) {
				aux->Rows[0]->Cells[i]->Value = "No encontrado";
			}
		}
	}
	private: System::Void SaveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		table->SaveTable();
	}
	private: System::Void AddFilterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		label5->Visible = true;
		FilterTypeCbx2->Visible = true;
		AddFilterBtn->Visible = false;
		label9->Location = Point(10, 41);
		NameColumnTbx4->Location = Point(10, 57);
		label8->Location = Point(10, 80);
		FilterTypeCbx->Location = Point(13, 101);
		ExtraDataTbx->Location = Point(13, 151);
		ExtraDataTxt->Location = Point(10, 132);
		label5->Location=Point(10,224);
		FilterTypeCbx2->Location = Point(13,240);
		label1->Location = Point(10,178);
		ExtraDataTbx2->Location = Point(13,192);
		FilterBtn->Location = Point(36,328);
		label7->Location = Point(25,9);
		label1->Visible = true;
		ExtraDataTbx2->Visible = true;
}
	private: System::Void FilterTypeCbx2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ t = FilterTypeCbx2->Text;
		textBox2->Visible = true;
		label10->Visible = true;
		if (t == "Buscar") label10->Text = "Dato a buscar 2";
		else if (t == "Orden ascendente" || t == "Orden descendente" || t == "Ninguno") {
			textBox2->Visible = false;
			label10->Visible = false;
			textBox2->Text = "";
		}
		else label10->Text = "Dato a comparar 2";
	}
};
}
