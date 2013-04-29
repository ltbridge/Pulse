#include "StdAfx.h"
#include "ApptData.h"


ApptData::ApptData(void)
{
}


ApptData::~ApptData(void)
{
}

void ApptData::get(System::DateTime^ date, int doc_ID)
{
	System::String^ querystring = "Select * From Appointments ";
	querystring += "Join Users on appt_doc_id=user_id ";
	querystring += "Join Patients on appt_ptnt_id=ptnt_id ";
	querystring += "where CAST(appt_date as DATE)='"+date->ToString("MM/dd/yyyy")+"' AND appt_doc_id='"+doc_ID+"' ";
	querystring += "ORDER BY appt_date ASC";
	query(querystring);
}

bool ApptData::add(System::DateTime^ date, int doc_ID, int ptnt_ID)
{
	System::String^ querystring = "Insert into Appointments Values(";
	querystring += "" + doc_ID +", ";
	querystring += "" + ptnt_ID +",";
	querystring += "'" + date->ToString() +"')";
	query(querystring);
	closeConnection();
	return true;
}

bool ApptData::remove(int appt_ID)
{
	System::String^ querystring = "Delete from Appointments where ";
	querystring += "appt_id=" + appt_ID;
	query(querystring);
	closeConnection();
	return true;
}