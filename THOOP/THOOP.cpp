// THOOP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CH5.h"
#include "CH3.h"
using namespace Th;
void call(int i);
void enter();

int main()
{
	call(5);

}

void call(int i)
{
	switch (i)
	{
	case 3:
	{
				//CH3_ARR			ch3_arr[10];
				CH3				ch3_arr[3];					
				CH3*			p_arr = new CH3[3];
				CH3				ch3;
		const	CH3				const_ch3;					//这三个写法一样
				CH3		const	ch3_const;					//这三个写法一样
		const	CH3		const	const_ch3_const;			//这三个写法一样

				CH3&			ch3r = ch3;
		const	CH3&			const_ch3r = ch3;			//这两个写法一样
				CH3&	const	ch3_constr = ch3;			//没用
		const	CH3&	const	const_ch3_constr = ch3;		//这两个写法一样
			
				CH3*			p;							//指向	对象	的	指针	：不可以指向常对象
		const	CH3*			const_p;					//指向	常对象	的	指针	：指向对象的成员不可修改//*//用于做参数
				CH3*	const	p_const = new CH3 ;			//指向	对象	的	常指针	：指向不可修改
		const	CH3*	const	const_p_const = new CH3;	//指向	常对象	的	常指针	：二合一


		//p = new const CH3;// C2440:无法从“const Th::CH3 *”转换为“Th::CH3 *”
		//p->change_mutable_const();
		//p->print_const();
		//enter();
		
		ch3_arr[1].print_const();
		show_var("ch3_arr", typeid(ch3_arr).name());
		show_var("p", typeid(p).name());
		show_var("const_p", typeid(const_p).name());
		show_var("p_const", typeid(p_const).name());
		show_var("const_p_const", typeid(const_p_const).name());
		enter();
		
		const_p = new CH3;
		const_p->change_mutable_const();
		const_p->print_const();
		enter();

		const_ch3r.change_static_const();
		ch3_constr.change_normal();
		enter();

		const_p = new const CH3;
		const_p->change_mutable_const();
		const_p->print_const();
		enter();
		
		p_const->change_normal();
		p_const->print_const();
		enter();
			
		const_p_const->change_mutable_const();
		const_p_const->print_const();
		enter();

		//p = const_p;
		p = p_const;
		p->change_normal();
		p->print();
		enter();
			
		ch3_const.print_const();
		ch3_const.change_mutable_const();
		ch3_const.print_const();
		enter();

		
		break;
	}

	case 5:
	{
		Base be;
		Base be2;
		BaseSun bs;
		//be = bs;
		bs.a_show_nov();
		//bs.a_show_v();
		bs.a_base_show_nov();
		Base* bp = new BaseSun();
		bp->a_show_v();
		bp->a_show_nov();
		bp->c_show_v();

		int Base::* ppp  = &Base::p;
		//ppp = &be.p;
		be.*ppp = 5;
		break;
	}
	default:
		break;;
	}
}

void enter()
{
	std::cout << std::endl;
}
