#pragma once
using namespace System::Data::SqlClient;

//Base class for all database classes
//manages the connections and sending the query
//as well as a unified way to read the data back
public ref class DBase
{
public:
	DBase(void);
	virtual ~DBase(void);

protected:
	//base query function that opens a myReader object for reading;
	void query(System::String^ queryString);

	SqlConnection^ con;
	SqlCommand^ com;

public:
	//public function to close the connection
	void closeConnection();

	//public reader for database classes to access while a connection is open.
	SqlDataReader^ myReader;

};

