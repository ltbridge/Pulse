#pragma once
#include "AdminUserView.h"
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
	/// Summary for AdminUserListView
	/// </summary>
	public ref class AdminUserListView : public System::Windows::Forms::Form
	{

	private: SessionData ^ session; UserData ^ UserDB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  username;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  first;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  last;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  type;



	public:
		AdminUserListView(SessionData ^ s)
		{
			session=s;
			UserDB = gcnew UserData();
			InitializeComponent();
			this->Show();
			InitializeDataGridView();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminUserListView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;




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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->username = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->first = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->last = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->username, 
				this->first, this->last, this->type});
			this->dataGridView1->Location = System::Drawing::Point(13, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(452, 242);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminUserListView::dataGridView1_CellClick);
			// 
			// username
			// 
			this->username->HeaderText = L"UserName";
			this->username->Name = L"username";
			this->username->ReadOnly = true;
			// 
			// first
			// 
			this->first->HeaderText = L"First Name";
			this->first->Name = L"first";
			this->first->ReadOnly = true;
			this->first->Width = 125;
			// 
			// last
			// 
			this->last->HeaderText = L"Last Name";
			this->last->Name = L"last";
			this->last->ReadOnly = true;
			// 
			// type
			// 
			this->type->HeaderText = L"Authority";
			this->type->Name = L"type";
			this->type->ReadOnly = true;
			// 
			// AdminUserListView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 278);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"AdminUserListView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminUserListView";
			this->Activated += gcnew System::EventHandler(this, &AdminUserListView::AdminUserListView_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void InitializeDataGridView()
			{
				dataGridView1->Rows->Clear();
				UserDB->userList(0);
				bool dataLeft = true;
				if(UserDB->myReader->HasRows){
					 while(dataLeft){
						 String ^ atype;
						int typeNum = (int)(UserDB->myReader["user_type"]);
						switch(typeNum){
							case 1: 
								atype = "Admin";
								break;
							case 2:
								atype = "Doctor";
								break;
							case 3:
								atype = "Nurse";
								break;
							case 4:
							default:
								atype = "Patient";
								break;
						}
						dataGridView1->Rows->Add((String^)(UserDB->myReader["user_name"]),(String^)(UserDB->myReader["user_firstName"]),(String^)(UserDB->myReader["user_lastName"]), atype);
						if(!UserDB->myReader->Read())
							dataLeft = false;
					 }
				 }
				UserDB->closeConnection();
			}
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			User ^ tempUser = UserDB->get(this->dataGridView1[0,e->RowIndex]->Value->ToString(), false);
			AdminUserView ^ adminEditScreen = gcnew AdminUserView(tempUser);
		 }
private: System::Void AdminUserListView_Load(System::Object^  sender, System::EventArgs^  e) {
			 InitializeDataGridView();
		 }
};
}
