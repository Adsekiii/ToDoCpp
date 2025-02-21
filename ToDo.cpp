#pragma once
#include "ToDo.h"

ToDo::ToDo(std::string fileName) {
	_loader = std::make_unique<FileLoader>(fileName);
}

ToDo::~ToDo() {
	if (_loader != nullptr) {
		_loader.reset();
		_loader = nullptr;
	}
}

void ToDo::Init() {
	_loader->OverwriteFile("");

	AddTask();
	AddTask();
	AddTask();
	AddTask();
	AddTask();

	_loader->ReadLine(2);
}

void ToDo::AddTask() {
	std::string input;

	std::cout << "Task name: ";
	std::getline(std::cin, input);
	_loader->WriteLine(input);

	std::cout << "Current Status: ";
	std::getline(std::cin, input);
	_loader->WriteLine(input);

	std::cout << '\n';
	return;
}