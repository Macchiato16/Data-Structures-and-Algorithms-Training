#include "LinkList.h"
template<class Data>
LinkList<Data>::LinkList()
{
	//����һ��ͷ�ڵ�
	this->head = new LNode;
	this->tail = this->head;
	this->length = 0;
}
template<class Data>
LinkList<Data>::~LinkList()
{
	LNode<Date>* p = this->head;
	LNode<Date>* q = this->head->next;
	//����ɾ��
	while (q)
	{
		p = q;
		q = p->next;
		delete p;
	}
	//�ٽ�ͷ�ڵ�ɾ��
	delete this->head;
}
//�����Ƿ�Ϊ��
template<class Data>
bool LinkList<Data>::IsEmpty()
{
	if (this->length == 0)
		return true;
	return false;
}
//�������
template<class Data>
void LinkList<Data>::ClearList()
{
	LNode<Date> *p = this->head;
	LNode<Date> *q = this->head->next;
	//����ɾ��
	while (q)
	{
		p = q;
		q = p->next;
		delete p;
	}
	//��ͷ�ڵ�ָ���,βָ��ָ��ͷ�ڵ�,�����ȱ�Ϊ0
	this->head->next = NULL;
	this->tail = this->head;
	this->length = 0;
}
//����������Ԫ�ظ���
template<class Data>
int LinkList<Data>::ListLength()
{
	return this->length;
}
//ʹ��e��ȡ��i��Ԫ�ص�ֵ
template<class Data>
bool LinkList<Data>::GetElem(const int i, Data &e)
{
	//���ȼ���iֵ�Ƿ�Ϸ�
	if (i<1 || i>this.length)
	   return false;
	//��ָ���ƶ�����i��Ԫ����
	LNode<Data>* p = this->head;
	for (int j = 0;j < i;j++)
	{
		p = p->next;
	}
	//��ʱpָ���i��Ԫ��
	e = p->data;
	return true;
}
/*����L�е�1����e��ȵ�����Ԫ�ص�λ��
������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
template<class Data>
int LinkList<Data>::LocateElem(Data& e)
{
	//�ȿ������Ƿ�Ϊ��
	if (this->length == 0)
		return 0;
	//����Ϊ��ʱ
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
/*����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
template<class Data>
int LinkList<Data>::LocateElem(Data& e, bool(*compare)(Data& a, Data& b))
{
	//�ȿ������Ƿ�Ϊ��
	if (this->length == 0)
		return 0;
	//����Ϊ��ʱ
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
//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����ַ,�������ʧ��
template<class Data>
bool LinkList<Data>::PriorElem(Data cur_e, Data* pre_e)
{
	//�ȿ��������Ƿ����1
	if (this->length<=1)
		return false;
	//����c���ȴ���1ʱ���ӵڶ�����ʼ����
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
	//��������ֱ�ӷ��ش���
	return false;
}
//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��,�������ʧ��
template<class Data>
bool LinkList<Data>::NextElem(Data cur_e, Data* next_e)
{
	//�ȿ��������Ƿ�С�ڵ���1
	if (this->length <= 1)
		return false;
	//����c���ȴ���1ʱ���ӵ�1����ʼ����
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
	//��������ֱ�ӷ��ش���
	return false;
}
//�������β�����Ԫ��e,����ĳ��ȼ�1
template<class Data>
bool LinkList<Data>::ListAppend(Data& e)
{
	//�����ڵ�
	LNode<Data> *p = new LNode<Data>;
	if (!p)
	return false;
	p->data = e;
	//β������Ԫ��
	this->tail.next = p;
	this->tail = p;
	this->length++;
	return true;
}
//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e������ĳ��ȼ�1
template<class Data>
bool LinkList<Data>::ListInsert(const int i, Data& e)
{
	//���ȼ���iֵ�Ƿ�Ϸ�
	if (i<1 || i>this->length + 1)
		return false;
	//�����ڵ�
	LNode<Data>* p = new LNode<Data>;
	if (!p)
	return false;
	p->data = e;
	//������β����������
	if (i == length + 1)
	{
		this->tail.next = p;
		this->tail = p;
		this->length++;
		return true;
	}
	//�����������
	LNode<Data> *q = this->head;
	//��ָ��Ų����i�������
	for (int j = 1;j < i;j++)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	this->length++;
	return true;
}
//ɾ��L�ĵ�i������Ԫ�أ�����ĳ��ȼ�1
template<class Data>
bool LinkList<Data>::ListDelete(const int i)
{
	//���ȼ��������Ƿ�Ϊ��
	if (this->IsEmpty)
		return false;
	//��μ���iֵ�Ƿ�Ϸ�
	if (i<1 || i>this.length)
		return false;
	//��ָ���ƶ�����i-1��Ԫ����
	LNode<Data>* p = this->head;
	for (int j = 1;j < i;j++)
	{
		p = p->next;
	}
	//����β����ɾ�������
	if (i == this.length)
	{
		delete this->tail;
		this->length--;
		this->tail = p;
		this->tail.next = NULL;
		return true;
	}
	//��ʱpָ���i-1��Ԫ�أ�����ʱ��¼��i��Ԫ��
	LNode<Data>* q = p->next;
	p->next = q->next;
	delete q;
	this.legnth--;
	return true;
}