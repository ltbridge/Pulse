#pragma once
ref class ApptData :
public DBase
{
public:
	ApptData(void);
	virtual ~ApptData(void);
	void get(System::String ^ date, int doc_ID);
	bool add(System::String ^ date, int time, int doc_ID, int ptnt_ID);
	bool remove(Appt_ID);
};

