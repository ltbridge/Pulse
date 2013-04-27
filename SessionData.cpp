#include "StdAfx.h"
#include "SessionData.h"


SessionData::SessionData(void)
{
}


SessionData::~SessionData(void)
{
}

User^ SessionData::getcurrentUser(){return currentUser;}
Patient^ SessionData::getcurrentPatient(){return currentPatient;}
void SessionData::setcurrentUser(User^ u){currentUser = u;}
void SessionData::setcurrentPatient(Patient^ p){currentPatient = p;}