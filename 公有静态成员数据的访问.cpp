#include <iostream.h>

class Cat
{
public:
	Cat(int age):	itsAge(age)		{ HowManyCats++; }
	virtual ~Cat()					{ HowManyCats--; }

	virtual int GetAge()			{ return itsAge; }
	virtual void SetAge(int age)	{ itsAge = age;  }

	// 如果是公有的可以随便访问
	static int HowManyCats;	// 静态成员可以直接(类名::该成员)访问

private:
	int itsAge;
};

// 静态成员数据要初始化！
int Cat::HowManyCats = 0;


int main()
{
	const int MaxCats = 5;
	int i;
	Cat* CatHouse[MaxCats];

	for (i = 0; i < MaxCats; i++)
		CatHouse[i] = new Cat(i);

	for (i = 0; i < MaxCats; i++)
	{
		// 静态成员的访问写法
		cout <<Cat::HowManyCats << endl;

		cout <<CatHouse[i]->GetAge() << endl;

		delete CatHouse[i];
		CatHouse[i] = 0;
	}
	return 0;
}
