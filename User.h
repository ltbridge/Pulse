#pragma once

using namespace System;
public ref class User
{
public:
	User();
	User(String^ fName, String^ lName, int docId, String^ t, int userID, String^ password, String ^username);
	void AssignData(String^ fName, String^ lName, int docId, String^ t, int userID, String^ password, String ^ username);
	virtual ~User(void);
	String^ getfirstName();
	String^ getlastName();
	int getdoctorId();
	String^ gettype();
	int getuserId();
	String^ getpassword();
	String^ getuserName();
private:
	String^ firstName;
	String^ lastName;
	int doctorId;
	String^ type;
	int userId;
	String^ password;
	String^ username;
};

