#include<iostream.h>
class Mammal
{
public:
	Mammal():itsAge(1){} //��Ƕ����ʼ��
	virtual ~Mammal(){}  //ֻҪ������һ������ʽ�麯�������������������麯��!!!
	virtual void Speak()const {cout <<"Mammal ��Speak()\n";}
protected:
	int itsAge;
};
class Dog : public Mammal
{
public:
	void Speak()const{cout<<"Dog��Speak()\n";}
};
class Cat : public Mammal
{
public:
	void Speak()const{cout <<"Cat��Speak()\n";}
};
class Pig : public Mammal
{
public:
	void Speak()const{cout<<"Pig ��Speak()\n";}
};
class Horse : public Mammal
{
public:
	void peak()const{cout<<"���Speak()\n";}  //����麯��û�����ǣ���ô�����麯��ʱ���ʵĽ����麯������!!!
};
int main()
{
	Mammal* theArray[5];
	Mammal* ptr;
	int choice,i;
	for(i=0;i<5;i++)
	{
		cout <<"������ѡ��\n(1)dog(2)cat(3)horse(4)pig";
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
		theArray[i]=ptr; //ÿ�ζ���ָ�����������ָ�븳��ָ��Mammal��ָ��(ָ�븳��ָ�롣��)
	}
	for(i=0;i<5;i++)
		theArray[i]->Speak();
	ptr->Mammal::Speak();  //���õ���Mammal�����Speak()����ʾ�ĵ��û�����ĺ�������ʹ���麯��Ҳ���Ե���
	return 0;
}