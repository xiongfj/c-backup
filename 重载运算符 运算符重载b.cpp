#include <iostream.h>

class Cat
{
	int re, im;

public:
	Cat()	{ cout << "Cat构、\n"; }
	~Cat()	{ cout << "Cat析、\n"; }
	Cat( int r, int i ):	re(r), im(i)	{}

	// 无返回类型的成员函数只有一个参数也可以重载二元运算符，因为有对象！
	// 而在类外重载运算符，如果没返回类型，只有一个参数，是无法重载二元运算符的。
	void operator ++ ();			// 一元运算符
	Cat  operator ++ (int);				// 后置++
	void operator += ( Cat& );		// 二元运算符

	int getre()	{ return re; }
	int getim()	{ return im; }

	void set( int r, int i)	{ re = r; im = i; }
};


// 重载的是前置运算符
void Cat::operator ++ ()
{
	re++;
	im++;
}

/* 上面的重载前置运算符也可以写成这样
Cat Cat::operator ++ ()
{
	re++;
	im++;

	return *this;
}
*/


// 后置++
// int 只是为了区别上面的 void
Cat Cat::operator ++ (int a)
{
	Cat temp(*this);	// 自加前把值赋给 temp

	re++;
	im++;

	return temp;
}




// a += b;	 等同于 a.operator += (b);
// this 指针指向当前对象 a
// 由于没有返回值，不能将 a+=b 作为参数
// 因为 a+=b 整个式子根本就没值
// 返回 *this 的引用才可以
// 其他运算符也类似

void Cat::operator += ( Cat& com )
{
	// 此时直接访问 im 与 this->getim() 都是同一意思
	// this 指向当前对象，im 的值就是当前对象的值
	int er = this->getre() + com.getre();
	int mi = im			   + com.getim();

	this->set(er, mi);
}


void main()
{
	Cat a = Cat(1, 2);
	Cat b(2, 4);

	a += b;	// 等同于 a.operator += (b);
	cout << a.getre() << "-" << a.getim() << endl;

	++a;
	cout << a.getre() << "-" << a.getim() << endl;
	
}