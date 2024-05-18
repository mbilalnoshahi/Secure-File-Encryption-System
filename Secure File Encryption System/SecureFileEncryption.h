#pragma once

void xorEncryptDecrypt(std::string& data, const std::string& key);
std::string readFile(const std::string& filePath);
void writeFile(const std::string& filePath, const std::string& data);

