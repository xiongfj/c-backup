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
	cout << &a1 << endl;					// 修改前指针a自身地址为 0x0012ff70
	Change(a1);
	cout << a1->x << endl << &a1 << endl;		// 调用 Change() 后依然为 0x0012ff70
	cout << &(*a1) << endl;		// new A(10) 的地址，非指针自身的地址！！ 
}


// 指针传递过来的时候，创建了一个地址为 0x0012ff14 的指针 a
// 将 a1 指向的内容地址拷贝到 a 中，
// 两个不同地址的指针指向同一块内容地址数据~！！！！

void Change( A* a )
{
	cout << &a << endl;			// 指针自身地址为 0x0012ff14
	cout << &(*a) << endl;		// 指针对应的数据的地址！！！！

//	a = &aa;				// 不会改变 main 中 a 的指向！！
//	a = new A(111);			// 也不会！！！

//	a->x = 110;				// 也不会！！改变的只是 main 中 a 指向的内容
}
