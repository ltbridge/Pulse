#pragma once
#include "DBase.h"

//class that manages database reading and writing for comments
ref class CommData : public DBase
{
public:
	CommData(void);
	virtual ~CommData(void);

	//gets a list of comments for a specific patient on a specific day
	//connection is left open, so must be closed manually after using this function
	void get(System::DateTime^ date, int ptnt_ID);

	//adds a comment to the database, returns true if successful
	bool add(System::DateTime^ date, int ptnt_ID, System::String ^ enteredString);
};

