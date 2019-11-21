#pragma once
#include "CoreIncludes.h"


namespace Registration
{
	User* newUser();
	
	void inputName(User& user);
	void inputDateOfBirth(User& user);
	void inputBarangay(User& user);
	void inputAddress(User& user);
	void inputContactNumber(User& user);
	void inputEmergencyContact();
	void inputEmergencyNumber();
}