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
		virtual Status GetElem(int i, ElemType& e)const = 0;
		Status CheckInput(int input, int offset = 0) const
		{
			if (input<1 || input>length + offset)
				return ERROR;
			return OK;
		}
	};
}


