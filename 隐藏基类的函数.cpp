#include <iostream.h>
class Mammal
{
public:
	void Move()const{cout <<"MMMMM\n";}//��dog���ǡ���
	void Move(int a)const{cout <<"M������\n";}//��dog���أ�dog�����޷�����������غ���
protected:
	int itsAge;
};

class Dog:public Mammal
{
public:
	void Move()const{cout <<"dog�ĺ���\n";}//������Move()�����������������غ�������!!
};
int main()
{
	Mammal xx;
	Dog yy;
	xx.Move();
	xx.Move(100);
	yy.Move();
	//yy.Move(200);//�޷�����
	return 0;
}
