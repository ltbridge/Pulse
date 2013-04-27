#include "StdAfx.h"
#include "DBase.h"


DBase::DBase(void){}


DBase::~DBase(void){}

void DBase::query(System::String^ queryString){
	SqlCommand^ com = gcnew SqlCommand();
	SqlConnection^ con = gcnew SqlConnection();

	con->ConnectionString="Data Source=OBI-LAPTOP\\PULSEDB;Initial Catalog=PulseDatabase;Integrated Security=True";
	com->Connection=con;

	com->CommandText = queryString;
	con->Open();

	myReader=com->ExecuteReader();
	myReader->Read();
}

void DBase::closeConnection(){
	myReader->Close();
}
