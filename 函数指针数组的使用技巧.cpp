#include <iostream.h>

class A
{
public:
	void f1()	{cout <<"����f1��\n";}
	void f2()	{cout <<"����f2��\n";}
	void f3()	{cout <<"����f3��\n";}
	void f4()	{cout <<"����f4��\n";}
	void f5()	{cout <<"����f5��\n";}
};

typedef void (A::*F) ();	// ����һ������ָ������;
void main()
{
	int f = 0;
	A a;

	F p[5] = {A::f1, A::f2, A::f3, A::f4, A::f5};

	while (true)
	{
		cout <<"����������õĺ�����ţ�1-5";
		cin >> f;

		if (f > 5 || f < 1)
			break;

		// ��˾Ϳ��Ը�������ѡ������ĸ������ˣ���Ȼ����������ʵ�����ֹ��ܣ�����û�����ּ�����ˡ�
		(a.*p[f - 1])();
	}
}
