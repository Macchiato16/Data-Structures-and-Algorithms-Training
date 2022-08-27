#pragma once
//链表的节点
template<class Data>
class LNode
{
public:
	Data data;
	LNode* next;
	LNode()
	{
		this->next = NULL;
	}
	LNode(LNode* p = NULL)
	{
		this->next = p;
	}
};
//链表
template<class Data>
class LinkList
{
private:
	//头指针和尾指针
	LNode<Data>* head, tail;
	//链表的长度（不包括头节点）
	int length;
public:
	LinkList();
	~LinkList();
	//链表是否为空
	bool IsEmpty();
	//清空链表
	void ClearList();
	//返回链表中元素个数
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
	//在顺序表尾部添加元素e,L的长度加1
	bool ListAppend(Data& e);
	//在L中第i个位置之前插入新的数据元素e，L的长度加1
	bool ListInsert(int i, Data& e);
	//删除L的第i个数据元素，L的长度减1
	bool ListDelete(int i);

};


