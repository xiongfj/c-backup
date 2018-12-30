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


// 纯虚函数不能创建本类的对象访问！只能有其派生类间接访问
// 抽象类可以创建指向该类的空指针，但也不能用空指针访问
void Mammal::Speak() const
{
	cout <<".................";
}


//******************************************
class Dog:public Mammal
{
public:
	void Speak() const	{ cout << "dog的speak、\n";	  }
	void Move()	 const	{ cout << "dog的move、 \n";   }
};


//******************************************
class Cat:public Mammal
{
public:
	void Speak() const	{ cout << "cat的speeak、\n";  }
	void Move()	 const	{ cout << "cat的move、  \n";  }
};


//******************************************
class Horse:public Mammal
{
public:
	void Speak() const	{ cout << "Horse的speak、\n"; }
	void Move()  const	{ cout << "horse的move、 \n"; }
};


//******************************************
void main()
{
	// pFunc 作为一个指向 Mammal 成员函数的指针，其本身已经是 Mammal 的一个成员，不能直接使用
	// 申明成员函数指针的写法，函数有 const 同时也必须带上
	// 貌似可以不写 = 0
	void (Mammal::*pFunc)() const = 0;

	// 创建该指针式为了能访问 pFunc
	Mammal* ptr = 0;
	// Mammal m; // 错误，抽象类不能实例化对象！

	Dog dog;

	int Animal, Method;
	bool fQuit = false;

	while (!fQuit)
	{
		cout <<"0退出、1dog、2cat、3horse \n";
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

		cout <<"1speak、2move";
		cin  >> Method;

		switch (Method)
		{
			case 1:		pFunc = Mammal::Speak;	break;
			default:	pFunc = Mammal::Move;	break;
		}

		// 访问 pFunc 指向的对象，再以此对象访问成员函数，真墨迹
		(ptr->*pFunc)();
		delete ptr;

		// 访问的是 Mammal 的 Speak()
		// 只有指明类才能访问抽象类的成员虚函数
		// 如未指明，貌似无法访问，因为被覆盖了。。。又不能从自身类访问
		dog.Mammal::Speak();	
		// delete pFunc; // 错误，pFunc 未指向对象，无内存分配。
	}
}