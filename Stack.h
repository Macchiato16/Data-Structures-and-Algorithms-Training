#pragma once
//栈存储空间的默认初始分配量
#define STACK_INIT_SIZE 20
//栈扩容时的增加量
#define STACK_INCREMENT 5
template<class Data>
class Stack
{
private:
	Data* elem; /* 存储空间基址 */
	int length; /* 当前长度 */
	int stacksize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
public:
    //构造函数，产生一个空的栈
	Stack(int len = STACK_INIT_SIZE);
	//拷贝构造函数
	Stack(Stack& L);
	//析构函数
	~Stack();
	//置为空栈
	void ClearStack();
	//栈是否为空
	bool IsEmpty();
	//返回栈数据元素个数
	int StackLength();
	//e取栈顶元素
	bool GetTop(Data &e);
	//入栈
	bool Push(Data e);
	//出栈
	bool Pop();

};

