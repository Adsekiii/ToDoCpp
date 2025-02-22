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

	ReadToDo();
	return;
}

void ToDo::AddTask() {
	std::vector<std::string> input;

	input.push_back("");
	input.push_back("");

	std::cout << "Task name: ";
	std::getline(std::cin, input.at(0));

	std::cout << "Current Status: ";
	std::getline(std::cin, input.at(1));

	_loader->WriteToFile(input);

	std::cout << '\n';
	return;
}

void ToDo::EditTask() {
	std::vector<std::string> fileValue = _loader->ReadFromFile();

	int userChoice = 0;

	system("cls");
	ReadToDo();
	std::cout << "Which task would you like to edit? : ";
	std::cin >> userChoice;
	if (userChoice > fileValue.size() / 2 || userChoice < 1) {
		std::cout << "No such task, press any key to try again!";
		_getch();
		EditTask();
	}

	system("cls");
	

	return;
}

void ToDo::ReadToDo() {
	std::vector<std::string> fileValue= _loader->ReadFromFile();

	int taskNum = 1;

	for (int i = 0; i < fileValue.size(); i++) {
		if(i%2 == 0)
			std::cout << taskNum++ << ". " << fileValue.at(i) << '\n';

		else
			std::cout << fileValue.at(i) << '\n';
	}

	return;
}