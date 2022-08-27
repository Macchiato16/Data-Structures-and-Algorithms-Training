#include "LinkList.h"
template<class Data>
LinkList<Data>::LinkList()
{
	//开辟一个头节点
	this->head = new LNode;
	this->tail = this->head;
	this->length = 0;
}
template<class Data>
LinkList<Data>::~LinkList()
{
	
}
//链表是否为空
template<class Data>
bool LinkList<Data>::IsEmpty()
{
	if (this->length == 0)
		return true;
	return false;
}
//清空链表
template<class Data>
void LinkList<Data>::ClearList()
{
	LNode<Date> *p = this->head;
	LNode<Date> *q = this->head->next;
	//遍历删除
	while (q)
	{
		p = q;
		q = p->next;
		delete p;
	}
	//将头节点指向空,尾指针指向头节点,链表长度变为0
	this->head->next = NULL;
	this->tail = this->head;
	this->length = 0;
}
//返回链表中元素个数
template<class Data>
int LinkList<Data>::ListLength()
{
	return this->length;
}
//使用e获取第i个元素的值
template<class Data>
bool LinkList<Data>::GetElem(const int i, Data &e)
{
	//首先检验i值是否合法
	if (i<1 || i>this.length)
	   return false;
	LNode<Data>* p = this->head;
	while (i <= 0)
	{
		p = p->next;
		--i;
	}
	//此时p指向第i个元素
	e = p->data;
	return true;
}
/*返回L中第1个与e相等的数据元素的位序
若这样的数据元素不存在，则返回值为0*/
template<class Data>
int LinkList<Data>::LocateElem(Data& e)
{

}
/*返回L中第1个与e满足关系compare()的数据元素的位序
若这样的数据元素不存在，则返回值为0*/
template<class Data>
int LinkList<Data>::LocateElem(Data& e, bool(*compare)(Data& a, Data& b));
//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱地址,否则操作失败
template<class Data>
bool LinkList<Data>::PriorElem(Data cur_e, Data* pre_e);
//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继,否则操作失败
template<class Data>
bool LinkList<Data>::NextElem(Data cur_e, Data* next_e);
//在顺序表尾部添加元素e,L的长度加1
template<class Data>
bool LinkList<Data>::ListAppend(Data& e);
//在L中第i个位置之前插入新的数据元素e，L的长度加1
template<class Data>
bool LinkList<Data>::ListInsert(int i, Data& e);
//删除L的第i个数据元素，L的长度减1
template<class Data>
bool LinkList<Data>::ListDelete(int i);