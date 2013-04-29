#pragma once
#include "DBase.h"
#include "Patient.h"

using namespace System;

//class for managing reading and writing from the database for patients
ref class PtntData :public DBase
{
public:
	//constructor and destructor methods
	PtntData(void);
	virtual ~PtntData(void);

	//returns a patient object with the information matching the patient id
	//if the user bool is flagged, it instead returns the patient object that has that user id
	//it is assumed you will only call this method knowing the IDs are valid, no checking is
	//done in the method	
	Patient^ get(int ptnt_ID, bool user);

	//searches for a patient based on any of the parameters passed in
	//docid is required and will only return patients assigned to the doctor
	//the other parameters are all optional and are searched on an OR basis 
	void search(String^ firstName, String^ lastName, String^ phoneNum, int id, int docid);

	//adds a patient with the passed through parameters.  A patient class is supposed to be 
	//created beforehand and passed into this method
	Patient ^ add(Patient^ newPatient, int userID, int docID);

	//updates a patient, requires ALL parameters and none may be null
	bool update(int ptnt_id, String ^ first, String ^ last, String ^ newAddress, String ^ newCity, 
				String ^ newState, int zip, String ^ newphone, String^ newEmail, String ^newInsur, 
				String ^ newPolicy);

private:

};

