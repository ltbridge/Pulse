#pragma once
#include "stdafx.h"
#include "LoginView.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Base class for the program that starts the session
	/// Main purpose is to be an owner to all forms and sit behind them allowing
	/// the user to minimize or close all forms simultaneously
	/// </summary>
	public ref class PulseMain : public System::Windows::Forms::Form
	{
	public:
		PulseMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			session = gcnew SessionData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PulseMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		SessionData^ session;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PulseMain::typeid));
			this->SuspendLayout();
			// 
			// PulseMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(893, 525);
			this->Name = L"PulseMain";
			this->Text = L"PulseMain";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &PulseMain::PulseMain_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		//on load this form calls the login screen
		System::Void PulseMain_Load(System::Object^  sender, System::EventArgs^  e) {
			LoginView ^ login = gcnew LoginView(session);
			login->Owner = this;
		}

	public:
		//depreciated function
		//no longer in use in favor of removing close buttons from main screen
		System::Void logout() {
			session = gcnew SessionData();
			LoginView ^ login = gcnew LoginView(session);
			login->Owner = this;
		}
		
	};
}

