#include <iostream.h>

class Counter
{
public:
	Counter();
	~Counter() {}
	int GetItsVal() const {return itsVal;}
	void SetItaVal(int x) {itsVal = x;}
	const Counter& operator ++ ();

private:
	int itsVal;
};


Counter::Counter():

itsVal(111)

{};

const Counter& Counter::operator ++ ()	// 去掉引用也可以，不过返回的是对象，发生对象传递，会调用赋值构造函数
{
	++itsVal;
	return *this;	// this 指针式指向对象的
}

int main()
{
	Counter i;
	cout << i.GetItsVal() << endl;

	++i;
	cout << i.GetItsVal() << endl;

	Counter a = ++i;
	cout << i.GetItsVal() << endl;
	return 0;
}
