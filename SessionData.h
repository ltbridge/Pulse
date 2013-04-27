#pragma once
#include "Patient.h"
#include "User.h"

public ref class SessionData
{
public:
	SessionData(void);
	virtual ~SessionData(void);
	User ^ getcurrentUser();
	Patient ^ getcurrentPatient();
	void setcurrentUser(User ^ u);
	void setcurrentPatient(Patient ^ p);
private:
	User ^ currentUser;
	Patient ^ currentPatient;
};

