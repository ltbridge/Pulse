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
	String ^ phone = (String ^)myReader["ptnt_phone"];
	String ^ email = (String ^)myReader["ptnt_email"];
	String ^ insurance = (String ^)myReader["ptnt_insurance"];
	String ^ policyNum = (String ^)myReader["ptnt_policyNum"];
	Patient ^ temp = gcnew Patient(patientID, firstName, lastName, address, city, state, zipcode, phone, email, insurance, policyNum);
	closeConnection();
	return temp;
}

Patient ^ PtntData::add(Patient^ newPatient, int userID, int docID)
{
	String^ querystring = "Insert into Patients Values(";
	querystring += "" + userID +", ";
	querystring += "" + docID +", ";
	querystring += "'" + newPatient->getFirst() +"', ";
	querystring += "'" + newPatient->getLast() +"', ";
	querystring += "'" + newPatient->getAddress() +"', ";
	querystring += "'" + newPatient->getCity() +"', ";
	querystring += "'" + newPatient->getState() +"', ";
	querystring += "" + newPatient->getZipcode() +", ";
	querystring += "'" + newPatient->getPhone() +"', ";
	querystring += "'" + newPatient->getEmail() +"', ";
	querystring += "'" + newPatient->getInsurance() +"', ";
	querystring += "'" + newPatient->getPolicyNum() +"')";
	query(querystring);
	closeConnection();
	return this->get(userID, true);
}

bool PtntData::update(int ptnt_id, String ^ first, String ^ last, String ^ newAddress,
		String ^ newCity, String ^ newState, int zip, String ^ newphone, String^ newEmail, String ^newInsur, String ^ newPolicy)
{
	String^ querystring = "Update Patients Set ";
	querystring += "ptnt_firstName='" + first +"', ";
	querystring += "ptnt_lastName='" + last +"', ";
	querystring += "ptnt_address='" + newAddress +"', ";
	querystring += "ptnt_city='" + newCity +"', ";
	querystring += "ptnt_state='" + newState +"', ";
	querystring += "ptnt_zipcode=" + zip +", ";
	querystring += "ptnt_phone='" + newphone +"', ";
	querystring += "ptnt_email='" + newEmail +"', ";
	querystring += "ptnt_insurance='" + newInsur +"', ";
	querystring += "ptnt_policyNum='" + newPolicy +"' ";
	querystring += "where ptnt_id=" + ptnt_id +"";
	query(querystring);
	closeConnection();
	return true;
}

void PtntData::search(String^ firstName, String^ lastName, String^ phoneNum, int id, int docid){
	String^ querystring = "Select * from Patients where ";
	bool orSetter = false;
	if(firstName != ""){
		querystring += "ptnt_firstName LIKE '%"+firstName+"%'";
		orSetter = true;
	}
	if(lastName != ""){
		querystring += (orSetter? " OR ": "")+"ptnt_lastName LIKE '%"+id+"%'";
		orSetter = true;
	}
	if(phoneNum != ""){
		querystring += (orSetter? " OR ": "")+"ptnt_phone LIKE '%"+phoneNum+"%'";
		orSetter = true;
	}
	if(id != 0){
		querystring += (orSetter? " OR ": "")+"ptnt_id LIKE '%"+id+"%'";
		orSetter = true;
	}
	if(docid != 0){
		querystring += (orSetter? " AND ": "")+"ptnt_doc_id="+docid;
	}
	query(querystring);
}