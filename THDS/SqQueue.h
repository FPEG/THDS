#pragma once
#include "SqList.h"
#define MAXQSIZE SqList<QElemType>::LIST_INIT_SIZE
namespace Th {
	template<typename QElemType>
	class SqQueue :
		protected SqList<QElemType>
	{
		
		int front;//头指针，若队列不空，指向队列头元素
		int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
	public:
		SqQueue():SqList<QElemType>()
		{
			front = rear = 0;
		};
		virtual ~SqQueue()
		{
			
		};
		
		int QueueLength()
		{
			return (rear - front + MAXQSIZE) % MAXQSIZE;
		}

		Status QueueEmpty()
		{
			if (front == rear)return TRUE;
			return ERROR;
		}
		
		Status QueueFull()
		{
			if ((rear + 1) % MAXQSIZE == front)return TRUE;
			return ERROR;
		}
		
		Status EnQueue(QElemType e)
		{
			if (QueueFull())
				return ERROR;
			this->elem[rear] = e;
			rear = (rear + 1) % MAXQSIZE;
			return OK;
		}

		Status DeQueue(QElemType &e)
		{
			if (QueueEmpty())
				return ERROR;
			e = this->elem[front];
			front = (front + 1) % MAXQSIZE;
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
