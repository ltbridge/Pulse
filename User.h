#pragma once

using namespace System;

//Entity class used for passing information between forms
//Used to manage permissions for the currently logged in user
//Also used to determine the doctor in charge of the current session
public ref class User
{
public:
	//constructor and destructor methods
	User();
	User(String^ fName, String^ lName, int docId, String^ t, int userID, String^ password, String ^username);
	virtual ~User(void);

	//assigns a full user if a blank user was created originally, takes the place of a copy constructor
	void AssignData(String^ fName, String^ lName, int docId, String^ t, int userID, String^ password, String ^ username);

	//get methods
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

