#include <iostream.h>
class Mammal
{
public:
	Mammal():itsAge(1){cout <<"M�Ĺ��캯��\n";}
	virtual~Mammal(){cout <<"M����������\n";}
    void Move()const{cout <<"M��move\n";}
	virtual void Speak()const{cout <<"M������\n";}
protected:
	int itsAge;
};
class Dog:public Mammal
{
public:
	Dog(){cout <<"dog�Ĺ��캯��\n";}
	virtual ~Dog(){cout <<"dog����������\n";}
	void WagTail(){cout <<"WagTail\n";}
	void Speak()const{cout <<"dog������\n";}
	void Move()const{cout <<"dog��move\n";}
};

int main()
{
	Mammal* p=new Dog;//Ҳ������������캯��//���Ǻ�������ʱ�������������������
	p->Move();//��Ϊ�����Moveǰû��virtual�����Բ�����������������Mammal��Move
	p->Speak();//���յ��õ���Dog��Speak()
	return 0;
}