#include <iostream.h>
class Cat           
{
public:
	Cat(){cout <<"构造函数-------\n";}
	Cat(Cat&){cout <<"复制构造函数llllllllllll\n";}//必须写成Cat(Cat&)，，才能被调用???
	~Cat(){cout <<"析构函数eeeeeeeee\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	Cat* setage(Cat *a){a->SetAge(111);return a;}//返回的是指针，不会调用复制构造函数
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
	
	y.setage(&x);   //使用的是指针传递，不会调用构造函数
	cout <<x.GetAge()<<endl;    //输出的是111而不是5
	cout <<y.GetAge()<<endl;
	return 0;//函数结束，x,y作用域结束，调用两次析构函数!!
}
