#include <iostream.h>
class Mammal
{
public:
	void Move()const{cout <<"MMMMMMM\n";}
	void Move(int a)const
	{
		cout <<a<<"MMMM�����غ���\n";
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
	cout <<"dog��move\n";
	Mammal::Move(100);//�������صĺ�����д��
}
int main()
{
	Mammal xx;
	Dog yy;
	yy.Move();
	xx.Move(123);
	yy.Mammal::Move(456);//����Ҫ���ʵĺ���ǰ������������+����ð�š�����
	return 0;
}
