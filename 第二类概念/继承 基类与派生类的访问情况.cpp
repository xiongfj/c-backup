#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=100;cout <<"Mammal的构造函数\n";}
	~Mammal(){cout <<"Mammal的析构函数\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}

	void Speak()const{cout <<"声音!!\n";}
	void Sleep()const{cout <<"zzz~zz~~~睡觉呢!!\n";}
protected:    //保护型成员对于该类的派生类是可见的
	int itsAge;
};

class Dog:public Mammal//只有派生的类可以访问基类的成员，没有基类可以访问派生类的成员!!
{
public:
	Dog(){itsBreed=golden;cout <<"Dog的构造函数\n";}
	~Dog(){cout <<"Dog的析构函数\n";}

	int GetBreed()const{return itsBreed;}
	void SetBreed(breed x){itsBreed=x;}
	int WagTail()const{return itsAge;}//派生类的成员函数内可以访问基类的保护型和公有成员，不能直接访问私有的(。。)!

private:
	breed itsBreed;
};
int main()
{
	Dog xx;      //只有派生类的对象可以访问基类的成员(非私有的成员，非构造，复制构造，析构)，而基类的对象则不能访问其所派生的类的成员(不管什么成员)
	xx.Speak();  //派生类Dog的对象可以访问Dog的基类的公有成员和保护型成员
	xx.WagTail();//如果xx换成Mammal xx,变成基类的对象，那么xx将不能访问WagTail()
	cout <<xx.GetAge()<<endl;
	cout <<xx.WagTail()<<endl;
//  Mammal yy;定义对象是调用函数的顺序为：Mammal的构造函数>Dog的构造函数>(对象作用域结束)>Dog的析构函数>Mammal的析构函数
	return 0;
}



