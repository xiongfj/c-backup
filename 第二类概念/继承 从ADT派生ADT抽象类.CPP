#include <iostream.h>

enum COLOR {Red, Green, Blue};

//********************************************** Animal
class Animal
{
public:
	Animal(int);
	virtual ~Animal()				{ cout <<"Animal析、\n"; }

	virtual int GetAge() const		{ return itsAge; }
	virtual void SetAge(int age)	{ itsAge = age;  }

	virtual void Sleep()		const = 0;
	virtual void Eat()			const = 0;
	virtual void Reproduce()	const = 0;
	virtual void Move()			const = 0;
	virtual void Speak()		const = 0;

private:
	int itsAge;
};

Animal::Animal(int age):
itsAge(age)
{
	cout <<"Animal构、\n";
}


// 该抽象类 Mammal 已经覆盖了 Reproduce()，那么从该类派生出去的都不用覆盖该函数了，但是 Animal 的其他纯虚函数还是必须覆盖的。
// 从抽象类派生抽象类不一定要覆盖纯虚函数!
// 没覆盖完基类中的纯虚函数，那么该类将是抽象类
//********************************************** Mammal

class Mammal:public Animal
{
public:
	Mammal(int age):Animal(age)		{ cout <<"Mammal构、	\n"; }
	virtual ~Mammal()				{ cout <<"Mammal析、	\n"; }

	virtual void Reproduce() const	{ cout <<"Mammal的rep、	\n"; }
};



// 该类是直接从抽象基类派生而来，所以要覆盖所有纯虚函数
//********************************************** Fish
class Fish:public Animal
{
public:
	Fish(int age): Animal(age)				{ cout <<"Fish构、		\n";	}
	virtual ~Fish()							{ cout <<"Fish析、		\n";	}

	virtual void Sleep()		const		{ cout <<"Fish的sleep、	\n";	}
	virtual void Eat()			const		{ cout <<"fish的eat、	\n";	}
	virtual void Reproduce()	const		{ cout <<"fish的rep、	\n";	}
	virtual void Move()			const		{ cout <<"fish的move、	\n";	}
	virtual void Speak()		const		{ cout <<"fish的speak、	\n";	}
};



// 该类从抽象类的抽象类派生而来，直接的基类 Mammal 已经覆盖了 Reproduce()，所以可以不用覆盖 Reproduce()
//********************************************** Horse
class Horse:public Mammal
{
public:
	Horse(int age, COLOR color):	Mammal(age), itsColor(color)	{cout <<"horse构、\n";}
	virtual ~Horse() /*const*/			{ cout <<"horse析、     \n"; }		// 关键词 const 不能用于构造、析构函数！！！！！！！！！！！！！！！！！
	
	virtual COLOR GetColor()	const	{ return itsColor;			 }

	virtual void Speak()		const	{ cout <<"horsespeak、  \n"; }
	virtual void Sleep()		const	{ cout <<"horse的sleep、\n"; }
	virtual void Eat()			const	{ cout <<"horse的wat、  \n"; }
	virtual void Move()			const	{ cout <<"horse的move、 \n"; }

protected:
	COLOR itsColor;
};



// 该类也可以不覆盖 Reproduce()
//********************************************** Dog
class Dog:public Mammal
{
public:
	Dog(int age, COLOR color):	Mammal(age), itsColor(color)	{cout <<"Dog构、\n";}
	virtual ~Dog() {cout <<"Dog的析、\n";}

	virtual void Speak()		const	{ cout <<"dog的speak、\n"; }
	virtual void Sleep()		const	{ cout <<"dog的sleep、\n"; }
	virtual void Eat()			const	{ cout <<"dog的eat、  \n"; }
	virtual void Move()			const	{ cout <<"dog的move、 \n"; }
	virtual void Reproduce()	const	{ cout <<"dog的rep、  \n"; }

protected:
	COLOR itsColor;
};



// Mammal -> Animal
// fish   -> Animal
// dog/horse -> Mammal -> Animal
//**********************************************
void main()
{
	Animal* pAnimal = 0;
	int choice;
	bool fQuit = false;

	while (1)
	{
		cout <<"1-dog、2-horse、3-fish、0=quit";
		cin  >> choice;

		switch (choice)
		{
			case 1:	pAnimal = new Dog(5, Red);		break;
			case 2:	pAnimal = new Horse(4, Green);	break;	// Horse 没有 Reproduce() 将调用其基类 Mammal 的 Reproduce()
			case 3:	pAnimal = new Fish(5);			break;
			default:  fQuit = true;					break;
		}

		if (fQuit)
			break;

		pAnimal->Speak();
		pAnimal->Eat();
		pAnimal->Reproduce();
		pAnimal->Move();
		pAnimal->Sleep();

		cout << endl;
	}
}