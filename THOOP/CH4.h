#pragma once
#include "../GlobalDef.h"
namespace Th
{
	class CH4
	{
		int x;
	public:
		CH4(int x):x(x)
		{
			
		}
		friend std::ostream& operator <<(std::ostream& output,CH4 & cc)
		{
			output << cc.x;
			return output;
		}
		virtual ~CH4()
		{
			
		}
	};
}

