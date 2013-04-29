#pragma once
#include "stdafx.h"
#include "DBase.h"

public ref class StatData : public DBase
{
public:
	StatData(void);
	virtual ~StatData(void);
	void get(System::DateTime^ date, int patientID);
	void getSeries(System::String^ type, System::DateTime^ date, int patientID);
	void get(System::String^ type, System::DateTime^ date, int patientID);
	void add(System::String^ type, System::DateTime^ date, int data, int patientID);
};

