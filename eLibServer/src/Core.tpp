namespace Core
{
	template<typename T>
	static void printLn(const T& string)
	{
		std::cout << string << std::endl;
	}

	template<typename T>
	static void print(const T& string)
	{
		std::cout << string << std::flush;
	}

	template<typename T>
	static void printErr(const T& string)
	{
		try
		{
			std::cerr << string << std::endl;
			throw std::runtime_error(string);
		}
		catch (std::runtime_error & e)
		{
			handleException(e);
		}
	}

	template<typename T>
	static void handleException(const T& exception)
	{
		print("Exception occured: ");
		printLn(exception.what());
		printLn("Please contact your sysadmin, program exiting...");
	}
}