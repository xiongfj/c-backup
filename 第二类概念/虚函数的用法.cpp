#include <iostream.h>
class Mammal
{
public:
	Mammal():itsAge(1){cout <<"M的构造函数\n";}
	virtual~Mammal(){cout <<"M的析构函数\n";}
    void Move()const{cout <<"M的move\n";}
	virtual void Speak()const{cout <<"M的声音\n";}
protected:
	int itsAge;
};
class Dog:public Mammal
{
public:
	Dog(){cout <<"dog的构造函数\n";}
	virtual ~Dog(){cout <<"dog的析构函数\n";}
	void WagTail(){cout <<"WagTail\n";}
	void Speak()const{cout <<"dog的声音\n";}
	void Move()const{cout <<"dog的move\n";}
};

int main()
{
	Mammal* p=new Dog;//也会调用两个构造函数//但是函数结束时不会调用析构函数。。
	p->Move();//因为基类的Move前没有virtual，所以不会跳过，最后调用了Mammal的Move
	p->Speak();//最终调用的是Dog的Speak()
	return 0;
}