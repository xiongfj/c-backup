#include <iostream.h>

class Counter
{
public:
	Counter();
	~Counter(){}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	const Counter& operator ++ ();		// ++i
	const Counter operator ++ (int);	// i++ 参数用于区别 前置++ 而已, 不使用

private:
	int itsVal;
};


Counter::Counter():

itsVal(0)

{}


// 前置运算的实现
const Counter& Counter::operator ++ ()	// 返回引用，避免了多余的函数调用
{
	++ itsVal;
	return *this;
}



// 后置运算的实现
const Counter Counter::operator ++ (int x)	// 此时不能返回引用或指针，因为返回的是临时对象。返回之后对象都不存在了你怎么引用呢？
{
	Counter temp(*this);	// 这是另一种赋值写法！相当于 Counter temp = *this !
	++itsVal;
	return temp;
}


void main()
{
	Counter i;
	cout << i.GetItsVal() << endl;

	Counter a = ++i;
	cout << a.GetItsVal() << endl;

	a = i++;	// 只要你定义了后置，系统会自动调用对应的函数！
	cout << a.GetItsVal() << endl;
}