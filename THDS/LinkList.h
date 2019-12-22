#pragma once
#include "List.h"
#include "LinkNode.h"
namespace Th
{
	template<typename ElemType>
	class LinkList :
		public List<ElemType>
	{
	public:
		LinkNode<ElemType>* head, * tail;
		LinkList(ElemType e) :head(new LinkNode<ElemType>(e)),tail(head)
		{

		};
		virtual ~LinkList()
		{

		};


		/**
		 * \par ��ʼ����
		 * ���Ա�L�Ѵ���,l<i<ListLength(L)
		 * \par �������
		 * ��e����L�е�i������Ԫ�ص�ֵ��
		 * \brief ����i��Ԫ�ش���ʱ����ֵ����e������OK,���򷵻�ERROR
		 *
		 * \param i Ԫ��λ��
		 * \param[out] e ����Ԫ��
		 * \return OK;ERROR
		 */
		Status GetElem(const int i, ElemType& e) override
		{
			if (List<ElemType>::CheckInput(i))
			{
				LinkNode<ElemType>* temp = nullptr;
				if (LocatePos(i, temp))
				{
					e = temp->data;
					return OK;
				}
			}
			return ERROR;
		}
		/**
		 * \brief ����Pָʾ��������L�е�i������λ�ò�����OK,iֵ���Ϸ�ʱ����ERROR
		 * \param i ��i���ڵ㣨��1��ʼ����
		 * \param q ��i���ڵ�ĵ�ַ����1��ʼ����
		 * \return OK;ERROR
		 */
		Status LocatePos(const int i, LinkNode<ElemType>*& q)
		{
			LinkNode<ElemType>* p = head;//ͷָ��
			int j = 1;//������
			if (i == 0)
			{
				q->next = head;
				return OK;
			}
			while (
				p &&//p���ǿ�ָ�룬Ԫ�ش���
				j < i//��ǰ������С��Ŀ��λ��
				)
			{
				p = p->next;
				++j;
			}

			if (
				!p ||//p�ǿ�ָ�룬Ԫ�ز�����
				j > i//����������Ŀ��λ��
				)
			{
				return ERROR;
			}
			q = p;
			return OK;
		}

		Status ListInsert(int i, ElemType e) override
		{
			LinkNode<ElemType>* h = new LinkNode<ElemType>;//���ڴ�Ŵ�����λ�õ�ͷ�ڵ�
			if (!LocatePos(i - 1, h))
				return ERROR;
			LinkNode<ElemType>* s = new LinkNode<ElemType>(e);
			h->InsFirst(s);
			if (i == 1)//��һ���ڵ������Ҫ�ҽ�ͷ�ڵ�
			{
				head = s;
			}
			++this->length;
			return OK;
		}
		Status ListTraverse(Status(*visit)(ElemType)) override
		{
			LinkNode<ElemType>* p = head;
			while (p)
			{
				visit(p->data);
				p = p->next;
			}
			return OK;
		}

		Status ClearList() override
		{
			return OK;
		}
		Status ListDelete(int i, ElemType& e) override
		{
			return OK;
		}

		Status Append(LinkNode<ElemType>* e)
		{
			tail->next = e;
			return OK;
		}
	};
}
