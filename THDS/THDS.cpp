#include <iostream>
#include "SqList.h"
#include "LinkList.h"
using namespace Th;
int main()
{
	Status(*print)(int) = [](int x) {std::cout << x << " "; return OK; };
	
	SqList<int> sl;
	sl.ListInsert(1, 2);
	sl.ListInsert(2, 5);
	sl.ListInsert(3, 9);
	sl.ListInsert(4, 11);
	sl.ListInsert(5, 19);
	SqList<int> s2;
	s2.ListInsert(1, 3);
	s2.ListInsert(2, 5);
	s2.ListInsert(3, 10);
	s2.ListInsert(4, 12);
	s2.ListInsert(5, 20);
	//std::cout << sl.LocateElem(4, [](int x, int y) {return (x == y) ? TRUE : FALSE; });
	SqList<int> s3 = sl + s2;
	//s3.ListTraverse([](int x) {std::cout << x << " "; return OK; });

	LinkList<int> la = LinkList<int>(1);

	
	la.ListInsert(1, 2);
	la.ListTraverse(print);
	std::cout << std::endl;
	
	la.ListInsert(2, 3);
	la.ListTraverse(print);
	std::cout << std::endl;
	
	la.ListInsert(3, 4);
	la.ListTraverse(print);
	std::cout << std::endl;
	
	la.ListInsert(1, 400);
	la.ListTraverse(print);
	std::cout << std::endl;

	la.Append(new LinkNode<int>(999));
	la.ListTraverse(print);
	std::cout << std::endl;

	int temp_1=0;
	la.ListDelete(1, temp_1);
	la.ListTraverse([](int x) {std::cout << x << " "; return OK; });
	std::cout << std::endl;
	
	int a = 0;
	la.GetElem(0, a);
	std::cout << a << std::endl;

	LinkList<int> lb = LinkList<int>(5,new int[5]{5,4,3,2,1});
	lb.ListTraverse([](int x) {std::cout << x << " "; return OK; });
	std::cout << std::endl;

	lb.Append(new LinkNode<int>(999));
	lb.ListTraverse([](int x) {std::cout << x << " "; return OK; });
	std::cout << std::endl;

	lb.ListDelete(2, temp_1);
	lb.ListTraverse([](int x) {std::cout << x << " "; return OK; });
	std::cout << std::endl;
}
