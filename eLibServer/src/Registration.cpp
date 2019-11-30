#include "Registration.h"

#define PadLeft() ImGui::Dummy(ImVec2(0.5f, 0.0f))
#define SpaceOut() ImGui::Dummy(ImVec2(0.0f, 6.0f))
#define TextFieldSize(x) x + 1

User::User(char* lastName, char* firstName, char* middleName, char* suffixName, char* dateOfBirth, char* age, char* occupation,
	       char* address, char* barangay, char* contactNumber, char* emailAddress, char* emergencyContact, char* emergencyNumber,
	       bool& isRegisteredVoter)
	:lastName(lastName), firstName(firstName), middleName(middleName), suffixName(suffixName), dateOfBirth(dateOfBirth), age(age), occupation(occupation),
	 address(address), barangay(barangay), contactNumber(contactNumber), emailAddress(emailAddress), emergencyContact(emergencyContact), emergencyNumber(emergencyNumber),
	 isRegisteredVoter(isRegisteredVoter), id(0)
{
}
User::~User()
{

}


static int FilterOnlyNumber(ImGuiInputTextCallbackData* data)
{
	ImWchar c = data->EventChar;
	if (!((c >= '0' && c <= '9') || c == '-'))
		return 1;
	else
		return 0;
}

static int FilterCommas(ImGuiInputTextCallbackData* data)
{
	ImWchar c = data->EventChar;
	if (c == ',' || c == '\'')
		return 1;
	else
		return 0;
}

namespace Registration
{
	void OpenRegistrationForm(bool& isOpen)
	{
		{
			ImGui::Begin("SKFB e-Library Registration Form", &isOpen);
			ImGui::Text("SKFB e-Library Registration Form");

			ImGui::Dummy(ImVec2(0.0f, 8.0f));

			ImGui::PushItemWidth(120.0f);
			PadLeft();
			ImGui::SameLine(); ImGui::Text("Surname:");
			static char bufSurname[TextFieldSize(30)] = "";
			ImGui::SameLine(); ImGui::InputText("##surname", bufSurname, IM_ARRAYSIZE(bufSurname), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			ImGui::SameLine(); ImGui::Text("First name:");
			static char bufFirstName[TextFieldSize(30)] = "";
			ImGui::SameLine(); ImGui::InputText("##firstname", bufFirstName, IM_ARRAYSIZE(bufFirstName), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			ImGui::SameLine(); ImGui::Text("Middle name:");
			static char bufMiddleName[TextFieldSize(30)] = "";
			ImGui::SameLine(); ImGui::InputText("##middlename", bufMiddleName, IM_ARRAYSIZE(bufMiddleName), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			ImGui::SameLine(); ImGui::Text("Registered Voter?");
			static bool isRegisteredVoter = false;
			ImGui::SameLine(); ImGui::Checkbox("##isregisteredvoter", &isRegisteredVoter);
			SpaceOut();
			PadLeft();
			ImGui::SameLine(); ImGui::Text("Suffix:");
			static const char* suffix[] =
			{
				"Sr.",
				"Jr.",
				"III",
				"IV",
				"V",
				"N/A"
			};
			static int selectedSuffix = -1;
			ImGui::SameLine(); ImGui::Combo("##suffix", &selectedSuffix, suffix, IM_ARRAYSIZE(suffix));
			SpaceOut();
			PadLeft();
			ImGui::SameLine(); ImGui::Text("Date of Birth: (YYYY-MM-DD)");
			static char bufDateOfBirth[TextFieldSize(10)];
			ImGui::SameLine(); ImGui::InputText("##dateofbirth", bufDateOfBirth, IM_ARRAYSIZE(bufDateOfBirth), ImGuiInputTextFlags_CallbackCharFilter, FilterOnlyNumber);
			ImGui::SameLine(); ImGui::Text("Age:");
			static char bufAge[TextFieldSize(2)];
			ImGui::SameLine(); ImGui::InputText("##age", bufAge, IM_ARRAYSIZE(bufAge), ImGuiInputTextFlags_CallbackCharFilter, FilterOnlyNumber);

			SpaceOut();
			ImGui::Separator();
			SpaceOut();

			PadLeft();
			ImGui::PushItemWidth(160.0f);
			ImGui::SameLine(); ImGui::Text("Occupation:");
			static char bufOccupation[TextFieldSize(30)] = "";
			ImGui::SameLine(); ImGui::InputText("##occupation", bufOccupation, IM_ARRAYSIZE(bufOccupation), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			SpaceOut();
			PadLeft();
			ImGui::SameLine(); ImGui::Text("Email Address:");
			static char bufEmailAddress[TextFieldSize(60)];
			ImGui::SameLine(); ImGui::InputText("##emailaddress", bufEmailAddress, IM_ARRAYSIZE(bufEmailAddress), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			ImGui::SameLine(); ImGui::Text("Contact Number: (09XXXXXXXXX)");
			static char bufContactNumber[TextFieldSize(11)];
			ImGui::SameLine(); ImGui::InputText("##contactNumber", bufContactNumber, IM_ARRAYSIZE(bufContactNumber), ImGuiInputTextFlags_CallbackCharFilter, FilterOnlyNumber);

			SpaceOut();
			ImGui::Separator();
			SpaceOut();

			PadLeft();
			ImGui::SameLine(); ImGui::Text("Address: (Blk No. - House No. - Street - Subdivision (USE DASHES))");
			static char bufAddress[TextFieldSize(160)] = "";
			PadLeft();
			ImGui::SameLine(); ImGui::InputTextMultiline("##address", bufAddress, IM_ARRAYSIZE(bufAddress), ImVec2(520.0f, 60.0f), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			SpaceOut();
			PadLeft();
			ImGui::SameLine(); ImGui::Text("Barangay");
			static const char* barangays[] =
			{
				"Pagasa",
				"Tayuman",
				"San Carlos",
				"Tagpos"
			};
			static int selectedBarangay = -1;
			ImGui::PushItemWidth(100.0f);
			ImGui::SameLine(); ImGui::Combo("##barangaydropdown", &selectedBarangay, barangays, IM_ARRAYSIZE(barangays));

			SpaceOut();
			ImGui::Separator();
			SpaceOut();

			PadLeft();
			ImGui::PushItemWidth(160.0f);
			ImGui::SameLine(); ImGui::Text("Emergency Contact: (Parent or Guardian)");
			static char bufEmergencyContact[TextFieldSize(160)];
			ImGui::SameLine(); ImGui::InputText("##emergencycontact", bufEmergencyContact, IM_ARRAYSIZE(bufEmergencyContact), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			SpaceOut();
			PadLeft();
			ImGui::SameLine(); ImGui::Text("Contact Number: (09XXXXXXXXX)");
			static char bufEmergencyNumber[TextFieldSize(11)];
			ImGui::SameLine(); ImGui::InputText("##emergencynumber", bufEmergencyNumber, IM_ARRAYSIZE(bufEmergencyNumber), ImGuiInputTextFlags_CallbackCharFilter, FilterCommas);
			SpaceOut();
			ImGui::Dummy(ImVec2(700.0f, 0.0f));
			ImGui::SameLine(); 
			if (ImGui::Button("Register"))
			{
				/*char* uLastName = static_cast<char*> (bufSurname);
				char* uFirstName = static_cast<char*> (bufFirstName);
				char* uMiddleName = static_cast<char*> (bufMiddleName);
				char* uDateOfBirth = static_cast<char*> (bufSurname);
				char* uAge = static_cast<char*> (bufSurname);
				char* uOccupation = static_cast<char*> (bufSurname);
				char* uAddress = static_cast<char*> (bufSurname);
				char* uContactNumber = static_cast<char*> (bufSurname);
				char* uEmailAddress = static_cast<char*> (bufEmailAddress);
				char* uEmergencyContact = static_cast<char*> (bufEmergencyContact);
				char* uEmergencyNumber = static_cast<char*> (bufEmergencyNumber);*/
				char* uSuffix = const_cast<char*> (suffix[selectedSuffix]);
				char* uBarangay = const_cast<char*> (suffix[selectedBarangay]);

				User user(bufSurname, bufFirstName, bufMiddleName, uSuffix, bufDateOfBirth, bufAge, bufOccupation, 
					      bufAddress, uBarangay, bufContactNumber, bufEmailAddress, bufEmergencyContact, bufEmergencyNumber, isRegisteredVoter);
				RegisterUser(user);
			}
			ImGui::End();
		}
	}

	void RegisterUser(User& user)
	{
		sqlite3* db;
		int exit = 0;
		exit = sqlite3_open("user.db", &db);
		if (exit) {
			Core::printErr("Failed to open user.db!");
			return;
		}
		Core::printLn("Successfully opened user.db");

	}
}

