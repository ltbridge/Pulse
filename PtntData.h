#pragma once
ref class PtntData :
public DBase
{
public:
	PtntData(void);
	virtual ~PtntData(void);
	Patient^ get(int ptnt_ID, bool user);
	bool add(Patient^ newPatient);

private:

};

