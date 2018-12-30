#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(){itsAge=2;}
	~SimpleCat();
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
};
SimpleCat::~SimpleCat()
{
	cout <<"我又被调用了，cccc\n";
}
int main()
{
	SimpleCat*p=new SimpleCat;
	cout <<p->GetAge()<<endl;
	p->SetAge(7);    //成员指针运算符（->）访问
	cout <<(*p).GetAge()<<endl;
	(*p).SetAge(9);  //间接引用指针*访问
	cout <<p->GetAge()<<endl;
	delete p;

	SimpleCat xx;
	xx.SetAge(100);
	cout <<"\n"<<xx.GetAge()<<endl<<endl;

	SimpleCat yy;
	yy.SetAge(200);
	cout <<yy.GetAge()<<endl; //如果写成xx.GetAge()，那么输出的将是100，而不是200（每一个对象里面私有成员的值互不干扰!）
	return 0;      //函数结束前，因为定义了两个非自由存储区的对象，所以会调用两次析构函数
}            //如果不定义非自由存储区的对象，那么函数结束之前不会调用析构函数的!
