#include "SqList.h"
template<class Data>
SqList<Data>::SqList()
{
	//��ʼ��
	elem = new Data[LIST_INIT_SIZE];
	length = 0;
	listsize = LIST_INIT_SIZE;
}
template<class Data>
SqList<Data>::SqList(SqList& L)
{
	//�������캯��
	this->elem = L.elem;
	this->length = L.length;
	this->listsize = L.listsize;
}
template<class Data>
SqList<Data>::~SqList()
{
	//��������
	if (this.elem)
	{
		delete elem;
	}
}
//����˳���
template<class Data>
void SqList<Data>::DestroyList()
{
	if (this.elem)
	{
		delete elem;
	}
}
//��Ϊ�ձ�
template<class Data>
void SqList<Data>::ClearList()
{
	this->length = 0;
}
//˳����Ƿ�Ϊ��
template<class Data>
bool SqList<Data>::IsEmpty()
{
	if (this->length)
		return  false;
	return  true;

}
//����˳�����Ԫ�ظ���
template<class Data>
int SqList<Data>::ListLength()
{
	return this->length;
}
//ʹ��e��ȡ��i��Ԫ�ص�ֵ
template<class Data>
bool SqList<Data>::GetElem(const int i, Data& e)
{
	//���ȼ���iֵ�Ƿ�Ϸ�
	if (i<1 || i>this.length)
		return false;
	e = elem[i - 1];
	return true;
}
/*����L�е�1����e��ȵ�����Ԫ�ص�λ��
	������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
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
/*����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
	������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
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
//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����ַ,�������ʧ��
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
//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̵�ַ,�������ʧ��
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
//��˳���β�����Ԫ��e,˳���ĳ��ȼ�1
template<class Data>
bool SqList<Data>::ListAppend(Data& e)
{
	//�ռ乻ʱֱ�����Ԫ��
	if (this->length < this->listsize)
	{
		elem[length] = e;
		++length;
		return true;
	}
	//˳������ռ䲻��ʱ���´���һ�������˳���
	Data* temp = new Data[this.listsize + LIST_INCREMENT];
	//�ռ����ʧ��
	if (!temp)
		return false;
	//�ռ����ɹ�,��ԭ���������ݿ�������
	for (int i = 0;i < length;i++)
	{
		temp[i] = this->elem[i];
	}
	//����ԭ��������
	delete elem;
	//elemָ��������
	elem = temp;
	//���ķ���Ŀռ��С
	this->listsize += LIST_INCREMENT;
		//�ռ乻��������
		elem[this.length] = e;
	  ++length;
	return true;
}
//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��˳���ĳ��ȼ�1
template<class Data>
bool SqList<Data>::ListInsert(const int i, Data& e)
{
	//�����ж�iֵ�Ƿ�Ϸ���1<=i<=length+1)
	if (i<1 || i>this->length + 1)
	{
		return false;
	}
	//����ж�˳����Ƿ�����
	if (this->length >= this->listsize)
	{
		//˳������ռ䲻��ʱ���´���һ�������˳���
		Data* temp = new Data[this.listsize + LIST_INCREMENT];
		//�ռ����ʧ��
		if (!temp)
			return false;
		//�ռ����ɹ�,��ԭ���������ݿ�������
		for (int i = 0;i < length;i++)
		{
			temp[i] = this->elem[i];
		}
		//����ԭ��������
		delete elem;
		//elemָ��������
		elem = temp;
		//���ķ���Ŀռ��С
		this->listsize += LIST_INCREMENT;
	}
	//�����ʺϲ���Ԫ��,�Ƚ���i��λ�ü��Ժ��Ԫ������Ųһλ
	for (int j = this.length - 1;j >= i - 1;j--)
	{
		this->elem[j + 1] = this->elem[j];
	}
	//��e���ڵ�i��λ��
	this->elem[i - 1] = e;
	//���Ա���+1
	++this->length;
	return true;
}
//ɾ��L�ĵ�i������Ԫ�أ�˳���ĳ��ȼ�1
template<class Data>
bool SqList<Data>::ListDelete(const int i)
{
	//�����ж�iֵ�Ƿ�Ϸ���1<=i<=length+1)
	if (i<1 || i>this->length + 1)
	{
		return false;
	}
	//ɾ����i��Ԫ�أ�����i��Ԫ�ؼ��Ժ��Ԫ����ǰŲһλ
	for (int j = i;j < this.length;j++)
	{
		this->elem[j - 1] = this->elem[j];
	}
	//���ȼ�1
	--this->length;
	return true;

}
