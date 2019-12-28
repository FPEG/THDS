#pragma once
#include "Global.h"


namespace Th
{
	class CH3
	{
		int normal;
		static int static_;//369
		const static int const_static_;
		const int const_;//123
		mutable int mutable_;
	public:
		CH3():const_(123),mutable_(456),normal(12)
		{
		}
		void change_normal()
		{
			normal++;
		}
		//void change_normal_const() const
		//{
		//	normal++;
		//}
		void change_mutable()
		{
			mutable_++;
		}
		void change_mutable_const() const
		{
			mutable_++;
		}
		void change_static_()
		{
			static_++;
		}
		void change_static_const() const
		{
			static_++;
		}
		//void change_const()
		//{
		//	const_++;
		//}
		//void change_const_const() const
		//{
		//	const_++;
		//}
		



		void print()
		{
			print_const();
		}
		void print_const() const
		{
			show_var("normal", normal);
			show_var("const_", const_);
			show_var("mutable_", mutable_);
			show_var("const_static_", const_static_);
			show_var("static_", static_);
		}
		virtual ~CH3()
		{}
	};
	class CH3_ARR
	{
		
	};
	int CH3::static_ = 369;//私有类外初始化
	const int CH3::const_static_ = 369;//私有类外初始化
}




