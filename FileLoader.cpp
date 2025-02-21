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

void FileLoader::ReadFromFile() {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::in);

	std::string line;

	_file->clear();
	_file->seekg(0, std::ios::beg);

	if (_file->is_open()) {
		while (std::getline(*_file, line)){
			std::cout << line << '\n';
		}
	}
	else {
		std::cout << "File can't be open\n";
	}
	_file->close();
	_file = nullptr;
	return;
}

void FileLoader::OverwriteFile(std::string text) {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::out);

	*_file << text;

	_file->close();
	_file = nullptr;
	return;
}

void FileLoader::ReadLine(int taskNumber) {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::in);

	std::string line;

	_file->clear();
	_file->seekg(0,std::ios::beg);

	int lineNum = 1;

	taskNumber = taskNumber * 2 - 1;

	if (_file->is_open()) {
		while (std::getline(*_file, line)) {
			if (lineNum == taskNumber || lineNum == taskNumber + 1) {
				std::cout << line << '\n';
			}
			lineNum += 1;
		}
	}
	else {
		std::cout << "File can't be open\n";
	}

	_file->close();
	_file = nullptr;
	return;
}

void FileLoader::WriteLine(std::string text) {
	_file = std::make_unique<std::fstream>(_fileName, std::ios::app);

	_file->clear();
	_file->seekg(0,std::ios::end);

	*_file << text << '\n';
}