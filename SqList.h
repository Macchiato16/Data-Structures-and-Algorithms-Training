#pragma once
#include"config.h"
//˳���洢�ռ�ĳ�ʼ������
#define LIST_INIT_SIZE 20
//˳�������ʱ��������
#define LIST_INCREMENT 5
//˳���ʵ��
template<class Data>
class SqList
{
private:
	Data* elem; /* �洢�ռ��ַ */
	int length; /* ��ǰ���� */
	int listsize; /* ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) */
	//Ĭ�Ϲ��캯��������һ���յ�˳���
	SqList();
	//�������캯��
	SqList(SqList& L);
	//��������������˳���
	~SqList();
public:
	//����Ϊ�㷨
	//����˳���
	void DestroyList();
	//��Ϊ�ձ�
	void ClearList();
	//˳����Ƿ�Ϊ��
	bool IsEmpty();
	//����˳�����Ԫ�ظ���
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
	//��˳���β�����Ԫ��e,˳���ĳ��ȼ�1
	bool ListAppend(Data& e);
	//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��˳���ĳ��ȼ�1
	bool ListInsert(const int i, Data& e);
	//ɾ��L�ĵ�i������Ԫ�أ�˳���ĳ��ȼ�1
	bool ListDelete(const int i);

};


