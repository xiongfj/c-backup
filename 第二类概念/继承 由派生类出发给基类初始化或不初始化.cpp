#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=100;cout <<"Mammal的构造函数\n";}
	Mammal(int a){itsAge=a;cout<<"我被调用了吗?\n";}
	~Mammal(){cout <<"Mammal的析构函数\n";}
	int GetAge()const{return itsAge;}
	void Speak()const{cout <<"喵喵..!!\n";}
protected:    
	int itsAge;
};

class Dog:public Mammal//
{
public:
	Dog(int age,breed a);
	~Dog(){cout <<"Dog的析构函数\n";}
	int GetBreed()const{return itsBreed;}
	int WagTail()const{return itsAge;}

private:
	breed itsBreed;
};
Dog::Dog(int age,breed a):
//Mammal(age),//加上这一句，在创建对象xx的时候就不会调用默认构造函数了，在这里写什么构造函数就只调用什么构造函数，
itsBreed(a)
{
	cout <<"Dog的构造函数\n";
}
int main()
{
	Dog xx(200,lab);//传递的参量是给派生类的构造函数的，同时在上面注释出写明此时你想调用的哪个基类构造函数，不写的话将调用基类的默认构造函数。      
	xx.Speak();
	xx.WagTail();
	cout <<xx.GetAge()<<endl;
	cout <<xx.WagTail()<<endl;
	return 0;
}//这程序主要是为了：当你只想初始化该对象(xx)在派生类的成员(itsBreed)而不想初始化该对象从基类继承的成员数据(itsAge),那么就在第一行的注释出写上一个无参量的构造函数即可，或者不写(只要类中有其他构造函数，那么你必须写上默认构造函数!!)



