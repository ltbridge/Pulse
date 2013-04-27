#pragma once

#include "Patient.h"


Patient::Patient(int newID, String ^ first, String ^ last, String ^ newAddress, 
	String ^ newCity, String ^ newState, int zip, String^ newEmail, String ^newInsur, String ^ newPolicy)
{
	patientID = newID;
	firstName = first;
	lastName = last;
	address = newAddress;
	city = newCity;
	state = newState;
	zipcode = zip;
	email = newEmail;
	insurance = newInsur;
	policyNum = newPolicy;
}


Patient::~Patient(void)
{

}

int Patient::getPatientID(){return patientID;}
String ^ Patient::getFirst(){return firstName;}
String ^ Patient::getLast(){return lastName;}
String ^ Patient::getAddress(){return address;}
String ^ Patient::getCity(){return city;}
String ^ Patient::getState(){return state;}
int Patient::getZipcode(){return zipcode;}
String ^ Patient::getEmail(){return email;}
String ^ Patient::getInsurance(){return insurance;}
String ^ Patient::getPolicyNum(){return policyNum;}



