#include <iostream.h>

class Cat
{
public:
	Cat(int age):	itsAge(age)		{ HowManyCats++;	  }
	virtual ~Cat()					{ HowManyCats--; 	  }

	virtual int GetAge()			{ return itsAge;	  }
	virtual void SetAge(int age)	{ itsAge = age;		  }

	// 静态成员函数可以在任何地方使用 ( Cat::GetHowMany() ) 访问其
	// 静态成员函数没有 this 指针，不能申明为 const !!
	// 静态成员函数不能访问任何的非静态成员变量!!
	static int GetHowMany()			{ return HowManyCats; }

private:
	int itsAge;
	static int HowManyCats;
};

int Cat::HowManyCats = 0;

void TelepathicFunction();

void main()
{
	int i;
	Cat* CatHouse[5];

	for (i = 0; i < 5; i++)
	{
		CatHouse[i] = new Cat(i);

		// 静态成员函数也可以用对象访问它，不过结果都一样
		cout << CatHouse[i]->GetHowMany() << endl;
		TelepathicFunction();
	}

	for (i = 0; i < 5; i++)
	{
		delete CatHouse[i];
		TelepathicFunction();
	}
}


void TelepathicFunction()
{
	cout << Cat::GetHowMany() <<endl;
}