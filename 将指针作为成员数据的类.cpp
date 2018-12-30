#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(int a,int b);
    ~SimpleCat();
	int GetAge()const{return *itsAge;}
	void SetAge(int age){*itsAge=age;}
	int GetWeight()const{return *itsWeight;}
	void SetWeight(int weight){*itsWeight=weight;}
private:
	int*itsAge;
	int*itsWeight;
};
SimpleCat::SimpleCat(int a,int b)
{
	itsAge=new int(a);
	itsWeight=new int(b);
}
SimpleCat::~SimpleCat()
{
	delete itsAge;     //在析构函数里面delete指针，释放内存不会再调用析构函数
	delete itsWeight;
}               //在这释放，后面只要有delete或者非自由存储区的对象都会西东调用析构函数并 delete私有成员数据
int main()
{
	SimpleCat*first=new SimpleCat(2,5);//构造函数带有参数的类的对象的定义格式。。
	cout <<first->GetAge()<<endl;
	cout <<first->GetWeight()<<endl;

	first->SetAge(9);
	first->SetWeight(10);
	cout <<first->GetAge()<<endl;
	cout <<(*first).GetWeight()<<endl;
	delete first;              //delete指针，释放了内存里9和10的值，是first与9,10再无关联

	first=new SimpleCat(90,100);  
	cout <<first->GetAge()<<endl;//由于上面delete了指针first，这里又重新定义了指针first指向的内存，所以输出不会再是9和10，
	cout <<first->GetWeight()<<endl;
	delete first;

	SimpleCat xx(22,55);
	cout <<xx.GetAge()<<endl;
	cout <<xx.GetWeight()<<endl;

	SimpleCat yy(33,77);        //对象yy调用构造函数设置私有成员的值，不影响对象xx的私有成员的值
	cout <<xx.GetAge()<<endl;   //输出22
	cout <<xx.GetWeight()<<endl;//输出55

	xx.SetAge(88);
	xx.SetWeight(99); //更换了xx对象里面itsAge 和itsWeight的值
	cout <<xx.GetAge()<<endl;
	cout <<xx.GetWeight()<<endl;

	return 0;
}

