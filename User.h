#pragma once

using namespace System;
public ref class User
{
public:
	User();
	User(String^ fName, String^ lName, int docId, String^ t, int userID);
	void AssignData(String^ fName, String^ lName, int docId, String^ t, int userID);
	virtual ~User(void);
	String^ getfirstName();
	String^ getlastName();
	int getdoctorId();
	String^ gettype();
	int getuserId();
private:
	String^ firstName;
	String^ lastName;
	int doctorId;
	String^ type;
	int userId;
};

