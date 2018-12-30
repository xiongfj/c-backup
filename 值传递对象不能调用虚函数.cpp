#include<iostream.h>
class Mammal
{
public:
	Mammal():itsAge(1){}
	virtual ~Mammal(){}
	virtual void Speak()const{cout<<"Mammal的Speak\n";}
protected:
	int itsAge;
};
class Dog : public Mammal
{
public:
	void Speak()const{cout<<"我是dog\n";}
};
class Cat : public Mammal
{
public:
	void Speak()const{cout <<"我是cat\n";}
};
void ValueFunction(Mammal);  //函数申明中指明了是使用什么方式传递的!!!!
void PtrFunction(Mammal*);
void RefFunction(Mammal&);
int main()
{
	Mammal* ptr=0;
	int choice;
	while(1)
	{
		bool fQuit=false;
		cout <<"1 dog,2 cat,0 quit:";
		cin>>choice;
		switch(choice)
		{
		case 0:fQuit=true;
			break;
		case 1:ptr=new Dog;
			break;
		case 2:
			ptr=new Cat;
			break;
		default:ptr=new Mammal;
			break;
		}
		if(fQuit)
			break;
		ValueFunction(*ptr); //间接引用指针是属于值传递!!!!!!!!!此时访问的虚函数永远是其本身!!!!
		PtrFunction(ptr);
		RefFunction(*ptr);
	}
	return 0;
}
void ValueFunction(Mammal MammalValue)
{
	MammalValue.Speak();
}
void PtrFunction(Mammal* pMammal)
{
	pMammal->Speak();
}
void RefFunction(Mammal &rMammal)
{
	rMammal.Speak();
}