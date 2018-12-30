#include <iostream.h>
class Mammal
{
public:
	void Move()const{cout <<"MMMMMMM\n";}
	void Move(int a)const
	{
		cout <<a<<"MMMM的重载函数\n";
	}
protected:
	int itsAge;
};
class Dog:public Mammal
{
public:
	void Move()const;
};
void Dog::Move()const
{
	cout <<"dog的move\n";
	Mammal::Move(100);//访问隐藏的函数的写法
}
int main()
{
	Mammal xx;
	Dog yy;
	yy.Move();
	xx.Move(123);
	yy.Mammal::Move(456);//在需要访问的函数前加上它的类名+两个冒号。。。
	return 0;
}
