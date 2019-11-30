#include <SQLite3/sqlite3.h>
#include <iostream>

int main()
{
	sqlite3* db;
	int exit = 0;
	exit = sqlite3_open("user.db", &db);

	if (exit)
	{
		std::cerr << "Failed to open db" << std::endl;
		std::cin.get();
		return -1;
	}
	std::cout << "Opened db successfully";

	std::string sqCreate = "CREATE TABLE PAGASA("
		                   "ID INT PRIMARY KEY NOT NULL, "
		                   "SURNAME TEXT NOT NULL, "
		                   "FIRSTNAME TEXT NOT NULL, "
		                   "MIDDLENAME TEXT NOT NULL, "
		                   "SUFFIX TEXT NOT NULL, "
		                   "BIRTHDATE TEXT NOT NULL, "
		                   "AGE TEXT NOT NULL, "
		                   "OCCUPATION TEXT NOT NULL, "
		                   "ADDRESS TEXT NOT NULL, "
		                   "CONTACTNUMBER TEXT NOT NULL, "
		                   "EMERGENCYCONTACT TEXT NOT NULL, "
		                   "EMERGENCYNUMBER TEXT NOT NULL, "
		                   "ISVOTER INT NOT NULL);";

	char* error;
	exit = sqlite3_exec(db, sqCreate.c_str(), NULL, 0, &error);
	if (exit != SQLITE_OK)
	{
		std::cerr << "Failed to create table" << std::endl;
		sqlite3_free(error);
		std::cout << error << std::endl;
		std::cin.get();
		return -1;
	}
	std::cout << "Created table!" << std::endl;
	sqlite3_close(db);

	std::cin.get();
	return 0;
}