#pragma once
#include "../GlobalDef.h"

namespace Th
{

	class Base
	{
		const int c = 10;
	protected:
		int a;
		const int d = 10;
	public:
		int p = 2;
		Base() :a(1)
		{
		}
		Base(int a) :a(a), c(12), d(11)
		{

		}
		void a_fun()
		{
			a = 2;
		}
		virtual ~Base()
		{
			std::cout << "үү" << std::endl;
		}
		void a_show_nov()
		{
			std::cout << a << std::endl;
		}
		virtual void a_show_v()
		{
			std::cout << a << std::endl;
		}
		virtual void c_show_v()
		{
			std::cout << c << std::endl;

		}
	};



	class BaseSun :
		public Base
	{

		int a;
		int b;
		int c = 13;
		virtual void a_show_v()
		{
			show_var("BaseSun::private a_show_v,a", a, "˽�к�������̬��̬����");
			show_var("BaseSun::private a_show_v,b", b, "˽�к�������̬��̬����");
		}
	public:
		BaseSun() :a(3), b(4), Base(5)
		{

		}
		void a_show_nov()
		{
			show_var("BaseSun::a_show_nov,a", a);
			show_var("BaseSun::a_show_nov,b", b);
		}

		void a_base_show_nov()
		{
			std::cout << Base::a << std::endl;
		}

		virtual void c_show_v()
		{
			show_var("BaseSun::c_show_v,c", c);
			show_var("BaseSun::c_show_v,d", d, "const d �����캯�����θ�ֵ");
		}

		friend int friend_(BaseSun& as, const BaseSun& as2)
		{

		}

		void show_d()
		{
			show_var("BaseSun::show_d", d);
		}
		~BaseSun()
		{
			std::cout << "�ְ�1" << std::endl;

		}

	};

	class BaseSun2
	{
		int a;
	public:
		BaseSun2()
		{
			std::cout << "�ְ�2����" << std::endl;
		}
		~BaseSun2()
		{
			std::cout << "�ְ�2" << std::endl;

		}
	};

	class BaseSun3
	{
		int a;
	public:
		
		~BaseSun3()
		{
			std::cout << "�ְ�3" << std::endl;

		}
	};

	class BaseGrandM :public BaseSun,public BaseSun3
	{
		void show()
		{
			//show_var("BaseSun::c_show_v,c", a);//error C2385: �ԡ�a���ķ��ʲ���ȷ
		}

		void show_d()
		{
			show_var("BaseSun::show_d", d);
		}
	public:
		~BaseGrandM()
		{
			std::cout << "����" << std::endl;
		}
	};
}
