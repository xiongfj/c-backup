#include<iostream.h>
class Mammal
{
public:
	Mammal():itsAge(1){} //内嵌并初始化
	virtual ~Mammal(){}  //只要本类有一个函数式虚函数，析构函数必须是虚函数!!!
	virtual void Speak()const {cout <<"Mammal 的Speak()\n";}
protected:
	int itsAge;
};
class Dog : public Mammal
{
public:
	void Speak()const{cout<<"Dog的Speak()\n";}
};
class Cat : public Mammal
{
public:
	void Speak()const{cout <<"Cat的Speak()\n";}
};
class Pig : public Mammal
{
public:
	void Speak()const{cout<<"Pig 的Speak()\n";}
};
class Horse : public Mammal
{
public:
	void peak()const{cout<<"马的Speak()\n";}  //如果虚函数没被覆盖，那么访问虚函数时访问的将是虚函数本身!!!
};
int main()
{
	Mammal* theArray[5];
	Mammal* ptr;
	int choice,i;
	for(i=0;i<5;i++)
	{
		cout <<"请输入选择：\n(1)dog(2)cat(3)horse(4)pig";
		cin>>choice;
		switch(choice)
		{
		case 1:ptr=new Dog;
			break;
		case 2:ptr=new Cat;
			break;
		case 3:ptr=new Horse;
			break;
		case 4:ptr=new Pig;
			break;
		default:ptr=new Mammal;
			break;
		}
		theArray[i]=ptr; //每次都将指向其他对象的指针赋予指向Mammal的指针(指针赋予指针。。)
	}
	for(i=0;i<5;i++)
		theArray[i]->Speak();
	ptr->Mammal::Speak();  //调用的是Mammal里面的Speak()。显示的调用基类里的函数，即使是虚函数也可以调用
	return 0;
}