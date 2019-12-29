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
			std::cout << "Ò¯Ò¯¹¹Ôì" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "Ò¯Ò¯vfun" << std::endl;

		}
		virtual ~GrandFather()
		{
			std::cout << "Ò¯Ò¯Îö¹¹" << std::endl;
		}
		
	};

	class Father1:public GrandFather
	{
	public:
		Father1(int n):GrandFather(n)
		{
			std::cout << "°Ö°Ö1¹¹Ôì" << std::endl;

		}
		void fun()
		{
			std::cout << "°Ö°Ö1fun" << std::endl;

		}
		virtual void vfun() 
		{
			std::cout << "°Ö°Ö1vfun" << std::endl;

		}
		~Father1()
		{
			std::cout << "°Ö°Ö1Îö¹¹" << std::endl;
		}
	};

	class Father2: public GrandFather
	{
	public:
		Father2(int n):GrandFather(n)
		{
			std::cout << "°Ö°Ö2¹¹Ôì" << std::endl;

		}
		void fun()
		{
			std::cout << "°Ö°Ö2fun" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "°Ö°Ö2vfun" << std::endl;

		}
		~Father2()
		{
			std::cout << "°Ö°Ö2Îö¹¹" << std::endl;
		}
	};
	class Father1v : virtual public GrandFather
	{
	public:
		Father1v(int n) :GrandFather(n)
		{
			std::cout << "v°Ö°Ö1¹¹Ôì" << std::endl;

		}
		void fun()
		{
			std::cout << "v°Ö°Ö1fun" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "v°Ö°Ö1vfun" << std::endl;

		}
		~Father1v()
		{
			std::cout << "v°Ö°Ö1Îö¹¹" << std::endl;
		}
	};
	class Father2v : virtual public GrandFather
	{
	public:
		Father2v(int n):GrandFather(n)
		{
			std::cout << "v°Ö°Ö2¹¹Ôì" << std::endl;

		}
		void fun()
		{
			std::cout << "v°Ö°Ö2fun" << std::endl;

		}
		virtual void vfun()
		{
			std::cout << "v°Ö°Ö2vfun" << std::endl;

		}
		~Father2v()
		{
			std::cout << "v°Ö°Ö2Îö¹¹" << std::endl;
		}
	};
	class Sun1:
	/*public Father1,public Father2,*/public Father2v
	{
	public:
		Sun1(int n):/*Father1(n),Father2(n),*/GrandFather(n),Father2v(n)
		{
			std::cout << "¶ù×Ó1¹¹Ôì" << std::endl;
		}

		virtual void vfun()
		{
			std::cout << "¶ù×Óvfun" << std::endl;

		}
		void ffun()
		{
			vfun();
		}
		~Sun1()
		{
			std::cout << "¶ù×Ó1Îö¹¹" << std::endl;

		}
	};
	
}
