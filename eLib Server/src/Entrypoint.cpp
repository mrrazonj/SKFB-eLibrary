#include "Registration.h"
#include <sqlite3.h>

int main(int argc, char** argv) 
{
	static bool isInRegistration = true;
	while (isInRegistration)
	{
		User* user = new User();
		Registration::registerUser(*user);
		user->displayData();

		sqlite3* db;
		int exit = 0;
		exit = sqlite3_open("Users.db", &db);

		if (exit)
		{
			std::cerr << "Cannot open database, please contact sysadmin! " << sqlite3_errmsg(db) << std::endl;
			throw "App failed to open database, please contact sysadmin!";
			
			system("pause");
		}

		else
		{
			std::cout << "Database Users.db opened successfully!" << std::endl;

			system("pause");
		}

		delete user;
	}
}