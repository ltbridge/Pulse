#pragma once
#include "DBase.h"

public ref class ApptData :public DBase
{
public:
	ApptData(void);
	virtual ~ApptData(void);
	void get(System::DateTime date, int doc_ID);
	bool add(System::DateTime date, int doc_ID, int ptnt_ID);
	bool remove(int appt_ID);
};

