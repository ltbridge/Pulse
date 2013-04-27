#include "StdAfx.h"
#include "User.h"

using namespace System;
User::User(){
}

User::User(String^ fName, String^ lName, int docId, String^ t)
{
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
}


User::~User(void)
{
}

void User::AssignData(String^ fName, String^ lName, int docId, String^ t){
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
}

String^ User::getfirstName(){return firstName;}
String^ User::getlastName(){return lastName;}
int User::getdoctorId(){return doctorId;}
String^ User::gettype(){return type;}