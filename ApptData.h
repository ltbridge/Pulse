#pragma once
#include "DBase.h"

//class that manages database reading and writing for Appointments
public ref class ApptData :public DBase
{
public:
	ApptData(void);
	virtual ~ApptData(void);

	//gets all appointments for a specific doctor and date
	//connection is left open, must be closed after calling this function
	void get(System::DateTime^ date, int doc_ID);

	//adds an appointment to the database, returns true if successful
	bool add(System::DateTime^ date, int doc_ID, int ptnt_ID);

	//removes an appointment to the database, returns true if successful
	bool remove(int appt_ID);
};

