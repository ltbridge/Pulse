#pragma once
#include "Patient.h"
#include "User.h"


//Entity class that controls data passing between forms and ensures permissions
//are enforced through the whole program.  It also holds the current User information for display purposes
public ref class SessionData
{
public:
	//constructor and destructor methods
	SessionData(void);
	virtual ~SessionData(void);

	//get and set methods
	User ^ getcurrentUser();
	Patient ^ getcurrentPatient();
	void setcurrentUser(User ^ u);
	void setcurrentPatient(Patient ^ p);
private:
	User ^ currentUser;
	Patient ^ currentPatient;
};

