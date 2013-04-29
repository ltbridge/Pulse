#include "StdAfx.h"
#include "StatData.h"


StatData::StatData(void)
{
}


StatData::~StatData(void)
{
}

void StatData::getSeries(System::String^ type, System::DateTime^ date, int patientID){
	
	System::String^ querystring = "Select * From Stats where ";
	querystring += "MONTH(stat_date)="+date->ToString("MM")+" AND ";
	querystring += "stat_type ='"+type+"' AND ";
	querystring += "stat_ptnt_id ="+patientID + " ";
	querystring += "ORDER BY stat_date ASC";
	query(querystring);
}

void StatData::get(System::DateTime^ date, int patientID){
	System::String^ querystring = "Select * From Stats where ";
	querystring += "stat_date ='"+date->ToString("MM/dd/yyyy")+"' AND ";
	querystring += "stat_ptnt_id ="+patientID;
	querystring += " ORDER BY stat_type ASC";
	query(querystring);
}

void StatData::get(System::String^ type, System::DateTime^ date, int patientID){
	
	System::String^ querystring = "Select * From Stats where ";
	querystring += "stat_date='" + date->ToString("MM/dd/yyyy")+"' AND ";
	querystring += "stat_type ='"+type+"' AND ";
	querystring += "stat_ptnt_id ="+patientID;
	query(querystring);
}

void StatData::add(System::String^ type, System::DateTime^ date, int data, int patientID){
	//check if it already exists
	this->get(type, date, patientID);
	if(myReader->HasRows){
		System::String^ querystring = "Update Stats Set ";
		querystring += "stat_ptnt_ID="+patientID+", ";
		querystring += "stat_type='" +  type + "', ";
		querystring += "stat_data="+data+", ";
		querystring += "stat_date='" + date->ToString("MM/dd/yyyy")+"' ";
		querystring += "where stat_id=" + (int)myReader["stat_id"]+"";
		closeConnection();
		query(querystring);
		closeConnection();
	} else {
		closeConnection();
		System::String^ querystring = "Insert Into Stats Values (";
		querystring += patientID+", ";
		querystring += "'" +  type + "', ";
		querystring += data+", ";
		querystring += "'" + date->ToString("MM/dd/yyyy")+"')";
		query(querystring);
		closeConnection();
	}
}
