#include<iostream.h>
class Mammal
{
public:
	Mammal(){cout <<"����Mm���캯��";}
	virtual ~Mammal(){cout <<"��������";}
	virtual void Speak()const{cout<<"����M��Speak";}
};
class dog:public Mammal
{
public:
	void Speak()const{cout <<"����dog��Speak";}
};
void main()
{
	Mammal xx;
	xx.Speak(); //m��
	cout<<endl;
	
	Mammal* p=new Mammal;
	p->Speak(); //m��
	cout<<endl;
	
	(*p).Speak(); //m��
	cout<<endl;
	
	Mammal* p2=new dog;
	p2->Speak();  //dog��
	cout<<endl;
	
	(*p2).Speak(); //dog��
	
	Mammal& r1=*p2;
	cout <<endl;
	
	r1.Speak();  //dog�ģ�����Ҳ���Է�����������ĺ���
}
