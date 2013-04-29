#pragma once
#include "stdafx.h"
#include "DBase.h"

//class for managing reading and writing from the database for patients
public ref class StatData : public DBase
{
public:
	//constructor and destructor methods
	StatData(void);
	virtual ~StatData(void);

	//GET functions are overloaded
	
	//This get function returns all stattypes entered for a specific patient and day
	void get(System::DateTime^ date, int patientID);

	//This get function returns at most one row, specifically used to determine if
	//a record already exists for a day, type, and patient
	void get(System::String^ type, System::DateTime^ date, int patientID);

	//returns all data points in a month for a specific type and patient
	//sorts on ASC order
	void getSeries(System::String^ type, System::DateTime^ date, int patientID);

	//adds a stat data, will first check if it exists and if so will instead update
	void add(System::String^ type, System::DateTime^ date, int data, int patientID);
};

