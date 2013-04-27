#pragma once

using namespace System;
public ref class User
{
public:
	User();
	User(String^ fName, String^ lName, int docId, String^ t);
	void AssignData(String^ fName, String^ lName, int docId, String^ t);
	virtual ~User(void);
	String^ getfirstName();
	String^ getlastName();
	int getdoctorId();
	String^ gettype();
private:
	String^ firstName;
	String^ lastName;
	int doctorId;
	String^ type;
};

