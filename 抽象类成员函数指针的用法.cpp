#include <iostream.h>


//******************************************
class Mammal
{
public:
	Mammal(): itsAge(1) {}
	virtual ~Mammal()	{}
	virtual void Speak() const = 0;
	virtual void Move()  const = 0;

protected:
	int itsAge;
};


// ���麯�����ܴ�������Ķ�����ʣ�ֻ�������������ӷ���
// ��������Դ���ָ�����Ŀ�ָ�룬��Ҳ�����ÿ�ָ�����
void Mammal::Speak() const
{
	cout <<".................";
}


//******************************************
class Dog:public Mammal
{
public:
	void Speak() const	{ cout << "dog��speak��\n";	  }
	void Move()	 const	{ cout << "dog��move�� \n";   }
};


//******************************************
class Cat:public Mammal
{
public:
	void Speak() const	{ cout << "cat��speeak��\n";  }
	void Move()	 const	{ cout << "cat��move��  \n";  }
};


//******************************************
class Horse:public Mammal
{
public:
	void Speak() const	{ cout << "Horse��speak��\n"; }
	void Move()  const	{ cout << "horse��move�� \n"; }
};


//******************************************
void main()
{
	// pFunc ��Ϊһ��ָ�� Mammal ��Ա������ָ�룬�䱾���Ѿ��� Mammal ��һ����Ա������ֱ��ʹ��
	// ������Ա����ָ���д���������� const ͬʱҲ�������
	// ò�ƿ��Բ�д = 0
	void (Mammal::*pFunc)() const = 0;

	// ������ָ��ʽΪ���ܷ��� pFunc
	Mammal* ptr = 0;
	// Mammal m; // ���󣬳����಻��ʵ��������

	Dog dog;

	int Animal, Method;
	bool fQuit = false;

	while (!fQuit)
	{
		cout <<"0�˳���1dog��2cat��3horse \n";
		cin  >> Animal;

		switch (Animal)
		{
			case 1: 	ptr = new Dog;		break;
			case 2:		ptr = new Cat;		break;
			case 3:		ptr = new Horse;	break;
			default:  fQuit = true;			break;
		}

		if (fQuit)
			break;

		cout <<"1speak��2move";
		cin  >> Method;

		switch (Method)
		{
			case 1:		pFunc = Mammal::Speak;	break;
			default:	pFunc = Mammal::Move;	break;
		}

		// ���� pFunc ָ��Ķ������Դ˶�����ʳ�Ա��������ī��
		(ptr->*pFunc)();
		delete ptr;

		// ���ʵ��� Mammal �� Speak()
		// ֻ��ָ������ܷ��ʳ�����ĳ�Ա�麯��
		// ��δָ����ò���޷����ʣ���Ϊ�������ˡ������ֲ��ܴ����������
		dog.Mammal::Speak();	
		// delete pFunc; // ����pFunc δָ��������ڴ���䡣
	}
}