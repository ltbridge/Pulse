#pragma once

using namespace System;


//Entity class used for passing information between forms
//For doctors and nurses, an instance of the viewed patient is passed between forms
//For patients, their patient record is attached to the session class
public ref class Patient
{

public:
	//creates a blank patient class
	Patient();
	//creates a patient class with all the necessary parameters
	Patient(int newID, String ^ first, String ^ last, String ^ newAddress,
		String ^ newCity, String ^ newState, int zip, String^ phone, String^ newEmail, String ^newInsur, String ^ newPolicy);
	virtual ~Patient(void);
	
	//get methods
	String ^ getFirst();
	String ^ getLast();
	int getPatientID();
	String ^ getAddress();
	String ^ getCity();
	String ^ getState();
	int getZipcode();
	String ^ getPhone();
	String ^ getEmail();
	String ^ getInsurance();
	String ^ getPolicyNum();

private:
	int patientID;
	String ^ firstName;
	String ^ lastName;
	String ^ address;
	String ^ city;
	String ^ state;
	int zipcode;
	String ^ phone;
	String ^ email;
	String ^ insurance;
	String ^ policyNum;

};

