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
			//if (! L. elem) exit (OVERFLOW);//�Ŵ�������
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
		 * \par ��ʼ����
		 * ���Ա�L�Ѵ���,l<=i<=ListLength(L)
		 * \par �������
		 * ��e����L�е�i������Ԫ�ص�ֵ��
		 * \brief ����i��Ԫ�ش���ʱ����ֵ����e������OK,���򷵻�ERROR
		 *
		 * \param i Ԫ��λ��(��1��ʼ)
		 * \param[out] e ����Ԫ��
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
		 * \brief ��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e,
		 i �ĺϷ�ֵΪ l<=i<=List:Length(L) + 1
		 * \param i ��i��λ��֮ǰ���루��1��ʼ����
		 * \param e �µ�Ԫ��
		 * \par
			ʱ�临�Ӷȣ�O(n)
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
			return OK;
		}


		/**
		 * \brief ��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
		 * \param i Ҫɾ����λ��
		 * \param[out] e ���ر�ɾ����ֵ
		 * \par
			ʱ�临�Ӷȣ�O(n)
		 * \return
		 */
		virtual Status ListDelete(int i, ElemType & e) override
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
		virtual int LocateElem(ElemType e, Status(*compare)(ElemType, ElemType))
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


		/**
		 * \brief �������
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
			int i = 1;//la��ָ��λ��
			int j = 1;//lb��ָ��λ��
			//int la_len = this->ListLength();//��ôдҪ���ӱ�
			const int lb_len = lb.ListLength();//�������ı�
			ElemType ai, bj;
			while ((i <= this->ListLength()) && (j <= lb_len))// La �� Lb ���ǿ�
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
					//++la_len//����þֲ�����������Ҫ���ӱ�//�涯
					++i;//�涯
					++j;//�涯
				}
			}
			while (j <= lb_len)
			{
				lb.GetElem(j, bj);
				ListInsert(i, bj);
				++i;//�涯
				++j;//�涯
			}
		}
		friend SqList operator+(const SqList<ElemType> & la, const SqList<ElemType> & lb)
		{
			SqList<ElemType> lc(la.compare);
			int i = 1;//la��ָ��λ��
			int j = 1;//lb��ָ��λ��
			int k = 1;//lc�����λ��
			const int la_len = la.ListLength();//�������ı�
			const int lb_len = lb.ListLength();//�������ı�
			ElemType ai, bj;
			while ((i <= la_len) && (j <= lb_len))// La �� Lb ���ǿ�
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
				k++;//�涯
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
			ElemType* pa = la.elem;//la��ʼλ��ָ��
			ElemType* pb = lb.elem;//lb��ʼλ��ָ��
			ElemType* pc = lc.elem;//lc��ʼλ��ָ��
			ElemType* pa_last = la.elem + la.length - 1;//laĩλ��ָ��
			ElemType* pb_last = lb.elem + lb.length - 1;//lbĩλ��ָ��

			while (
				pa <= pa_last &&//paû���������
				pb <= pb_last//pbû���������
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
#endif
			return lc;
		}

	};

	/*template<typename ElemType>
	using SSTable = SqList<ElemType>;*/

}