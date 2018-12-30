#include <iostream.h>

class BB
{
public:
	BB()
	{
		cout << "caonima" << endl;
		s = 100;
	}
	int s;
};

class AA
{
public:
	BB* pb;
	BB b;// 如果有其他类的对象，那么在创建 AA 的对象的时候会自动分配其成员对象的内存，即会调用那个对象的构造函数
};

void main()
{
	AA* pa = new AA();
	pa->pb = new BB();			// 程序不会自动分配类的成员指针的内存！！
	cout << pa->pb->s;

	AA a;		// 这样也会调用 BB 的构造函数，因为 AA 有成员对象是 BB 的对象。。。
	cout << a.b.s;
}