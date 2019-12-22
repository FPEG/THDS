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
			//if (! L. elem) exit (OVERFLOW);//�Ŵ�������
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
		 * \brief ��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e,
		 i �ĺϷ�ֵΪ l<i<List:Length(L) + 1
		 * \param i ��i��λ��֮ǰ���루��1��ʼ����
		 * \param e �µ�Ԫ��
		 * \par
			ʱ�临�Ӷȣ�O(n)
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
			ElemType* q = &(this->elem[i - 1]);//Ҫ����λ�õ�Ԫ��ָ��
			for (
				ElemType* p = &(this->elem[this->length - 1]);//p��ʼ��ָ�����һ��Ԫ�ص�ָ��
				p >= q;
				--p
				)
			{
				*(p + 1) = *p;//p+1��ʼλ��Ϊû��Ԫ�ص���һ��λ��
			}
			*q = e;//����Ԫ��
			++this->length;
		}


		/**
		 * \brief ��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
		 * \param i Ҫɾ����λ��
		 * \param[out] e ���ر�ɾ����ֵ
		 * \par
			ʱ�临�Ӷȣ�O(n)
		 * \return
		 */
		Status ListDelete(int i, ElemType & e) override
		{
			if (i<1 || i>this->length)
				return ERROR;
			ElemType * p = &(this->elem[i - 1]);//Ҫɾ����λ��
			e = *p;
			ElemType * q = this->elem + this->length - 1;//��λԪ��λ��
			for (++p; p <= q; ++p)
			{
				*(p - 1) = *p;//����ƶ�
			}
			--this->length;
			return OK;

		}

		/**
		 * \brief ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��,���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
		 * \param e
		 * \param compare
		 * \return
		 */
		int LocateElem(ElemType e, Status(*compare)(ElemType, ElemType))
		{
			// i�ĳ�ֵΪ��1��Ԫ�ص�λ��
			int i = 1;
			// p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
			ElemType* p = this->elem;
			while (
				i < this->length &&
				!(*compare)(*p++, e)
				)
			{
				i++;
			}
			//��δ�ҵ�����ʱi=this->length
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
			ElemType* pa = la.elem;//la��ʼλ��ָ��
			ElemType* pb = lb.elem;//lb��ʼλ��ָ��
			ElemType* pc = lc.elem;//lc��ʼλ��ָ��
			ElemType* pa_last = la.elem + la.length - 1;//laĩλ��ָ��
			ElemType* pb_last = lb.elem + lb.length - 1;//lbĩλ��ָ��
			
			while (
				pa <= pa_last &&//paû�����
				pb <= pb_last//pbû�����
				)
			{
				if (*pa <= *pb)
					//����С�ģ�pa����
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
			//��ʱpa���˻�pb����last
			//ʣ�µ�˭û��˭��ֱ��д��
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