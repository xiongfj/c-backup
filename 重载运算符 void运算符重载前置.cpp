#include <iostream.h>

class Counter
{
public:
	Counter();
	~Counter() {cout << "我是析构函数";}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	void Increament() {++itsVal;}

	// 使用 ++i 实际上是调用了重载运算符函数！如果该函数的函数体为空，那么即使你 i++ 后什么也不会改变！
	void operator ++ () {--itsVal;}	// 重载什么运算符，下面的 i 就只能使用什么运算符！

private:
	int itsVal;
};

Counter::Counter():

itsVal(111)

{
	cout << "我是构造函数" <<endl;
}

int main()
{
	Counter i;
	cout << "The Value of i is " << i.GetItsVal() << endl;

	i.Increament();
	cout << i.GetItsVal() << endl;

	++i;		// 只能是 ++i 或 i++，不能是 --(除非重载的是--)。也不能用该运算式给其他东西赋值！
				//例：COunter a = ++i; 这是错误的！因为是 void operator
	cout << i.GetItsVal() << endl;

	return 0;
}