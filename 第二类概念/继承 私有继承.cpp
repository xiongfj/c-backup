#include <iostream.h>


class A
{
public:
	A()		{ cout << "我被调用了"; }
	~A()	{}
	void set( int age )		{ itsage = age; }
	int getage()	{ return itsage; }
	void speaka()	{ cout << "我被使用了\n"; }

private:
	int itsage;
};

class B : private A
{
public:
	void speak()	{ speaka(); }		// 只有在函数体内才能访问基类的函数!!!
	int get()		{ return age; }

private:
	int age;
};


void main()
{
	B b;
	b.speak();

	//b.speaka();	错误！私有继承而来的类的对象不能直接访问基类的函数!!!
}