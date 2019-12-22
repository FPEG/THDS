#pragma once
#include "List.h"

namespace Th {
	template<typename ElemType>
	class SqList :
		public List<ElemType>
	{
		enum { LIST_INIT_SIZE = 100, LISTINCREMENT = 10 };
		int listsize;
	public:
		SqList()
		{
			//if (! L. elem) exit (OVERFLOW);//古代错误处理
			this->elem = new ElemType[LIST_INIT_SIZE];
			this->length = 0;
			listsize = LIST_INIT_SIZE;

		};
		virtual ~SqList()= default;
		Status ClearList() override
		{
			return TRUE;
		}

		Status GetElem(int i, ElemType& e) override
		{
			if (i<1 || i>this->length)
				return ERROR;
			e = this->elem[i];
			return OK;
		}

		/**
		 * \brief 在顺序线性表L中第i个位置之前插入新的元素e,
		 i 的合法值为 l<i<List:Length(L) + 1
		 * \param i 第i个位置之前插入（从1开始数）
		 * \param e 新的元素
		 * \par
			时间复杂度：O(n)
		 * \return
		 */
		Status ListInsert(int i, ElemType e)
		{
			if (i<1 || i>this->length + 1)
				return ERROR;
			if (this->length + 1 > listsize)
			{
				auto newbase = new ElemType[listsize + LISTINCREMENT];
				std::copy_n(this->elem, listsize, newbase);
				delete[] this->elem;
				this->elem = newbase;
			}
			ElemType* q = &(this->elem[i - 1]);//要插入位置的元素指针
			for (
				ElemType* p = &(this->elem[this->length - 1]);//p初始是指向最后一个元素的指针
				p >= q;
				--p
				)
			{
				*(p + 1) = *p;//p+1初始位置为没有元素的下一个位置
			}
			*q = e;//插入元素
			++this->length;
		}


		/**
		 * \brief 在顺序线性表中删除第i个元素，并用e返回其值
		 * \param i 要删除的位置
		 * \param[out] e 返回被删除的值
		 * \par
			时间复杂度：O(n)
		 * \return
		 */
		Status ListDelete(int i, ElemType & e) override
		{
			if (i<1 || i>this->length)
				return ERROR;
			ElemType * p = &(this->elem[i - 1]);//要删除的位置
			e = *p;
			ElemType * q = this->elem + this->length - 1;//表位元素位置
			for (++p; p <= q; ++p)
			{
				*(p - 1) = *p;//向后移动
			}
			--this->length;
			return OK;

		}

		/**
		 * \brief 在顺序线性表L中查找第1个值与e满足compare()的元素的位序,若找到，则返回其在L中的位序，否则返回0
		 * \param e
		 * \param compare
		 * \return
		 */
		int LocateElem(ElemType e, Status(*compare)(ElemType, ElemType))
		{
			// i的初值为第1个元素的位序
			int i = 1;
			// p的初值为第1个元素的存储位置
			ElemType* p = this->elem;
			while (
				i < this->length &&
				!(*compare)(*p++, e)
				)
			{
				i++;
			}
			//若未找到，此时i=this->length
			if (i < this->length)
				return i;
			return 0;
		}
		Status ListTraverse(Status(*visit)(ElemType))
		{
			for (int i = 0; i < this->length; i++)
			{
				visit(this->elem[i]);
			}
			return OK;
		}
		friend SqList operator+(SqList<ElemType> & la, SqList<ElemType> & lb)
		{
			SqList<ElemType> lc;
			ElemType* pa = la.elem;//la初始位置指针
			ElemType* pb = lb.elem;//lb初始位置指针
			ElemType* pc = lc.elem;//lc初始位置指针
			ElemType* pa_last = la.elem + la.length - 1;//la末位置指针
			ElemType* pb_last = lb.elem + lb.length - 1;//lb末位置指针
			
			while (
				pa <= pa_last &&//pa没到最后
				pb <= pb_last//pb没到最后
				)
			{
				if (*pa <= *pb)
					//插入小的，pa优先
				{
					*pc = *pa;
					++pc;
					++pa;
				}
				else
				{
					*pc = *pb;
					++pc;
					++pb;
				}
				++lc.length;
			}
			//此时pa超了或pb超了last
			//剩下的谁没超谁就直接写入
			while (pa <= pa_last)
			{
				*pc = *pa;
				++pc;
				++pa;
				++lc.length;
			}
			while (pb <= pb_last)
			{
				*pc = *pb;
				++pc;
				++pb;
				++lc.length;
			}
			return lc;
		}

	};
}