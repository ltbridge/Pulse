#pragma once
#include "stdafx.h"
#include "Patient.h"
#include "StatData.h"

namespace Pulse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PatientGraphView
	/// </summary>
	public ref class PatientGraphView : public System::Windows::Forms::Form
	{

		private: SessionData^ session; Patient ^ patient;

		public:
			PatientGraphView(SessionData ^ s, Patient ^ p)
			{
				session = s;
				patient = p;
				InitializeComponent();
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Show();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~PatientGraphView()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
		private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::ComboBox^  comboBox1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
		private: System::Windows::Forms::Label^  label5;
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
				System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
				System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->label5 = (gcnew System::Windows::Forms::Label());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->BeginInit();
				this->SuspendLayout();
				// 
				// dateTimePicker1
				// 
				this->dateTimePicker1->Location = System::Drawing::Point(12, 12);
				this->dateTimePicker1->Name = L"dateTimePicker1";
				this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
				this->dateTimePicker1->TabIndex = 0;
				this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &PatientGraphView::dateTimePicker1_ValueChanged);
				// 
				// textBox1
				// 
				this->textBox1->Location = System::Drawing::Point(442, 12);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(100, 20);
				this->textBox1->TabIndex = 7;
				this->textBox1->TextChanged += gcnew System::EventHandler(this, &PatientGraphView::textBox1_TextChanged);
				// 
				// comboBox1
				// 
				this->comboBox1->FormattingEnabled = true;
				this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Weight", L"Blood Pressure", L"Sugar Level"});
				this->comboBox1->Location = System::Drawing::Point(286, 11);
				this->comboBox1->Name = L"comboBox1";
				this->comboBox1->Size = System::Drawing::Size(121, 21);
				this->comboBox1->TabIndex = 8;
				this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PatientGraphView::comboBox1_SelectedIndexChanged);
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(548, 11);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(75, 23);
				this->button2->TabIndex = 9;
				this->button2->Text = L"Add Goal";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &PatientGraphView::button2_Click);
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(218, 14);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(62, 13);
				this->label4->TabIndex = 11;
				this->label4->Text = L"Graph Data";
				this->label4->Click += gcnew System::EventHandler(this, &PatientGraphView::label4_Click);
				// 
				// chart2
				// 
				chartArea1->Name = L"ChartArea1";
				this->chart2->ChartAreas->Add(chartArea1);
				legend1->Name = L"Legend1";
				this->chart2->Legends->Add(legend1);
				this->chart2->Location = System::Drawing::Point(7, 43);
				this->chart2->Name = L"chart2";
				this->chart2->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Fire;
				series1->ChartArea = L"ChartArea1";
				series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
				series1->Legend = L"Legend1";
				series1->Name = L"Data";
				series2->ChartArea = L"ChartArea1";
				series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
				series2->Legend = L"Legend1";
				series2->Name = L"Goal";
				this->chart2->Series->Add(series1);
				this->chart2->Series->Add(series2);
				this->chart2->Size = System::Drawing::Size(616, 209);
				this->chart2->TabIndex = 12;
				this->chart2->Text = L"chart2";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(259, 43);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(41, 13);
				this->label5->TabIndex = 13;
				this->label5->Text = L"Weight";
				// 
				// PatientGraphView
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(635, 264);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->chart2);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->comboBox1);
				this->Controls->Add(this->textBox1);
				this->Controls->Add(this->dateTimePicker1);
				this->Name = L"PatientGraphView";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 String ^ tempstartdate =  dateTimePicker1->Value.ToString("MM/dd/yyyy");
				 //dateTimePicker1->Value = DateTime->Now->AddDays(7);
				 //string startdate;
				 //MarshalString(tempstartdate, startdate);
				 //Pull all stats from this date to end date and display them on the graph and goal line if applicable

			 }
	private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 //String^ tempenddate =  dateTimePicker2->Value.ToString("MM/dd/yyyy");
				 //string enddate;
				 //MarshalString(tempenddate, enddate);
				 //Change end date of graph
			 }

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(comboBox1->SelectedIndex == 0)
				 {
					 this->label5->Text = L"Weight";
					 this->chart2->Series[0]->Points->Clear();
					 this->chart2->Series[1]->Points->Clear();
				 }
				 else if(comboBox1->SelectedIndex == 1)
				 {
					 this->label5->Text = L"Blood Pressure";
					 this->chart2->Series[0]->Points->Clear();
					 this->chart2->Series[1]->Points->Clear();
				 }
				 else if(comboBox1->SelectedIndex == 2)
				 {
					 this->label5->Text = L"Sugar Level";
					 this->chart2->Series[0]->Points->Clear();
					 this->chart2->Series[1]->Points->Clear();
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 String ^ temp = textBox1->Text;
				 if(temp != "")
				 {
				 int goal = int::Parse(temp);
				 if(goal != 0)
				 {
					 this->chart2->Series[1]->Points->AddXY(0,goal);
					 this->chart2->Series[1]->Points->AddXY(14,goal);
				 }
				 }
				 /*this->chart2->Series[0]->Points->AddXY(1,25);
				 this->chart2->Series[0]->Points->AddXY(2,10);
				 this->chart2->Series[0]->Points->AddXY(5,5);
				 this->chart2->Series[0]->Points->AddXY(9,5);
				 this->chart2->Series[0]->Points->AddXY(15,5);*/
				 //string goal;
				 //MarshalString(temp, goal);

				 //Save Goal in database along with goaltype
				 //Refresh graph
			 }

	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
