#pragma once
#include "SessionData.h"
#include "UserData.h"
#include "User.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// View to allow editing and adding of users
	/// simple form adds and updates to the database
	/// </summary>
	public ref class AdminUserView : public System::Windows::Forms::Form
	{
	private: UserData^ UserDB; User^ user;
			 array<String^>^ authority;
			 array<String^>^ docs; 
	private: System::Windows::Forms::Label^  label8;
	public:
		AdminUserView(User^ u)
		{

			InitializeComponent();
			user = u;

			//instantiation of database classes
			UserDB = gcnew UserData();

			//create list of assignable doctors
			comboBox2List();

			//create array of authority level for user in dropdown box
			authority = gcnew array<String^>(4);
			authority[0] = "Admin";
			authority[1] = "Doctor";
			authority[2] = "Nurse";
			authority[3] = "Patient";
			if(user == nullptr){ //if we aren't editing a user, then we are adding
				this->label7->Text = "Add User";
			} else { //if we aren't adding, we are editing, so populate fields
				PopulateFields();
			}
			this->Show();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminUserView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Password:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"User Name:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Admin", L"Doctor", L"Nurse", L"Patient"});
			this->comboBox1->Location = System::Drawing::Point(103, 98);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(103, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(103, 71);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Type:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(103, 155);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 16;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(103, 128);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 158);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Last Name:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 131);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"First Name:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 188);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Assigned Doctor:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(103, 185);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 21);
			this->comboBox2->TabIndex = 18;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(78, 17);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(59, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Edit User";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(72, 244);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminUserView::button1_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(57, 218);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(107, 13);
			this->label8->TabIndex = 21;
			this->label8->Visible = false;
			this->label8->Text = L"All Fields are required";
			// 
			// AdminUserView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 279);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Name = L"AdminUserView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminUserView";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//button to save the user, validation checks are done in this method
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ name = textBox1->Text ; 
			 String^ password = textBox2->Text;
			 String^ fname = textBox4->Text;
			 String^ lname = textBox3->Text;
			 int atype = 1+comboBox1->SelectedIndex;
			 if(user == nullptr && UserDB->nameExists(name)){ //username can't be blank and it can't already exist
				 label8->Text = "UserName already exists.";
				 label8->Visible = true;
			 }
			 //all fields are required, they can not be blank
			 else if(name == "" || password == "" || fname == "" || lname == "" || comboBox1->SelectedIndex < 0 || comboBox2->SelectedIndex < 0){
				label8->Visible = true;
				label8->Text = "All Fields are required";
			 }else{ //if passed all fail scenarios, add user
				 int docid;
				 if(comboBox2->SelectedIndex > 0){ //parse combo box selection
					User ^ doc = UserDB->get(docs[comboBox2->SelectedIndex], true);
					 docid= doc->getuserId();
				 } else { //if none, docid = 0
					 docid = 0;
				 }
				 int forgot = 0;
				 if(user == nullptr){ //if no user assigned to form, then adding
					UserDB->add(name, password, docid, forgot, atype, fname, lname);
					this->Close();
				 } else { //else updating
					 UserDB->update(user->getuserId(), name, password, docid, forgot, atype, fname, lname);
					 this->Close();
				 }
			 }
			
			 
		 }

		 //populate dynamic doctor listbox
		 System::Void comboBox2List(){
			 
			 UserDB->userList(2);//gets list of doctors
			 this->docs = gcnew array<String^>(250);
			 comboBox2->Items->Add("None");
			 docs[0] = "None";
			 bool dataLeft = true;
			 int i = 1;
			 if(UserDB->myReader->HasRows){ //iterate through list and assign them to the dropdown menu as well as the translation array
					while(dataLeft){
					comboBox2->Items->Add((String^)(UserDB->myReader["user_firstName"])+" "+(String^)(UserDB->myReader["user_lastName"]));
					docs[i] = (String^)(UserDB->myReader["user_firstName"])+" "+(String^)(UserDB->myReader["user_lastName"]);
					i++;
					if(!UserDB->myReader->Read())
						dataLeft = false;
					}
					
				}
			 UserDB->closeConnection();
			 //set default selections
			 this->comboBox2->SelectedIndex = 0;
			 this->comboBox1->SelectedIndex = 0;

		 }

		 //populate user fields
		 System::Void PopulateFields(){
			 textBox1->Text = user->getuserName();
			 textBox2->Text = user->getpassword();
			 textBox3->Text = user->getlastName();
			 textBox4->Text = user->getfirstName();
			 for(int i = 0; i < 4; i++){ //loop through and determine authority level
				if(user->gettype() == authority[i]) // translation necessary since authority level is a string, selectedindex is an int
					comboBox1->SelectedIndex = i;
			 }
			 comboBox1->SelectedText = user->gettype();
			 if(user->getdoctorId()){
				User^ doc = UserDB->get(user->getdoctorId());
				int j = 0;
				while(docs[j] != nullptr){
					if((doc->getfirstName()+" "+ doc->getlastName()) == docs[j])
						comboBox2->SelectedIndex = j;
					j++;
				}
			 } else {
				 comboBox2->SelectedIndex = 0;
			 }
		 }
};
}
