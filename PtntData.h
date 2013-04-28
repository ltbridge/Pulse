#pragma once
#include "DBase.h"
#include "Patient.h"

ref class PtntData :public DBase
{
public:
	PtntData(void);
	virtual ~PtntData(void);
	Patient^ get(int ptnt_ID, bool user);
	bool add(Patient^ newPatient);

private:

};

