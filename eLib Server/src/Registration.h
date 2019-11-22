#pragma once
#include "Engine.h"


namespace Registration
{
	User* newUser();

	void registerUser(User& user);
	
	void inputName(User& user);
	void inputDateOfBirth(User& user);
	void inputBarangay(User& user);
	void inputAddress(User& user);
	void inputContactNumber(User& user);
	void inputEmergencyContact(User& user);
	void inputEmergencyNumber(User& user);

	void finalizeID(User& user);
}