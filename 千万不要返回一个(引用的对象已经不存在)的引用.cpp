#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(int age){itsAge=age;}
	~SimpleCat(){}
	int GetAge()const{return itsAge;}
private:
	int itsAge;
};
SimpleCat& function();
int main()
{
	SimpleCat& cat=function();
	int age=cat.GetAge();
	cout <<age<<endl;
	return 0;
}
SimpleCat& function()
{
	SimpleCat xx(888);
	return xx;//��������������һ����xx��������ã����Ǻ������غ����xx�Ѿ��������ˣ����ý���ɿ����ã���������벻���Ľ��!!!
}