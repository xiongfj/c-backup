#include <iostream.h>

class A
{
public:
	virtual void Speak() const	{cout <<"aspeak��\n";}
private:
	int a;
};


class B:public A
{
public:
	void Speak() const {cout << "bspeak��\n";}	// ���ǣ��п��ܻ������
private:
	int b;
};


void main()
{
	// ԭ������ const ��������ָ��ʱҲ�����С���
	// *p ����Ա A ��һ���֣������ڳ�Ա������Ҫ��ָ�������ȡ�ú���ָ����ָ��ĺ�����
	void (A::*p)() const;

	A* pa = new B;
	p = A::Speak;

	A aa;

	// pa->*p ��ȡ *p ָ��ĺ�����()����
	(pa->*p)();

	// ���������Զ���ʵ��Ǳ���
	(aa.*p)();

}