#pragma once
#include "stdafx.h"
#include "UserData.h"
#include "ApptMainView.h"
#include "PatientMainView.h"
#include "AdminMainView.h"
#include "PtntData.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class LoginView : public System::Windows::Forms::Form {
	
	public:
		LoginView(SessionData^ s)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			UserDB = gcnew UserData();
			PtntDB = gcnew PtntData();
			this->Show();
			session = s;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginView()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  username_tb;
	private: System::Windows::Forms::TextBox^  pw_tb;
	private: System::Windows::Forms::Button^  login_btn;

	private: System::Windows::Forms::Label^  login_message;
	private: System::Windows::Forms::LinkLabel^  FpwLink;
	private: UserData^ UserDB;
			 PtntData^ PtntDB;
			 SessionData^ session;


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
			this->username_tb = (gcnew System::Windows::Forms::TextBox());
			this->pw_tb = (gcnew System::Windows::Forms::TextBox());
			this->login_btn = (gcnew System::Windows::Forms::Button());
			this->login_message = (gcnew System::Windows::Forms::Label());
			this->FpwLink = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Username:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Password:";
			// 
			// username_tb
			// 
			this->username_tb->Location = System::Drawing::Point(76, 20);
			this->username_tb->Name = L"username_tb";
			this->username_tb->Size = System::Drawing::Size(177, 20);
			this->username_tb->TabIndex = 13;
			// 
			// pw_tb
			// 
			this->pw_tb->Location = System::Drawing::Point(76, 52);
			this->pw_tb->Name = L"pw_tb";
			this->pw_tb->PasswordChar = '*';
			this->pw_tb->Size = System::Drawing::Size(177, 20);
			this->pw_tb->TabIndex = 14;
			this->pw_tb->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginView::pw_tb_KeyDown);
			// 
			// login_btn
			// 
			this->login_btn->Location = System::Drawing::Point(76, 91);
			this->login_btn->Name = L"login_btn";
			this->login_btn->Size = System::Drawing::Size(99, 23);
			this->login_btn->TabIndex = 15;
			this->login_btn->Text = L"Login";
			this->login_btn->UseVisualStyleBackColor = true;
			this->login_btn->Click += gcnew System::EventHandler(this, &LoginView::login_btn_Click);
			// 
			// login_message
			// 
			this->login_message->AutoSize = true;
			this->login_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->login_message->ForeColor = System::Drawing::Color::Red;
			this->login_message->Location = System::Drawing::Point(23, 75);
			this->login_message->Name = L"login_message";
			this->login_message->Size = System::Drawing::Size(0, 13);
			this->login_message->TabIndex = 17;
			this->login_message->Visible = false;
			// 
			// FpwLink
			// 
			this->FpwLink->AutoSize = true;
			this->FpwLink->Location = System::Drawing::Point(83, 117);
			this->FpwLink->Name = L"FpwLink";
			this->FpwLink->Size = System::Drawing::Size(92, 13);
			this->FpwLink->TabIndex = 18;
			this->FpwLink->TabStop = true;
			this->FpwLink->Text = L"Forgot Password\?";
			this->FpwLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginView::FpwLink_LinkClicked);
			// 
			// LoginView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(268, 155);
			this->Controls->Add(this->FpwLink);
			this->Controls->Add(this->login_message);
			this->Controls->Add(this->login_btn);
			this->Controls->Add(this->pw_tb);
			this->Controls->Add(this->username_tb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LoginView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Access Pulse";
			this->Load += gcnew System::EventHandler(this, &LoginView::LoginView_Load);
			this->ResumeLayout(false);
			this->ControlBox = false;
			this->PerformLayout();

		}
#pragma endregion
	private:
		/////////////////////////////
		//Event Handlers
		/////////////////////////////
		System::Void LoginView_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void login_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				submitLogin();
		 }
		System::Void pw_tb_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Enter)
				submitLogin();
		 }
		System::Void FpwLink_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {

		 }
		/////////////////////////////
		//Login Functions
		/////////////////////////////
		System::Void submitLogin(){
			this->login_message->Visible = true;
			if(UserDB->validLogin(username_tb->Text, pw_tb->Text)){
					CreateSession(username_tb->Text, pw_tb->Text);
					RedirectMain();
			} else {
					this->login_message->Text = "Invalid username or password.";
			}
		}
		System::Void CreateSession(System::String^ userN, System::String^ passW){
			AssignUser(userN, passW);
			if(session->getcurrentUser()->gettype() == "Patient")
				AssignPatient();
		}

		System::Void AssignPatient(){
			session->setcurrentPatient(PtntDB->get(session->getcurrentUser()->getuserId(), true));
		}

		System::Void AssignUser(System::String^ userN, System::String^ passW){
			User^ tempUser = UserDB->get(username_tb->Text, pw_tb->Text);
			session->setcurrentUser(tempUser);
		}
		System::Void RedirectMain(){
			this->pw_tb->Text = "";
			this->username_tb->Text = "";
			
			String^ type = session->getcurrentUser()->gettype();
			
			if(type == "Admin"){
				AdminMainView ^ admin = gcnew AdminMainView(session);
				admin->Owner = this;
				this->Hide();
			} else if (type == "Doctor" || type == "Nurse"){
				ApptMainView ^ appt = gcnew ApptMainView(session);
				appt->Owner = this;
				this->Hide();
			} else if (type == "Patient"){
				PatientMainView ^ ptntView = gcnew PatientMainView(session);
				ptntView->Owner = this;
				this->Hide();
			} else {
				this->login_message->Text = "Report to System Admin regarding Access.";
			}
		}
};
}


