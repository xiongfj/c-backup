#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(int age);
	~SimpleCat();
	void setage(int age){itsAge=age;}
	int getage()const{return itsAge;}
private:
	int itsAge;
};
SimpleCat::SimpleCat(int age)
{
	cout <<"调用的构造函数\n";
	itsAge=age;
}
SimpleCat::~SimpleCat()
{
	cout <<"调用了析构函数\n";
}
int main()
{
	cout <<"SimpleCat first。。\n";
	SimpleCat first(7);            //定义对象的同时会调用构造函数(只有这样定义的对象在函数结束时才会调用析构函数)
	cout <<first.getage()<<endl;

	cout <<"\n申明了一个对象指针。。\n";
	SimpleCat*p=new SimpleCat(9);   //带参数的构造函数的类的对象的创建，在自由存储区创建对象也对调用构造函数，但是函数结束时不会调用次对象的析构函数。。。
    cout <<p->getage()<<endl;
	cout <<"\ndelete p。。。\n";
	delete p;                   //释放指针指向的内存空间前，调用析构函数

	cout <<"对象first作用域结束，调用析构函数。。\n";
	return 0;                 //函数返回前，调用析构函数，自由存储区对象作用于结束不会调用析构函数。。。
}
