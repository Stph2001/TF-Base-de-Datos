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
			panelList.Add(RemoveDataPnl);

			for (int i = 0; i < MenuPnl->Controls->Count; i++) {
				MenuPnl->Controls[i]->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::MenuPnl_MouseEnter);
			}
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

	private: System::Windows::Forms::DataGridView^ TableDgv;
	private: System::Windows::Forms::Label^ TitleTableTxt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ CheckBtn;
	private: System::Windows::Forms::Panel^ DataTablePnl;
	private: System::Windows::Forms::Panel^ TableSettingsPnl;



	private: System::Windows::Forms::Button^ AddDataColumnBtn;
	private: System::Windows::Forms::TextBox^ DataColumnTbx;
	private: System::Windows::Forms::Button^ CreateTableBtn;
	private: System::Windows::Forms::Label^ NroColumnTxt;
	private: System::Windows::Forms::Label^ NColumnsTxt;
	private: System::Windows::Forms::Button^ AddTableNameBtn;
	private: System::Windows::Forms::TextBox^ TableNameTbx;
	private: System::Windows::Forms::Label^ TableNameTxt;
	private: System::Windows::Forms::Button^ jje;

	private: System::Windows::Forms::TextBox^ ColumnNameTbx;
	private: System::Windows::Forms::Label^ TypeTxt;
	private: System::Windows::Forms::ComboBox^ TypeCbx;
	private: System::Windows::Forms::Label^ ColumnNameTxt;
	private: System::Windows::Forms::Label^ DataColumnTxt;
	private: System::Windows::Forms::PictureBox^ LoadingPbx;
	private: System::Windows::Forms::ComboBox^ FilterTypeTbx;
	private: System::Windows::Forms::Label^ FilterTypeTxt;
	private: System::Windows::Forms::Label^ CompareDataTxt;

	private: System::Windows::Forms::TextBox^ CompareDataTbx;
	private: System::Windows::Forms::Button^ NoseBtn;
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
private: System::Windows::Forms::Panel^ RemoveDataPnl;

private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ label6;
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
private: System::Windows::Forms::TextBox^ ExtraDataCbx;
private: System::Windows::Forms::Label^ ExtraDataTxt;




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
			this->TitleTableTxt = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CheckBtn = (gcnew System::Windows::Forms::Button());
			this->DataTablePnl = (gcnew System::Windows::Forms::Panel());
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
			this->NoseBtn = (gcnew System::Windows::Forms::Button());
			this->RemoveDataPnl = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->IndexPnl = (gcnew System::Windows::Forms::Panel());
			this->IndexBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CompareDataTxt = (gcnew System::Windows::Forms::Label());
			this->CompareDataTbx = (gcnew System::Windows::Forms::TextBox());
			this->AddColumnPnl = (gcnew System::Windows::Forms::Panel());
			this->AddColumnBtn = (gcnew System::Windows::Forms::Button());
			this->AddColumnTxt = (gcnew System::Windows::Forms::Label());
			this->ColumnTypeCbx = (gcnew System::Windows::Forms::ComboBox());
			this->ColumnTypeTxt = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx = (gcnew System::Windows::Forms::TextBox());
			this->NameColumnTxt = (gcnew System::Windows::Forms::Label());
			this->FilterTypeTbx = (gcnew System::Windows::Forms::ComboBox());
			this->FilterTypeTxt = (gcnew System::Windows::Forms::Label());
			this->LoadingPbx = (gcnew System::Windows::Forms::PictureBox());
			this->TableSettingsPnl = (gcnew System::Windows::Forms::Panel());
			this->DataColumnTxt = (gcnew System::Windows::Forms::Label());
			this->AddDataColumnBtn = (gcnew System::Windows::Forms::Button());
			this->DataColumnTbx = (gcnew System::Windows::Forms::TextBox());
			this->CreateTableBtn = (gcnew System::Windows::Forms::Button());
			this->NroColumnTxt = (gcnew System::Windows::Forms::Label());
			this->NColumnsTxt = (gcnew System::Windows::Forms::Label());
			this->AddTableNameBtn = (gcnew System::Windows::Forms::Button());
			this->TableNameTbx = (gcnew System::Windows::Forms::TextBox());
			this->TableNameTxt = (gcnew System::Windows::Forms::Label());
			this->jje = (gcnew System::Windows::Forms::Button());
			this->ColumnNameTbx = (gcnew System::Windows::Forms::TextBox());
			this->TypeTxt = (gcnew System::Windows::Forms::Label());
			this->TypeCbx = (gcnew System::Windows::Forms::ComboBox());
			this->ColumnNameTxt = (gcnew System::Windows::Forms::Label());
			this->MenuPnl = (gcnew System::Windows::Forms::Panel());
			this->btnFilter = (gcnew System::Windows::Forms::Button());
			this->btnIndex = (gcnew System::Windows::Forms::Button());
			this->btnAddData = (gcnew System::Windows::Forms::Button());
			this->btnAddColumn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->FilterPnl = (gcnew System::Windows::Forms::Panel());
			this->ExtraDataCbx = (gcnew System::Windows::Forms::TextBox());
			this->ExtraDataTxt = (gcnew System::Windows::Forms::Label());
			this->FilterBtn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->FilterTypeCbx = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->NameColumnTbx4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->BeginInit();
			this->DataTablePnl->SuspendLayout();
			this->AddDataPnl->SuspendLayout();
			this->RemoveDataPnl->SuspendLayout();
			this->IndexPnl->SuspendLayout();
			this->AddColumnPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadingPbx))->BeginInit();
			this->TableSettingsPnl->SuspendLayout();
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
			this->TableDgv->Location = System::Drawing::Point(9, 74);
			this->TableDgv->Margin = System::Windows::Forms::Padding(2);
			this->TableDgv->Name = L"TableDgv";
			this->TableDgv->RowHeadersWidth = 51;
			this->TableDgv->RowTemplate->Height = 24;
			this->TableDgv->Size = System::Drawing::Size(776, 240);
			this->TableDgv->TabIndex = 0;
			this->TableDgv->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Tabla_Forms::TableDgv_CellClick);
			// 
			// TitleTableTxt
			// 
			this->TitleTableTxt->AutoSize = true;
			this->TitleTableTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TitleTableTxt->Location = System::Drawing::Point(358, 34);
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
			// CheckBtn
			// 
			this->CheckBtn->Location = System::Drawing::Point(630, 27);
			this->CheckBtn->Margin = System::Windows::Forms::Padding(2);
			this->CheckBtn->Name = L"CheckBtn";
			this->CheckBtn->Size = System::Drawing::Size(81, 27);
			this->CheckBtn->TabIndex = 3;
			this->CheckBtn->Text = L"Comprobar";
			this->CheckBtn->UseVisualStyleBackColor = true;
			this->CheckBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::button1_Click);
			// 
			// DataTablePnl
			// 
			this->DataTablePnl->Controls->Add(this->NoseBtn);
			this->DataTablePnl->Controls->Add(this->CompareDataTxt);
			this->DataTablePnl->Controls->Add(this->CompareDataTbx);
			this->DataTablePnl->Controls->Add(this->FilterTypeTbx);
			this->DataTablePnl->Controls->Add(this->FilterTypeTxt);
			this->DataTablePnl->Controls->Add(this->LoadingPbx);
			this->DataTablePnl->Controls->Add(this->TableDgv);
			this->DataTablePnl->Controls->Add(this->TitleTableTxt);
			this->DataTablePnl->Controls->Add(this->label1);
			this->DataTablePnl->Controls->Add(this->CheckBtn);
			this->DataTablePnl->Location = System::Drawing::Point(32, 70);
			this->DataTablePnl->Margin = System::Windows::Forms::Padding(2);
			this->DataTablePnl->Name = L"DataTablePnl";
			this->DataTablePnl->Size = System::Drawing::Size(785, 322);
			this->DataTablePnl->TabIndex = 9;
			// 
			// AddDataPnl
			// 
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
			this->AddDataPnl->Location = System::Drawing::Point(962, 192);
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
			// NoseBtn
			// 
			this->NoseBtn->Location = System::Drawing::Point(232, 17);
			this->NoseBtn->Name = L"NoseBtn";
			this->NoseBtn->Size = System::Drawing::Size(75, 23);
			this->NoseBtn->TabIndex = 15;
			this->NoseBtn->Text = L"Nose";
			this->NoseBtn->UseVisualStyleBackColor = true;
			// 
			// RemoveDataPnl
			// 
			this->RemoveDataPnl->Controls->Add(this->button5);
			this->RemoveDataPnl->Controls->Add(this->label3);
			this->RemoveDataPnl->Controls->Add(this->comboBox1);
			this->RemoveDataPnl->Controls->Add(this->label5);
			this->RemoveDataPnl->Controls->Add(this->textBox1);
			this->RemoveDataPnl->Controls->Add(this->label6);
			this->RemoveDataPnl->Location = System::Drawing::Point(967, 30);
			this->RemoveDataPnl->Name = L"RemoveDataPnl";
			this->RemoveDataPnl->Size = System::Drawing::Size(49, 36);
			this->RemoveDataPnl->TabIndex = 13;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(36, 262);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(144, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"button4";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(11, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 26);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Remover Dato";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Números", L"Palabras", L"Letras" });
			this->comboBox1->Location = System::Drawing::Point(13, 184);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(187, 21);
			this->comboBox1->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 13);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Tipo de Columna";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(187, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 96);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Nombre de la columna";
			// 
			// IndexPnl
			// 
			this->IndexPnl->Controls->Add(this->IndexBtn);
			this->IndexPnl->Controls->Add(this->label2);
			this->IndexPnl->Controls->Add(this->NameColumnTbx3);
			this->IndexPnl->Controls->Add(this->label4);
			this->IndexPnl->Location = System::Drawing::Point(968, 80);
			this->IndexPnl->Name = L"IndexPnl";
			this->IndexPnl->Size = System::Drawing::Size(48, 19);
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
			// CompareDataTxt
			// 
			this->CompareDataTxt->AutoSize = true;
			this->CompareDataTxt->Location = System::Drawing::Point(153, 27);
			this->CompareDataTxt->Name = L"CompareDataTxt";
			this->CompareDataTxt->Size = System::Drawing::Size(30, 13);
			this->CompareDataTxt->TabIndex = 14;
			this->CompareDataTxt->Text = L"Dato";
			// 
			// CompareDataTbx
			// 
			this->CompareDataTbx->Location = System::Drawing::Point(156, 46);
			this->CompareDataTbx->Name = L"CompareDataTbx";
			this->CompareDataTbx->Size = System::Drawing::Size(100, 20);
			this->CompareDataTbx->TabIndex = 12;
			// 
			// AddColumnPnl
			// 
			this->AddColumnPnl->Controls->Add(this->AddColumnBtn);
			this->AddColumnPnl->Controls->Add(this->AddColumnTxt);
			this->AddColumnPnl->Controls->Add(this->ColumnTypeCbx);
			this->AddColumnPnl->Controls->Add(this->ColumnTypeTxt);
			this->AddColumnPnl->Controls->Add(this->NameColumnTbx);
			this->AddColumnPnl->Controls->Add(this->NameColumnTxt);
			this->AddColumnPnl->Location = System::Drawing::Point(962, 126);
			this->AddColumnPnl->Name = L"AddColumnPnl";
			this->AddColumnPnl->Size = System::Drawing::Size(54, 27);
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
			this->ColumnTypeCbx->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Ninguno", L"Numeros", L"Palabras", L"Letras" });
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
			// FilterTypeTbx
			// 
			this->FilterTypeTbx->FormattingEnabled = true;
			this->FilterTypeTbx->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Buscar", L"Igual a", L"Mayor que", L"Menor que",
					L"Contiene", L"No contiene", L"Inicia con", L"Termina con", L"Orden ascendente", L"Orden descendente"
			});
			this->FilterTypeTbx->Location = System::Drawing::Point(13, 48);
			this->FilterTypeTbx->Name = L"FilterTypeTbx";
			this->FilterTypeTbx->Size = System::Drawing::Size(121, 21);
			this->FilterTypeTbx->TabIndex = 11;
			this->FilterTypeTbx->Text = L"Ninguno";
			// 
			// FilterTypeTxt
			// 
			this->FilterTypeTxt->AutoSize = true;
			this->FilterTypeTxt->Location = System::Drawing::Point(10, 27);
			this->FilterTypeTxt->Name = L"FilterTypeTxt";
			this->FilterTypeTxt->Size = System::Drawing::Size(65, 13);
			this->FilterTypeTxt->TabIndex = 10;
			this->FilterTypeTxt->Text = L"Tipo de filtro";
			// 
			// LoadingPbx
			// 
			this->LoadingPbx->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadingPbx.Image")));
			this->LoadingPbx->Location = System::Drawing::Point(445, 10);
			this->LoadingPbx->Name = L"LoadingPbx";
			this->LoadingPbx->Size = System::Drawing::Size(30, 30);
			this->LoadingPbx->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LoadingPbx->TabIndex = 9;
			this->LoadingPbx->TabStop = false;
			// 
			// TableSettingsPnl
			// 
			this->TableSettingsPnl->Controls->Add(this->DataColumnTxt);
			this->TableSettingsPnl->Controls->Add(this->AddDataColumnBtn);
			this->TableSettingsPnl->Controls->Add(this->DataColumnTbx);
			this->TableSettingsPnl->Controls->Add(this->CreateTableBtn);
			this->TableSettingsPnl->Controls->Add(this->NroColumnTxt);
			this->TableSettingsPnl->Controls->Add(this->NColumnsTxt);
			this->TableSettingsPnl->Controls->Add(this->AddTableNameBtn);
			this->TableSettingsPnl->Controls->Add(this->TableNameTbx);
			this->TableSettingsPnl->Controls->Add(this->TableNameTxt);
			this->TableSettingsPnl->Controls->Add(this->jje);
			this->TableSettingsPnl->Controls->Add(this->ColumnNameTbx);
			this->TableSettingsPnl->Controls->Add(this->TypeTxt);
			this->TableSettingsPnl->Controls->Add(this->TypeCbx);
			this->TableSettingsPnl->Controls->Add(this->ColumnNameTxt);
			this->TableSettingsPnl->Location = System::Drawing::Point(32, 0);
			this->TableSettingsPnl->Margin = System::Windows::Forms::Padding(2);
			this->TableSettingsPnl->Name = L"TableSettingsPnl";
			this->TableSettingsPnl->Size = System::Drawing::Size(785, 66);
			this->TableSettingsPnl->TabIndex = 10;
			// 
			// DataColumnTxt
			// 
			this->DataColumnTxt->AutoSize = true;
			this->DataColumnTxt->Location = System::Drawing::Point(273, 9);
			this->DataColumnTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->DataColumnTxt->Name = L"DataColumnTxt";
			this->DataColumnTxt->Size = System::Drawing::Size(104, 13);
			this->DataColumnTxt->TabIndex = 27;
			this->DataColumnTxt->Text = L"Datos de la columna";
			// 
			// AddDataColumnBtn
			// 
			this->AddDataColumnBtn->Location = System::Drawing::Point(419, 25);
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
			this->DataColumnTbx->Location = System::Drawing::Point(272, 25);
			this->DataColumnTbx->Margin = System::Windows::Forms::Padding(2);
			this->DataColumnTbx->Name = L"DataColumnTbx";
			this->DataColumnTbx->Size = System::Drawing::Size(144, 20);
			this->DataColumnTbx->TabIndex = 25;
			// 
			// CreateTableBtn
			// 
			this->CreateTableBtn->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->CreateTableBtn->Location = System::Drawing::Point(457, 58);
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
			// jje
			// 
			this->jje->Location = System::Drawing::Point(232, 68);
			this->jje->Margin = System::Windows::Forms::Padding(2);
			this->jje->Name = L"jje";
			this->jje->Size = System::Drawing::Size(56, 19);
			this->jje->TabIndex = 18;
			this->jje->Text = L"Add";
			this->jje->UseVisualStyleBackColor = true;
			this->jje->Click += gcnew System::EventHandler(this, &Tabla_Forms::ButtonColumnName_Click);
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
			// MenuPnl
			// 
			this->MenuPnl->BackColor = System::Drawing::SystemColors::Control;
			this->MenuPnl->Controls->Add(this->btnFilter);
			this->MenuPnl->Controls->Add(this->btnIndex);
			this->MenuPnl->Controls->Add(this->btnAddData);
			this->MenuPnl->Controls->Add(this->btnAddColumn);
			this->MenuPnl->Controls->Add(this->pictureBox1);
			this->MenuPnl->Location = System::Drawing::Point(-198, 0);
			this->MenuPnl->Name = L"MenuPnl";
			this->MenuPnl->Size = System::Drawing::Size(228, 392);
			this->MenuPnl->TabIndex = 11;
			this->MenuPnl->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::MenuPnl_MouseEnter);
			// 
			// btnFilter
			// 
			this->btnFilter->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnFilter->FlatAppearance->BorderSize = 0;
			this->btnFilter->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFilter->Location = System::Drawing::Point(0, 137);
			this->btnFilter->Margin = System::Windows::Forms::Padding(0);
			this->btnFilter->Name = L"btnFilter";
			this->btnFilter->Size = System::Drawing::Size(228, 23);
			this->btnFilter->TabIndex = 4;
			this->btnFilter->Text = L"Filtrar Columna";
			this->btnFilter->UseVisualStyleBackColor = false;
			this->btnFilter->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnFilter_Click);
			// 
			// btnIndex
			// 
			this->btnIndex->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnIndex->FlatAppearance->BorderSize = 0;
			this->btnIndex->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnIndex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIndex->Location = System::Drawing::Point(0, 108);
			this->btnIndex->Margin = System::Windows::Forms::Padding(0);
			this->btnIndex->Name = L"btnIndex";
			this->btnIndex->Size = System::Drawing::Size(228, 23);
			this->btnIndex->TabIndex = 3;
			this->btnIndex->Text = L"Indexar Columna";
			this->btnIndex->UseVisualStyleBackColor = false;
			this->btnIndex->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnIndex_Click);
			// 
			// btnAddData
			// 
			this->btnAddData->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAddData->FlatAppearance->BorderSize = 0;
			this->btnAddData->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnAddData->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddData->Location = System::Drawing::Point(0, 80);
			this->btnAddData->Margin = System::Windows::Forms::Padding(0);
			this->btnAddData->Name = L"btnAddData";
			this->btnAddData->Size = System::Drawing::Size(228, 23);
			this->btnAddData->TabIndex = 2;
			this->btnAddData->Text = L"Agregar Dato";
			this->btnAddData->UseVisualStyleBackColor = false;
			this->btnAddData->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnAddData_Click);
			// 
			// btnAddColumn
			// 
			this->btnAddColumn->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnAddColumn->FlatAppearance->BorderSize = 0;
			this->btnAddColumn->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnAddColumn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddColumn->Location = System::Drawing::Point(0, 53);
			this->btnAddColumn->Margin = System::Windows::Forms::Padding(0);
			this->btnAddColumn->Name = L"btnAddColumn";
			this->btnAddColumn->Size = System::Drawing::Size(228, 23);
			this->btnAddColumn->TabIndex = 1;
			this->btnAddColumn->Text = L"Agregar Columna";
			this->btnAddColumn->UseVisualStyleBackColor = false;
			this->btnAddColumn->Click += gcnew System::EventHandler(this, &Tabla_Forms::btnAddColumn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(198, 1);
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
			this->FilterPnl->Controls->Add(this->ExtraDataCbx);
			this->FilterPnl->Controls->Add(this->ExtraDataTxt);
			this->FilterPnl->Controls->Add(this->FilterBtn);
			this->FilterPnl->Controls->Add(this->label7);
			this->FilterPnl->Controls->Add(this->FilterTypeCbx);
			this->FilterPnl->Controls->Add(this->label8);
			this->FilterPnl->Controls->Add(this->NameColumnTbx4);
			this->FilterPnl->Controls->Add(this->label9);
			this->FilterPnl->Location = System::Drawing::Point(972, 275);
			this->FilterPnl->Name = L"FilterPnl";
			this->FilterPnl->Size = System::Drawing::Size(44, 40);
			this->FilterPnl->TabIndex = 13;
			// 
			// ExtraDataCbx
			// 
			this->ExtraDataCbx->Location = System::Drawing::Point(13, 231);
			this->ExtraDataCbx->Name = L"ExtraDataCbx";
			this->ExtraDataCbx->Size = System::Drawing::Size(187, 20);
			this->ExtraDataCbx->TabIndex = 8;
			this->ExtraDataCbx->Visible = false;
			// 
			// ExtraDataTxt
			// 
			this->ExtraDataTxt->AutoSize = true;
			this->ExtraDataTxt->Location = System::Drawing::Point(10, 211);
			this->ExtraDataTxt->Name = L"ExtraDataTxt";
			this->ExtraDataTxt->Size = System::Drawing::Size(113, 13);
			this->ExtraDataTxt->TabIndex = 7;
			this->ExtraDataTxt->Text = L"Nombre de la columna";
			this->ExtraDataTxt->Visible = false;
			// 
			// FilterBtn
			// 
			this->FilterBtn->Location = System::Drawing::Point(36, 274);
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
			this->label7->Location = System::Drawing::Point(19, 45);
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
			this->FilterTypeCbx->Location = System::Drawing::Point(13, 170);
			this->FilterTypeCbx->Name = L"FilterTypeCbx";
			this->FilterTypeCbx->Size = System::Drawing::Size(187, 21);
			this->FilterTypeCbx->TabIndex = 4;
			this->FilterTypeCbx->SelectedIndexChanged += gcnew System::EventHandler(this, &Tabla_Forms::FilterTypeCbx_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 149);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 13);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Tipo de filtro";
			// 
			// NameColumnTbx4
			// 
			this->NameColumnTbx4->Location = System::Drawing::Point(13, 111);
			this->NameColumnTbx4->Name = L"NameColumnTbx4";
			this->NameColumnTbx4->Size = System::Drawing::Size(187, 20);
			this->NameColumnTbx4->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 91);
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
			this->Controls->Add(this->AddDataPnl);
			this->Controls->Add(this->IndexPnl);
			this->Controls->Add(this->RemoveDataPnl);
			this->Controls->Add(this->AddColumnPnl);
			this->Controls->Add(this->FilterPnl);
			this->Controls->Add(this->MenuPnl);
			this->Controls->Add(this->TableSettingsPnl);
			this->Controls->Add(this->DataTablePnl);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			this->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_MouseEnter);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->EndInit();
			this->DataTablePnl->ResumeLayout(false);
			this->DataTablePnl->PerformLayout();
			this->AddDataPnl->ResumeLayout(false);
			this->AddDataPnl->PerformLayout();
			this->RemoveDataPnl->ResumeLayout(false);
			this->RemoveDataPnl->PerformLayout();
			this->IndexPnl->ResumeLayout(false);
			this->IndexPnl->PerformLayout();
			this->AddColumnPnl->ResumeLayout(false);
			this->AddColumnPnl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadingPbx))->EndInit();
			this->TableSettingsPnl->ResumeLayout(false);
			this->TableSettingsPnl->PerformLayout();
			this->MenuPnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->FilterPnl->ResumeLayout(false);
			this->FilterPnl->PerformLayout();
			this->ResumeLayout(false);

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
		ExtraDataCbx->Visible = false;
		ExtraDataTxt->Visible = false;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Comprobar();
	}
	private: System::Void ButtonColumnName_Click(System::Object^ sender, System::EventArgs^ e) {
		/*nColumn += 1;
		NroColumnTxt->Text = nColumn.ToString();
		DataGridViewTextBoxColumn^ CHeader = gcnew DataGridViewTextBoxColumn;
		CHeader->HeaderText = ColumnNameTbx->Text;
		this->TableDgv->Columns->Add(CHeader);
		string type;
		MarshalString(TypeCbx->Text, type);
		table->AddColumn(type);
		ColumnNameTbx->Text = "";
		DataColumnTxt->Text = "Datos de la Columna " + nColumn;*/
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
		setActivePanel(TableSettingsPnl->Name);
		//panel1->Dock = DockStyle::Fill;
	}
	private: void setActivePanel(String^ panelName) {
		this->TableSettingsPnl->Visible = TableSettingsPnl->Name == panelName;
		this->DataTablePnl->Visible = DataTablePnl->Name == panelName;
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (nColumn > 0) {
			string d;
			int n = 0;
			MarshalString(DataColumnTbx->Text, d);

			/*if (TypeCbx->Text == "letters"){
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
			DataColumnTbx->Text = "";*/
		}
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
			n = (TableDgv->RowCount <= n ?
				TableDgv->Rows->Add() : n - 1);
			TableDgv->Rows[n]->Cells[nColumn - 1]->Value = DataTbx->Text;
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
	private: System::Void FilterTypeCbx_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ t = FilterTypeCbx->Text;
		ExtraDataCbx->Visible = true;
		ExtraDataTxt->Visible = true;
		if (t == "Buscar") ExtraDataTxt->Text = "Dato a buscar";
		else if (t == "Orden ascendente" || t == "Orden descendente") {
			ExtraDataCbx->Visible = false;
			ExtraDataTxt->Visible = false;
			ExtraDataCbx->Text = "";
		}
		else ExtraDataTxt->Text = "Dato a comparar";
	}
	private: System::Void FilterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ t = FilterTypeCbx->Text;
		if (t == "Ninguno") return;
		Tabla_Forms^ auxTable = gcnew Tabla_Forms();
		auxTable->setDataGridView(this->TableDgv);
		if (t == "Buscar") {

		}
		else if (t == "Iguales a") {

		}
		else if (t == "Mayores que") {

		}
		else if (t == "Menores que") {

		}
		else if (t == "Contiene") {

		}
		else if (t == "No contiene") {

		}
		else if (t == "Empieza con") {

		}
		else if (t == "Termina con") {

		}
		else if (t == "Orden ascendente") {

		}
		else if (t == "Orden descendente") {

		}
		auxTable->Show();
	}
	public: void setDataGridView(DataGridView^ dgv) {
		this->TableDgv = dgv;
	}
};
}
