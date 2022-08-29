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
	LNode<Data>* p = this->head;
	while (i <= 0)
	{
		p = p->next;
		--i;
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

}
/*����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
template<class Data>
int LinkList<Data>::LocateElem(Data& e, bool(*compare)(Data& a, Data& b));
//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����ַ,�������ʧ��
template<class Data>
bool LinkList<Data>::PriorElem(Data cur_e, Data* pre_e);
//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��,�������ʧ��
template<class Data>
bool LinkList<Data>::NextElem(Data cur_e, Data* next_e);
//��˳���β�����Ԫ��e,L�ĳ��ȼ�1
template<class Data>
bool LinkList<Data>::ListAppend(Data& e);
//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
template<class Data>
bool LinkList<Data>::ListInsert(int i, Data& e);
//ɾ��L�ĵ�i������Ԫ�أ�L�ĳ��ȼ�1
template<class Data>
bool LinkList<Data>::ListDelete(int i);