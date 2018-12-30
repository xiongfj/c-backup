#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=1;itsWeight=5;cout <<"M的构造函数。。。\n";}
	Mammal(int age){itsAge=age;itsWeight=5;cout <<"M(int)重载构造函数\n";}
	~Mammal(){cout <<"M的析构函数\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	int GetWeight(){return itsWeight;}
	void SetWeight(int weight){itsWeight=weight;}

	void Speak()const {cout <<"喵喵。。。。";}
protected:
	int itsAge,itsWeight;
};


class Dog:public Mammal
{
public:
	Dog();
	Dog(int age);
	Dog(int age,int weight);
	Dog(int age,breed x);
	Dog(int age,int weight,breed x);
	~Dog(){cout <<"dog析构函数\n";}
	breed GetBreed()const{return itsBreed;}
	void SetBreed(breed a){itsBreed=a;}

	void WagTail()const {cout <<" 小狗狗..\n";}
private:
	breed itsBreed;
};
Dog::Dog():
Mammal(),//这个放在函数体里面和放在初始化阶段是不一样的!!!!
itsBreed(golden)
{ //Mammal();//在这加一代码，为什么后面会调用析构函数了呢?
   cout <<"dog构造函数1\n";
}

Dog::Dog(int age):
Mammal(age),//重载构造函数放不进函数体里面??!!//能，但是也必须定义对象初始化才能访问
itsBreed(golden)
{cout <<"dog重载构造函数2\n";}//成员函数没有继承构造函数，复制构造函数，析构函数，所以在里面无法直接使用他们，可以Dog x(*)调用

Dog::Dog(int age,int weight):
Mammal(age),//新建对象时，显式的调用并初始化基类的构造函数(构造或者复制构造，可选，调用了重载构造，就不调用默认的构造函数了)
itsBreed(golden)
{
	itsWeight=weight;
	cout <<"dog重载构造函数3\n";
}

Dog::Dog(int age,breed x):
Mammal(age),//即使这行注释掉，还是会调用基类的默认构造函数滴!!
itsBreed(golden)
{cout <<"dog重载构造函数5\n";}

Dog::Dog(int age,int weight,breed x)//即使没写成初始化格式，在main中利用该重载构造函数对firth初始化的时候依然会调用基类的默认构造函数，虽然它没有参量，也会被调用。
{
    itsBreed=x;
	itsWeight=weight;
	cout <<"dog重载构造函数4\n";
}




int main()
{
	Dog first;
	Dog second(100);//100只会赋给dog的构造函数
	Dog third(200,1);
	Dog forth(300,golden);//如果初始化阶段不选择调用基类的哪个构造函数，那么就会自动调用默认的构造函数。。。
	Dog firth(400,2,doberman);//每次都会调用基类的构造函数，至于调用默认构造函数还是重载构造函数，在派生类的构造函数的初始化阶段选择
	first.Speak();
	second.WagTail();
	cout <<forth.GetAge()<<endl;
	cout <<firth.GetWeight()<<endl;
	return 0;//函数结束，5个对象，调用5次基类的析构和5次派生类的析构
}
