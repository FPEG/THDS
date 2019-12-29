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
		 * \brief �������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0��
		 * \param key �ؼ���
		 * \return
		 */
		int Search_Bin(ElemType key)
		{
			int low = 1;
			int high = this->length;  // �������ֵ
			while (low <= high)
			{
				int mid = (low + high) / 2;
				if (this->compare(key, this->elem[mid]))
				{
					return mid;// �ҵ�����Ԫ��
				}
				if (lt(key, this->elem[mid]))
				{
					high = mid - 1;// ������ǰ��������в���
				}
				else
				{
					low = mid + 1;//�����ں��������в���
				}
			}
			return 0;  //˳����в����ڴ���Ԫ��
		}

		/**
		 * \brief ��˳���L����������
		 */
		void Quicksort() {
			QSort(1, this->length);
		}

		/**
		 * \brief ��˳����е�������L. rElow. . high������������
		 * \param low
		 * \param high
		 */
		void QSort(int low, int high) {

			if (low < high) { //���ȴ���1
				const int pivotloc = Partition(low, high); //�� L.r[low..high]һ��Ϊ��
				QSort(low, pivotloc - 1); //�Ե��ӱ�ݹ�����Pivotloc������λ��
				QSort(pivotloc + 1, high); //�Ը��ӱ�ݹ�����
			}
		}
		int Partition(int low, int high) {

			this->elem[0] = this->elem[low];  //���ӱ�ĵ�һ����¼������,�������¼�ݴ���r[0]
			ElemType pivotkey = this->elem[low];  // �����¼�ؼ���
			while (low < high) {  //�ӱ�����˽�������м�ɨ��
				while (low < high && this->elem[high] >= pivotkey)
				{
					--high;
				}
				this->elem[low] = this->elem[high];  //���������¼С�ļ�¼�Ƶ��Ͷ�
				while (low < high && this->elem[low] <= pivotkey)
				{
					++low;
				}
				this->elem[high] = this->elem[low];  //���������¼��ļ�¼�Ƶ��߶�
			}
			this->elem[low] = this->elem[0];
			return low;
		} 


		virtual ~SSTable() = default;
	};

}