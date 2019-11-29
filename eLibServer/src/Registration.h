#pragma once
#include "Core.h"

class User
{
	int id;

	char* lastName;
	char* firstName;
	char* middleName;
	char* suffixName;
	char* dateOfBirth;
	char* age;
	char* occupation;
	
	char* address;
	char* barangay;
	
	char* contactNumber;
	char* emailAddress;
	char* emergencyContact;
	char* emergencyNumber;

	bool isRegisteredVoter;


public:
	User(char* lastName, char* firstName, char* middleName, char* suffixName, char* dateOfBirth, char* age, char* occupation,
		 char* address, char* barangay, char* contactNumber, char* emailAddress, char* emergencyContact, char* emergencyNumber,
		 bool& isRegisteredVoter);
	~User();

	char* getLastName();
	char* getFirstName();
	char* getMiddleName();
	char* getSuffixName();
	char* getDateOfBirth();
	char* getAge();
	char* getOccupation();
	char* getAddress();
	char* getBarangay();
	char* getContactNumber();
	char* getEmailAddress();
	char* getEmergencyContact();
	char* getEmergencyNumber();
	bool getVoterStatus();

	void setLastName();
	void setFirstName();
	void setMiddleName();
	void setSuffixName();
	void setDateOfBirth();
	void setAge();
	void setOccupation();
	void setAddress();
	void setBarangay();
	void setContactNumber();
	void setEmailAddress();
	void setEmergencyContact();
	void setEmergencyNumber();
	bool setVoterStatus();
};

namespace Registration
{
	void OpenRegistrationForm(bool& isOpen);
	void RegisterUser(User& user);
}