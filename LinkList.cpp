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
	LNode<Date>* p = this->head;
	LNode<Date>* q = this->head->next;
	//遍历删除
	while (q)
	{
		p = q;
		q = p->next;
		delete p;
	}
	//再将头节点删除
	delete this->head;
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
	//将指针移动到第i个元素上
	LNode<Data>* p = this->head;
	for (int j = 0;j < i;j++)
	{
		p = p->next;
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
	//先看链表是否为空
	if (this->length == 0)
		return 0;
	//链表不为空时
	LNode<Data>* p = this->head->next;
	for (int i = 1;i <= length;i++)
	{
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}
/*返回L中第1个与e满足关系compare()的数据元素的位序
若这样的数据元素不存在，则返回值为0*/
template<class Data>
int LinkList<Data>::LocateElem(Data& e, bool(*compare)(Data& a, Data& b))
{
	//先看链表是否为空
	if (this->length == 0)
		return 0;
	//链表不为空时
	LNode<Data>* p = this->head->next;
	for (int i = 1;i <= length;i++)
	{
		if (compare(p->data,e))
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}
//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱地址,否则操作失败
template<class Data>
bool LinkList<Data>::PriorElem(Data cur_e, Data* pre_e)
{
	//先看链表长度是否大于1
	if (this->length<=1)
		return false;
	//链表c长度大于1时，从第二个开始遍历
	LNode<Data>* p = this->head->next;
	LNode<Data>* q = p->next;
	for (int i = 2;i <= length;i++)
	{
		if (q->data==cur_e)
		{
			pre_e = p;
			return true;
		}
		p = q;
		q = q->next;
	}
	//都不符合直接返回错误
	return false;
}
//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继,否则操作失败
template<class Data>
bool LinkList<Data>::NextElem(Data cur_e, Data* next_e)
{
	//先看链表长度是否小于等于1
	if (this->length <= 1)
		return false;
	//链表c长度大于1时，从第1个开始遍历
	LNode<Data>* p = this->head->next;
	for (int i = 1;i < length;i++)
	{
		if (p.data == cur_e)
		{
			next_e= p->next;
			return true;
		}
		p = p->next;
	}
	//都不符合直接返回错误
	return false;
}
//在链表表尾部添加元素e,链表的长度加1
template<class Data>
bool LinkList<Data>::ListAppend(Data& e)
{
	//创建节点
	LNode<Data> *p = new LNode<Data>;
	if (!p)
	return false;
	p->data = e;
	//尾部插入元素
	this->tail.next = p;
	this->tail = p;
	this->length++;
	return true;
}
//在L中第i个位置之前插入新的数据元素e，链表的长度加1
template<class Data>
bool LinkList<Data>::ListInsert(const int i, Data& e)
{
	//首先检验i值是否合法
	if (i<1 || i>this->length + 1)
		return false;
	//创建节点
	LNode<Data>* p = new LNode<Data>;
	if (!p)
	return false;
	p->data = e;
	//处理在尾部插入的情况
	if (i == length + 1)
	{
		this->tail.next = p;
		this->tail = p;
		this->length++;
		return true;
	}
	//处理其他情况
	LNode<Data> *q = this->head;
	//将指针挪到第i个结点上
	for (int j = 1;j < i;j++)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	this->length++;
	return true;
}
//删除L的第i个数据元素，链表的长度减1
template<class Data>
bool LinkList<Data>::ListDelete(const int i)
{
	//首先检验链表是否为空
	if (this->IsEmpty)
		return false;
	//其次检验i值是否合法
	if (i<1 || i>this.length)
		return false;
	//将指针移动到第i-1个元素上
	LNode<Data>* p = this->head;
	for (int j = 1;j < i;j++)
	{
		p = p->next;
	}
	//处理尾部被删除的情况
	if (i == this.length)
	{
		delete this->tail;
		this->length--;
		this->tail = p;
		this->tail.next = NULL;
		return true;
	}
	//此时p指向第i-1个元素，先暂时记录第i个元素
	LNode<Data>* q = p->next;
	p->next = q->next;
	delete q;
	this.legnth--;
	return true;
}