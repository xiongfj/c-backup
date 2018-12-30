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
	return xx;//整个函数返回了一个对xx对象的引用，但是函数返回后对象xx已经不存在了，引用将变成空引用，会出现意想不到的结果!!!
}