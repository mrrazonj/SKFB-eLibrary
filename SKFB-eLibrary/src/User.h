#pragma once
#include "ServerCore.h"

class User
{
private:
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
	User(std::string& firstName, std::string& lastName, std::string& middleName,
		 std::string& dateOfBirth, int age,
		 std::string& address, std::string& barangay,
		 std::string& contactNumber, std::string& emergencyContact, std::string& emergencyContactNumber);
	~User();

	void genIdYear();
	void genIdQuarter();
	void genIdBarangay();
	void genIdNumber();
};

