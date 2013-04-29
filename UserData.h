#pragma once
#include "User.h"
#include "DBase.h"

using namespace System::Data::SqlClient;

//class that manages database reading and writing for Appointments
public ref class UserData : public DBase
{
public:
	//constructor and destructor methods
	UserData(void);
	virtual ~UserData(void);

	//checks if username and password exist as a record in the database
	//return true if its valid, false if its not
	bool validLogin(System::String^ userN, System::String^ passW);

	//checks if username already exists in the database
	//used to prevent duplicate usernames when adding a new user
	bool nameExists(System::String^ userN);

	//GET methods are overloaded
	//They all return users based on their specific parameters

	//returns a user that has the username and password
	User^ get(System::String^ userN, System::String^ passW);
	
	//returns a user that matches the user id
	User^ get(int UserID);

	//FAL bool replaces the search for the username with the search for a user with the same concatenated
	//First And Last name
	User^ get(System::String^ userN, bool FAL);
	
	//internal method that creates a user based on currently open datareader
	User^ createUser();

	//adds a user with the parameters, returns true if successful
	bool add(String^ name, String^ password, int docid, int forgot, int type, String^ fname,String^ lname);
	//same as other add method but returns a User object instead
	User^ add(String^ fName, String^ lName, int docId, String^ t, String^ username, String ^ password);

	//updates a user with the parameters, all parameters are necessary and all will be updated to the 
	//record that matches the passed in userid
	bool update(int userid, String^ name, String^ password, int docid, int forgot, int type, String^ fname,String^ lname);
	
	//marks a user that matches the passed in username as forgetting their password
	bool forgotPass(System::String^ userN);

	//removes the forgot password flag from the user that matches the passed in username
	bool removeforgotPass(System::String^ userN);

	//Opens a connection to read all the records of users that are marked for forgetting their password
	//must manuall close the connection afterwards
	void forgotPassList();

	//pulls all users of a specific type, connection remains open for row by row reading
	//must manually close the connection afterwards
	void userList(int type);
	
private:

};

