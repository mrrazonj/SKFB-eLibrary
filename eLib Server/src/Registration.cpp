#include "Registration.h"

namespace Registration
{
	User* newUser() {
		User* user = new User();
		return user;
	}

	int inputDateOfBirth(User& user) {
		std::string yearString;
		std::cout << "Enter year of birth:" << std::endl;
		std::cout << ">" << std::flush;
		std::getline(std::cin, yearString);
		std::string monthString;
		std::cout << "Enter month of birth:" << std::endl;
		std::cout << ">" << std::flush;
		std::getline(std::cin, monthString);
		std::string dayString;
		std::cout << "Enter day of birth:" << std::endl;
		std::cout << ">" << std::flush;
		std::getline(std::cin, dayString);

		time_t rawTime = time(NULL);
		struct tm timeTable;
		localtime_s(&timeTable, &rawTime);

		int currentYear = timeTable.tm_year + 1900;
		int currentMonth = timeTable.tm_mon + 1;

		int birthYear = std::stoi(yearString);
		int birthMonth = std::stoi(monthString);
		int birthDay = std::stoi(dayString);

		std::cout << currentYear << std::endl;
		int userAge = currentMonth > birthMonth || (currentMonth == birthMonth && timeTable.tm_mday >= birthDay) ? currentYear - birthYear : currentYear - birthYear - 1;
		std::cout << userAge << std::endl;

		std::stringstream ss;
		ss << yearString << monthString << dayString;
		std::cout << ss.str() << std::endl;

		system("pause");
		return std::stoi(ss.str());
	}
}