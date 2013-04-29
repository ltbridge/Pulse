#pragma once
#include "DBase.h"

//class that manages database reading and writing for prescriptions
ref class PresData : public DBase
{
public:
	//constructor and desctructor methods
	PresData(void);
	virtual ~PresData(void);

	//gets a single prescription record according to primary key
	//connection is left open due to no prescription entity class
	void get(int pres_ID);

	//gets a list of prescriptions for a single patient
	//connection is left open due to no prescription entity class
	void getList(int ptnt_ID);

	//edits a single prescription record in the database, returns true if successful
	bool edit(int pres_ID, int ptnt_ID, int doc_ID,  System::String ^ pres_num, System::String ^ pres_Name, 
					System::String ^ pres_Dose, System::String ^ pres_Instructions, System::String ^ pres_refills, 
					System::String ^ pres_comments);

	//adda a new prescription to the database, returns true if successul
	bool add(int ptnt_ID, int doc_ID, System::String ^ pres_num, System::String ^ pres_Name, System::String^ pres_Dose, 
					System::String ^ pres_Instructions, System::String ^ pres_refills, System::String ^ pres_comments);
private:
};

