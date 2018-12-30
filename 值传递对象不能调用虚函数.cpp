#include<iostream.h>
class Mammal
{
public:
	Mammal():itsAge(1){}
	virtual ~Mammal(){}
	virtual void Speak()const{cout<<"Mammal��Speak\n";}
protected:
	int itsAge;
};
class Dog : public Mammal
{
public:
	void Speak()const{cout<<"����dog\n";}
};
class Cat : public Mammal
{
public:
	void Speak()const{cout <<"����cat\n";}
};
void ValueFunction(Mammal);  //����������ָ������ʹ��ʲô��ʽ���ݵ�!!!!
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
		ValueFunction(*ptr); //�������ָ��������ֵ����!!!!!!!!!��ʱ���ʵ��麯����Զ���䱾��!!!!
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