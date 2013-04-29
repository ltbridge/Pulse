#pragma once
#include "stdafx.h"
#include "PtntData.h"
#include "Patient.h"
#include "UserData.h"
#include "PatientMainView.h"

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
	/// Form to add or edit a patient's information
	/// </summary>
	public ref class PatientAddView : public System::Windows::Forms::Form
	{
		private: PtntData^ PtntDB; SessionData^ session;
	private: System::Windows::Forms::Label^  label18;
			 UserData^ UserDB;
		public:
			PatientAddView(SessionData^ s)
			{
				InitializeComponent();
				
				session = s;

				//instantiate database classes
				PtntDB = gcnew PtntData();
				UserDB = gcnew UserData();
				this->Show();
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~PatientAddView()
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
		private: System::Windows::Forms::Label^  label7;
		private: System::Windows::Forms::TextBox^  firstBox;
		private: System::Windows::Forms::TextBox^  stateBox;
		private: System::Windows::Forms::TextBox^  cityBox;
		private: System::Windows::Forms::TextBox^  addressBox;
		private: System::Windows::Forms::TextBox^  lastBox;
		private: System::Windows::Forms::TextBox^  zipBox;
		private: System::Windows::Forms::Label^  label8;
		private: System::Windows::Forms::TextBox^  insuranceBox;
		private: System::Windows::Forms::Label^  label9;
		private: System::Windows::Forms::TextBox^  policyBox;
		private: System::Windows::Forms::Label^  label10;
		private: System::Windows::Forms::TextBox^  emailBox;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Label^  label11;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label12;
		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::TextBox^  textBox3;
		private: System::Windows::Forms::Label^  label13;
		private: System::Windows::Forms::Label^  label14;
		private: System::Windows::Forms::Label^  label15;
		private: System::Windows::Forms::TextBox^  textBox4;
		private: System::Windows::Forms::Label^  label16;
		private: System::Windows::Forms::Label^  label17;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->firstBox = (gcnew System::Windows::Forms::TextBox());
			this->stateBox = (gcnew System::Windows::Forms::TextBox());
			this->cityBox = (gcnew System::Windows::Forms::TextBox());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->lastBox = (gcnew System::Windows::Forms::TextBox());
			this->zipBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->insuranceBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->policyBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(359, 308);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"All fields are required";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"First Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Last Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 123);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Address";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(37, 149);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"City";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(37, 175);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"State";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(36, 201);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Zipcode";
			// 
			// firstBox
			// 
			this->firstBox->Location = System::Drawing::Point(103, 68);
			this->firstBox->Name = L"firstBox";
			this->firstBox->Size = System::Drawing::Size(164, 20);
			this->firstBox->TabIndex = 1;
			// 
			// stateBox
			// 
			this->stateBox->Location = System::Drawing::Point(103, 172);
			this->stateBox->Name = L"stateBox";
			this->stateBox->Size = System::Drawing::Size(164, 20);
			this->stateBox->TabIndex = 5;
			// 
			// cityBox
			// 
			this->cityBox->Location = System::Drawing::Point(103, 146);
			this->cityBox->Name = L"cityBox";
			this->cityBox->Size = System::Drawing::Size(164, 20);
			this->cityBox->TabIndex = 4;
			// 
			// addressBox
			// 
			this->addressBox->Location = System::Drawing::Point(103, 120);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(164, 20);
			this->addressBox->TabIndex = 3;
			// 
			// lastBox
			// 
			this->lastBox->Location = System::Drawing::Point(103, 94);
			this->lastBox->Name = L"lastBox";
			this->lastBox->Size = System::Drawing::Size(164, 20);
			this->lastBox->TabIndex = 2;
			// 
			// zipBox
			// 
			this->zipBox->Location = System::Drawing::Point(103, 198);
			this->zipBox->Name = L"zipBox";
			this->zipBox->Size = System::Drawing::Size(164, 20);
			this->zipBox->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(36, 281);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(54, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Insurance";
			// 
			// insuranceBox
			// 
			this->insuranceBox->Location = System::Drawing::Point(103, 276);
			this->insuranceBox->Name = L"insuranceBox";
			this->insuranceBox->Size = System::Drawing::Size(164, 20);
			this->insuranceBox->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(36, 305);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Policy #*";
			// 
			// policyBox
			// 
			this->policyBox->Location = System::Drawing::Point(103, 302);
			this->policyBox->Name = L"policyBox";
			this->policyBox->Size = System::Drawing::Size(164, 20);
			this->policyBox->TabIndex = 9;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(37, 253);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(32, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Email";
			// 
			// emailBox
			// 
			this->emailBox->Location = System::Drawing::Point(103, 250);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(164, 20);
			this->emailBox->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(327, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 34);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Create Patient File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PatientAddView::button1_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(324, 68);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(55, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Username";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(385, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 20);
			this->textBox1->TabIndex = 19;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PatientAddView::textBox1_TextChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(326, 97);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(53, 13);
			this->label12->TabIndex = 20;
			this->label12->Text = L"Password";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(385, 94);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(147, 20);
			this->textBox2->TabIndex = 21;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &PatientAddView::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(385, 121);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(147, 20);
			this->textBox3->TabIndex = 22;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &PatientAddView::textBox3_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(297, 124);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(82, 13);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Verify Password";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(54, 18);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(213, 26);
			this->label14->TabIndex = 24;
			this->label14->Text = L"Personal Information";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(357, 18);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(152, 26);
			this->label15->TabIndex = 25;
			this->label15->Text = L"Pulse Account";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(103, 224);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(164, 20);
			this->textBox4->TabIndex = 26;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(37, 227);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(38, 13);
			this->label16->TabIndex = 27;
			this->label16->Text = L"Phone";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->ForeColor = System::Drawing::Color::Red;
			this->label17->Location = System::Drawing::Point(396, 149);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(120, 13);
			this->label17->TabIndex = 28;
			this->label17->Text = L"Passwords do no match";
			this->label17->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->ForeColor = System::Drawing::Color::Red;
			this->label18->Location = System::Drawing::Point(396, 49);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(121, 13);
			this->label18->TabIndex = 29;
			this->label18->Text = L"Username already exists";
			this->label18->Visible = false;
			// 
			// PatientAddView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(544, 372);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->policyBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->insuranceBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->zipBox);
			this->Controls->Add(this->lastBox);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->cityBox);
			this->Controls->Add(this->stateBox);
			this->Controls->Add(this->firstBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"PatientAddView";
			this->Text = L"Pulse";
			this->Load += gcnew System::EventHandler(this, &PatientAddView::PatientAddView_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			
	private: System::Void PatientAddView_Load(System::Object^  sender, System::EventArgs^  e) {
				String ^ name = ""+session->getcurrentUser()->getfirstName()+" "+session->getcurrentUser()->getlastName();
				this->label2->Text = name;
			}
			 //save patient information
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				if(this->textBox2->Text != this->textBox3->Text){ //error if passwords dont matcht
					this->label17->Visible = true;
				} else if (UserDB->nameExists(this->textBox1->Text)){ //error if username already exists
					this->label18->Visible = true;
				} else { //no errors then add to database
					User ^ user = UserDB->add(this->firstBox->Text, this->lastBox->Text, session->getcurrentUser()->getdoctorId(), 
												"Patient", this->textBox1->Text, this->textBox2->Text);
					Patient ^ patient = gcnew Patient(-1, this->firstBox->Text, this->lastBox->Text, this->addressBox->Text,
														this->cityBox->Text, this->stateBox->Text, Convert::ToInt32(this->zipBox->Text), 
														this->textBox4->Text, this->emailBox->Text, this->insuranceBox->Text, this->policyBox->Text);
					patient = PtntDB->add(patient, user->getuserId(), session->getcurrentUser()->getdoctorId());
					PatientMainView ^ pMain = gcnew PatientMainView(session, patient);
					pMain->Owner = this->Owner;
					this->Close();
				}
			 }


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Close(); //or hide
			 }
			 //if passwords or username changed, remove any associated errors
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				this->label17->Visible = false;
			 }
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				this->label17->Visible = false;
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				this->label18->Visible = false;
			}
};
}

