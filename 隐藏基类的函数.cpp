#include <iostream.h>
class Mammal
{
public:
	void Move()const{cout <<"MMMMM\n";}//被dog覆盖。。
	void Move(int a)const{cout <<"M的重载\n";}//被dog隐藏，dog对象无法访问这个重载函数
protected:
	int itsAge;
};

class Dog:public Mammal
{
public:
	void Move()const{cout <<"dog的函数\n";}//覆盖了Move()，隐藏了其所有重载函数！！!!
};
int main()
{
	Mammal xx;
	Dog yy;
	xx.Move();
	xx.Move(100);
	yy.Move();
	//yy.Move(200);//无法访问
	return 0;
}
