#include <iostream.h>
class Cat           
{
public:
	Cat(){cout <<"构造函数-------\n";}
	Cat(Cat&){cout <<"复制构造函数llllllllllll\n";}//必须写成Cat(Cat&)，，才能被调用???
	~Cat(){cout <<"析构函数eeeeeeeee\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	Cat& setage(Cat &a){a.SetAge(111);return a;}//类型中加了个&表示返回的是引用，故此不会调用构造函数，此处可以不加&，那么返回的a就表示对象，将会调用复制构造函数，析构函数。。
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
	
	y.setage(x);   //前面申明的形参是使用引用，所以这里不拷贝对象，不调用复制构造函数
	cout <<x.GetAge()<<endl;    //输出的是111而不是5
	cout <<y.GetAge()<<endl;
	return 0;//函数结束，x,y作用域结束，调用两次析构函数!!
}
