#include "StdAfx.h"
#include "User.h"

User::User(){
}

User::User(System::String^ fName, System::String^ lName, int docId, System::String^ t)
{
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
}


User::~User(void)
{
}

void User::AssignData(System::String^ fName, System::String^ lName, int docId, System::String^ t){
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
}

System::String^ User::getfirstName(){return firstName;}
System::String^ User::getlastName(){return lastName;}
int User::getdoctorId(){return doctorId;}
System::String^ User::gettype(){return type;}