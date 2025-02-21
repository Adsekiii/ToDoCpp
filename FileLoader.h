#pragma once
#include <fstream>
#include <iostream>
#include <string>

class FileLoader {
public:
	FileLoader(std::string fileName);		//
	~FileLoader();							//
	void ReadFromFile();					//
	void OverwriteFile(std::string);		//
	void ReadLine(int);						//
	void WriteLine(std::string);			//
private:									//
	std::unique_ptr<std::fstream> _file;	//
	std::string _fileName;					//
};