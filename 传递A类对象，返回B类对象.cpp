#include <iostream.h>
class DOG
{
	
};
class Cat
{
public:
	Cat(){cout <<"构造函数------\n";}
	Cat(Cat&){cout <<"复制构造函数lllllllll\n";}
	~Cat(){cout <<"析构函数。。。。。\n";}
	DOG function(Cat a);
private:
	DOG dog;

};

DOG Cat::function(Cat a)
{
	return dog;//只调用了一次析构函数----x对象的拷贝作用域结束
}//返回其他对象（非Cat类的对象）好像不调用任何东东????
int main()
{
	Cat x;
	x.function(x);//只调用了一次复制构造函数
	return 0;
}
