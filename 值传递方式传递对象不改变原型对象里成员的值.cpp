#include <iostream.h>
class Cat           
{
public:
	Cat(){cout <<"构造函数-------\n";}
	Cat(Cat&){cout <<"复制构造函数llllllllllll\n";}//必须写成Cat(Cat&)，，才能被调用???
	~Cat(){cout <<"析构函数eeeeeeeee\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	Cat setage(Cat a){a.SetAge(111);return a;}//返回对象a，又创建一个拷贝，又调用复制构造函数，函数结束return的拷贝a和传递过来的拷贝a作用域都结束，调用两次析构函数。
private:        
	int itsAge;
};
int main()
{
	Cat x,y;//也可以这样定义两个不同的对象
	x.SetAge(5);
	y.SetAge(6);
	cout <<x.GetAge()<<"\n";
	cout <<y.GetAge()<<endl;
	
	y.setage(x);   //传递了一个x的拷贝过去，调用复制构造函数
	cout <<x.GetAge()<<endl;                      //输出的仍然是5!!!
	cout <<y.GetAge()<<endl;
	return 0;//函数结束，x,y作用域结束，调用两次析构函数!!
}
