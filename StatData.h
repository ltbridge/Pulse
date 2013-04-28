#pragma once
#include "stdafx.h"
#include "DBase.h"

public ref class StatData : 
{
public:
	StatData(void);
	virtual ~StatData(void);
	void get(System::String^ type, System::String^ date, int patientID);
	void add(System::String^ type, System::String^ date, int patientID, System::DateTime date);
};

