#include <iostream>
#include "SqList.h"
#include "LinkList.h"
#include "SqStack.h"
#include "LinkQueue.h"
#include "SqQueue.h"
#include "SSTable.h"
using namespace Th;

void test()
{
	std::cout << "adsd" << std::endl;
}

int main()
{
	Status(*print_int)(int) = [](int x) {std::cout << x << " "; return OK; };
	auto compare_int = [](int x, int y) {return (x == y) ? TRUE : FALSE; };
	auto enter = []() {std::cout << std::endl; };
	
	SqList<int> s1(compare_int);
	s1.ListInsert(1, 2);
	s1.ListInsert(2, 5);
	s1.ListInsert(3, 9);
	s1.ListInsert(4, 11);
	s1.ListInsert(5, 19);
	SqList<int> s2(compare_int);
	s2.ListInsert(1, 3);
	s2.ListInsert(2, 5);
	s2.ListInsert(3, 10);
	s2.ListInsert(4, 12);
	s2.ListInsert(5, 20);
	//std::cout << sl.LocateElem(4, [](int x, int y) {return (x == y) ? TRUE : FALSE; });
	SqList<int> s3 = s1 + s2;
	s2 += s1;
	s2.ListTraverse(print_int);
	enter();

	s3.ListTraverse(print_int);
	enter();

	LinkList<int> la = LinkList<int>(1);

	
	la.ListInsert(1, 2);
	la.ListTraverse(print_int);
	enter();
	
	la.ListInsert(2, 3);
	la.ListTraverse(print_int);
	std::cout << std::endl;
	
	la.ListInsert(3, 4);
	la.ListTraverse(print_int);
	std::cout << std::endl;
	
	la.ListInsert(1, 400);
	la.ListTraverse(print_int);
	std::cout << std::endl;

	la.Append(new LinkNode<int>(999));
	la.ListTraverse(print_int);
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

	SqStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);

	int temp_2 = 0;

	stack.StackTraverse(print_int);
	std::cout << std::endl;
	
	LinkQueue<int>queue;
	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(3);
	queue.EnQueue(4);

	queue.QueueTraverse(print_int);
	std::cout << std::endl;

	SqQueue<int>queues;

	queues.EnQueue(1);
	queues.EnQueue(2);
	queues.EnQueue(3);
	queues.EnQueue(4);

	queues.QueueTraverse(print_int);
	std::cout << std::endl;
	auto lt_int = [](int a, int b) {return a < b ? TRUE : FALSE; };
	auto sst = new SSTable<int>(compare_int, lt_int,0);
	sst->ListInsert(1, 1);
	sst->ListInsert(2, 2);
	sst->ListInsert(3, 7);
	sst->ListInsert(4, 8);
	sst->ListInsert(5, 49);

	sst->ListTraverse(print_int);
	enter();
	show_var("sst.Search_Bin(1)", sst->Search_Bin(1));
	enter();
}
