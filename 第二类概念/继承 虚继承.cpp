#include <iostream.h>

enum COLOR {Red, Green, Blue};


//***** ��̳еĻ��� *********************************************
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


//****** ��̳� ********************************************
class Horse:virtual public Animal
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

// ��̳��У���������Ǹ�������Ķ����ǣ��ó�ʼ��������
Horse::Horse(COLOR color, int height, int age):

Animal(age),
itsColor(color),
itsHeight(height)
{
	cout <<"Horse����\n";
}


//****** ��̳� ********************************************
class Bird:virtual public Animal
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


// ��̳��У���������Ǹ�������Ķ����ǣ��ó�ʼ��������
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


// ��̳��еĹ��캯������������������Ĺ��캯���ڳ�ʼ�������������������ʱ��������������(�ǻ���)�Ĺ��캯����ʼ������
Pegasus::Pegasus(COLOR a, int b, bool c, long d, int e):

Animal(e * 2),	// ��̳��У�������Ǹ���������Ҫ��ʼ�����࣡
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

	// ����ʹ�õ�����̳У����в���Horse��Bird �Ĺ��캯����ô��ʼ������Ӱ�첻������
	int age1 = pPeg->GetAge();
	cout << age1 << endl;		// 4

	int age2 = pPeg->Bird::GetAge();
	cout << age2 << endl;		// 4

	delete pPeg;
	return 0;
}