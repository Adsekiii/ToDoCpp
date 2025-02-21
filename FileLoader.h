#pragma once
#include <fstream>

class FileLoader {
public:
	FileLoader(std::string fileName);	//
	~FileLoader();						//
	void ReadFromFile();				//
	void WriteToFile();					//
private:								//
	std::unique_ptr<std::fstream> _file;//
};