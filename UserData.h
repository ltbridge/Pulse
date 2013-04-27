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
	User^ get(System::String^ userN, System::String^ passW);
private:

};

