#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
//#define LIST_INIT_SIZE 100
//#define LISTINCREMENT 10

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
/**
* ���
*/
#define OVERFLOW -2
typedef int Status;

# define EQ(a, b) ((a) == (b))
# define LT(a, b) ((a) < (b))
# define LQ(a, b) ((a) < = (b))

template<typename T>
void show_var(std::string name, T var, std::string extra = "")
{
	std::cout << name << "��\t";
	/*if (var != nullptr)
	{*/
		std::cout << var;
	//}
	if (!extra.empty())
	{
		std::cout << "��" << extra;
	}
	std::cout << std::endl;
}

