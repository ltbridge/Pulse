#pragma once
#include "DBase.h"

ref class PresData : public DBase
{
public:
	PresData(void);
	virtual ~PresData(void);
	void get(int pres_ID);
	void getList(int ptnt_ID);
	bool edit(int pres_ID, int ptnt_ID, int doc_ID,  System::String ^ pres_num, System::String ^ pres_Name, 
					System::String ^ pres_Dose, System::String ^ pres_Instructions, System::String ^ pres_refills, 
					System::String ^ pres_comments);
	bool add(int ptnt_ID, int doc_ID, System::String ^ pres_num, System::String ^ pres_Name, System::String^ pres_Dose, 
					System::String ^ pres_Instructions, System::String ^ pres_refills, System::String ^ pres_comments);
private:
};

