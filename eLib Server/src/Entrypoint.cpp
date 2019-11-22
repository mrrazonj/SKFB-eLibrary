#include "Registration.h"

int main(int argc, char** argv) 
{
	while (true)
	{
		User* user = new User();
		Registration::registerUser(*user);
		user->displayData();
		delete user;
	}
}