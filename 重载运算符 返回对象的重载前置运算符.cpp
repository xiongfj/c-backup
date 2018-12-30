#include <iostream.h>

class Counter
{
public:

	Counter();
	Counter(int x) {itsVal = x;}
	~Counter(){}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	void Increment() {++itsVal;}
	Counter operator ++ ();

private:

	int itsVal;
};

Counter::Counter():

itsVal(0)

{
	cout << "我是构造函数";
}


// 返回一个对象，是 ++i 可以给其他对象赋值
Counter Counter::operator ++ ()
{
	++itsVal;

	Counter temp;
	temp.SetItsVal(itsVal);
	return temp;

	//return Counter(itsVal);	// 使用无名临时对象（前提是有使用值作为参量的重载构造函数）。该句可换成上面的三行
					// 有一点相同：该函数返回的都是临时对象，在返回后这些对象就不存在了！所以该函数的返回类型不能是引用！或指针！
}

int main()
{
	Counter i;
	cout << i.GetItsVal() << endl;

	i.Increment();
	cout << i.GetItsVal() << endl;

	++i;	// 如果 operator() 的函数体有定义新对象，那么就会调用构造函数
	cout << i.GetItsVal() << endl;

	Counter a = ++i;	// 有返回类型的 operator() 可以讲对象赋值给对象，相当于 ++i 返回类型为 Counter
						// 此时定义的 a 同时赋值，不会调用构造函数，分开才会调用。

						// ++i 换成 i++ 也是一样的 a.GetItsVal() = 3;
						// 因为重载运算符函数 operator() 只给出了前置 ++i，没有给出后置 i++(即应该还有一个重载函数，它的函数体是先取 i，后 ++i，才行)
	cout << a.GetItsVal() << endl;
	cout << i.GetItsVal() << endl;

	return 0;
}