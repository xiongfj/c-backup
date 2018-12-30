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
	return a;//返回的a是对对象xx的引用。。。故不会出现空引用，因为引用返回后xx还存在!!
}



