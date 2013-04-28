#pragma once
#include"stdafx.h"
#include "PatientAddView.h"
#include "PatientSearchView.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ApptMainView
	/// </summary>
	public ref class ApptMainView : public System::Windows::Forms::Form
	{
	public:
		ApptMainView(SessionData ^ s)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			session = s;
			this->Show();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ApptMainView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Time;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Name;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Del;

	private:
		SessionData ^ session;




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
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Del = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome, ";
			this->label1->Click += gcnew System::EventHandler(this, &ApptMainView::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Maroon;
			this->label2->Location = System::Drawing::Point(62, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name Goes Here";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(549, 21);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(40, 13);
			this->linkLabel1->TabIndex = 2;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Logout";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ApptMainView::linkLabel1_LinkClicked);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(205, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(180, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Appointments";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"MMMMdd, yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(65, 84);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(134, 20);
			this->dateTimePicker1->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Time, this->Name, 
				this->Del});
			this->dataGridView1->Location = System::Drawing::Point(65, 110);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(500, 168);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ApptMainView::dataGridView1_CellContentClick);
			// 
			// Time
			// 
			this->Time->HeaderText = L"Time";
			this->Time->Name = L"Time";
			this->Time->ReadOnly = true;
			this->Time->Width = 175;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Name";
			this->Name->Name = L"Name";
			this->Name->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Name->Width = 250;
			// 
			// Del
			// 
			this->Del->HeaderText = L"Del";
			this->Del->Name = L"Del";
			this->Del->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Del->Text = L"X";
			this->Del->Width = 30;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(65, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(66, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Prev";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(211, 283);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 22);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Add Patient";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ApptMainView::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(326, 283);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 21);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Patient Search";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ApptMainView::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(498, 284);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(67, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Next";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// ApptMainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 335);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			//this->Name = L"ApptMainView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ApptMainView";
			this->Load += gcnew System::EventHandler(this, &ApptMainView::ApptMainView_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->ControlBox = false;
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
	private: System::Void ApptMainView_Load(System::Object^  sender, System::EventArgs^  e) {
				 String ^ name = ""+session->getcurrentUser()->getfirstName()+" "+session->getcurrentUser()->getlastName();
				 this->label2->Text = name;
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 PatientAddView ^ addP = gcnew PatientAddView(session);
				 addP->Owner = this->Owner;
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 PatientSearchView ^ searchP = gcnew PatientSearchView(session);
				 searchP->Owner = this->Owner;
			}
	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
				this->Owner->Show();
				this->Close();
			 }
};
}
