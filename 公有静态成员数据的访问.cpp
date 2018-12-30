#include <iostream.h>

class Cat
{
public:
	Cat(int age):	itsAge(age)		{ HowManyCats++; }
	virtual ~Cat()					{ HowManyCats--; }

	virtual int GetAge()			{ return itsAge; }
	virtual void SetAge(int age)	{ itsAge = age;  }

	// ����ǹ��еĿ���������
	static int HowManyCats;	// ��̬��Ա����ֱ��(����::�ó�Ա)����

private:
	int itsAge;
};

// ��̬��Ա����Ҫ��ʼ����
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
		// ��̬��Ա�ķ���д��
		cout <<Cat::HowManyCats << endl;

		cout <<CatHouse[i]->GetAge() << endl;

		delete CatHouse[i];
		CatHouse[i] = 0;
	}
	return 0;
}
