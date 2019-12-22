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
		LinkList(ElemType e) :head(new LinkNode<ElemType>(e)), tail(head)
		{
			this->length = 1;
		};
		LinkList(int n, ElemType* arr) :head(nullptr), tail(nullptr)
		{
			LinkNode<ElemType>* node = new LinkNode<ElemType>(arr[0]);
			LinkNode<ElemType>* p = nullptr;
			head = node;
			p = head;
			this->length = 1;
			
			for (int i = 1; i < n; i++)
			{
				node = new LinkNode<ElemType>(arr[i]);
				p->next = node;
				p = p->next;
				tail = node;
				++this->length;
			}
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
		 * \param q ��i���ڵ�ĵ�ַ����1��ʼ���������i=1�򷵻�ָ��ͷ�ڵ����ָ��
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
			if (List<ElemType>::CheckInput(i))
			{
				LinkNode<ElemType>* h = new LinkNode<ElemType>;//���ڴ�Ŵ�����λ�õ���һ���ڵ�,��i=1����hΪhead����һ���ڵ�
				if (!LocatePos(i - 1, h))
					return ERROR;
				LinkNode<ElemType>* s = new LinkNode<ElemType>(e);
				h->InsFirst(s);
				//�ı��һ���ڵ����������ͷ�ڵ㵽h.next��
				if (i == 1)
				{
					head = h->next;
				}
				++this->length;
				return OK;
			}
			return ERROR;
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
			if (List<ElemType>::CheckInput(i))
			{
				LinkNode<ElemType>* h = new LinkNode<ElemType>;//���ڴ�Ŵ�ɾ��λ�õ���һ���ڵ�
				if (!LocatePos(i - 1, h))
					return ERROR;
				LinkNode<ElemType>* s = new LinkNode<ElemType>(e);//���ڴ�ű�ɾ��λ�õĽڵ�
				h->DelFirst(s);
				//�ı��һ���ڵ����������ͷ�ڵ㵽h.next��
				if (i == 1)
				{
					head = h->next;
				}

				--this->length;
				return OK;
			}
			return ERROR;

		}

		Status Append(LinkNode<ElemType>* e)
		{
			tail->next = e;
			return OK;
		}
	};
}
