#include <iostream.h>

class A
{
public:
	virtual void Speak() const	{cout <<"aspeak、\n";}
private:
	int a;
};


class B:public A
{
public:
	void Speak() const {cout << "bspeak、\n";}	// 覆盖，有可能基类访问
private:
	int b;
};


void main()
{
	// 原函数有 const 申明函数指针时也必须有。。
	// *p 将成员 A 的一部分，类似于成员，所以要用指针或对象获取该函数指针所指向的函数。
	void (A::*p)() const;

	A* pa = new B;
	p = A::Speak;

	A aa;

	// pa->*p 获取 *p 指向的函数、()调用
	(pa->*p)();

	// 对象访问永远访问的是本类
	(aa.*p)();

}