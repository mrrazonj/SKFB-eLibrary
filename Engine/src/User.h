#pragma once
#include "CoreIncludes.h"

class User
{
private:
	static int userCount;

	std::string firstName;
	std::string lastName;
	std::string middleName;

	std::string dateOfBirth;
	int age;

	std::string address;
	std::string barangay;

	std::string contactNumber;
	std::string emergencyContact;
	std::string emergencyContactNumber;

	std::string idYear;
	std::string idQuarter;
	std::string idBarangay;
	std::string idNumber;

public:
	User();
	User(const std::string& firstName, const std::string& lastName, const std::string& middleName,
		 const std::string& dateOfBirth, int age,
		 const std::string& address, const std::string& barangay,
		 const std::string& contactNumber, const std::string& emergencyContact, const std::string& emergencyContactNumber);
	~User();

	void genIdYear();
	void genIdQuarter();
	void genIdBarangay();
	void genIdNumber();

	std::string getName() const;
	int getAge() const;
	std::string getDateOfBirth() const;
	std::string getBarangay() const;
	std::string getAddress() const;
	std::string getContactNumber() const;

	void setName(const std::string& lastName,
				 const std::string& firstName,
				 const std::string& middleName);
	void setAge(int age);
	void setdateOfBirth(const std::string& dateOfBirth);
	void setBarangay(int barangayId);
	void setAddress(const std::string& address);
	void setContactNumber(const std::string& contactNumber);
};