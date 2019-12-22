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
		 * \par 初始条件
		 * 线性表L已存在,l<i<ListLength(L)
		 * \par 操作结果
		 * 用e返回L中第i个数据元素的值。
		 * \brief 当第i个元素存在时，其值赋给e并返回OK,否则返回ERROR
		 *
		 * \param i 元素位置
		 * \param[out] e 返回元素
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
		 * \brief 返回P指示线性链表L中第i个结点的位置并返回OK,i值不合法时返回ERROR
		 * \param i 第i个节点（从1开始数）
		 * \param q 第i个节点的地址（从1开始数）
		 * \return OK;ERROR
		 */
		Status LocatePos(const int i, LinkNode<ElemType>*& q)
		{
			LinkNode<ElemType>* p = head;//头指针
			int j = 1;//计数器
			if (i == 0)
			{
				q->next = head;
				return OK;
			}
			while (
				p &&//p不是空指针，元素存在
				j < i//当前计数器小于目标位置
				)
			{
				p = p->next;
				++j;
			}

			if (
				!p ||//p是空指针，元素不存在
				j > i//计数器大于目标位置
				)
			{
				return ERROR;
			}
			q = p;
			return OK;
		}

		Status ListInsert(int i, ElemType e) override
		{
			LinkNode<ElemType>* h = new LinkNode<ElemType>;//用于存放待插入位置的头节点
			if (!LocatePos(i - 1, h))
				return ERROR;
			LinkNode<ElemType>* s = new LinkNode<ElemType>(e);
			h->InsFirst(s);
			if (i == 1)//第一个节点插入需要挂接头节点
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
