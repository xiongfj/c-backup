#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();
};
SimpleCat::SimpleCat()
{
	cout <<"构造函数---!\n";
}
SimpleCat::SimpleCat(SimpleCat&)
{
	cout <<"复制构造函数...........!\n";
}
SimpleCat::~SimpleCat()
{
	cout <<"析构函数iiiiiiiiii\n";
}
SimpleCat functionone(SimpleCat theCat);
SimpleCat *functiontwo(SimpleCat *theCat);
int main()
{
	SimpleCat first;//调用构造函数
	functionone(first);//采用值传递方式给functionone传递了对象first的拷贝过去(functionone里面就有个第一个拷贝的对象first，调用了复制构造函数!
	functiontwo(&first);//采取引用传递的方式不会创建拷贝也不会调用任何函数!!!
	return 0;//函数结束，first对象作用域结束，调用析构函数
}
SimpleCat functionone(SimpleCat theCat)
{
	return theCat;//采取值传递的方式返回SimpleCat对象，建立first的第二个拷贝返回给函数，调用复制构造函数
}//调用该函数产生了两个拷贝，这两个拷贝的作用域结束的时候用调用了两次析构函数!!

SimpleCat *functiontwo(SimpleCat *theCat)
{
	return theCat;
}


