#include "Registration.h"

int main(int argc, char** argv) 
{
	User* user = new User();
	Registration::inputName(*user);
	Registration::inputDateOfBirth(*user);
	Registration::inputAddress(*user);
	Registration::inputContactNumber(*user);
	delete user;
}