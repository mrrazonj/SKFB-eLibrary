#include "User.h"

int User::userCount = 0;

User::User()
{

}

User::User(const std::string& firstName, const std::string& lastName, const std::string& middleName,
		   const std::string& dateOfBirth, int age,
		   const std::string& address, const std::string& barangay,
		   const std::string& contactNumber, const std::string& emergencyContact, const std::string& emergencyContactNumber)
			   :firstName(firstName), lastName(lastName), middleName(middleName),
			    dateOfBirth(dateOfBirth), age(age),
			    address(address), barangay(barangay),
			    contactNumber(contactNumber), emergencyContact(emergencyContact), emergencyContactNumber(emergencyContactNumber)
{
	genIdYear();
	genIdQuarter();
	genIdBarangay();
	genIdNumber();
	++userCount;
}

User::~User()
{

}


void User::genIdYear()
{
	time_t rawTime = time(NULL);
	struct tm timeTable;
	localtime_s(&timeTable, &rawTime);

	this->idYear = timeTable.tm_year;
}

void User::genIdQuarter()
{
	time_t rawTime = time(NULL);
	struct tm timeTable;
	localtime_s(&timeTable, &rawTime);


	this->idQuarter = (int)(timeTable.tm_mon / 4) + 1;
}

void User::genIdBarangay()
{
	this->idBarangay = Engine::barangayToIdMap[this->barangay];
}

void User::genIdNumber()
{
	static bool isArrayInitialized = false;
	static std::vector<int> idNumber;
	if (!isArrayInitialized) 
	{
		for (unsigned int i = 0; i < Engine::barangayToIdMap.size(); i++)
		{
			idNumber[i] = 0;
		}
		isArrayInitialized = true;
	}

	int i = std::stoi(this->idBarangay);
	this->idNumber = idNumber[i]++;
}

std::string User::getName() const
{
	std::stringstream ss;
	ss << this->lastName << ", " << this->firstName << " " << this->middleName;
	return ss.str();
}

int User::getAge() const
{
	return this->age;
}

std::string User::getDateOfBirth() const
{
	return this->dateOfBirth;
}

std::string User::getBarangay() const
{
	return this->barangay;
}

std::string User::getAddress() const
{
	return this->address;
}

std::string User::getContactNumber() const
{
	return this->contactNumber;
}

std::ostream& operator<< (std::ostream& stream, User& user)
{
	stream << "Name: " << user.getName() << std::endl;
	return stream;
}

void User::setName(const std::string& lastName,
				   const std::string& firstName,
	               const std::string& middleName)
{
	this->firstName = firstName;
	this->middleName = middleName;
	this->lastName = lastName;
}

void User::setAge(int age)
{
	this->age = age;
}

void User::setdateOfBirth(const std::string& dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

void User::setBarangay(int barangayId)
{
	this->barangay = Engine::idToBarangayMap[barangayId];
}

void User::setAddress(const std::string& address)
{
	this->address = address;
}

void User::setContactNumber(const std::string& contactNumber)
{
	this->contactNumber = contactNumber;
}