#pragma once
#include "stdafx.h"
#include "DBase.h"

public ref class StatData : public DBase
{
public:
	StatData(void);
	virtual ~StatData(void);
	void get(System::String^ type, System::DateTime date, int patientID);
	void add(System::String^ type, int data, int patientID, System::DateTime date);
};

