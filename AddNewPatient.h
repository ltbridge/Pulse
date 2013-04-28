#pragma once
#include <iostream>
#include <string>
#include "stdafx.h"

using namespace std;
using namespace System;

void MarshalString ( String ^ s, string& os ) ;


namespace PulseVisualJ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddNewPatient
	/// </summary>
	public ref class AddNewPatient : public System::Windows::Forms::Form
	{
	public:
		AddNewPatient(SessionData^ s)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			PtntDB = gcnew PtntData();
			this->Show;
			session = s;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddNewPatient()
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
	private: System::Windows::Forms::Button^  button2;

	private: PtntData^ PtntDB; SessionData^ session;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(140, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Please fill out all required fields*";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"First Name*";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Last Name*";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(34, 155);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Address*";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(34, 198);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"City*";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(34, 237);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"State*";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(34, 282);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Zipcode*";
			// 
			// firstBox
			// 
			this->firstBox->Location = System::Drawing::Point(144, 64);
			this->firstBox->Name = L"firstBox";
			this->firstBox->Size = System::Drawing::Size(100, 20);
			this->firstBox->TabIndex = 1;
			// 
			// stateBox
			// 
			this->stateBox->Location = System::Drawing::Point(144, 237);
			this->stateBox->Name = L"stateBox";
			this->stateBox->Size = System::Drawing::Size(100, 20);
			this->stateBox->TabIndex = 5;
			// 
			// cityBox
			// 
			this->cityBox->Location = System::Drawing::Point(144, 198);
			this->cityBox->Name = L"cityBox";
			this->cityBox->Size = System::Drawing::Size(100, 20);
			this->cityBox->TabIndex = 4;
			// 
			// addressBox
			// 
			this->addressBox->Location = System::Drawing::Point(144, 155);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(100, 20);
			this->addressBox->TabIndex = 3;
			// 
			// lastBox
			// 
			this->lastBox->Location = System::Drawing::Point(144, 107);
			this->lastBox->Name = L"lastBox";
			this->lastBox->Size = System::Drawing::Size(100, 20);
			this->lastBox->TabIndex = 2;
			// 
			// zipBox
			// 
			this->zipBox->Location = System::Drawing::Point(144, 282);
			this->zipBox->Name = L"zipBox";
			this->zipBox->Size = System::Drawing::Size(100, 20);
			this->zipBox->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(295, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(105, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Insurance Company*";
			// 
			// insuranceBox
			// 
			this->insuranceBox->Location = System::Drawing::Point(423, 107);
			this->insuranceBox->Name = L"insuranceBox";
			this->insuranceBox->Size = System::Drawing::Size(100, 20);
			this->insuranceBox->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(295, 156);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Policy #*";
			// 
			// policyBox
			// 
			this->policyBox->Location = System::Drawing::Point(423, 156);
			this->policyBox->Name = L"policyBox";
			this->policyBox->Size = System::Drawing::Size(100, 20);
			this->policyBox->TabIndex = 9;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(295, 67);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(36, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Email*";
			// 
			// emailBox
			// 
			this->emailBox->Location = System::Drawing::Point(423, 64);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(100, 20);
			this->emailBox->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 337);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddNewPatient::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(313, 337);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddNewPatient::button2_Click);
			// 
			// AddNewPatient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(544, 372);
			this->Controls->Add(this->button2);
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
			this->Name = L"AddNewPatient";
			this->Text = L"Pulse";
			this->Load += gcnew System::EventHandler(this, &AddNewPatient::AddNewPatient_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				/*String ^ temp = firstBox->Text;
				int i = int::Parse(temp);
				i++;
				cout<<i;*/
		
			 }


private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 AddNewPatient::Close(); //or hide
		 }
};
}
