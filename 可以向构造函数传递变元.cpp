#include <iostream.h>
class A
{
public:
	A(int a);
	~A(){}
	void setage(int age){itsage=age;}
	int getage()const{return itsage;}
private:
	int itsage;
};
A::A(int a)
{
	itsage=a*3;
}
int main()
{
	int number;
	cout <<"����һ������:";
	cin >>number;
	A x(number);
	cout <<x.getage()<<endl;
	return 0;
}


