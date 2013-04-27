#pragma once
public ref class User
{
public:
	User();
	User(System::String^ fName, System::String^ lName, int docId, System::String^ t);
	void AssignData(System::String^ fName, System::String^ lName, int docId, System::String^ t);
	virtual ~User(void);
	System::String^ getfirstName();
	System::String^ getlastName();
	int getdoctorId();
	System::String^ gettype();
private:
	System::String^ firstName;
	System::String^ lastName;
	int doctorId;
	System::String^ type;
};

