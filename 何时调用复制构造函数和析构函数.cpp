#include <iostream.h>
class DOG
{
	
};
class Cat
{
public:
	Cat(int a);//申明构造函数
	Cat(Cat&){cout <<"复制构造函数------\n";}
	~Cat();//申明析构函数
	Cat function(Cat a){return a;}//值传递方式返回了一个对象，创建了一个拷贝，调用了复制构造函数；
	//函数结束，a和a的拷贝作用域结束，调用了两次析构函数
	int GetAge();
	void SetAge(int a);
	void Meow();
private:
	DOG dog;
	int itsAge;
};


Cat::Cat(int b)//构造函数的定义.前面不能加任何返回值类型(int void ...)!
{
	itsAge=b;
}

Cat::~Cat()//析构函数，无参量，无返回值,同样不能加返回值类型!!
{
	cout <<"析构函数!!!!!!!!\n";
}

int Cat::GetAge()////有返回值的一个成员函数，为了把值返回到main函数中
{
	return itsAge;
}
void Cat::SetAge(int c)//无返回值的成员函数，用于对成员参数赋值
{
	itsAge=c;
}
void Cat::Meow()
{
	cout <<"Meow: \n";
}

int main()
{
	Cat X(5);//申明对象的同时，也调用了构造函数Cat(int b)! Cat(int b)又对成员参量初始化（赋值）。
	X.Meow();//上面一步骤省去了一行X.SetAge(5);
	cout <<"X cat is: "<<X.GetAge()<<"years old! \n";
	X.Meow();
	X.SetAge(7);//重新给itsAge赋值,不能直接调用构造函数!X.Cat(7)错误的写法。Cat X(7)同样是错误的写法！不能定义两个相同的对象，把x换成y或者其他即可
	cout <<"now X cat is: "<<X.GetAge()<<"years old! \n";
	X.function(X);//值传递方式传递了一个对象，创建了一个拷贝，调用了复制构造函数
	return 0;
}//函数结束前或者该类的对象作用域结束，会自动调用析构函数，即使你显式的X.~Cat();调用了，程序还是会在调用一次!