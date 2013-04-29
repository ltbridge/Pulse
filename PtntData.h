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
	void search(String^ firstName, String^ lastName, String^ phoneNum, int id);
	bool add(Patient^ newPatient);

private:

};

