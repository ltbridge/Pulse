#pragma once
#include "DBase.h"

ref class CommData : public DBase
{
public:
	CommData(void);
	virtual ~CommData(void);
	void get(System::DateTime^ date, int ptnt_ID);
	bool add(System::DateTime^ date, int ptnt_ID, System::String ^ enteredString);
};

