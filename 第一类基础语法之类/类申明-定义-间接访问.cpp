#include <iostream.h>
class Cat           //类申明
{
public:             //下面变成公有
	inline void GetAge(int);//要成为内嵌，只要申明或定义的时候再最前面加上inline即可，或者两处都加，都不会出现错误
	int SetAge();
	void Meow();    //打酱油？
private:        //公有到此结束，下面的变成私有
	int itsAge;
};
void Cat::GetAge(int a)   //类函数的定义
{
	itsAge=a;
}
int Cat::SetAge()
{
	return itsAge;
}
void Cat::Meow()
{
	cout <<"Meow: \n";
}
int main()
{
	Cat x,y;//也可以这样定义两个不同的对象
	x.GetAge(5);//访问函数的写法
	y.GetAge(6);
	x.Meow();
	cout <<"x is:"<<x.SetAge()<<"years old \n";//这两行cout分别输出的是对象x中和对象y中的iteAge
	cout <<"y is:"<<y.SetAge()<<endl;//必须使用对象!就是因为iteAge在不同的对象中有不同的值!
	x.Meow();
	return 0;
}