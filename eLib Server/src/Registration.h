#pragma once
#include "CoreIncludes.h"


namespace Registration
{
	User* newUser();
	
	std::string inputName();
	void inputDateOfBirth(User& user);
	void inputBarangay(User& user);
	void inputAddress(User& user);
	std::string inputContactNumber();
	std::string inputEmergencyContact();
	std::string inputEmergencyNumber();
}