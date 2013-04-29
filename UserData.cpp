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

User^ UserData::get(int userID){
	System::String^ querystring = 
		"Select * From Users where user_id="+userID;
	query(querystring);
	return createUser();
}

User^ UserData::get(System::String^ userN, bool firstAndLast){
	System::String^ querystring;
	if(firstAndLast)
		querystring ="Select * From Users where (user_firstName + ' ' + user_lastName)='"+userN+"'";
	else 
		querystring = "Select * From Users where user_name='"+userN+"'";
	query(querystring);
	return createUser();
}

User^ UserData::get(System::String^ userN, System::String^ passW){
	System::String^ querystring = "Select * From Users where user_name='"+userN+"' AND user_password='"+passW+"'";
	query(querystring);
	return createUser();
}

User^ UserData::createUser(){
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
	System::String^ password = (System::String^)myReader["user_password"];
	System::String^ name = (System::String^)myReader["user_name"];
	
	int doc_id;
	if(type == "Doctor"){
		 doc_id= (int)myReader["user_id"];
	} else {
		doc_id = (int)myReader["user_doc_id"];
	}
	int user_id = (int)myReader["user_id"];
	User^ returnUser = gcnew User(fName, lName, doc_id, type, user_id, password, name);
	closeConnection();
	return returnUser;
}

bool UserData::forgotPass(System::String^ userN){
	System::String^ querystring = 
		"Update Users SET user_forgot=1 where user_name='"+userN+"'";
	query(querystring);
	closeConnection();
	return true;
}

bool UserData::nameExists(System::String^ userN){
	System::String^ querystring = 
		"Select * From Users where user_name='"+userN+"'";
	query(querystring);
	if(myReader->HasRows){
		closeConnection();
		return true;
	}else
		return false;
}

User ^ UserData::add(String^ fName, String^ lName, int docId, String^ t, String^ username, String ^ password){
	int type;
	if(t == "Admin") 
		type = 1;
	if(t ==  "Doctor")
		type = 2;
	if(t ==  "Nurse")
		type = 3;
	if(t ==  "Patient")
		type = 4;

	System::String^ querystring = "Insert into Users Values(";
	querystring += "'" + username +"', ";
	querystring += "'" + password +"', ";
	querystring += "" + docId +", ";
	querystring += "" + 0 +", ";
	querystring += "" + type +", ";
	querystring += "'" + fName +"', ";
	querystring += "'" + lName +"')";
	query(querystring);
	closeConnection();
	User ^ user = get(username, password);
	return user;
}

void UserData::forgotPassList(){
	System::String^ querystring = 
		"Select * From Users where user_forgot=1";
	query(querystring);
}

bool UserData::removeforgotPass(System::String^ userN){
	System::String^ querystring = 
		"Update Users SET user_forgot=0 where user_name='"+userN+"'";
	query(querystring);
	closeConnection();
	return true;
}

void UserData::userList(int type){
	System::String^ querystring;
	if(type == 0)
		 querystring = "Select * From Users";
	else
		querystring = "Select * From Users where user_type="+type;
	query(querystring);
}

bool UserData::add(String^ name, String^ password, int docid, int forgot, int type, String^ fname,String^ lname){
	System::String^ querystring = "Insert into Users Values(";
	querystring += "'" + name +"', ";
	querystring += "'" + password +"', ";
	querystring += "" + docid +", ";
	querystring += "" + forgot +", ";
	querystring += "" + type +", ";
	querystring += "'" + fname +"', ";
	querystring += "'" + lname +"')";
	query(querystring);
	closeConnection();
	return true;
}
bool UserData::update(int userid, String^ name, String^ password, int docid, int forgot, int type, String^ fname,String^ lname){
	System::String^ querystring = "Update Users Set ";
	querystring += "user_name='" + name +"', ";
	querystring += "user_password='" + password +"', ";
	querystring += "user_doc_id=" + docid +", ";
	querystring += "user_forgot=" + forgot +", ";
	querystring += "user_type=" + type +", ";
	querystring += "user_firstName='" + fname +"', ";
	querystring += "user_lastNAme='" + lname +"' ";
	querystring += "where user_id="+userid;
	query(querystring);
	closeConnection();
	return true;
}