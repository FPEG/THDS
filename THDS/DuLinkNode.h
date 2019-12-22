#pragma once
#include "Node.h"

namespace Th
{
	template<typename ElemType>
	class DuLinkNode :
		public Node<ElemType>
	{

	public:
		DuLinkNode* next;
		DuLinkNode* prior;
		DuLinkNode(): next(nullptr), prior(nullptr)
		{
			
		}
		;
		virtual ~DuLinkNode() = default;
	};
}