#include "StdAfx.h"
#include "CommData.h"


CommData::CommData(void)
{
}


CommData::~CommData(void)
{
}

void CommData::get(System::DateTime^ date, int ptnt_ID)
{
	System::String^ querystring = "Select * From Comments ";
	querystring += "where comm_date ='"+date->ToString("MM/dd/yyyy")+"' AND comm_ptnt_id='"+ptnt_ID+"' ";
	querystring += "ORDER BY comm_date ASC";
	query(querystring);
}

bool CommData::add(System::DateTime^ date, int ptnt_ID, System::String ^ enteredString)
{
	System::String^ querystring = "Insert Into Comments Values (";
	querystring += ptnt_ID+", ";
	querystring += "'" +  enteredString + "', ";
	querystring += "'" + date->ToString("MM/dd/yyyy")+"')";
	query(querystring);
	closeConnection();
	return true;
}
