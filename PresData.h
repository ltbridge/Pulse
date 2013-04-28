#pragma once
#include "DBase.h"

ref class PresData : public DBase
{
public:
	PresData(void);
	virtual ~PresData(void);
	void get(int ptnt_ID);
	bool edit(int ptnt_ID, System::String ^ pres_Name, int pres_Dose, System::String ^ pres_Instructions);
	bool add(int ptnt_ID, System::String ^ pres_Name, int pres_Dose, System::String ^ pres_Instructions);
private:
};

