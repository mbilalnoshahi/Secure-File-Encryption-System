#include <iostream>
#include <fstream>
#include "SecureFileEncryption.h"

// Main function
int main()
{
    // Console based application to encrypt or decrypt files

    std::string input;
    std::cout << "\tWelcome to SECURE FILE ENCRYPTION SYSTEM" << std::endl << std::endl;
    std::cout << "Here you can secure your data by applying encryption on the files. And Decrypt them to watch the content again." << std::endl;
    std::cout << "Do your selection:" << std::endl;
    std::cout << "1- Encryption" << std::endl;
    std::cout << "2- Decryption" << std::endl;
    std::cout << std::endl << "Input your choice: ";
    std::cin >> input;

    // Validate user input
    while (1)
    {
        if (input == "1" || input == "2")
        {
            break;
        }

        std::cout << std::endl << "Please enter a valid choice..." << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> input;
    }

    // Handle encryption
    if (input == "1")
    {
        std::string filePath;
        std::string fileKey;

        std::cout << std::endl << std::endl << "******************* Encryption Section *******************" << std::endl;
        std::cout << std::endl << "Please type the FILE path: " << std::endl;
        std::cin >> filePath;
        std::cout << "Enter the encryption key: ";
        std::cin >> fileKey;

        try {
            // Read the file content
            std::string content = readFile(filePath);

            {
                // Encrypt the content
                xorEncryptDecrypt(content, fileKey);
                std::string encryptedFilePath = filePath + ".enc";
                // Write the encrypted content to a new file
                writeFile(encryptedFilePath, content);
                std::cout << "File encrypted successfully. Encrypted file: " << encryptedFilePath << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    }
    // Handle decryption
    else if (input == "2")
    {
        std::string filePath;
        std::string fileKey;
        std::cout << std::endl << std::endl << "\t******************* Decryption Section *******************" << std::endl;
        std::cout << std::endl << "Please type the FILE path: " << std::endl;
        std::cin >> filePath;
        std::cout << "Enter the decryption key: ";
        std::cin >> fileKey;

        try {
            // Read the file content
            std::string content = readFile(filePath);

            {
                // Decrypt the content
                xorEncryptDecrypt(content, fileKey);
                std::string decryptedFilePath = filePath + ".dec";
                // Write the decrypted content to a new file
                writeFile(decryptedFilePath, content);
                std::cout << "File decrypted successfully. Decrypted file: " << decryptedFilePath << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}

// XOR encryption/decryption function
void xorEncryptDecrypt(std::string& data, const std::string& key)
{
    size_t keyLength = key.length();
    for (size_t i = 0; i < data.size(); i++) {
        data[i] ^= key[i % keyLength];
    }
}

// Function to read the content of a file
std::string readFile(const std::string& filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file for reading.");
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

// Function to write content to a file
void writeFile(const std::string& filePath, const std::string& data)
{
    std::ofstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file for writing.");
    }
    file.write(data.c_str(), data.size());
    file.close();
}