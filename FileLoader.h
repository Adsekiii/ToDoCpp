#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileLoader {
public:
	FileLoader(std::string fileName);		
	~FileLoader();							
	std::vector<std::string> ReadFromFile();
	void WriteToFile(std::vector<std::string>);
	void ClearFile(std::string);
private:									
	std::unique_ptr<std::fstream> _file;	
	std::string _fileName;					
};