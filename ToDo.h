#pragma once
#include "FileLoader.h"
#include <conio.h>
#include <iostream>

class ToDo {
public:
	ToDo(std::string fileName);
	~ToDo();
	void Init();
	void AddTask();
	void EraseTask();
	void EditTask();
private:
	std::unique_ptr<FileLoader> _loader;
};