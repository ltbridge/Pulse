#pragma once
ref class CommData :
public DBase
{
public:
	CommData(void);
	virtual ~CommData(void);
	void get(System::String ^ date, int ptnt_ID);
	bool add(System::String ^ date, int ptnt_ID, System::String ^ enteredString);
	bool remove(Comm_ID);
};

