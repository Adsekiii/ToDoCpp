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

	EditTask();
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
	
	std::string task = fileValue.at(2 * userChoice-1-1);
	char currentChar = '\0';


	while (currentChar != '\r') {
		system("cls");
		std::cout << task;
		currentChar = _getch();

		if (currentChar == '\b') {
			if (task.length() > 1) {
				task.pop_back();
			}
			else {
				task.at(0) = ' ';
			}
			continue;
		}

		if (task.at(0) == ' ') {
			task.at(0) = currentChar;
			continue;
		}

		task += currentChar;
		
	}
	//popping the new line character
	task.pop_back();

	//							 -1  -1 => one for the equation to work and the other for the vector to start from 0
	fileValue.at(2 * userChoice - 1 - 1) = task;
	_loader->ClearFile("");
	_loader->WriteToFile(fileValue);
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