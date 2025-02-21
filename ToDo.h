#pragma once
#include "FileLoader.h"
#include <conio.h>

class ToDo {
public:
	ToDo(std::string fileName);
	~ToDo();
	void Init();
	void AddTask();
	void EraseTask();
	void EditTask();
private:
	FileLoader* _loader;
};