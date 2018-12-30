#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=100;cout <<"Mammal的构造函数\n";}
	~Mammal(){cout <<"Mammal的析构函数\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}

	void Speak()const{cout <<"声音!!\n";}
	void Sleep()const{cout <<"zzz~zz~~~睡觉呢!!\n";}
protected:    //保护型成员对于该类的派生类是可见的
	int itsAge;
};
class sijiaoanimal:public Mammal
{
public:
	sijiaoanimal(){itsMao=200;cout <<"四角动物的构造函数\n";}
	~sijiaoanimal(){cout <<"嘶叫动物的析构函数\n";}

	int GetMao()const{return itsMao;}
	void maomao()const{cout <<"我是毛毛动物类\n";}
protected:
	int itsMao;
};

class Dog:public sijiaoanimal
{
public:
	Dog(){itsBreed=golden;cout <<"Dog的构造函数\n";}
	~Dog(){cout <<"Dog的析构函数\n";}

	int GetBreed()const{return itsBreed;}
	void SetBreed(breed x){itsBreed=x;}
	int WagTail()const{return itsAge;}

private:
	breed itsBreed;
};
int main()
{
	Dog xx;     //调用三次构造函数
	xx.Speak();  //中间插了一个类，一样的访问基类的基类。。。
	
	cout <<xx.GetAge()<<endl;
	cout <<xx.WagTail()<<endl;

	return 0;//调用三次析构函数
}



