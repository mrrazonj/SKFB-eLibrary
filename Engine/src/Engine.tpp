namespace Engine
{
	template<typename T>
	void printLn(const T& string)
	{
		std::cout << string << std::endl;
	}

	template<typename T>
	void print(const T& string)
	{
		std::cout << string << std::flush;
	}

	template<typename T>
	void printErr(const T& string)
	{
		std::cerr << string << std::endl;
		throw std::runtime_error(string);
	}

	template<typename T>
	void handleException(const T& e)
	{
		print("Exception occured: ");
		printLn(e.what());
		printLn("Please contact system administrator, closing application...");
	}
}