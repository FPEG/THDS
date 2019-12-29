#pragma once
#include "../GlobalDef.h"
namespace Th
{
	class GrandFather
	{

	public:
		int n;
		GrandFather(int n):n(n)
		{
			std::cout << "үү����" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "үүvfun" << std::endl;

		}
		virtual ~GrandFather()
		{
			std::cout << "үү����" << std::endl;
		}
		
	};

	class Father1:public GrandFather
	{
	public:
		Father1(int n):GrandFather(n)
		{
			std::cout << "�ְ�1����" << std::endl;

		}
		void fun()
		{
			std::cout << "�ְ�1fun" << std::endl;

		}
		virtual void vfun() 
		{
			std::cout << "�ְ�1vfun" << std::endl;

		}
		~Father1()
		{
			std::cout << "�ְ�1����" << std::endl;
		}
	};

	class Father2: public GrandFather
	{
	public:
		Father2(int n):GrandFather(n)
		{
			std::cout << "�ְ�2����" << std::endl;

		}
		void fun()
		{
			std::cout << "�ְ�2fun" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "�ְ�2vfun" << std::endl;

		}
		~Father2()
		{
			std::cout << "�ְ�2����" << std::endl;
		}
	};
	class Father1v : virtual public GrandFather
	{
	public:
		Father1v(int n) :GrandFather(n)
		{
			std::cout << "v�ְ�1����" << std::endl;

		}
		void fun()
		{
			std::cout << "v�ְ�1fun" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "v�ְ�1vfun" << std::endl;

		}
		~Father1v()
		{
			std::cout << "v�ְ�1����" << std::endl;
		}
	};
	class Father2v : virtual public GrandFather
	{
	public:
		Father2v(int n):GrandFather(n)
		{
			std::cout << "v�ְ�2����" << std::endl;

		}
		void fun()
		{
			std::cout << "v�ְ�2fun" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "v�ְ�2vfun" << std::endl;

		}
		~Father2v()
		{
			std::cout << "v�ְ�2����" << std::endl;
		}
	};
	class Sun1:
	/*public Father1,public Father2,*/public Father2v
	{
	public:
		Sun1(int n):/*Father1(n),Father2(n),*/GrandFather(n),Father2v(n)
		{
			std::cout << "����1����" << std::endl;
		}

		virtual void vfun()
		{
			std::cout << "����vfun" << std::endl;

		}
		void ffun()
		{
			vfun();
		}
		~Sun1()
		{
			std::cout << "����1����" << std::endl;

		}
	};
	
}
