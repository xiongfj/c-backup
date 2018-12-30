#include <iostream.h>
class Rectangle
{
public:
	Rectangle();
	~Rectangle(){}
	void SetWidth(int width){itsWidth=width;}
	int GetWidth()const{return itsWidth;}
private:
	int itsWidth;
};
Rectangle::Rectangle()
{

	itsWidth=5;
}
int main()
{
	Rectangle*p1=new Rectangle;//调用构造函数给私有成员itsWidth赋值5
	const Rectangle*p2=new Rectangle;//指向const型对象的指针只能访问const型的函数方法
	Rectangle*const p3=new Rectangle;//p3是常量(不能指向其他类型，只能指向Rectangle类型)
//class Cat
//..
//..
//delete p3;
//Cat*p3=new Cat;此时的p3是不能指向其他类型(Cat)的!
	cout <<p1->GetWidth()<<endl;
	cout <<p2->GetWidth()<<endl;
	cout <<p3->GetWidth()<<endl;

	p1->SetWidth(111);
	//p2->SetWidth(222);//由于SetWidth不是const型的，所以p2不能访问
	p3->SetWidth(333);

	cout <<p1->GetWidth()<<endl;
	cout <<p2->GetWidth()<<endl;
	cout <<p3->GetWidth()<<endl;
	return 0;
}