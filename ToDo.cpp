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

	while (true) {
		std::string userChoice = "0";
		
		system("cls");
		std::cout << "======ToDo======\n";
		std::cout << "1.Show list\n";
		std::cout << "2.Add task\n";
		std::cout << "3.Edit task\n";
		std::cout << "4.Edit status\n";
		std::cout << "5.Erase task\n";
		std::cout << "6.Clear tasks\n";
		
		std::getline(std::cin, userChoice);

		int choice;

		try {
			choice = std::stoi(userChoice);
		}
		catch (std::exception e) {
			std::cout << e.what() << '\n';
			choice = 10;
		}

		if (choice > 6 || choice < 1) {
			std::cout << "There is no such option! Press any key to continue.\n";
			_getch();
			Init();
		}

		switch (choice)
		{
		case 1:
			ReadToDo();
			std::cout << "Press any key to continue.\n";
			_getch();
			break;
		case 2:
			AddTask();
			break;
		case 3:
			EditTask();
			break;
		case 4:
			EditStatus();
			break;
		case 5:
			EraseTask();
			break;
		case 6:
			_loader->ClearFile("");
			break;
		}
	}
	return;
}

void ToDo::AddTask() {
	std::vector<std::string> input;

	system("cls");

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

	std::string userChoice = "0";

	system("cls");
	ReadToDo();
	std::cout << "Which task would you like to edit? : ";
	
	std::getline(std::cin, userChoice);

	int choice;

	try {
		choice = std::stoi(userChoice);
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
		choice = fileValue.size()*2;
	}

	if (choice > fileValue.size() / 2 || choice < 1) {
		std::cout << "No such task, press any key to try again!";
		_getch();
		EditTask();
	}

	system("cls");
	
	std::string task = fileValue.at(2 * choice - 1 - 1);
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
	fileValue.at(2 * choice - 1 - 1) = task;
	_loader->ClearFile("");
	_loader->WriteToFile(fileValue);
	system("cls");
	return;
}

void ToDo::EditStatus() {
	std::vector<std::string> fileValue = _loader->ReadFromFile();

	std::string userChoice = "0";
	

	system("cls");
	ReadToDo();
	std::cout << "Status of which task would you like to edit? : ";
	std::getline(std::cin, userChoice);

	int choice;

	try {
		choice = std::stoi(userChoice);
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
		choice = fileValue.size() * 2;
	}

	if (choice > fileValue.size() / 2 || choice < 1) {
		std::cout << "No such task, press any key to try again!";
		_getch();
		EditTask();
	}

	system("cls");

	std::string task = fileValue.at(2 * choice - 1);
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

	fileValue.at(2 * choice - 1 ) = task;
	_loader->ClearFile("");
	_loader->WriteToFile(fileValue);
	system("cls");
	return;
}

void ToDo::ReadToDo() {
	std::vector<std::string> fileValue= _loader->ReadFromFile();

	int taskNum = 1;

	system("cls");

	for (int i = 0; i < fileValue.size(); i++) {
		if(i%2 == 0)
			std::cout << taskNum++ << ". " << fileValue.at(i) << '\n';

		else
			std::cout << fileValue.at(i) << '\n';
	}

	return;
}

void ToDo::EraseTask() {

	std::vector<std::string> fileValue = _loader->ReadFromFile();
	std::string userChoice = "0";

	system("cls");

	ReadToDo();

	std::cout << "Which task would you like to delete: ";
	std::getline(std::cin, userChoice);

	int choice;

	try {
		choice = std::stoi(userChoice);
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
		choice = fileValue.size() * 2;
	}

	if (choice > fileValue.size() / 2 || choice < 1) {
		std::cout << "There is no task under that index! Press any key to try again!";
		_getch();
		EraseTask();
	}

	for (int i = choice * 2 - 1 - 1; i < fileValue.size() - 2; i++) {
		fileValue.at(i) = fileValue.at(i+2);
	}

	fileValue.pop_back();
	fileValue.pop_back();

	_loader->ClearFile("");
	_loader->WriteToFile(fileValue);

	return;
}