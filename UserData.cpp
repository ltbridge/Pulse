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
	SqlConnection^ con=gcnew SqlConnection();
	con->ConnectionString="Data Source=OBI-LAPTOP\\PULSEDB;Initial Catalog=PulseDatabase;Integrated Security=True";

	SqlCommand^ com=gcnew SqlCommand();
	com->Connection=con;
	com->CommandText="Select * From Users where user_name='"+userN+"' AND user_password='"+passW+"'";
	con->Open();

	SqlDataReader^ myReader;
	myReader=com->ExecuteReader();
	myReader->Read();

	if(myReader->HasRows)
			result = true;
	myReader->Close();
	con->Close();
	return result;
}

User^ UserData::get(System::String^ userN, System::String^ passW){
	SqlConnection^ con=gcnew SqlConnection();
	con->ConnectionString="Data Source=OBI-LAPTOP\\PULSEDB;Initial Catalog=PulseDatabase;Integrated Security=True";

	SqlCommand^ com=gcnew SqlCommand();
	com->Connection=con;
	com->CommandText="Select * From Users where user_name='"+userN+"' AND user_password='"+passW+"'";
	con->Open();

	SqlDataReader^ myReader;
	myReader=com->ExecuteReader();
	myReader->Read();

	System::String^ type;
	int typeNum = (int)myReader[5];
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
	int doc_id = (int)myReader["user_doc_id"];
	User^ returnUser = gcnew User(fName, lName, doc_id, type);

	myReader->Close();
	con->Close();
	return returnUser;
}
