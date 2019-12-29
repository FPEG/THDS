#pragma once
#include "SqList.h"
#define MAXQSIZE SqList<QElemType>::LIST_INIT_SIZE
namespace Th {
	template<typename QElemType>
	class SqQueue :
		protected SqList<QElemType>
	{
		
		int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
		int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص�*��һ��λ��*//����λ��
	public:
		SqQueue():SqList<QElemType>()
		{
			front = rear = 0;
		};
		virtual ~SqQueue()
		{
			
		};
		
		int QueueLength() const
		{
			return (rear - front + MAXQSIZE) % MAXQSIZE;
		}

		Status QueueEmpty() const
		{
			if (front == rear)
			{
				return TRUE;
			}
			return ERROR;
		}
		
		Status QueueFull() const
		{
			if (front == (rear + 1) % MAXQSIZE)//β�ڵ��ǰ��һ����ͷ�ڵ�
			{
				return TRUE;
			}
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
