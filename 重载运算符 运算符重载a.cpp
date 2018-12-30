#include <iostream.h>

class Cat
{
	double re, im;	// 复数

public:
	Cat()	{ cout << "Cat构、\n"; }
	~Cat()	{ cout << "Cat析、\n"; }
	Cat( double r, double i ):	re(r), im(i)	{}
	Cat operator + ( Cat& );	// + 号是二元运算符，由于是成员函数，当前对象代表一元，参数代表一元
	Cat operator * ( Cat& );	// 二元

	double getre()	{ return re; }
	double getim()	{ return im; }

	void setre( double r )	{ re = r; }
	void setim( double i )	{ im = i; }
};


// 以引用为参数可以避免调用复制构造函数 和 析构函数
// 如果不是引用参数的话，com 的作用域结束后会调用析构函数，但不会调用构造函数，它是作为传递的对象。
Cat Cat::operator + ( Cat& com )
{
	Cat temp1;

	temp1.setre( re + com.getre() );
	temp1.setim( im + com.getim() );

	return temp1;
}


// a * b，this 就是指向 a 的指针。com 就是 b 的引用。貌似有问题，a 自身也被改变了!!!
Cat Cat::operator * ( Cat& com )
{
	this->setre( re * com.getre() );
	this->setim( im * com.getim() );

	return *this;
}


// 在类外重载二元运算符
// 由于不是成员函数，没有对象，所以必须要两个参数。
Cat operator - (Cat& a, Cat& b)
{
	Cat temp3;

	temp3.setre( a.getre() - b.getre() );
	temp3.setim( a.getim() - b.getim() );

	return temp3;
}


void main()
{
	// 完整定义对象的写法，a/b 对象的定义调用带两个 double 参数的构造函数，不调用默认构造函数，程序结束还是会调用析构函数的。
	Cat a = Cat(1, 2);
	Cat b(2, 4);

	// 此时定义的 c、d 不会调用构造函数，因为它们不是使用构造函数构造的。但程序结束时会调用析构函数
	// 由于 + 重载运算符中创建了临时对象，所以使用 + 会调用构造函数，对象返回作用域结束又调用析构函数
	// 而 * 重载运算符使用的是指向 a 的隐含指针 this，此时的 a 就是当前对象实例。可以省去多余的调用！！
	Cat c = a + b;
	Cat d = a.operator * (b);	// 显式的写法。
	cout << c.getre() << "-" << c.getim() << endl;
	cout << d.getre() << "-" << d.getim() << endl;

	c = a + Cat(1, 2);	// 调用了构造函数，所以也会调用一次析构函数。事实上该处调用了三次析构函数，不知道为啥
	cout << c.getre() << "-" << c.getim() << endl;

	Cat e = b - a;	// 与 Cat e = operator - (b, a); 同义
	cout << e.getre() << "-" << e.getim() << endl;
}