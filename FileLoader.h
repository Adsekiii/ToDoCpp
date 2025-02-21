#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileLoader {
public:
	FileLoader(std::string fileName);		//
	~FileLoader();							//
	void ReadFromFile();					//
	void OverwriteFile(std::string);		//
	void ReadLine(int);						//
	void WriteLine(std::string);			//
	std::vector<std::string> GetLine(int);	//
private:									//
	std::unique_ptr<std::fstream> _file;	//
	std::string _fileName;					//
};