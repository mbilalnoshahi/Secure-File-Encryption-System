#include <iostream>

int main()
{
	// Console based: I am going to encrypt or decrypt files

	int input;
	std::cout << "\tWelcome to SECURE FILE ENCRYPTION SYSTEM" << std::endl << std::endl;
	std::cout << "Here you can secure your data by applying encryption on the files. And Decrypt them to watch the content again." << std::endl;
	std::cout << "Do your selection:" << std::endl;
	std::cout << "1- Encryption" << std::endl;
	std::cout << "2- Decryption" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	std::cin >> input;
	return 0;
}