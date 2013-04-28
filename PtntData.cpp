#include "StdAfx.h"
#include "PtntData.h"

using namespace System;

PtntData::PtntData(void)
{
}


PtntData::~PtntData(void)
{
}

Patient^ PtntData::get(int id, bool user)
{
	String^ querystring = "Select * from Patients where ";
	if(!user){
		querystring = querystring+"ptnt_id="+id;
	} else {
		querystring = querystring+"ptnt_user_id="+id;
	}
	query(querystring);

	int patientID = (int)myReader["ptnt_id"];
	String ^ firstName = (String ^)myReader["ptnt_firstName"];
	String ^ lastName = (String ^)myReader["ptnt_lastName"];
	String ^ address = (String ^)myReader["ptnt_address"];
	String ^ city = (String ^)myReader["ptnt_city"];
	String ^ state = (String ^)myReader["ptnt_state"];
	int zipcode = (int)myReader["ptnt_zipcode"];
	String ^ email = (String ^)myReader["ptnt_email"];
	String ^ insurance = (String ^)myReader["ptnt_insurance"];
	String ^ policyNum = (String ^)myReader["ptnt_policyNum"];
	Patient ^ temp = gcnew Patient(patientID, firstName, lastName, address, city, state, zipcode, email, insurance, policyNum);
	closeConnection();
	return temp;
}

bool PtntData::add(Patient^ newPatient)
{
	return false;
}