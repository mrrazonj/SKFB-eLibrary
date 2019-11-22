#include "Registration.h"
#include "Engine.h"

namespace Registration
{
	User* newUser()
	{
		return new User();
	}

	void registerUser(User& user)
	{
		inputName(user);
		inputDateOfBirth(user);
		inputAddress(user);
		inputContactNumber(user);
		inputEmergencyContact(user);
		inputEmergencyNumber(user);

		finalizeID(user);
	}

	void inputName(User& user)
	{
		system("cls");
		Engine::printLine("Enter your last name:");
		Engine::print(">");
		std::string lastNameInput;
		std::getline(std::cin, lastNameInput);

		Engine::printLine("Enter your first name:");
		Engine::print(">");
		std::string firstNameInput;
		std::getline(std::cin, firstNameInput);

		std::cout << "Enter your middle name:" << std::endl;
		Engine::print(">");
		std::string middleNameInput;
		std::getline(std::cin, middleNameInput);

		user.setName(lastNameInput, firstNameInput, middleNameInput);
		std::cout << user.getName() << std::endl;

		system("pause");
	}

	void inputDateOfBirth(User& user)
	{
		system("cls");
		std::cout << "Enter year of birth:" << std::endl;
		Engine::print(">");
		std::string yearString;
		std::getline(std::cin, yearString);

		std::cout << "Enter month of birth:" << std::endl;
		Engine::print(">");
		std::string monthString;
		std::getline(std::cin, monthString);

		std::cout << "Enter day of birth:" << std::endl;
		Engine::print(">");
		std::string dayString;
		std::getline(std::cin, dayString);

		time_t rawTime = time(NULL);
		struct tm timeTable;
		localtime_s(&timeTable, &rawTime);

		int currentYear = timeTable.tm_year + 1900;
		int currentMonth = timeTable.tm_mon + 1;
		int currentDay = timeTable.tm_mday;

		int birthYear = std::stoi(yearString);
		int birthMonth = std::stoi(monthString);
		int birthDay = std::stoi(dayString);

		user.setAge(currentMonth > birthMonth || (currentMonth == birthMonth && currentDay >= birthDay) ? currentYear - birthYear : currentYear - birthYear - 1);
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
		Engine::print(">");
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
		Engine::print('>');
		std::string addressInput;
		std::getline(std::cin, addressInput);

		std::stringstream ss;
		ss << addressInput << ", " << user.getBarangay() << ", Binangonan Rizal";
		user.setAddress(ss.str());
		std::cout << user.getAddress() << std::endl;

		system("pause");
	}

	void inputContactNumber(User& user)
	{
		system("cls");
		std::cout << "Enter your contact number (preferrably mobile):" << std::endl;
		Engine::print(">");
		std::string contactNumberInput;
		std::getline(std::cin, contactNumberInput);

		user.setContactNumber(contactNumberInput);
		std::cout << user.getContactNumber() << std::endl;

		system("pause");
	}

	void inputEmergencyContact(User& user)
	{
		system("cls");
		std::cout << "Enter name of emergency contact (preferrably parent or guardian):" << std::endl;
		Engine::print(">");
		std::string emergencyContactInput;
		std::getline(std::cin, emergencyContactInput);

		user.setEmergencyContact(emergencyContactInput);
		std::cout << user.getEmergencyContact() << std::endl;

		system("pause");
	}

	void inputEmergencyNumber(User& user)
	{
		system("cls");
		std::cout << "Enter contact number of your emergency contact:" << std::endl;
		Engine::print(">");
		std::string emergencyNumberInput;
		std::getline(std::cin, emergencyNumberInput);

		user.setEmergencyNumber(emergencyNumberInput);
		std::cout << user.getEmergencyNumber() << std::endl;

		system("pause");
	}

	void finalizeID(User& user)
	{
		system("cls");
		user.genIdYear();
		user.genIdQuarter();
		user.genIdBarangay();
		user.genIdNumber();
		user.appendId();

		std::cout << user.getUserID() << std::endl;
		system("pause");
	}
}