#pragma once
#include "CoreIncludes.h"

namespace Engine
{
	static std::unordered_map<std::string, std::string> barangayToIdMap =
	{
		{"Pag-asa", "01"},
		{"Tayuman", "02"},
		{"San Carlos", "03"},
		{"Tagpos", "04"}
	};

	static std::unordered_map<int, std::string> idToBarangayMap =
	{
		{1, "Pag-asa"},
		{2, "Tayuman"},
		{3, "San Carlos"},
		{4, "Tagpos"}
	};

	template<typename T>
	void printLine(T& string);

	template<typename T>
	void print(const T& string);

	template<typename T>
	void printError(T& string);
}

#include "Engine.tpp"
