#include "StdAfx.h"
#include "StatData.h"


StatData::StatData(void)
{
}


StatData::~StatData(void)
{
}

void StatData::get(System::String^ type, System::DateTime date, int patientID){
	//get data from database
}
void StatData::add(System::String^ type, int data, int patientID, System::DateTime date){
	//save data to database
}
