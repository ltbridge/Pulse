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
	querystring += "where CAST(appt_date as DATE)='"+date->ToString("MM/dd/yyyy")+"' AND appt_doc_id='"+doc_ID+"'";
	query(querystring);
}

bool ApptData::add(System::DateTime^ date, int doc_ID, int ptnt_ID)
{
	return false;
}

bool ApptData::remove(int appt_ID)
{
	return false;
}