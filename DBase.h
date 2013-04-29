#pragma once
using namespace System::Data::SqlClient;

public ref class DBase
{
public:
	DBase(void);
	virtual ~DBase(void);

protected:
	void query(System::String^ queryString);

	SqlConnection^ con;
	SqlCommand^ com;

public:
	void closeConnection();
	SqlDataReader^ myReader;

};

