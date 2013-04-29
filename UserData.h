#pragma once
#include "User.h"
#include "DBase.h"

using namespace System::Data::SqlClient;

public ref class UserData : public DBase
{
public:
	UserData(void);
	virtual ~UserData(void);
	bool validLogin(System::String^ userN, System::String^ passW);
	bool nameExists(System::String^ userN);
	User^ get(System::String^ userN, System::String^ passW);
	User^ get(int UserID);
	User^ get(System::String^ userN, bool FAL);
	User^ createUser();
	bool add(String^ name, String^ password, int docid, int forgot, int type, String^ fname,String^ lname);
	bool update(int userid, String^ name, String^ password, int docid, int forgot, int type, String^ fname,String^ lname);
	bool forgotPass(System::String^ userN);
	bool removeforgotPass(System::String^ userN);
	void forgotPassList();
	void userList(int type);
	User^ add(String^ fName, String^ lName, int docId, String^ t, String^ username, String ^ password);
	
private:

};

