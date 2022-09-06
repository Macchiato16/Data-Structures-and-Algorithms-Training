#include "Stack.h"
template<class Data>
Stack<Data>::Stack(int len)
{
	//��ʼ��
	elem = new Data[len];
	length = 0;
	stacksize = len;
}
template<class Data>
Stack<Data>::Stack(Stack& L)
{
	//�������캯��
	this->elem = new Data[L.stacksize];
	//��������
	for (int i = 0;i < L.length;i++)
	{
		this->elem[i] = L.elem[i];
	}
	this->length = L.length;
	this->stacksize = L.stacksize;
}
template<class Data>
Stack<Data>::~Stack()
{
	//��������
	if (this.elem)
	{
		delete elem;
	}
}
//��Ϊ��ջ
template<class Data>
void Stack<Data>::ClearStack()
{
	this->length = 0;
}
//ջ�Ƿ�Ϊ��
template<class Data>
bool Stack<Data>::IsEmpty()
{
	if (this->length)
		return  false;
	return  true;

}
//����ջԪ�ظ���
template<class Data>
int Stack<Data>::StackLength()
{
	return this->length;
}
//eȡջ��Ԫ��
template<class Data>
bool Stack<Data>::GetTop(Data &e)
{
	if (this->length == 0)
		return false;
	e=this->elem[this->length - 1];
	return true;
}
//��ջ
template<class Data>
bool Stack<Data>::Push(Data e)
{
	if (this->length == this->stacksize)
		return false;
	this->elem[this.length] = e;
	return true;
}
//��ջ
template<class Data>
bool Stack<Data>::Pop()
{
	if (this->length == 0)
		return false;
	this->length--;
	return true;
}
