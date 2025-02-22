#include "FileLoader.h"

FileLoader::FileLoader(std::string fileName) {
	_fileName = fileName;
	_file = nullptr;
}

FileLoader::~FileLoader() {
	if (_file != nullptr) {
		_file.reset();
		_file = nullptr;
	}
}

std::vector<std::string> FileLoader::ReadFromFile() {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::in);

	std::vector<std::string> outputValue;

	std::string line;

	_file->clear();
	_file->seekg(0, std::ios::beg);

	if (_file->is_open()) {
		while (std::getline(*_file, line)){
			outputValue.push_back(line);
		}
	}
	else {
		std::cout << "File can't be open\n";
	}
	_file->close();
	_file = nullptr;
	return outputValue;
}

void FileLoader::WriteToFile(std::vector<std::string> message) {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::app);

	_file->clear();
	_file->seekg(0, std::ios::beg);

	for(std::string text : message)
		*_file << text << '\n';

	_file->close();
	_file = nullptr;
	return;
}

void FileLoader::ClearFile(std::string text) {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::out);

	*_file << text;

	_file->close();
	_file = nullptr;
	return;
}

