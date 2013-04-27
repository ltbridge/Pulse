#pragma once

using namespace System;

public ref class Patient
{

public:
	Patient(int newID, String ^ first, String ^ last, String ^ newAddress,
		String ^ newCity, String ^ newState, int zip, String^ newEmail, String ^newInsur, String ^ newPolicy);
	virtual ~Patient(void);
	String ^ getFirst();
	String ^ getLast();
	int getPatientID();
	String ^ getAddress();
	String ^ getCity();
	String ^ getState();
	int getZipcode();
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
	String ^ email;
	String ^ insurance;
	String ^ policyNum;

};

