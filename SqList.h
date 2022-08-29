#pragma once
#include"config.h"
//顺序表存储空间的初始分配量
#define LIST_INIT_SIZE 20
//顺序表扩容时的增加量
#define LIST_INCREMENT 5
//顺序表实现
template<class Data>
class SqList
{
private:
	Data* elem; /* 存储空间基址 */
	int length; /* 当前长度 */
	int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
	//默认构造函数，产生一个空的顺序表
	SqList();
	//拷贝构造函数
	SqList(SqList& L);
	//析构函数，销毁顺序表
	~SqList();
public:
	//以下为算法
	//销毁顺序表
	void DestroyList();
	//置为空表
	void ClearList();
	//顺序表是否为空
	bool IsEmpty();
	//返回顺序表中元素个数
	int ListLength();
	//使用e获取第i个元素的值
	bool GetElem(const int i, Data& e);
	/*返回L中第1个与e相等的数据元素的位序
	若这样的数据元素不存在，则返回值为0*/
	int LocateElem(Data& e);
	/*返回L中第1个与e满足关系compare()的数据元素的位序
	若这样的数据元素不存在，则返回值为0*/
	int LocateElem(Data& e, bool(*compare)(Data& a, Data& b));
	//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱地址,否则操作失败
	bool PriorElem(Data cur_e, Data* pre_e);
	//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继,否则操作失败
	bool NextElem(Data cur_e, Data* next_e);
	//在顺序表尾部添加元素e,顺序表的长度加1
	bool ListAppend(Data& e);
	//在L中第i个位置之前插入新的数据元素e，顺序表的长度加1
	bool ListInsert(const int i, Data& e);
	//删除L的第i个数据元素，顺序表的长度减1
	bool ListDelete(const int i);

};


