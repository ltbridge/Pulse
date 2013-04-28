#pragma once
//#include "stdafx.h"

//#include <string>
//#include <iostream>
#include "SessionData.h"

namespace PulseTesting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;





	public ref class CommView : public System::Windows::Forms::Form
	{
	public:
		CommView(SessionData ^ s)
		{
			SessionData ^ session = gcnew SessionData();
			session=s;
			InitializeComponent();
			showComments();
			this->Show();			
		}

	protected:
		~CommView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  newComment;
	protected: 

	protected: 
	private: System::Windows::Forms::Button^  add_btn;

	private: System::Windows::Forms::DateTimePicker^  dateTimePicker;
	private: System::Windows::Forms::RichTextBox^  commentList;




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
			this->newComment = (gcnew System::Windows::Forms::RichTextBox());
			this->add_btn = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->commentList = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// newComment
			// 
			this->newComment->Location = System::Drawing::Point(13, 70);
			this->newComment->Name = L"newComment";
			this->newComment->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->newComment->Size = System::Drawing::Size(200, 110);
			this->newComment->TabIndex = 0;
			this->newComment->Text = L"Enter a new comment here";
			// 
			// add_btn
			// 
			this->add_btn->Location = System::Drawing::Point(65, 200);
			this->add_btn->Name = L"add_btn";
			this->add_btn->Size = System::Drawing::Size(81, 23);
			this->add_btn->TabIndex = 1;
			this->add_btn->Text = L"Add Comment";
			this->add_btn->UseVisualStyleBackColor = true;
			this->add_btn->Click += gcnew System::EventHandler(this, &CommView::add_btn_Click);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Location = System::Drawing::Point(13, 31);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker->TabIndex = 3;
			// 
			// commentList
			// 
			this->commentList->BackColor = System::Drawing::Color::White;
			this->commentList->Location = System::Drawing::Point(234, 27);
			this->commentList->Name = L"commentList";
			this->commentList->ReadOnly = true;
			this->commentList->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->commentList->Size = System::Drawing::Size(200, 196);
			this->commentList->TabIndex = 4;
			this->commentList->Text = L"";
			// 
			// CommView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 248);
			this->Controls->Add(this->commentList);
			this->Controls->Add(this->dateTimePicker);
			this->Controls->Add(this->add_btn);
			this->Controls->Add(this->newComment);
			this->Name = L"CommView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pulse";
			this->Load += gcnew System::EventHandler(this, &CommView::CommView_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
/////////////////////////////
//Comment Functions
/////////////////////////////
void showComments()
{
	//Updates commentList->Text to display all comments from the specific date and patient

	/*FUNCTION TESTING
	array<System::String ^>^ list = gcnew array <System::String ^>(10);
	list = gcnew array<System::String ^>{"1. This patient was really good.", "2. The patient had some minor pain, but not much.", "3. The patient felt better today.", "4. The patient needed to eat more becasue he lost alot of wait."};

	int i=0;
	while (i<3)
	{
		commentList->Text=commentList->Text+list[i]+"\n";
		i++;
	}
	*/
}

void addComment(String ^ comment)
{
	//Adds inputted comment to the database

	/*FUNCTION TESTING
	commentList->Text=commentList->Text+comment+"\n";
	*/
}


/////////////////////////////
//Comment View Functions
/////////////////////////////
	private: System::Void add_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^ comment=newComment->Text;
				 addComment(comment);
				 showComments();

			 }
	private: System::Void CommView_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
