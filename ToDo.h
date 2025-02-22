#pragma once
#include "FileLoader.h"
#include <conio.h>
#include <vector>
#include <string>
#include <iostream>

class ToDo {
public:
	ToDo(std::string fileName);
	~ToDo();
	void Init();
	void AddTask();
	void EraseTask();
	void EditTask();
	void ReadToDo();
	void EditStatus();
private:
	std::unique_ptr<FileLoader> _loader;
};