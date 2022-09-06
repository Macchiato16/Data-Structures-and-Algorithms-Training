#pragma once
//ջ�洢�ռ��Ĭ�ϳ�ʼ������
#define STACK_INIT_SIZE 20
//ջ����ʱ��������
#define STACK_INCREMENT 5
template<class Data>
class Stack
{
private:
	Data* elem; /* �洢�ռ��ַ */
	int length; /* ��ǰ���� */
	int stacksize; /* ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) */
public:
    //���캯��������һ���յ�ջ
	Stack(int len = STACK_INIT_SIZE);
	//�������캯��
	Stack(Stack& L);
	//��������
	~Stack();
	//��Ϊ��ջ
	void ClearStack();
	//ջ�Ƿ�Ϊ��
	bool IsEmpty();
	//����ջ����Ԫ�ظ���
	int StackLength();
	//eȡջ��Ԫ��
	bool GetTop(Data &e);
	//��ջ
	bool Push(Data e);
	//��ջ
	bool Pop();

};

