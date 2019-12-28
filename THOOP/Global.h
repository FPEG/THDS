#pragma once
#include <string>
#include <iostream>

template<typename T>
void show_var(std::string name, T var, std::string extra = "")
{
	std::cout << name << "£º\t" << var;
	if (!extra.empty())
	{
		std::cout << "£¬" << extra;
	}
	std::cout << std::endl;
}
