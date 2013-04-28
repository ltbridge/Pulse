#pragma once
#include "stdafx.h"
#include "PresEditAddView.h"
#include "SessionData.h"
#include "PatientGraphView.h"

using namespace std;
using namespace System;

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PatientMainView
	/// </summary>
	public ref class PatientMainView : public System::Windows::Forms::Form
	{
	public:
		PatientMainView(SessionData ^ s)
		{
			session = s;
			InitializeComponent();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			CheckPermissions();
			this->Show();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PatientMainView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;










	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::LinkLabel^  linkLabel5;
	private: System::Windows::Forms::LinkLabel^  linkLabel4;
	private: System::Windows::Forms::LinkLabel^  linkLabel3;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::RichTextBox^  commentList;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker;
	private: System::Windows::Forms::Button^  add_btn;
	private: System::Windows::Forms::RichTextBox^  newComment;
private: System::Windows::Forms::LinkLabel^  linkLabel6;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::TextBox^  textBox13;
private: System::Windows::Forms::Label^  label24;
	private:
		SessionData ^ session;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->linkLabel5 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel4 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->commentList = (gcnew System::Windows::Forms::RichTextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->add_btn = (gcnew System::Windows::Forms::Button());
			this->newComment = (gcnew System::Windows::Forms::RichTextBox());
			this->linkLabel6 = (gcnew System::Windows::Forms::LinkLabel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(9, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(548, 388);
			this->tabControl1->TabIndex = 12;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->textBox7);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Controls->Add(this->textBox9);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(540, 359);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Info";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(144, 214);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 7;
			this->textBox7->Text = L"85555";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(144, 181);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 6;
			this->textBox6->Text = L"AZ";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(144, 148);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			this->textBox5->Text = L"Phoenix";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(144, 114);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"1234 E Main";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(144, 83);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"555-555-5555";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(144, 47);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"Mae";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(144, 248);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 8;
			this->textBox8->Text = L"Aetna";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(144, 279);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 9;
			this->textBox9->Text = L"123456789";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(144, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Sally";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(169, 314);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PatientMainView::button1_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(33, 282);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(48, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Policy #:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(33, 248);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(104, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Insurance Company:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(34, 214);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Zipcode:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(33, 181);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"State:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(34, 148);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"City:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(33, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Address:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(34, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Phone #:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(33, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Last Name:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(34, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First Name:";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->textBox13);
			this->tabPage2->Controls->Add(this->label24);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->dateTimePicker2);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->textBox10);
			this->tabPage2->Controls->Add(this->textBox11);
			this->tabPage2->Controls->Add(this->textBox12);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->label19);
			this->tabPage2->Controls->Add(this->label20);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(540, 359);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Stats";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(327, 236);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 24;
			this->button3->Text = L"Add Data";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &PatientMainView::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(42, 225);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(91, 23);
			this->button4->TabIndex = 23;
			this->button4->Text = L"View Graph";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &PatientMainView::button4_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(75, 64);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(46, 17);
			this->label21->TabIndex = 22;
			this->label21->Text = L"Date: ";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dateTimePicker2->Location = System::Drawing::Point(10, 84);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 21;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(421, 196);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(43, 13);
			this->label15->TabIndex = 20;
			this->label15->Text = L"mg / dl ";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(265, 115);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(43, 13);
			this->label16->TabIndex = 19;
			this->label16->Text = L"Systolic";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(421, 44);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(20, 13);
			this->label17->TabIndex = 18;
			this->label17->Text = L"lbs";
			// 
			// textBox10
			// 
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(315, 193);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 17;
			// 
			// textBox11
			// 
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(315, 106);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 16;
			// 
			// textBox12
			// 
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(315, 44);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(100, 20);
			this->textBox12->TabIndex = 15;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(324, 173);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(67, 13);
			this->label18->TabIndex = 14;
			this->label18->Text = L"Sugar Level:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(324, 90);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(81, 13);
			this->label19->TabIndex = 13;
			this->label19->Text = L"Blood Pressure:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(337, 23);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(44, 13);
			this->label20->TabIndex = 12;
			this->label20->Text = L"Weight:";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->linkLabel5);
			this->tabPage3->Controls->Add(this->linkLabel4);
			this->tabPage3->Controls->Add(this->linkLabel3);
			this->tabPage3->Controls->Add(this->linkLabel2);
			this->tabPage3->Controls->Add(this->linkLabel1);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->label13);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(540, 359);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Prescriptions";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// linkLabel5
			// 
			this->linkLabel5->AutoSize = true;
			this->linkLabel5->Location = System::Drawing::Point(155, 238);
			this->linkLabel5->Name = L"linkLabel5";
			this->linkLabel5->Size = System::Drawing::Size(112, 17);
			this->linkLabel5->TabIndex = 14;
			this->linkLabel5->TabStop = true;
			this->linkLabel5->Text = L"Add Prescription";
			// 
			// linkLabel4
			// 
			this->linkLabel4->AutoSize = true;
			this->linkLabel4->Location = System::Drawing::Point(155, 187);
			this->linkLabel4->Name = L"linkLabel4";
			this->linkLabel4->Size = System::Drawing::Size(112, 17);
			this->linkLabel4->TabIndex = 13;
			this->linkLabel4->TabStop = true;
			this->linkLabel4->Text = L"Add Prescription";
			// 
			// linkLabel3
			// 
			this->linkLabel3->AutoSize = true;
			this->linkLabel3->Location = System::Drawing::Point(155, 130);
			this->linkLabel3->Name = L"linkLabel3";
			this->linkLabel3->Size = System::Drawing::Size(112, 17);
			this->linkLabel3->TabIndex = 12;
			this->linkLabel3->TabStop = true;
			this->linkLabel3->Text = L"Add Prescription";
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(155, 74);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(112, 17);
			this->linkLabel2->TabIndex = 11;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"Add Prescription";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(155, 25);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(112, 17);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Add Prescription";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &PatientMainView::linkLabel1_LinkClicked);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(23, 238);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(103, 17);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Prescription #5";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(23, 187);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(103, 17);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Prescription #4";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(23, 130);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(103, 17);
			this->label12->TabIndex = 7;
			this->label12->Text = L"Prescription #3";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(23, 74);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(103, 17);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Prescription #2";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(23, 25);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(103, 17);
			this->label14->TabIndex = 5;
			this->label14->Text = L"Prescription #1";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->commentList);
			this->tabPage4->Controls->Add(this->dateTimePicker);
			this->tabPage4->Controls->Add(this->add_btn);
			this->tabPage4->Controls->Add(this->newComment);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(540, 359);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Comments";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// commentList
			// 
			this->commentList->BackColor = System::Drawing::Color::White;
			this->commentList->Location = System::Drawing::Point(7, 43);
			this->commentList->Name = L"commentList";
			this->commentList->ReadOnly = true;
			this->commentList->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->commentList->Size = System::Drawing::Size(314, 291);
			this->commentList->TabIndex = 8;
			this->commentList->Text = L"";
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CustomFormat = L"MMMM dd , yyyy";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(183, 14);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(170, 23);
			this->dateTimePicker->TabIndex = 7;
			// 
			// add_btn
			// 
			this->add_btn->Location = System::Drawing::Point(389, 275);
			this->add_btn->Name = L"add_btn";
			this->add_btn->Size = System::Drawing::Size(81, 23);
			this->add_btn->TabIndex = 6;
			this->add_btn->Text = L"Add Comment";
			this->add_btn->UseVisualStyleBackColor = true;
			// 
			// newComment
			// 
			this->newComment->Location = System::Drawing::Point(327, 43);
			this->newComment->Name = L"newComment";
			this->newComment->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->newComment->Size = System::Drawing::Size(200, 226);
			this->newComment->TabIndex = 5;
			this->newComment->Text = L"Enter a new comment here";
			// 
			// linkLabel6
			// 
			this->linkLabel6->AutoSize = true;
			this->linkLabel6->Location = System::Drawing::Point(517, 9);
			this->linkLabel6->Name = L"linkLabel6";
			this->linkLabel6->Size = System::Drawing::Size(40, 13);
			this->linkLabel6->TabIndex = 15;
			this->linkLabel6->TabStop = true;
			this->linkLabel6->Text = L"Logout";
			this->linkLabel6->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &PatientMainView::linkLabel6_LinkClicked);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Maroon;
			this->label22->Location = System::Drawing::Point(70, 8);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(103, 13);
			this->label22->TabIndex = 14;
			this->label22->Text = L"Name Goes Here";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 8);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(58, 13);
			this->label23->TabIndex = 13;
			this->label23->Text = L"Welcome, ";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(267, 135);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(42, 13);
			this->label24->TabIndex = 25;
			this->label24->Text = L"Diatolic";
			// 
			// textBox13
			// 
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(315, 132);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 20);
			this->textBox13->TabIndex = 26;
			// 
			// PatientMainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 424);
			this->Controls->Add(this->linkLabel6);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->tabControl1);
			this->Name = L"PatientMainView";
			this->Text = L"Patient Information";
			this->Load += gcnew System::EventHandler(this, &PatientMainView::PatientMainView_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

			 
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Testingscreen ^ newScreen = gcnew Testingscreen;
			 //newScreen->ShowDialog();
			 //PatientMainView::Hide();
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
		 {
			 PresEditAddView ^ newPres = gcnew PresEditAddView(session);
			 newPres->Owner = this->Owner;
			 
			 
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String ^ temp = textBox1->Text; 
			 temp = textBox2->Text; 
			 temp = textBox3->Text; 
			 String ^ tempdate =  dateTimePicker2->Value.ToString("MM/dd/yyyy");;

			 //Save everything from the entered fields, into the database for the date specified

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 PatientGraphView ^ newGraph = gcnew PatientGraphView(session);
			 newGraph->Owner = this->Owner;
		 }
private: System::Void PatientMainView_Load(System::Object^  sender, System::EventArgs^  e) {
		 }

		 System::Void CheckPermissions(){
			 if(session->getcurrentUser()->gettype() == "Patient"){
				NoEdit();
				tabControl1->TabPages->Remove(tabPage4);
				this->ControlBox = false;
				this->label22->Text = session->getcurrentUser()->getfirstName()+" "+session->getcurrentUser()->getlastName();
			 } else {
				 this->label22->Visible = false;
				 this->label23->Visible = false;
				 this->linkLabel6->Visible = false;
			 }
			 PopulateFields(session->getcurrentPatient());
		 }

		 System::Void NoEdit(){
			this->textBox1->ReadOnly = true;
			this->textBox2->ReadOnly = true;
			this->textBox3->ReadOnly = true;
			this->textBox4->ReadOnly = true;
			this->textBox5->ReadOnly = true;
			this->textBox6->ReadOnly = true;
			this->textBox7->ReadOnly = true;
			this->textBox8->ReadOnly = true;
			this->textBox9->ReadOnly = true;
		 }

		 System::Void PopulateFields(Patient ^ patient){
			 this->textBox1->Text = patient->getFirst();
			 this->textBox2->Text = patient->getLast();
			 this->textBox3->Text = patient->getAddress();
			 this->textBox4->Text = patient->getCity();
			 this->textBox5->Text = patient->getState();
			 this->textBox6->Text = System::Convert::ToString(patient->getZipcode());
			 this->textBox7->Text = patient->getEmail();
			 this->textBox8->Text = patient->getInsurance();
			 this->textBox9->Text = patient->getPolicyNum();
		 }

private: System::Void linkLabel6_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			this->Owner->Show();
			this->Close();
		 }
};
}
//#endif
