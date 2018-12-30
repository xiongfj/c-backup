#include <iostream.h>
class Mammal
{
public:
	Mammal(){cout <<"M构造函数\n";}
	~Mammal(){cout <<"M析构函数\n";}
	void Speak()const{cout <<"M的声音\n";}
protected:
	int itsAge;
};
class Dog:public Mammal
{
public:
	Dog(){cout <<"dog的构造函数\n";}
	~Dog(){cout <<"dog的析构函数\n";}
	void Speak()const{cout <<"我是dog的speak!!\n";}
private:
	int weight;
};

int main()
{
	Mammal xx;//类Mammal上面没有基类，所以只调用M的构造函数
	Dog yy;
	xx.Speak();//Mammal的对象访问的函数是Mammal里面的..
	yy.Speak();//Dog的对象访问的这个speak是Dog里面的，
	return 0;
}
