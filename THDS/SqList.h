#pragma once
#include "List.h"

namespace Th {
	
	template<typename ElemType>
	class SqList :
		public List<ElemType>
	{
	protected:
		enum { LIST_INIT_SIZE = 100, LISTINCREMENT = 10 };
		int listsize;
		Status(*compare)(ElemType, ElemType);
	public:
		SqList() :SqList(nullptr)
		{

		}
		SqList(Status(*compare)(ElemType, ElemType),int length=0) :compare(compare)
		{
			//if (! L. elem) exit (OVERFLOW);//古代错误处理
			this->elem = new ElemType[LIST_INIT_SIZE];
			this->length = length;
			listsize = LIST_INIT_SIZE;

		};
		virtual ~SqList() = default;
		Status ClearList() override
		{
			return TRUE;
		}

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
		Status GetElem(int i, ElemType& e) const override
		{
			if (i<1 || i>this->length)
				return ERROR;
			e = this->elem[i-1];
			return OK;
		}
		
		Status ListReplace(int i, ElemType e)
		{
			if (i<1 || i>this->length)
				return ERROR;
			this->elem[i - 1] = e;
			return OK;
		}
		/**
		 * \brief 在顺序线性表L中第i个位置之前插入新的元素e,
		 i 的合法值为 l<=i<=List:Length(L) + 1
		 * \param i 第i个位置之前插入（从1开始数）
		 * \param e 新的元素
		 * \par
			时间复杂度：O(n)
		 * \return
		 */
		virtual Status ListInsert(int i, ElemType e)
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
			return OK;
		}


		/**
		 * \brief 在顺序线性表中删除第i个元素，并用e返回其值
		 * \param i 要删除的位置
		 * \param[out] e 返回被删除的值
		 * \par
			时间复杂度：O(n)
		 * \return
		 */
		virtual Status ListDelete(int i, ElemType & e) override
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
		virtual int LocateElem(ElemType e, Status(*compare)(ElemType, ElemType))
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


		/**
		 * \brief 集合添加
		 * \param lb
		 */
		void operator|=(SqList<ElemType> & lb)
		{
			int la_len = this->ListLength();
			int lb_len = lb.ListLength();
			ElemType e;
			for (int i = 1; i < lb_len; i++)
			{
				lb.GetElem(i, e);
				if (!LocateElem(e, compare))
				{
					la_len += 1;
					ListInsert(la_len, e);
				}
			}
		}
		void operator+=(SqList<ElemType>& lb)
		{
			int i = 1;//la上指针位置
			int j = 1;//lb上指针位置
			//int la_len = this->ListLength();//这么写要增加表长
			const int lb_len = lb.ListLength();//表长，不改变
			ElemType ai, bj;
			while ((i <= this->ListLength()) && (j <= lb_len))// La 和 Lb 均非空
			{
				this->GetElem(i, ai);
				lb.GetElem(j, bj);
				if (ai <= bj)
				{
					++i;
				}
				else
				{
					ListInsert(i, bj);
					//++la_len//如果用局部变量在这里要增加表长//随动
					++i;//随动
					++j;//随动
				}
			}
			while (j <= lb_len)
			{
				lb.GetElem(j, bj);
				ListInsert(i, bj);
				++i;//随动
				++j;//随动
			}
		}
		friend SqList operator+(const SqList<ElemType> & la, const SqList<ElemType> & lb)
		{
			SqList<ElemType> lc(la.compare);
			int i = 1;//la上指针位置
			int j = 1;//lb上指针位置
			int k = 1;//lc插入的位置
			const int la_len = la.ListLength();//表长，不改变
			const int lb_len = lb.ListLength();//表长，不改变
			ElemType ai, bj;
			while ((i <= la_len) && (j <= lb_len))// La 和 Lb 均非空
			{
				la.GetElem(i, ai);
				lb.GetElem(j, bj);
				if (ai <= bj)
				{
					lc.ListInsert(k, ai);
					++i;
				}
				else
				{
					lc.ListInsert(k, bj);
					++j;
				}
				k++;//随动
			}
			while (i <= la_len)
			{
				la.GetElem(i++, ai);
				lc.ListInsert(k++, ai);
			}
			while (j <= lb_len)
			{
				lb.GetElem(j++, bj);
				lc.ListInsert(k++, bj);
			}

#ifdef op
			ElemType* pa = la.elem;//la初始位置指针
			ElemType* pb = lb.elem;//lb初始位置指针
			ElemType* pc = lc.elem;//lc初始位置指针
			ElemType* pa_last = la.elem + la.length - 1;//la末位置指针
			ElemType* pb_last = lb.elem + lb.length - 1;//lb末位置指针

			while (
				pa <= pa_last &&//pa没迭代到最后
				pb <= pb_last//pb没迭代到最后
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
#endif
			return lc;
		}

	};

	/*template<typename ElemType>
	using SSTable = SqList<ElemType>;*/

}