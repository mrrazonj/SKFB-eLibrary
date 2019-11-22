namespace Engine
{
	template<typename T>
	void printLine(T& string)
	{
		std::cout << string << std::endl;
	}

	template<typename T>
	void print(const T& string)
	{
		std::cout << string << std::flush;
	}

	template<typename T>
	void printError(T& string)
	{
		std::cerr << string << std::endl;
		throw string;
	}
}