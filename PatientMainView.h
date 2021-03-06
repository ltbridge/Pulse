#pragma once
#include "stdafx.h"
#include "PresEditAddView.h"
#include "SessionData.h"
#include "CommData.h"
#include "PresData.h"
#include "StatData.h"
#include "PtntData.h"
#include "PatientGraphView.h"
#include "Patient.h"

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
	/// Main screen containing tabs and all functionality for the following use cases:
	/// Comments (restricted to Doctors and Nurses only)
	/// Prescriptions (editing restricted to Doctors and Nurses only)
	/// Stats
	/// Information (editing restricted to Doctors and Nurses only)
	/// </summary>
	public ref class PatientMainView : public System::Windows::Forms::Form
	{

		private:
		SessionData ^ session; Patient ^ patient; PtntData ^ PtntDB;
		CommData ^ CommDB; PresData ^ PresDB; StatData ^ StatDB;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  PresID;



	private: System::Windows::Forms::Label^  label11;

	public:

		//two constructors differ based on where the user comes from

		//main view for patients, does not instantiate comments because they can't see it
		PatientMainView(SessionData ^ s)
		{
			InitializeComponent();

			session = s;
			patient = session->getcurrentPatient();

			//instantiate database classes
			PtntDB = gcnew PtntData();
			StatDB = gcnew StatData();
			PresDB = gcnew PresData();

			//fill datagridviews and forms
			populateStatFields();
			pullPrescriptions();


			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			CheckPermissions();
			this->Show();
		}


		//view for doctors and nurses coming from elsewhere. the passed in patient
		//object ensures this form and all owned forms can edit a separate patient
		//from other opened instances of this form
		PatientMainView(SessionData ^ s, Patient ^ p)
		{
			InitializeComponent();

			session = s;
			patient = p;
			
			//instantiate database classes
			PtntDB = gcnew PtntData();
			CommDB = gcnew CommData();		
			StatDB = gcnew StatData();
			PresDB = gcnew PresData();

			//fill fields and forms
			populateStatFields();
			pullComments();
			pullPrescriptions();


			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			CheckPermissions();
			this->Show();
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
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::DataGridView^  dataGridView1;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
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
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PresID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->commentList = (gcnew System::Windows::Forms::RichTextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->add_btn = (gcnew System::Windows::Forms::Button());
			this->newComment = (gcnew System::Windows::Forms::RichTextBox());
			this->linkLabel6 = (gcnew System::Windows::Forms::LinkLabel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
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
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->textBox14);
			this->tabPage1->Controls->Add(this->label25);
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
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label11->Location = System::Drawing::Point(183, 314);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(168, 17);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Successfully Updated!";
			this->label11->Visible = false;
			// 
			// textBox14
			// 
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(144, 203);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 20);
			this->textBox14->TabIndex = 14;
			this->textBox14->Text = L"85555";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(34, 206);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(32, 13);
			this->label25->TabIndex = 12;
			this->label25->Text = L"Email";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(144, 177);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 7;
			this->textBox7->Text = L"85555";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(144, 151);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 6;
			this->textBox6->Text = L"AZ";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(144, 125);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			this->textBox5->Text = L"Phoenix";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(144, 99);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"1234 E Main";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(144, 73);
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
			this->textBox8->Location = System::Drawing::Point(414, 17);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 8;
			this->textBox8->Text = L"Aetna";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(414, 43);
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
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(203, 258);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 53);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Update";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PatientMainView::button1_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(303, 46);
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
			this->label8->Location = System::Drawing::Point(303, 20);
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
			this->label7->Location = System::Drawing::Point(34, 180);
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
			this->label6->Location = System::Drawing::Point(33, 154);
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
			this->label5->Location = System::Drawing::Point(34, 128);
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
			this->label4->Location = System::Drawing::Point(33, 102);
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
			this->label3->Location = System::Drawing::Point(34, 76);
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
			// textBox13
			// 
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(315, 132);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 20);
			this->textBox13->TabIndex = 26;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(267, 135);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(47, 13);
			this->label24->TabIndex = 25;
			this->label24->Text = L"Diastolic";
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
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &PatientMainView::dateTimePicker2_ValueChanged);
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
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Controls->Add(this->dataGridView1);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(540, 359);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Prescriptions";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(175, 320);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 36);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Add Prescription";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PatientMainView::button2_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Number, 
				this->Name, this->PresID});
			this->dataGridView1->Location = System::Drawing::Point(10, 23);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(510, 291);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PatientMainView::dataGridView1_CellContentClick);
			// 
			// Number
			// 
			this->Number->HeaderText = L"Number";
			this->Number->Name = L"Number";
			this->Number->ReadOnly = true;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Name";
			this->Name->Name = L"Name";
			this->Name->ReadOnly = true;
			this->Name->Width = 350;
			// 
			// PresID
			// 
			this->PresID->HeaderText = L"PresID";
			this->PresID->Name = L"PresID";
			this->PresID->ReadOnly = true;
			this->PresID->Visible = false;
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
			this->dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &PatientMainView::dateTimePicker_ValueChanged);
			// 
			// add_btn
			// 
			this->add_btn->Location = System::Drawing::Point(389, 275);
			this->add_btn->Name = L"add_btn";
			this->add_btn->Size = System::Drawing::Size(81, 23);
			this->add_btn->TabIndex = 6;
			this->add_btn->Text = L"Add Comment";
			this->add_btn->UseVisualStyleBackColor = true;
			this->add_btn->Click += gcnew System::EventHandler(this, &PatientMainView::add_btn_Click);
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
			// PatientMainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 424);
			this->Controls->Add(this->linkLabel6);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->tabControl1);
			//this->Name = L"PatientMainView";
			this->Text = L"Patient Information";
			this->Activated += gcnew System::EventHandler(this, &PatientMainView::PatientMain_Activated);
			this->Load += gcnew System::EventHandler(this, &PatientMainView::PatientMainView_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
		//update information, button is hidden from patients
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 PtntDB->update(patient->getPatientID(), this->textBox1->Text, this->textBox2->Text, this->textBox4->Text,
							this->textBox5->Text, this->textBox6->Text, Convert::ToInt32(this->textBox7->Text), this->textBox3->Text, 
							this->textBox14->Text, this->textBox8->Text, this->textBox9->Text);
			 this->label11->Visible = true; //tell user their save was successful
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //Testingscreen ^ newScreen = gcnew Testingscreen;
			 //newScreen->ShowDialog();
			 //PatientMainView::Hide();
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
		 {
		 }

		 //add all stat fields to the database for the selected time
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String ^ sugar = textBox10->Text; 
			 String ^ systolic = textBox11->Text; 
			 String ^ diastolic = textBox13->Text; 
			 String ^ weight = textBox12->Text; 
			 DateTime ^ tempdate =  dateTimePicker2->Value;

			 //do not add fields if they are blank
			 if(sugar != "")
				 StatDB->add("sugar", tempdate, Convert::ToInt32(sugar), patient->getPatientID());
			 if(systolic != "")
				 StatDB->add("systolic", tempdate, Convert::ToInt32(systolic), patient->getPatientID());
			 if(diastolic != "")
				 StatDB->add("diastolic", tempdate, Convert::ToInt32(diastolic), patient->getPatientID());
			 if(weight != "")
				 StatDB->add("weight", tempdate, Convert::ToInt32(weight), patient->getPatientID());

		 }
		 //display graph view
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 PatientGraphView ^ newGraph = gcnew PatientGraphView(session, patient);
			 newGraph->Owner = this;
		 }
private: System::Void PatientMainView_Load(System::Object^  sender, System::EventArgs^  e) {
		 }

		 //check permissions and hide buttons from patients, and make certain fields uneditable
		 System::Void CheckPermissions(){
			 if(session->getcurrentUser()->gettype() == "Patient"){
				NoEdit(); //fields uneditable
				tabControl1->TabPages->Remove(tabPage4); //remove comment tab
				this->ControlBox = false; //since this is the main screen for patients, create logout link
				this->button1->Visible = false; //hide other buttons
				this->button2->Visible = false;
				//personalized welcome message
				this->label22->Text = session->getcurrentUser()->getfirstName()+" "+session->getcurrentUser()->getlastName();
			 } else {
				 //hide all personalized information and logout button
				 this->label22->Visible = false;
				 this->label23->Visible = false;
				 this->linkLabel6->Visible = false;
			 }
			 //populate information fields
			 PopulateFields();
		 }

		 //make information fields uneditable
		 //used for patient authority level
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
			this->textBox14->ReadOnly = true;
		 }

		 //fill fields according to patient class assigned to this form
		 System::Void PopulateFields(){
			 this->textBox1->Text = patient->getFirst();
			 this->textBox2->Text = patient->getLast();
			 this->textBox3->Text = patient->getPhone();
			 this->textBox4->Text = patient->getAddress();
			 this->textBox5->Text = patient->getCity();
			 this->textBox6->Text = patient->getState();
			 this->textBox7->Text = System::Convert::ToString(patient->getZipcode());
			 this->textBox14->Text = patient->getEmail();
			 this->textBox8->Text = patient->getInsurance();
			 this->textBox9->Text = patient->getPolicyNum();
			 
		 }

		 //pulls all comments for a patient for the selected day
		 //used on load and after a comment has been added
		 System::Void pullComments(){
			 //clear comments first
			 commentList->Text = "";
			 CommDB->get(this->dateTimePicker->Value, patient->getPatientID());

			 //standard loop through reader data loop
			 bool dataLeft = (CommDB->myReader->HasRows ? true : false);
			 while(dataLeft){
				commentList->Text += (String^)(CommDB->myReader["comm_text"]);
				if(!CommDB->myReader->Read())
					dataLeft = false;
			 }
			 CommDB->closeConnection();
		 }

		 //pull all prescriptions for a patient
		 System::Void pullPrescriptions(){
			 PresDB->getList(patient->getPatientID());
			 this->dataGridView1->Rows->Clear();
			 bool dataLeft = PresDB->myReader->HasRows ? true : false;
			 while(dataLeft){
				 String^ num = (String^)(PresDB->myReader["pres_num"]);
				 String^ name = (String^)(PresDB->myReader["pres_name"]);
				 int presid = (int)(PresDB->myReader["pres_id"]);
				 this->dataGridView1->Rows->Add(num, name, presid);
				 if(!PresDB->myReader->Read())
					 dataLeft = false;
			 }
			 PresDB->closeConnection();
		 }

		 //logout button
private: System::Void linkLabel6_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			this->Owner->Show();
			this->Close();
		 }
		 //add a new comment, specifically prevent accidental adding of default message
private: System::Void add_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(newComment->Text != "Enter a new comment here"){
				String ^ addedComment = ""+session->getcurrentUser()->getfirstName() + " " + 
								session->getcurrentUser()->getlastName() + " :: " + 
								newComment->Text + "\n\n";
				CommDB->add(this->dateTimePicker->Value, patient->getPatientID(), addedComment);
				pullComments(); //refresh comments after insertion into database
				newComment->Text = "";
			 }
		 }
private: System::Void dateTimePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 pullComments(); //on date change, refresh comments
		 }
		 //if clicking on a prescription, pull up information
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 if(e->RowIndex >=0){ //only works if clicking on a non-header row
				int pres_id = Convert::ToInt32(this->dataGridView1[2,e->RowIndex]->Value);
				PresEditAddView ^ pAdd = gcnew PresEditAddView(session, patient, pres_id);
				pAdd->Owner = this;
			 }
		 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 PresEditAddView ^ pAdd = gcnew PresEditAddView(session, patient, 0);
			 pAdd->Owner = this;
		 }
		 System::Void PatientMain_Activated(System::Object^  sender, System::EventArgs^  e){
			 pullPrescriptions(); //refresh prescriptions after adding one
		 }
private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			populateStatFields(); //refresh stats after changing the date
		 }

		 //fill the stat fields according to currently selected day
		 System::Void populateStatFields(){
			 StatDB->get(this->dateTimePicker2->Value, patient->getPatientID());

			 //array for looping
			 array<String^>^ types = gcnew array<String^>(4);
			 types[0] = "diastolic";
			 types[1] = "sugar";
			 types[2] = "systolic";
			 types[3] = "weight";

			 String^ statdata;
			 String^ stattype;

			 //loop through database data, only fill fields that have been entered
			 bool dataLeft = StatDB->myReader->HasRows ? true : false;
			 for(int i = 0; i < 4; i++){
				 stattype = types[i];
				 if(dataLeft && (String^)(StatDB->myReader["stat_type"]) == stattype){
					statdata = StatDB->myReader["stat_data"]->ToString();
					if(!StatDB->myReader->Read())
						dataLeft = false;
				 } else {
					 statdata = "";
				 }
				if(stattype == "sugar")
					textBox10->Text = statdata;
				if(stattype == "systolic")
					textBox11->Text = statdata; 
				if(stattype == "diastolic")
					textBox13->Text = statdata; 
				if(stattype == "weight")
					textBox12->Text = statdata; 
			 }
			 StatDB->closeConnection();
		 }
};
}
//#endif
