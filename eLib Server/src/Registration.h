#pragma once
#include "CoreIncludes.h"

namespace Registration
{
	User* newUser();
	
	std::string inputName();
	int inputDateOfBirth(User& user);
	std::string inputBarangay();
	std::string inputAddress();
	std::string inputContactNumber();
	std::string inputEmergencyContact();
	std::string inputEmergencyNumber();

}