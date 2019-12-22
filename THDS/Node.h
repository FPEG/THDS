#pragma once
namespace Th
{
	template<typename ElemType>
	class Node
	{
	public:
		ElemType data;

		Node(ElemType data):data(data)
		{
			
		}
		Node() :data(nullptr)
		{

		}

		virtual ~Node()=default;
	};
}
