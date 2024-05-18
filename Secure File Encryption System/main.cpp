#include <iostream>

int main()
{
	// Console based: I am going to encrypt or decrypt files

	std::string input;
	std::cout << "\tWelcome to SECURE FILE ENCRYPTION SYSTEM" << std::endl << std::endl;
	std::cout << "Here you can secure your data by applying encryption on the files. And Decrypt them to watch the content again." << std::endl;
	std::cout << "Do your selection:" << std::endl;
	std::cout << "1- Encryption" << std::endl;
	std::cout << "2- Decryption" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	std::cin >> input;

	
	while(1)
	{
		if (input == "1" || input == "2")
		{
			break;
		}

		std::cout << std::endl << "Please enter a valid choice..." << std::endl;
		std::cout << "Input your choice: ";
		std::cin >> input;
	}

	if (input == "1")
	{
		std::string filePath;
		std::string fileKey;

		std::cout << std::endl << std::endl << "******************* Encryption Section *******************" << std::endl;
		std::cout << std::endl << "Please type the FILE path: " << std::endl;
		std::cin >> filePath;
		std::cout << "Enter the encryption key: ";
		std::cin >> fileKey;
	}
	else if (input == "2")
	{
		std::string filePath;
		std::string fileKey;
		std::cout << std::endl << std::endl << "t\******************* Decryption Section *******************" << std::endl;
		std::cout << std::endl << "Please type the FILE path: " << std::endl;
		std::cin >> filePath;
		std::cout << "Enter the decryption key: ";
		std::cin >> fileKey;
	}

	return 0;
}