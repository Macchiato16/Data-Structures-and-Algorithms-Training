#include "SqList.h"
template<class Data>
SqList<Data>::SqList()
{
	//初始化
	elem = new Data[LIST_INIT_SIZE];
	length = 0;
	listsize = LIST_INIT_SIZE;
}
template<class Data>
SqList<Data>::SqList(SqList& L)
{
	//拷贝构造函数
	this->elem = L.elem;
	this->length = L.length;
	this->listsize = L.listsize;
}
template<class Data>
SqList<Data>::~SqList()
{
	//销毁数组
	if (this.elem)
	{
		delete elem;
	}
}
//销毁顺序表
template<class Data>
void SqList<Data>::DestroyList()
{
	if (this.elem)
	{
		delete elem;
	}
}
//置为空表
template<class Data>
void SqList<Data>::ClearList()
{
	this->length = 0;
}
//顺序表是否为空
template<class Data>
bool SqList<Data>::IsEmpty()
{
	if (this->length)
		return  false;
	return  true;

}
//返回顺序表中元素个数
template<class Data>
int SqList<Data>::ListLength()
{
	return this->length;
}
//使用e获取第i个元素的值
template<class Data>
bool SqList<Data>::GetElem(const int i, Data& e)
{
	//首先检验i值是否合法
	if (i<1 || i>this.length)
		return false;
	e = elem[i - 1];
	return true;
}
/*返回L中第1个与e相等的数据元素的位序
	若这样的数据元素不存在，则返回值为0*/
template<class Data>
int SqList<Data>::LocateElem(Data& e)
{
	for (int i = 0;i < this.length;i++)
	{
		if (elem[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}
/*返回L中第1个与e满足关系compare()的数据元素的位序
	若这样的数据元素不存在，则返回值为0*/
template<class Data>
int SqList<Data>::LocateElem(Data& e, bool(*compare)(Data& a, Data& b))
{
	for (int i = 0;i < this.length;i++)
	{
		if (compare(elem[i], e))
		{
			return i + 1;
		}
	}
	return 0;
}
//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱地址,否则操作失败
template<class Data>
bool SqList<Data>::PriorElem(Data cur_e, Data* pre_e)
{
	for (int i = 1;i < this.length;i++)
	{
		if (elem[i] == cur_e)
		{
			pre_e = &elem[i - 1];
			return true;
		}
	}
	return false;
}
//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继地址,否则操作失败
template<class Data>
bool SqList<Data>::NextElem(Data cur_e, Data* next_e)
{
	for (int i = 0;i < this.length - 1;i++)
	{
		if (elem[i] == cur_e)
		{
			next_e = &elem[i + 1];
			return true;
		}
	}
	return false;
}
//在顺序表尾部添加元素e,顺序表的长度加1
template<class Data>
bool SqList<Data>::ListAppend(Data& e)
{
	//空间够时直接添加元素
	if (this->length < this->listsize)
	{
		elem[length] = e;
		++length;
		return true;
	}
	//顺序表分配空间不足时重新创建一个更大的顺序表
	Data* temp = new Data[this.listsize + LIST_INCREMENT];
	//空间分配失败
	if (!temp)
		return false;
	//空间分配成功,将原来数组数据拷贝过来
	for (int i = 0;i < length;i++)
	{
		temp[i] = this->elem[i];
	}
	//销毁原来的数组
	delete elem;
	//elem指向新数组
	elem = temp;
	//更改分配的空间大小
	this->listsize += LIST_INCREMENT;
		//空间够后继续添加
		elem[this.length] = e;
	  ++length;
	return true;
}
//在L中第i个位置之前插入新的数据元素e，顺序表的长度加1
template<class Data>
bool SqList<Data>::ListInsert(const int i, Data& e)
{
	//首先判断i值是否合法（1<=i<=length+1)
	if (i<1 || i>this->length + 1)
	{
		return false;
	}
	//其次判断顺序表是否已满
	if (this->length >= this->listsize)
	{
		//顺序表分配空间不足时重新创建一个更大的顺序表
		Data* temp = new Data[this.listsize + LIST_INCREMENT];
		//空间分配失败
		if (!temp)
			return false;
		//空间分配成功,将原来数组数据拷贝过来
		for (int i = 0;i < length;i++)
		{
			temp[i] = this->elem[i];
		}
		//销毁原来的数组
		delete elem;
		//elem指向新数组
		elem = temp;
		//更改分配的空间大小
		this->listsize += LIST_INCREMENT;
	}
	//条件适合插入元素,先将第i个位置及以后的元素往后挪一位
	for (int j = this.length - 1;j >= i - 1;j--)
	{
		this->elem[j + 1] = this->elem[j];
	}
	//将e放在第i个位置
	this->elem[i - 1] = e;
	//线性表长度+1
	++this->length;
	return true;
}
//删除L的第i个数据元素，顺序表的长度减1
template<class Data>
bool SqList<Data>::ListDelete(const int i)
{
	//首先判断i值是否合法（1<=i<=length+1)
	if (i<1 || i>this->length + 1)
	{
		return false;
	}
	//删除第i个元素，将第i个元素及以后的元素向前挪一位
	for (int j = i;j < this.length;j++)
	{
		this->elem[j - 1] = this->elem[j];
	}
	//长度减1
	--this->length;
	return true;

}
