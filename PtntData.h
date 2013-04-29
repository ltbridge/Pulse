#pragma once
#include "DBase.h"
#include "Patient.h"

using namespace System;

ref class PtntData :public DBase
{
public:
	PtntData(void);
	virtual ~PtntData(void);
	Patient^ get(int ptnt_ID, bool user);
	void search(String^ firstName, String^ lastName, String^ phoneNum, int id, int docid);
	Patient ^ add(Patient^ newPatient, int userID, int docID);
	bool update(int ptnt_id, String ^ first, String ^ last, String ^ newAddress, String ^ newCity, 
				String ^ newState, int zip, String ^ newphone, String^ newEmail, String ^newInsur, 
				String ^ newPolicy);

private:

};

