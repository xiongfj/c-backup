#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(){}
	~SimpleCat(){}
	void SetAge(int age){itsAge=age;}
	int GetAge(){return itsAge;}

private:
	int itsAge;
	
};
SimpleCat& thefunction(SimpleCat& a);
int main()
{
	SimpleCat xx;
	thefunction(xx);
	int age=xx.GetAge();
	cout <<age<<endl;
	return 0;
}
SimpleCat& thefunction(SimpleCat& a)
{
	a.SetAge(122);
	return a;//���ص�a�ǶԶ���xx�����á������ʲ�����ֿ����ã���Ϊ���÷��غ�xx������!!
}



