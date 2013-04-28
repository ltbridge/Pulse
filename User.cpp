#include "StdAfx.h"
#include "User.h"

using namespace System;
User::User(){
}

User::User(String^ fName, String^ lName, int docId, String^ t, int uId)
{
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
	userId = uId;
}


User::~User(void)
{
}

void User::AssignData(String^ fName, String^ lName, int docId, String^ t, int uId){
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
	userId = uId;
}

String^ User::getfirstName(){return firstName;}
String^ User::getlastName(){return lastName;}
int User::getdoctorId(){return doctorId;}
String^ User::gettype(){return type;}
int User::getuserId(){return userId;}