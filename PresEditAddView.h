#pragma once

#include "stdafx.h"
#include "Patient.h"
#include "PresData.h"
#include "User.h"
#include "UserData.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;



	/// <summary>
	/// Main form for editing and adding prescriptions
	/// </summary>
	public ref class PresEditAddView : public System::Windows::Forms::Form
	{
	private:
		SessionData ^ session; Patient ^ patient; UserData^ UserDB;
		PresData ^ PresDB; int presID;

	public:
		PresEditAddView(SessionData ^ s, Patient ^ p, int pID)
		{
			InitializeComponent();

			//instantiate database classes
			PresDB = gcnew PresData();
			UserDB = gcnew UserData();

			//assign needed parameters
			session = s;
			patient = p;
			presID = pID;

			//if we are working on editing a prescription, fill the fields
			if(presID)
				PopulateFields();

			//fill the doctor field regardless, because nurses can only have one doctor
			User^ user = UserDB->get(session->getcurrentUser()->getdoctorId());
			this->doctor->Text = user->getfirstName()+" "+user->getlastName();
			this->doctor->ReadOnly=true;

			//check permissions
			checkPermissions();
			this->Show();
			
			//
			//TODO: Add the constructor code here
			//
			session = s;
			patient = p;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PresEditAddView()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::TextBox^  prescription;

	private: System::Windows::Forms::TextBox^  name;
	private: System::Windows::Forms::TextBox^  dose;
	private: System::Windows::Forms::TextBox^  instructions;
	private: System::Windows::Forms::TextBox^  refills;
	private: System::Windows::Forms::TextBox^  doctor;
	private: System::Windows::Forms::TextBox^  comments;
	private: System::Windows::Forms::Button^  save;













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
			this->prescription = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->dose = (gcnew System::Windows::Forms::TextBox());
			this->instructions = (gcnew System::Windows::Forms::TextBox());
			this->refills = (gcnew System::Windows::Forms::TextBox());
			this->doctor = (gcnew System::Windows::Forms::TextBox());
			this->comments = (gcnew System::Windows::Forms::TextBox());
			this->save = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Prescription#";
			this->label1->Click += gcnew System::EventHandler(this, &PresEditAddView::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Dose";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Instructions";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Refills";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 188);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Doctor";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 220);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(56, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Comments";
			// 
			// prescription
			// 
			this->prescription->Location = System::Drawing::Point(87, 22);
			this->prescription->Name = L"prescription";
			this->prescription->Size = System::Drawing::Size(100, 20);
			this->prescription->TabIndex = 11;
			this->prescription->TextChanged += gcnew System::EventHandler(this, &PresEditAddView::prescription_TextChanged);
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(87, 56);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(100, 20);
			this->name->TabIndex = 12;
			this->name->TextChanged += gcnew System::EventHandler(this, &PresEditAddView::name_TextChanged);
			// 
			// dose
			// 
			this->dose->Location = System::Drawing::Point(87, 89);
			this->dose->Name = L"dose";
			this->dose->Size = System::Drawing::Size(100, 20);
			this->dose->TabIndex = 13;
			this->dose->TextChanged += gcnew System::EventHandler(this, &PresEditAddView::dose_TextChanged);
			// 
			// instructions
			// 
			this->instructions->Location = System::Drawing::Point(87, 119);
			this->instructions->Name = L"instructions";
			this->instructions->Size = System::Drawing::Size(283, 20);
			this->instructions->TabIndex = 14;
			this->instructions->TextChanged += gcnew System::EventHandler(this, &PresEditAddView::textBox4_TextChanged);
			// 
			// refills
			// 
			this->refills->Location = System::Drawing::Point(87, 152);
			this->refills->Name = L"refills";
			this->refills->Size = System::Drawing::Size(100, 20);
			this->refills->TabIndex = 15;
			this->refills->TextChanged += gcnew System::EventHandler(this, &PresEditAddView::textBox5_TextChanged);
			// 
			// doctor
			// 
			this->doctor->Location = System::Drawing::Point(87, 185);
			this->doctor->Name = L"doctor";
			this->doctor->Size = System::Drawing::Size(100, 20);
			this->doctor->TabIndex = 16;
			// 
			// comments
			// 
			this->comments->Location = System::Drawing::Point(87, 217);
			this->comments->Name = L"comments";
			this->comments->Size = System::Drawing::Size(283, 20);
			this->comments->TabIndex = 17;
			// 
			// save
			// 
			this->save->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->save->Location = System::Drawing::Point(136, 262);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(109, 44);
			this->save->TabIndex = 18;
			this->save->Text = L"Save";
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &PresEditAddView::save_Click);
			// 
			// PresEditAddView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(406, 337);
			this->Controls->Add(this->save);
			this->Controls->Add(this->comments);
			this->Controls->Add(this->doctor);
			this->Controls->Add(this->refills);
			this->Controls->Add(this->instructions);
			this->Controls->Add(this->dose);
			this->Controls->Add(this->name);
			this->Controls->Add(this->prescription);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"PresEditAddView";
			this->Text = L"Pulse";
			this->Load += gcnew System::EventHandler(this, &PresEditAddView::PresEditAddView_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 this->Close();
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void prescription_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 //string ^ temp = prescription->Text;
			 //textBox4->Text = temp;
		 }
private: System::Void name_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void dose_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		 //saves prescription to the database
private: System::Void save_Click(System::Object^  sender, System::EventArgs^  e) {
			String ^ pres1;
			String ^ pres2;
			String ^ pres3;
			String ^ pres4;
			String ^ pres5;
		    String ^ pres7;
			pres1 = this->prescription->Text;
			pres2 = this->name->Text;
			pres3 = this->dose->Text;
			pres4 = this->instructions->Text;
			pres5 = this->refills->Text;
			pres7 = this->comments->Text;
			if(presID) //if we are editing, we will update
				PresDB->edit(presID, patient->getPatientID(), session->getcurrentUser()->getdoctorId(), pres1, pres2, pres3, pres4, pres5, pres7);
			else // else we will be adding a new prescription
				PresDB->add(patient->getPatientID(), session->getcurrentUser()->getdoctorId(), pres1, pres2, pres3, pres4, pres5, pres7);	
			this->Close();
		 }

private: System::Void PresEditAddView_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
		 
		 //permission check to restrict patients, they should only be able to view
		 System::Void checkPermissions(){
			 if(session->getcurrentUser()->gettype() == "Patient"){
				NoEdit();
				this->save->Visible = false;
			 }
		 }
		 //makes all fields uneditable
		  System::Void NoEdit(){
			this->prescription->ReadOnly=true;
			this->name->ReadOnly=true;
			this->dose->ReadOnly=true;
			this->instructions->ReadOnly=true;
			this->refills->ReadOnly=true;
			this->comments->ReadOnly=true;
		 }
		  //fills the fields if we are editing a prescription
		 System::Void PopulateFields(){
			PresDB->get(presID);
			this->prescription->Text = (String^)(PresDB->myReader["pres_num"]);
			this->name->Text = (String^)(PresDB->myReader["pres_name"]);
			this->dose->Text = (String^)(PresDB->myReader["pres_dose"]);
			this->instructions->Text = (String^)(PresDB->myReader["pres_instructions"]);
			this->refills->Text = (String^)(PresDB->myReader["pres_refills"]);
			this->comments->Text = (String^)(PresDB->myReader["pres_comments"]);
			PresDB->closeConnection();
		 }
};
}



