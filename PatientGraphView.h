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
	/// Graph view for visualizing patient stat progress
	/// </summary>
	public ref class PatientGraphView : public System::Windows::Forms::Form
	{

		private: SessionData^ session; Patient ^ patient; StatData ^ StatDB;

		public:
			PatientGraphView(SessionData ^ s, Patient ^ p)
			{
				InitializeComponent();

				session = s;
				patient = p;
				
				//initialize database class
				StatDB = gcnew StatData();

				//weight always start selected
				this->comboBox1->SelectedIndex = 0;
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				
				//draw graph and write labels
				updateLabels();
				 updateAxis();
				 drawChart();
				this->Show();
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
				System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
				this->dateTimePicker1->CustomFormat = L"MMMM";
				this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
				this->dateTimePicker1->Location = System::Drawing::Point(12, 12);
				this->dateTimePicker1->Name = L"dateTimePicker1";
				this->dateTimePicker1->Size = System::Drawing::Size(91, 20);
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
				this->comboBox1->Location = System::Drawing::Point(246, 11);
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
				this->label4->Location = System::Drawing::Point(178, 14);
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
				series1->BorderWidth = 3;
				series1->ChartArea = L"ChartArea1";
				series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
				series1->Legend = L"Legend1";
				series1->Name = L"Data";
				series2->BorderWidth = 3;
				series2->ChartArea = L"ChartArea1";
				series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
				series2->Legend = L"Legend1";
				series2->Name = L"Data2";
				series3->BorderWidth = 4;
				series3->ChartArea = L"ChartArea1";
				series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
				series3->Legend = L"Legend1";
				series3->Name = L"Goal";
				this->chart2->Series->Add(series1);
				this->chart2->Series->Add(series2);
				this->chart2->Series->Add(series3);
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

			//main draw chart function
			//gets series from database based on currently selected option
			//then assigns points to the chart
	private:System::Void drawChart(){
				 int index = this->comboBox1->SelectedIndex;
				 switch (index){
					case 0:
						StatDB->getSeries("weight", this->dateTimePicker1->Value, patient->getPatientID());
						AssignPoints(0);
						break;
					case 1:
						StatDB->getSeries("systolic", this->dateTimePicker1->Value, patient->getPatientID());
						AssignPoints(0);
						StatDB->getSeries("diastolic", this->dateTimePicker1->Value, patient->getPatientID());
						AssignPoints(1);
						break;
					case 2:
						StatDB->getSeries("sugar", this->dateTimePicker1->Value, patient->getPatientID());
						AssignPoints(0);
						break;

				 }
			 }

			//assigning points to the chart
			 System::Void AssignPoints(int seriesnum){
				 //determine length of xAxis = days in the month
				int xAxis = System::DateTime::DaysInMonth(this->dateTimePicker1->Value.Year, this->dateTimePicker1->Value.Month);
				int steadyline = 0; //int to make straight lines between points
				DateTime ^ thisday = System::DateTime::Today;
				bool dataLeft = StatDB->myReader->HasRows ? true : false;
				bool pointset = false;
				for(int i = 1; i <= xAxis; i++){//for each x point, either print out data or holding pattern data
					if(dataLeft){
						DateTime ^ dbDate = (DateTime^)(StatDB->myReader["stat_date"]);
						if(dbDate->Day == i){
							this->chart2->Series[seriesnum]->Points->AddXY(i,(int)(StatDB->myReader["stat_data"]));
							steadyline = (int)(StatDB->myReader["stat_data"]);
							pointset = true;
							if(!StatDB->myReader->Read())
								dataLeft = false;
						}
						pointset = false;
					}
					if (thisday->Day > i && !pointset){
						this->chart2->Series[seriesnum]->Points->AddXY(i,steadyline);
					}
				}
			 }
			 //update labels based on currently selected data
			 System::Void updateLabels(){
				if(comboBox1->SelectedIndex == 0)
				 {
					 this->chart2->Series[0]->Points->Clear();
					 this->chart2->Series[1]->Points->Clear();
					 this->chart2->Series[2]->Points->Clear();
					 this->label5->Text = L"Weight";
					 this->chart2->Series[0]->Name = "Weight";
					 this->chart2->Series[1]->Enabled = false;
					 this->chart2->Series[2]->Name = "Goal";
					 this->chart2->ChartAreas["ChartArea1"]->AxisY->Title = "lb";
				 }
				 else if(comboBox1->SelectedIndex == 1)
				 {
					 this->label5->Text = L"Blood Pressure";
					 this->chart2->Series[0]->Points->Clear();
					 this->chart2->Series[1]->Points->Clear();
					 this->chart2->Series[2]->Points->Clear();
					 this->chart2->Series[1]->Enabled = true;
					 this->chart2->Series[0]->Name = "Systolic";
					 this->chart2->Series[1]->Name = "Diastolic";
					 this->chart2->Series[2]->Name = "Goal";
					 this->chart2->ChartAreas["ChartArea1"]->AxisY->Title = "mmHg";
				 }
				 else if(comboBox1->SelectedIndex == 2)
				 {
					 this->chart2->Series[0]->Points->Clear();
					 this->chart2->Series[1]->Points->Clear();
					 this->chart2->Series[2]->Points->Clear();
					 this->label5->Text = L"Sugar Level";
					 this->chart2->Series[0]->Name = "Sugar Level";
					 this->chart2->Series[1]->Enabled = false;
					 this->chart2->Series[2]->Name = "Goal";
					 this->chart2->ChartAreas["ChartArea1"]->AxisY->Title = "mg/dl";
				 }
			 }

			 //create x-axis lables and intervals
			 System::Void updateAxis(){
				this->chart2->ChartAreas["ChartArea1"]->AxisX->Interval = 7;
				this->chart2->ChartAreas["ChartArea1"]->AxisX->Title = "Day of the Month";
				//this->chart2->ChartAreas["ChartArea1"]->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Days;
			 }

			 //when date is changed, update graph
			System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 updateLabels();
				 updateAxis();
				 drawChart();
			 }
	private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
			 //when type is changed, update graph
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 updateLabels();
				 updateAxis();
				 drawChart();
			 }
			 //button to add a temporary goal
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 String ^ temp = textBox1->Text;
				 int goal= 0;
				 if(temp != "")
					goal = Convert::ToInt32(temp);
				 int xAxis = System::DateTime::DaysInMonth(this->dateTimePicker1->Value.Year, this->dateTimePicker1->Value.Month);
				 if(goal != 0)
				 {
					 this->chart2->Series[2]->Points->AddXY(1,goal);
					 this->chart2->Series[2]->Points->AddXY(xAxis,goal);
				 }
			 }

	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

};
}
