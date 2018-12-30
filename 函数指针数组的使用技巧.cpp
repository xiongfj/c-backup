#include <iostream.h>

class A
{
public:
	void f1()	{cout <<"我是f1、\n";}
	void f2()	{cout <<"我是f2、\n";}
	void f3()	{cout <<"我是f3、\n";}
	void f4()	{cout <<"我是f4、\n";}
	void f5()	{cout <<"我是f5、\n";}
};

typedef void (A::*F) ();	// 定义一个函数指针类型;
void main()
{
	int f = 0;
	A a;

	F p[5] = {A::f1, A::f2, A::f3, A::f4, A::f5};

	while (true)
	{
		cout <<"输入你想调用的函数标号：1-5";
		cin >> f;

		if (f > 5 || f < 1)
			break;

		// 如此就可以根据输入选择调用哪个函数了，当然有其他方法实现这种功能，不过没有这种简洁明了。
		(a.*p[f - 1])();
	}
}
