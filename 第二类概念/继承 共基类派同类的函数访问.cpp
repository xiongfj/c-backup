#include <iostream.h>

enum COLOR {Red, Green, Blue};


//**************************************************
class Animal
{
public:
	Animal(int);
	virtual ~Animal() {cout << "Animal����\n";}

	virtual int  GetAge() const		{ return itsAge;	}
	virtual void SetAge(int age)	{ itsAge = age;		}

private:
	int itsAge;
};

Animal::Animal(int age):
itsAge(age)
{
	cout <<"Animal����\n";
}


//**************************************************
class Horse:public Animal
{
public:
	Horse(COLOR color, int height, int age);
	virtual ~Horse() {cout <<"Horse����\n";}

	virtual void	Whinny()	const	{ cout <<"WHinn��\n";	}
	virtual int		GetHeight() const	{ return itsHeight;		}
	virtual COLOR	GetColor()	const	{ return itsColor;		}

private:
	int itsHeight;
	COLOR itsColor;
};

Horse::Horse(COLOR color, int height, int age):

Animal(age),
itsColor(color),
itsHeight(height)
{
	cout <<"Horse����\n";
}


//**************************************************
class Bird:public Animal
{
public:
	Bird(COLOR color, bool migrates, int age);
	virtual ~Bird() {cout <<"Bird����\n";}

	virtual void  Chirp()		 const		{ cout <<"Chirp��\n";	}
	virtual void  Fly()			 const		{ cout <<"��Fly��\n";	}
	virtual bool  GetMigration() const		{ return itsMigration;	}
	virtual COLOR GetColoer()	 const		{ return itsColor;		}


private:
	COLOR itsColor;
	bool itsMigration;
};


// ������Ĺ��캯����ʼ������Ĺ��캯����һ���ĳ�ʼ��
Bird::Bird(COLOR color, bool migrates, int age):

Animal(age),
itsColor(color),
itsMigration(migrates)
{
	cout <<"Bird����\n";
}


//**************************************************************
class Pegasus:public Horse, public Bird
{
public:
	Pegasus(COLOR, int, bool, long, int);
	virtual ~Pegasus() {cout <<"Pegasus����\n";}

	void Chirp() const {Whinny();}
	virtual long  GetNumberBelievers()	const			{ return itsNumberBelievers;	}
	virtual COLOR GetColor()			const			{ return Horse::GetColor();		}
	virtual int   GetAge()				const			{ return Horse::GetAge();		}

private:
	long itsNumberBelievers;
};


Pegasus::Pegasus(COLOR a, int b, bool c, long d, int e):

Horse(a, b, e),	// Horse �� e ��ʼ�� Animal �� itsAge
Bird(a, c, b),	// Bird  �� b ��ʼ�� Animal �� itsAge
itsNumberBelievers(d)
{
	cout <<"Pegasus����\n";
}


//**********************************************************************
int main()
{
	Pegasus* pPeg = new Pegasus(Red, 5, true, 10, 2);

	// �� Horse ���� Animal �� GetAge()�����ں��������ѱ�������·�������Կ���ֱ��д������
	int age1 = pPeg->GetAge();	// ���ʵ��� Pegasus �� GetAge()����GetAge() �ַ��� Animal �� GetAge()
	cout << age1 << endl;		// ��� 2��(����·����һ���õ��Ľ��ҳ��һ��)

	// �� Bird ���� Animal �� GetAge
	int age2 = pPeg->Bird::GetAge();	// ���� Pegasus ����û�к���ָ������·��������Ҫ��ʾ������
	cout << age2 << endl;		// 5

	delete pPeg;
	return 0;
}