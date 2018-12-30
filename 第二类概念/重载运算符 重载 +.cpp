#include <iostream.h>

class Counter
{
public:
	Counter();
	Counter(int a);
	~Counter() {}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	Counter operator + (const Counter&);	// 双目运算符需要使用参量。单目运算符不需要使用参量，但是可以有参量。

private:
	int itsVal;
};

Counter::Counter(int a)
{
	itsVal = a;
}

Counter::Counter()
{
	itsVal = 0;
}


Counter Counter::operator + (const Counter& rhs)
{
	return Counter(itsVal + rhs.GetItsVal());
}


void main()
{
	Counter one(2), two(3), three;
	three = one + two;	// 总之，你想对对象进行什么运算，都要在重载运算符函数体里面定义！！

	cout << one.GetItsVal() << endl;
	cout << two.GetItsVal() << endl;
	cout << three.GetItsVal() << endl;
}