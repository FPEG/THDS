#pragma once
#include "LinkNode.h"
#include "../GlobalDef.h"
namespace Th
{
	template<typename QElemType>
	class LinkQueue
	{
	public:
		LinkNode<QElemType>* front;//��ͷָ��
		LinkNode<QElemType>* rear;//��βָ��

		LinkQueue()
		{
			LinkNode<QElemType>* temp = new LinkNode<QElemType>;//ռλ�ڵ㣬������//������null
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
			//p->data = e;//���캯��������
			//p->next = nullptr;
			rear->next = p;
			rear = p;
			return OK;
		}

		Status DeQueue(QElemType & e)
		{
			if (QueueEmpty())
				return ERROR;
			LinkNode<QElemType>* p = front->next;//Ҫɾ���Ľڵ㣨ͷ�ڵ�(��)����һ����//front->next���Ǵ�ͳ�����front
			e = p->data;
			front->next = p->next;//�ı�ͷ�ڵ����һ���ڵ㣬���һ�λ�ĵ���ָ����
			if (rear == p)
				rear = front;//�ֶ��ϲ�ͷβ�ڵ㣬��Ȼβ�ڵ�ᱻ����������3-��2��
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