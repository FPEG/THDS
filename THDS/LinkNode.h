#pragma once
#include "Node.h"
namespace Th {
	/**
	 * \brief 单链表节点
	 * \tparam ElemType 元素类型
	 */
	template<typename ElemType>
	class LinkNode :
		public Node<ElemType>
	{
	public:
		LinkNode* next;
		LinkNode(ElemType e): Node<ElemType>(e),next(nullptr)
		{
		}
		LinkNode() : Node<ElemType>(0), next(nullptr)
		{
		}
		Status InsFirst(LinkNode* e)
		{
			e->next = next;
			next = e;
			return OK;
		}
		Status DelFirst(LinkNode*& q)
		{
			q = next;
			next = next->next;
			//delete q;
			return OK;
		}
		virtual ~LinkNode() = default;
	};
}
