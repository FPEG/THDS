#pragma once
#include "LinkNode.h"
#include "../GlobalDef.h"
namespace Th
{
	template<typename QElemType>
	class LinkQueue
	{
	public:
		LinkNode<QElemType>* front;//队头指针
		LinkNode<QElemType>* rear;//队尾指针

		LinkQueue()
		{
			LinkNode<QElemType>* temp = new LinkNode<QElemType>;//占位节点，无内容//不能用null
			front = rear = temp;
			front->next = nullptr;
		};
		virtual ~LinkQueue()
		{
		};

		Status QueueEmpty()
		{
			if (front == rear)return TRUE;
			return ERROR;
		}

		Status EnQueue(QElemType e)
		{
			LinkNode<QElemType>* p = new LinkNode<QElemType>(e);
			//p->data = e;//构造函数里有了
			//p->next = nullptr;
			rear->next = p;
			rear = p;
			return OK;
		}

		Status DeQueue(QElemType & e)
		{
			if (QueueEmpty())
				return ERROR;
			LinkNode<QElemType>* p = front->next;//要删除的节点（头节点(空)的下一个）//front->next就是传统意义的front
			e = p->data;
			front->next = p->next;//改变头节点的下一个节点，最后一次会改到空指针上
			if (rear == p)
				rear = front;//手动合并头尾节点，不然尾节点会被跳过（画出3-》2）
			delete p;
			return OK;
		}

		Status QueueTraverse(Status(*visit)(QElemType))
		{
			QElemType temp;
			while (DeQueue(temp))
			{
				if (!visit(temp))
					return ERROR;
			}
			return OK;
		}
	};

}