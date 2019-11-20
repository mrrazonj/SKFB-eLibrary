#include "Registration.h"

int main(int argc, char** argv) 
{
	User* user = new User();
	Registration::inputDateOfBirth(*user);
}