#include<iostream.h>
class Mammal
{
public:
	Mammal(){cout <<"我是Mm构造函数";}
	virtual ~Mammal(){cout <<"析构函数";}
	virtual void Speak()const{cout<<"我是M的Speak";}
};
class dog:public Mammal
{
public:
	void Speak()const{cout <<"我是dog的Speak";}
};
void main()
{
	Mammal xx;
	xx.Speak(); //m的
	cout<<endl;
	
	Mammal* p=new Mammal;
	p->Speak(); //m的
	cout<<endl;
	
	(*p).Speak(); //m的
	cout<<endl;
	
	Mammal* p2=new dog;
	p2->Speak();  //dog的
	cout<<endl;
	
	(*p2).Speak(); //dog的
	
	Mammal& r1=*p2;
	cout <<endl;
	
	r1.Speak();  //dog的，引用也可以访问派生类类的函数
}
