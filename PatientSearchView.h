#pragma once
#include "stdafx.h"
#include "PtntData.h"
#include "ApptData.h"
#include "Patient.h"
#include "PatientMainView.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form for searching patients
	/// both appointments and patient search use this form
	/// each have their own constructor
	/// </summary>
	public ref class PatientSearchView : public System::Windows::Forms::Form
	{

	private: PtntData ^ ptntDB; SessionData^ session; DateTime ^ date; ApptData ^ apptDB;

	private: System::Windows::Forms::Label^  label8;

	public:

		//constructor for patient search
		PatientSearchView(SessionData ^ s)
		{
			InitializeComponent();
			
			session = s;

			//instantiate database classes
			ptntDB = gcnew PtntData();
			apptDB = gcnew ApptData();
			this->Show();
			
		}

		//constructor for appointment creation, DateTime d determines the appointment time
		//the patient will be assigned to after selected
		PatientSearchView(SessionData ^ s, DateTime ^ d)
		{
			
			InitializeComponent();

			date = d;
			session = s;
			//instantiate database classes
			ptntDB = gcnew PtntData();
			apptDB = gcnew ApptData();
			this->Show();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PatientSearchView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FirstName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LastName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DateTime;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FirstName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(187, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Patient Search";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(116, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(308, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter information for one or more of the following fields:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"First Name:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Last Name:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(327, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Phone #:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(327, 112);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Patient ID #:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(78, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PatientSearchView::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(78, 109);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(149, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(400, 80);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(112, 20);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(400, 106);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(112, 20);
			this->textBox4->TabIndex = 4;
			// 
			// searchButton
			// 
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->searchButton->Location = System::Drawing::Point(233, 80);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(88, 49);
			this->searchButton->TabIndex = 5;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &PatientSearchView::searchButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 157);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(520, 211);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Results";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->ID, this->FirstName, 
				this->LastName, this->Phone, this->Type, this->DateTime});
			this->dataGridView1->Location = System::Drawing::Point(3, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(514, 182);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PatientSearchView::dataGridView1_CellClick);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Width = 50;
			// 
			// FirstName
			// 
			this->FirstName->HeaderText = L"First Name";
			this->FirstName->Name = L"FirstName";
			this->FirstName->ReadOnly = true;
			this->FirstName->Width = 135;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"Last Name";
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
			this->LastName->Width = 135;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Phone #";
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			this->Phone->Width = 150;
			// 
			// Type
			// 
			this->Type->HeaderText = L"Type";
			this->Type->Name = L"Type";
			this->Type->ReadOnly = true;
			this->Type->Visible = false;
			// 
			// DateTime
			// 
			this->DateTime->HeaderText = L"DateTime";
			this->DateTime->Name = L"DateTime";
			this->DateTime->ReadOnly = true;
			this->DateTime->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(148, 141);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(258, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Unable to add appointment, please try again";
			this->label8->Visible = false;
			// 
			// PatientSearchView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(544, 372);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"PatientSearchView";
			this->Text = L"PatientSearchView";
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//search button click to hit the database and fill the rows
private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //makes the error message go away, because once here, no errors possible
			 this->label8->Visible = false;
			 
			 //sets parameters to blank
			 String ^ first = "", ^ last = "", ^ phone = "";
			 int id = 0;;

			 //goes through each field and if blank, doesn't assign the Text value
			 if(this->textBox1->Text != "")
				 first = (String ^)(this->textBox1->Text);
			 if(this->textBox2->Text != "")
				 last = (String ^)(this->textBox2->Text);
			 if(this->textBox3->Text != "")
				 phone = (String ^)(this->textBox3->Text);
			 if(this->textBox4->Text != "")
				 id = Convert::ToInt32(this->textBox4->Text);
			 //search database
			 ptntDB->search(first, last, phone, id, this->session->getcurrentUser()->getdoctorId());
			 fillResult(); //fill rows
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
		 //clicking a cell either pulls up their information or adds it to the appointment
		 //flag is hidden in the table on row creation
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			if(e->RowIndex >=0 ){
				String ^ check = this->dataGridView1[4,e->RowIndex]->Value->ToString();
				if(check == "appt"){//flag to determine if adding to appointment
					//adds the appointment and if successful, closes
					if(apptDB->add(date, this->session->getcurrentUser()->getdoctorId(), Convert::ToInt32(this->dataGridView1[0,e->RowIndex]->Value))){
						this->Close();
					}else //else tells the user adding didn't work
						this->label8->Visible = true;
				} else { //if not flagged to add appointment, views user
					Patient ^ patient = ptntDB->get(Convert::ToInt32(this->dataGridView1[0,e->RowIndex]->Value), false);
					PatientMainView ^ pMain = gcnew PatientMainView(session, patient);
					pMain->Owner = this->Owner;
				}
			}
		 
		 }
		 //function to fill the rows
private: System::Void fillResult() {
			 //first clear the rows
			 this->dataGridView1->Rows->Clear();

			 bool dataLeft; //flag to determine if data is left 
			 if(ptntDB->myReader->HasRows)
				 dataLeft = true;
			 while(dataLeft){//while there is data left, make rows
				int id = (int)(ptntDB->myReader["ptnt_id"]);
				String ^ first = (String ^)(ptntDB->myReader["ptnt_firstName"]);
				String ^ last = (String ^)(ptntDB->myReader["ptnt_lastName"]);
				String ^ phone = (String ^)(ptntDB->myReader["ptnt_phone"]);
				String ^ type = this->date == nullptr ? "view" : "appt";
				String ^ datetime = this->date == nullptr ? "" : this->date->ToString();
				this->dataGridView1->Rows->Add(id, first, last, phone, type, datetime);
				if(!ptntDB->myReader->Read()) //if no data left, flag it
					dataLeft = false;
			 }
		 }
};
}
