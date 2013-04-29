#include "stdAfx.h"
#include "UserData.h"

using namespace System::Data::SqlClient;

UserData::UserData(void)
{
}


UserData::~UserData(void)
{
}

bool UserData::validLogin(System::String^ userN, System::String^ passW){
	bool result = false;
	System::String^ querystring = 
		"Select * From Users where user_name='"+userN+"' AND user_password='"+passW+"'";
	query(querystring);

	if(myReader->HasRows)
			result = true;
	closeConnection();
	return result;
}

User^ UserData::get(System::String^ userN, System::String^ passW){
	System::String^ querystring = 
		"Select * From Users where user_name='"+userN+"' AND user_password='"+passW+"'";
	query(querystring);

	System::String^ type;
	int typeNum = (int)myReader["user_type"];
	switch(typeNum){
		case 1: 
			type = "Admin";
			break;
		case 2:
			type = "Doctor";
			break;
		case 3:
			type = "Nurse";
			break;
		case 4:
		default:
			type = "Patient";
			break;
	}
	System::String^ fName = (System::String^)myReader["user_firstName"];
	System::String^ lName = (System::String^)myReader["user_lastName"];
	
	int doc_id;
	if(type == "Doctor"){
		 doc_id= (int)myReader["user_id"];
	} else {
		doc_id = (int)myReader["user_doc_id"];
	}
	int user_id = (int)myReader["user_id"];
	User^ returnUser = gcnew User(fName, lName, doc_id, type, user_id);
	closeConnection();
	return returnUser;
}
