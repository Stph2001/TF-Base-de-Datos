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
			currentColum = 0;
			menuSpeed = 1;

			for (int i = 0; i < MenuPnl->Controls->Count; i++) {
				MenuPnl->Controls[i]->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::MenuPnl_MouseEnter);
			}
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

	private: System::Windows::Forms::DataGridView^ TableDgv;
	private: System::Windows::Forms::Label^ TitleTableTxt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ CheckBtn;
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
	private: System::Windows::Forms::ComboBox^ FilterTypeTbx;
	private: System::Windows::Forms::Label^ FilterTypeTxt;
	private: System::Windows::Forms::Label^ CompareDataTxt;
	private: System::Windows::Forms::Button^ IndexBtn;
	private: System::Windows::Forms::TextBox^ CompareDataTbx;
	private: System::Windows::Forms::Button^ NoseBtn;
	private: System::Windows::Forms::Panel^ MenuPnl;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ BotonPrueba;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->NoseBtn = (gcnew System::Windows::Forms::Button());
			this->CompareDataTxt = (gcnew System::Windows::Forms::Label());
			this->IndexBtn = (gcnew System::Windows::Forms::Button());
			this->CompareDataTbx = (gcnew System::Windows::Forms::TextBox());
			this->FilterTypeTbx = (gcnew System::Windows::Forms::ComboBox());
			this->FilterTypeTxt = (gcnew System::Windows::Forms::Label());
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
			this->MenuPnl = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->BotonPrueba = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadingPbx))->BeginInit();
			this->panel2->SuspendLayout();
			this->MenuPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->TableDgv->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Tabla_Forms::TableDgv_CellClick);
			this->TableDgv->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Tabla_Forms::Table_KeyDown);
			// 
			// TitleTableTxt
			// 
			this->TitleTableTxt->AutoSize = true;
			this->TitleTableTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TitleTableTxt->Location = System::Drawing::Point(533, 41);
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
			this->CheckBtn->Location = System::Drawing::Point(878, 20);
			this->CheckBtn->Margin = System::Windows::Forms::Padding(2);
			this->CheckBtn->Name = L"CheckBtn";
			this->CheckBtn->Size = System::Drawing::Size(81, 27);
			this->CheckBtn->TabIndex = 3;
			this->CheckBtn->Text = L"Comprobar";
			this->CheckBtn->UseVisualStyleBackColor = true;
			this->CheckBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->NoseBtn);
			this->panel1->Controls->Add(this->CompareDataTxt);
			this->panel1->Controls->Add(this->IndexBtn);
			this->panel1->Controls->Add(this->CompareDataTbx);
			this->panel1->Controls->Add(this->FilterTypeTbx);
			this->panel1->Controls->Add(this->FilterTypeTxt);
			this->panel1->Controls->Add(this->LoadingPbx);
			this->panel1->Controls->Add(this->TableDgv);
			this->panel1->Controls->Add(this->TitleTableTxt);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->CheckBtn);
			this->panel1->Location = System::Drawing::Point(32, 70);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(996, 322);
			this->panel1->TabIndex = 9;
			// 
			// NoseBtn
			// 
			this->NoseBtn->Location = System::Drawing::Point(364, 39);
			this->NoseBtn->Name = L"NoseBtn";
			this->NoseBtn->Size = System::Drawing::Size(75, 23);
			this->NoseBtn->TabIndex = 15;
			this->NoseBtn->Text = L"Nose";
			this->NoseBtn->UseVisualStyleBackColor = true;
			// 
			// CompareDataTxt
			// 
			this->CompareDataTxt->AutoSize = true;
			this->CompareDataTxt->Location = System::Drawing::Point(258, 25);
			this->CompareDataTxt->Name = L"CompareDataTxt";
			this->CompareDataTxt->Size = System::Drawing::Size(30, 13);
			this->CompareDataTxt->TabIndex = 14;
			this->CompareDataTxt->Text = L"Dato";
			// 
			// IndexBtn
			// 
			this->IndexBtn->Location = System::Drawing::Point(756, 38);
			this->IndexBtn->Name = L"IndexBtn";
			this->IndexBtn->Size = System::Drawing::Size(75, 23);
			this->IndexBtn->TabIndex = 13;
			this->IndexBtn->Text = L"Indexar";
			this->IndexBtn->UseVisualStyleBackColor = true;
			this->IndexBtn->Click += gcnew System::EventHandler(this, &Tabla_Forms::IndexBtn_Click);
			// 
			// CompareDataTbx
			// 
			this->CompareDataTbx->Location = System::Drawing::Point(256, 41);
			this->CompareDataTbx->Name = L"CompareDataTbx";
			this->CompareDataTbx->Size = System::Drawing::Size(100, 20);
			this->CompareDataTbx->TabIndex = 12;
			// 
			// FilterTypeTbx
			// 
			this->FilterTypeTbx->FormattingEnabled = true;
			this->FilterTypeTbx->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Buscar", L"Igual a", L"Mayor que", L"Menor que",
					L"Contiene", L"No contiene", L"Inicia con", L"Termina con", L"Orden ascendente", L"Orden descendente"
			});
			this->FilterTypeTbx->Location = System::Drawing::Point(81, 41);
			this->FilterTypeTbx->Name = L"FilterTypeTbx";
			this->FilterTypeTbx->Size = System::Drawing::Size(121, 21);
			this->FilterTypeTbx->TabIndex = 11;
			this->FilterTypeTbx->Text = L"Ninguno";
			// 
			// FilterTypeTxt
			// 
			this->FilterTypeTxt->AutoSize = true;
			this->FilterTypeTxt->Location = System::Drawing::Point(78, 20);
			this->FilterTypeTxt->Name = L"FilterTypeTxt";
			this->FilterTypeTxt->Size = System::Drawing::Size(65, 13);
			this->FilterTypeTxt->TabIndex = 10;
			this->FilterTypeTxt->Text = L"Tipo de filtro";
			// 
			// LoadingPbx
			// 
			this->LoadingPbx->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadingPbx.Image")));
			this->LoadingPbx->Location = System::Drawing::Point(995, 39);
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
			this->panel2->Location = System::Drawing::Point(32, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(996, 66);
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
			// MenuPnl
			// 
			this->MenuPnl->BackColor = System::Drawing::SystemColors::Control;
			this->MenuPnl->Controls->Add(this->button3);
			this->MenuPnl->Controls->Add(this->button2);
			this->MenuPnl->Controls->Add(this->button1);
			this->MenuPnl->Controls->Add(this->BotonPrueba);
			this->MenuPnl->Controls->Add(this->pictureBox1);
			this->MenuPnl->Location = System::Drawing::Point(-198, 0);
			this->MenuPnl->Name = L"MenuPnl";
			this->MenuPnl->Size = System::Drawing::Size(228, 392);
			this->MenuPnl->TabIndex = 11;
			this->MenuPnl->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::MenuPnl_MouseEnter);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(0, 137);
			this->button3->Margin = System::Windows::Forms::Padding(0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(228, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Filtrar";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(0, 108);
			this->button2->Margin = System::Windows::Forms::Padding(0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(228, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Filtrar";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(0, 80);
			this->button1->Margin = System::Windows::Forms::Padding(0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(228, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Filtrar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// BotonPrueba
			// 
			this->BotonPrueba->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BotonPrueba->FlatAppearance->BorderSize = 0;
			this->BotonPrueba->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BotonPrueba->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotonPrueba->Location = System::Drawing::Point(0, 53);
			this->BotonPrueba->Margin = System::Windows::Forms::Padding(0);
			this->BotonPrueba->Name = L"BotonPrueba";
			this->BotonPrueba->Size = System::Drawing::Size(228, 23);
			this->BotonPrueba->TabIndex = 1;
			this->BotonPrueba->Text = L"Filtrar";
			this->BotonPrueba->UseVisualStyleBackColor = false;
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
			// Tabla_Forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 392);
			this->Controls->Add(this->MenuPnl);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Tabla_Forms";
			this->Text = L"Tabla_Forms";
			this->MouseEnter += gcnew System::EventHandler(this, &Tabla_Forms::Tabla_Forms_MouseEnter);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TableDgv))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadingPbx))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->MenuPnl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Table_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
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
		setActivePanel(panel2->Name);
		//panel1->Dock = DockStyle::Fill;
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
		
	}
	private: System::Void TableDgv_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		currentColum = e->ColumnIndex;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		MenuPnl->Location = Point(MenuPnl->Location.X + menuSpeed, MenuPnl->Location.Y);
		if (finalX == 0) {
			if (MenuPnl->Location.X >= finalX) {
				MenuPnl->Location = Point(0, 0);
				timer1->Stop();
			}
		}
		else {
			if (MenuPnl->Location.X <= finalX) {
				MenuPnl->Location = Point(-198, 0);
				timer1->Stop();
			}
		}
	}
	private: System::Void MenuPnl_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		if (finalX == 0) return;
		finalX = 0; menuSpeed = 10;
		timer1->Start();
	}
	private: System::Void Tabla_Forms_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		if (finalX == -198) return;
		finalX = -198; menuSpeed = -10;
		timer1->Start();
	}
};
}
