#include "Stack.h"
template<class Data>
Stack<Data>::Stack(int len)
{
	//初始化
	elem = new Data[len];
	length = 0;
	stacksize = len;
}
template<class Data>
Stack<Data>::Stack(Stack& L)
{
	//拷贝构造函数
	this->elem = new Data[L.stacksize];
	//遍历复制
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
	//销毁数组
	if (this.elem)
	{
		delete elem;
	}
}
//置为空栈
template<class Data>
void Stack<Data>::ClearStack()
{
	this->length = 0;
}
//栈是否为空
template<class Data>
bool Stack<Data>::IsEmpty()
{
	if (this->length)
		return  false;
	return  true;

}
//返回栈元素个数
template<class Data>
int Stack<Data>::StackLength()
{
	return this->length;
}
//e取栈顶元素
template<class Data>
bool Stack<Data>::GetTop(Data &e)
{
	if (this->length == 0)
		return false;
	e=this->elem[this->length - 1];
	return true;
}
//入栈
template<class Data>
bool Stack<Data>::Push(Data e)
{
	if (this->length == this->stacksize)
		return false;
	this->elem[this.length] = e;
	return true;
}
//出栈
template<class Data>
bool Stack<Data>::Pop()
{
	if (this->length == 0)
		return false;
	this->length--;
	return true;
}
