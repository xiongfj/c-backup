#include <iostream.h>

class Cat
{
public:
	Cat(int age):	itsAge(age)		{ HowManyCats++;	  }
	virtual ~Cat()					{ HowManyCats--; 	  }

	virtual int GetAge()			{ return itsAge;	  }
	virtual void SetAge(int age)	{ itsAge = age;		  }

	// ��̬��Ա�����������κεط�ʹ�� ( Cat::GetHowMany() ) ������
	// ��̬��Ա����û�� this ָ�룬��������Ϊ const !!
	// ��̬��Ա�������ܷ����κεķǾ�̬��Ա����!!
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

		// ��̬��Ա����Ҳ�����ö�������������������һ��
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