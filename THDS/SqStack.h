#pragma once
#include "../GlobalDef.h"

namespace Th
{

	template<typename SElemType>
	class SqStack
	{
		enum { STACK_INIT_SIZE = 100, STACKINCREMENT = 10 };
	public:
		SElemType* base;
		SElemType* top;
		int stacksize;
		SqStack()
		{
			base = new SElemType[STACK_INIT_SIZE];
			top = base;
			stacksize = STACK_INIT_SIZE;
		};
		virtual ~SqStack()
		{

		};
		Status GetTop(SElemType& e)
		{
			if (top == base)	return ERROR;
			e = *(top - 1);
			return OK;
		}
		Status Push(SElemType e)
		{
			if (top - base >= stacksize)
			{
				SElemType* newbase = new SElemType[stacksize + STACKINCREMENT];
				std::copy_n(this->base, stacksize, newbase);
				delete[] this->base;
				this->base = newbase;

				top = base + stacksize;
				stacksize += STACKINCREMENT;
			}
			*top = e;
			++top;
			return OK;
			
		}
		Status Pop(SElemType& e)
		{
			if (top == base) return ERROR;
			--top;
			e = *top;
			return OK;
		}
		Status StackTraverse(Status(*visit)(SElemType))
		{
			SElemType temp;
			while(Pop(temp))
			{
				if (!visit(temp))
					return ERROR;
				
			}
			return OK;
		}
	};
}

