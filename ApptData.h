#pragma once
ref class ApptData :
public DBase
{
public:
	ApptData(void);
	virtual ~ApptData(void);
	void get(System::DateTime date, int doc_ID);
	bool add(System::DateTime date, int doc_ID, int ptnt_ID);
	bool remove(Appt_ID);
};

