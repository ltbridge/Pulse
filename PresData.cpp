#include "StdAfx.h"
#include "PresData.h"


PresData::PresData(void)
{
}


PresData::~PresData(void)
{
}

void PresData::getList(int ptnt_ID)
{
	System::String^ querystring = "Select * From Prescriptions ";
	querystring += "where pres_ptnt_id='"+ptnt_ID+"'";
	query(querystring);
}

void PresData::get(int pres_ID)
{
	System::String^ querystring = "Select * From Prescriptions ";
	querystring += "where pres_id='"+pres_ID+"'";
	query(querystring);
}

bool PresData::edit(int pres_ID, int ptnt_ID, int doc_ID,  System::String ^ pres_num, System::String ^ pres_Name, 
					System::String ^ pres_Dose, System::String ^ pres_Instructions, System::String ^ pres_refills, 
					System::String ^ pres_comments)
{
	System::String^ querystring = "Update Prescriptions Set ";
	querystring += "pres_ptnt_id="+ptnt_ID+", ";
	querystring += "pres_doc_id="+doc_ID+", ";
	querystring += "pres_num='" +  pres_num + "', ";
	querystring += "pres_name='" +  pres_Name + "', ";
	querystring += "pres_dose='" +  pres_Dose + "', ";
	querystring += "pres_instructions='" +  pres_Instructions + "', ";
	querystring += "pres_refills='" +  pres_refills + "', ";
	querystring += "pres_comments='" +  pres_comments + "' ";
	querystring += "where pres_id="+pres_ID;
	query(querystring);
	closeConnection();
	return true;
}
bool PresData::add(int ptnt_ID, int doc_ID, System::String ^ pres_num, System::String ^ pres_Name, System::String^ pres_Dose, 
					System::String ^ pres_Instructions, System::String ^ pres_refills, System::String ^ pres_comments)
{
	System::String^ querystring = "Insert into Prescriptions Values (";
	querystring += ptnt_ID+", ";
	querystring += doc_ID+", ";
	querystring += "'" +  pres_num + "', ";
	querystring += "'" +  pres_Name + "', ";
	querystring += "'" +  pres_Dose + "', ";
	querystring += "'" +  pres_Instructions + "', ";
	querystring += "'" +  pres_refills + "', ";
	querystring += "'" +  pres_comments + "')";
	query(querystring);
	closeConnection();
	return true;
}
