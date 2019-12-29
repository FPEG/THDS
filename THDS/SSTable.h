#pragma once
#include "SqList.h"

namespace Th
{
	template<typename ElemType>
	class SSTable :
		public SqList<ElemType>
	{
	protected:
		Status(*lt)(ElemType, ElemType);
		Status(*lq)(ElemType, ElemType);
		Status(*rq)(ElemType, ElemType);
	public:
		SSTable() :SqList<ElemType>()
		{

		}
		SSTable(
			Status(*compare)(ElemType, ElemType),
			Status(*lt)(ElemType, ElemType),
			Status(*lq)(ElemType, ElemType) ,
			Status(*rq)(ElemType, ElemType) ,
			ElemType first_elem
		) :SqList<ElemType>(compare), lt(lt),lq(lq),rq(rq)
		{
			SqList<ElemType>::ListInsert(1, first_elem);
		}
		Status ListInsert(int i, ElemType e) override
		{
			return SqList<ElemType>::ListInsert(i + 1, e);
		}
		Status ListDelete(int i, ElemType& e) override
		{
			return SqList<ElemType>::ListDelete(i + 1, e);
		}
		int LocateElem(ElemType e, Status(*compare)(ElemType, ElemType)) override
		{
			return SqList<ElemType>::LocateElem(e, compare) + 1;
		}

		/**
		 * \brief 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0。
		 * \param key 关键字
		 * \return
		 */
		int Search_Bin(ElemType key)
		{
			int low = 1;
			int high = this->length;  // 置区间初值
			while (low <= high)
			{
				int mid = (low + high) / 2;
				if (this->compare(key, this->elem[mid]))
				{
					return mid;// 找到待查元素
				}
				if (lt(key, this->elem[mid]))
				{
					high = mid - 1;// 继续在前半区间进行查找
				}
				else
				{
					low = mid + 1;//继续在后半区间进行查找
				}
			}
			return 0;  //顺序表中不存在待查元素
		}

		/**
		 * \brief 对顺序表L作快速排序
		 */
		void Quicksort() {
			QSort(1, this->length);
		}

		/**
		 * \brief 对顺序表中的子序列L. rElow. . high］作快速排序
		 * \param low
		 * \param high
		 */
		void QSort(int low, int high) {

			if (low < high) { //长度大于1
				const int pivotloc = Partition(low, high); //将 L.r[low..high]一分为二
				QSort(low, pivotloc - 1); //对低子表递归排序，Pivotloc是枢轴位置
				QSort(pivotloc + 1, high); //对高子表递归排序
			}
		}
		int Partition(int low, int high) {

			this->elem[0] = this->elem[low];  //用子表的第一个记录作枢轴,将枢轴记录暂存在r[0]
			ElemType pivotkey = this->elem[low];  // 枢轴记录关键字
			while (low < high) {  //从表的两端交替地向中间扫描
				while (low < high && this->elem[high] >= pivotkey)
				{
					--high;
				}
				this->elem[low] = this->elem[high];  //将比枢轴记录小的记录移到低端
				while (low < high && this->elem[low] <= pivotkey)
				{
					++low;
				}
				this->elem[high] = this->elem[low];  //将比枢轴记录大的记录移到高端
			}
			this->elem[low] = this->elem[0];
			return low;
		} 


		virtual ~SSTable() = default;
	};

}