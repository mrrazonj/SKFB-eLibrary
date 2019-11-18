#include "User.h"

User::User(std::string& firstName, std::string& lastName, std::string& middleName,
		   std::string& dateOfBirth, int age,
		   std::string& address, std::string& barangay,
		   std::string& contactNumber, std::string& emergencyContact, std::string& emergencyContactNumber)
			   :firstName(firstName), lastName(lastName), middleName(middleName),
			    dateOfBirth(dateOfBirth), age(age),
			    address(address), barangay(barangay),
			    contactNumber(contactNumber), emergencyContact(emergencyContact), emergencyContactNumber(emergencyContactNumber)
{
	genIdYear();
	genIdQuarter();
	genIdBarangay();
	genIdNumber();
}

void User::genIdYear()
{
	time_t rawTime = time(NULL);
	struct tm timeTable = *localtime(&rawTime);

	this->idYear = timeTable.tm_year;
}

void User::genIdQuarter()
{
	time_t rawTime = time(NULL);
	struct tm timeTable = *localtime(&rawTime);

	this->idQuarter = (int)(timeTable.tm_mon / 4) + 1;
}


static std::unordered_map<std::string, std::string> barangayIdMap =
{
	{"Pag-asa", "01"},
	{"Tayuman", "02"},
	{"San Carlos", "03"},
	{"Tagpos", "04"}
};

void User::genIdBarangay()
{
	this->idBarangay = barangayIdMap[this->barangay];
}

void User::genIdNumber()
{
	static bool isArrayInitialized = false;
	static std::vector<int> idNumber;
	if (!isArrayInitialized) 
	{
		for (int i = 0; i < barangayIdMap.size(); i++)
		{
			idNumber[i] = 0;
		}
		isArrayInitialized = true;
	}

	int i = std::stoi(this->idBarangay);
	this->idNumber = idNumber[i]++;
}