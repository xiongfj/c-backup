#include <iostream.h>
#include <conio.h>


class A
{
public:
	A( int a )	{ x = a; }
	A():	x(121)	{}
	int x;
};

void Change( A* a );

A aa;


void main()
{
	A* a1 = new A(10);
	cout << &a1 << endl;					// �޸�ǰָ��a�����ַΪ 0x0012ff70
	Change(a1);
	cout << a1->x << endl << &a1 << endl;		// ���� Change() ����ȻΪ 0x0012ff70
	cout << &(*a1) << endl;		// new A(10) �ĵ�ַ����ָ������ĵ�ַ���� 
}


// ָ�봫�ݹ�����ʱ�򣬴�����һ����ַΪ 0x0012ff14 ��ָ�� a
// �� a1 ָ������ݵ�ַ������ a �У�
// ������ͬ��ַ��ָ��ָ��ͬһ�����ݵ�ַ����~��������

void Change( A* a )
{
	cout << &a << endl;			// ָ�������ַΪ 0x0012ff14
	cout << &(*a) << endl;		// ָ���Ӧ�����ݵĵ�ַ��������

//	a = &aa;				// ����ı� main �� a ��ָ�򣡣�
//	a = new A(111);			// Ҳ���ᣡ����

//	a->x = 110;				// Ҳ���ᣡ���ı��ֻ�� main �� a ָ�������
}
