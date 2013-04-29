#include "StdAfx.h"
#include "User.h"

using namespace System;
User::User(){
}

User::User(String^ fName, String^ lName, int docId, String^ t, int uId, String ^ pass, String ^ usern)
{
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
	userId = uId;
	password = pass;
	username = usern;
}


User::~User(void)
{
}

void User::AssignData(String^ fName, String^ lName, int docId, String^ t, int uId, String^ pass, String ^ usern){
	firstName = fName;
	lastName = lName;
	doctorId = docId;
	type = t;
	userId = uId;
	password = pass;
	username = usern;
}

String^ User::getfirstName(){return firstName;}
String^ User::getlastName(){return lastName;}
String^ User::getuserName(){return username;}
String^ User::getpassword(){return password;}
int User::getdoctorId(){return doctorId;}
String^ User::gettype(){return type;}
int User::getuserId(){return userId;}