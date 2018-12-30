#include <iostream.h>

class A
{
public:
	friend class B;
	A()	{ cout <<"fdasf\n"; }
	int get()	{ return age; }
	void set( int a )	{ age = a; }

private:
	int age;
};


class B
{
public:
	B()	{ p = new A; }
	void geta()			{ cout << p->age; }	// 即使是私有的成员也可以直接访问!!!
	void seta( int v )	{ p->set(v); }		// 必须有 A 的接口才能访问(对象或指针)!!!有点像包容，但是包容不能直接访问私有成员!!!

private:
	A* p;
	int val;
};


void main()
{
	B b;
	b.seta( 100 );

//	b.get(); 错误，非继承不可以!!!

	b.geta();
}