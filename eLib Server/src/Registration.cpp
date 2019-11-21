#include "Registration.h"

namespace Registration
{
	User* newUser()
	{
		User* user = new User();
		return user;
	}

	void inputDateOfBirth(User& user)
	{
		system("cls");
		std::cout << "Enter year of birth:" << std::endl;
		std::cout << ">" << std::flush;
		std::string yearString;
		std::getline(std::cin, yearString);
		std::cout << "Enter month of birth:" << std::endl;
		std::cout << ">" << std::flush;
		std::string monthString;
		std::getline(std::cin, monthString);
		std::cout << "Enter day of birth:" << std::endl;
		std::cout << ">" << std::flush;
		std::string dayString;
		std::getline(std::cin, dayString);

		time_t rawTime = time(NULL);
		struct tm timeTable;
		localtime_s(&timeTable, &rawTime);

		int currentYear = timeTable.tm_year + 1900;
		int currentMonth = timeTable.tm_mon + 1;

		int birthYear = std::stoi(yearString);
		int birthMonth = std::stoi(monthString);
		int birthDay = std::stoi(dayString);

		user.setAge(currentMonth > birthMonth || (currentMonth == birthMonth && timeTable.tm_mday >= birthDay) ? currentYear - birthYear : currentYear - birthYear - 1);
		std::cout << user.getAge() << std::endl;

		std::stringstream ss;
		ss << yearString << '/' << monthString << '/' << dayString;
		user.setdateOfBirth(ss.str());
		std::cout << user.getDateOfBirth() << std::endl;

		system("pause");
	}

	void inputBarangay(User& user)
	{
		system("cls");
		std::cout << "Enter your current residence's barangay (type only the number):" << std::endl;
		for (const auto& i : Engine::idToBarangayMap)
		{
			std::cout << i.first << ' ' << i.second << std::endl;
		}
		std::cout << ">" << std::flush;
		std::string idInput;
		std::getline(std::cin, idInput);

		int barangayId = std::stoi(idInput);
		user.setBarangay(barangayId);
		std::cout << user.getBarangay() << std::endl;

		system("pause");
	}

	void inputAddress(User& user)
	{
		inputBarangay(user);
		system("cls");

		std::cout << "Enter your current address (Blk #, House #, Street Name, Subdivision)" << std::endl;
		std::cout << ">" << std::flush;
		std::string addressInput;
		std::getline(std::cin, addressInput);

		std::stringstream ss;
		ss << addressInput << ", " << user.getBarangay() << ", Binangonan Rizal";
		user.setAddress(ss.str());
		std::cout << user.getAddress() << std::endl;

		system("pause");
	}
}