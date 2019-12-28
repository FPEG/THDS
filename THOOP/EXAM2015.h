#pragma once
#include <iostream>
namespace Th
{
	class A {
	public:
		virtual void display() {
			std::cout << "Base" << std::endl;
		}
	};
	class B :public A {
	public:
		virtual void display() {
			std::cout << "Derived" << std::endl;
		}
	};
	int main() {
		A a;
		
		a.display();
		B b;
		a = b;
		A& ar = b;
		a.display();
		A* pa = new B();
		pa->display();
	}

}