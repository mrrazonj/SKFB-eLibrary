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

	std::stringstream ss;
	ss << (timeTable.tm_year + 1900);
	this->idYear = ss.str();
}

void User::genIdQuarter()
{
	time_t rawTime = time(NULL);
	struct tm timeTable;
	localtime_s(&timeTable, &rawTime);

	std::stringstream ss;
	ss << (int)((timeTable.tm_mon / 3) + 1);

	this->idQuarter = ss.str();
}

void User::genIdBarangay()
{
	this->idBarangay = Engine::barangayToIdMap[this->barangay];
}

void User::genIdNumber()
{
	static bool isArrayInitialized = false;
	static constexpr int numberBarangays = 40;
	static int idNumber[numberBarangays];
	if (!isArrayInitialized) 
	{
		for (unsigned int i = 0; i < 40; i++)
		{
			idNumber[i] = 0;
		}
		isArrayInitialized = true;
	}

	int i = (std::stoi(this->idBarangay)) - 1;
	std::stringstream ss;
	ss << ++idNumber[i];
	this->idNumber = ss.str();
}

void User::appendId()
{
	std::stringstream ss;
	ss << this->idYear << std::setw(2) << std::setfill('0') << this->idQuarter;
	ss << std::setw(1) << '-' << std::setw(2) << std::setfill('0') << this->idBarangay << std::setw(5) << this->idNumber;
	
	this->userId = ss.str();
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

std::string User::getEmergencyContact() const
{
	return this->emergencyContact;
}

std::string User::getEmergencyNumber() const
{
	return this->emergencyContactNumber;
}

std::string User::getUserID() const
{
	return this->userId;
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

void User::setEmergencyContact(const std::string& emergencyContact)
{
	this->emergencyContact = emergencyContact;
}

void User::setEmergencyNumber(const std::string& emergencyNumber)
{
	this->emergencyContactNumber = emergencyNumber;
}

void User::displayData()
{
	std::cout << "Name: " << this->getName() << " UID: " << this->getUserID() << std::endl;
	std::cout << "Age: " << this->getAge() << " Date of birth: " << this->getDateOfBirth() << std::endl;
	std::cout << "Address: " << this->getAddress() << std::endl;
	std::cout << "Contact number: " << this->getContactNumber() << std::endl;
	std::cout << "Emergency contact: " << this->getEmergencyContact() << " Emergency contact number: " << this->getEmergencyNumber() << std::endl;

	system("pause");
}