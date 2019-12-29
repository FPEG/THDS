#pragma once
#include "../GlobalDef.h"
namespace Th
{
	template<typename ElemType>
	class List
	{
	public:
		ElemType* elem;
		int length;
		List() : elem(nullptr), length(0)
		{
		}
		;
		virtual ~List()
		{

		};
		virtual Status ClearList() = 0;
		int ListLength() const
		{
			return length;
		}
		virtual Status ListEmpty()
		{
			if (length == 0)
			{
				return TRUE;
			}
			return FALSE;
		};
		virtual Status ListInsert(int i, ElemType e) = 0;
		virtual Status ListDelete(int i, ElemType& e) = 0;
		virtual Status ListTraverse(Status(*visit)(ElemType)) = 0;
		/**
		 * \par 初始条件
		 * 线性表L已存在,l<=i<=ListLength(L)
		 * \par 操作结果
		 * 用e返回L中第i个数据元素的值。
		 * \brief 当第i个元素存在时，其值赋给e并返回OK,否则返回ERROR
		 *
		 * \param i 元素位置(从1开始)
		 * \param[out] e 返回元素
		 * \return OK;ERROR
		 */
		virtual Status GetElem(int i, ElemType& e)const = 0;
		Status CheckInput(int input, int offset = 0) const
		{
			if (input<1 || input>length + offset)
				return ERROR;
			return OK;
		}
	};
}


