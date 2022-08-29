#pragma once
//����Ľڵ�
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
//����
template<class Data>
class LinkList
{
private:
	//ͷָ���βָ��
	LNode<Data>* head, tail;
	//����ĳ��ȣ�������ͷ�ڵ㣩
	int length;
public:
	LinkList();
	~LinkList();
	//�����Ƿ�Ϊ��
	bool IsEmpty();
	//�������
	void ClearList();
	//����������Ԫ�ظ���
	int ListLength();
	//ʹ��e��ȡ��i��Ԫ�ص�ֵ
	bool GetElem(const int i, Data& e);
	/*����L�е�1����e��ȵ�����Ԫ�ص�λ��
	������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
	int LocateElem(Data& e);
	/*����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
	������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
	int LocateElem(Data& e, bool(*compare)(Data& a, Data& b));
	//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����ַ,�������ʧ��
	bool PriorElem(Data cur_e, Data* pre_e);
	//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��,�������ʧ��
	bool NextElem(Data cur_e, Data* next_e);
	//��˳���β�����Ԫ��e,L�ĳ��ȼ�1
	bool ListAppend(Data& e);
	//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
	bool ListInsert(int i, Data& e);
	//ɾ��L�ĵ�i������Ԫ�أ�L�ĳ��ȼ�1
	bool ListDelete(int i);

};


