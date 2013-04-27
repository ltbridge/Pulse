#pragma once
using namespace System::Data::SqlClient;

public ref class DBase
{
public:
	DBase(void);
	virtual ~DBase(void);

protected:
	void query(System::String^ queryString);
	void closeConnection();

	SqlConnection^ con;
	SqlCommand^ com;
	SqlDataReader^ myReader;
};

