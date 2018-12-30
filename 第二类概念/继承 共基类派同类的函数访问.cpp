#include <iostream.h>

enum COLOR {Red, Green, Blue};


//**************************************************
class Animal
{
public:
	Animal(int);
	virtual ~Animal() {cout << "Animal析、\n";}

	virtual int  GetAge() const		{ return itsAge;	}
	virtual void SetAge(int age)	{ itsAge = age;		}

private:
	int itsAge;
};

Animal::Animal(int age):
itsAge(age)
{
	cout <<"Animal构、\n";
}


//**************************************************
class Horse:public Animal
{
public:
	Horse(COLOR color, int height, int age);
	virtual ~Horse() {cout <<"Horse析、\n";}

	virtual void	Whinny()	const	{ cout <<"WHinn、\n";	}
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
	cout <<"Horse构、\n";
}


//**************************************************
class Bird:public Animal
{
public:
	Bird(COLOR color, bool migrates, int age);
	virtual ~Bird() {cout <<"Bird析、\n";}

	virtual void  Chirp()		 const		{ cout <<"Chirp、\n";	}
	virtual void  Fly()			 const		{ cout <<"我Fly、\n";	}
	virtual bool  GetMigration() const		{ return itsMigration;	}
	virtual COLOR GetColoer()	 const		{ return itsColor;		}


private:
	COLOR itsColor;
	bool itsMigration;
};


// 派生类的构造函数初始化基类的构造函数，一层层的初始化
Bird::Bird(COLOR color, bool migrates, int age):

Animal(age),
itsColor(color),
itsMigration(migrates)
{
	cout <<"Bird构、\n";
}


//**************************************************************
class Pegasus:public Horse, public Bird
{
public:
	Pegasus(COLOR, int, bool, long, int);
	virtual ~Pegasus() {cout <<"Pegasus析、\n";}

	void Chirp() const {Whinny();}
	virtual long  GetNumberBelievers()	const			{ return itsNumberBelievers;	}
	virtual COLOR GetColor()			const			{ return Horse::GetColor();		}
	virtual int   GetAge()				const			{ return Horse::GetAge();		}

private:
	long itsNumberBelievers;
};


Pegasus::Pegasus(COLOR a, int b, bool c, long d, int e):

Horse(a, b, e),	// Horse 用 e 初始化 Animal 的 itsAge
Bird(a, c, b),	// Bird  用 b 初始化 Animal 的 itsAge
itsNumberBelievers(d)
{
	cout <<"Pegasus构、\n";
}


//**********************************************************************
int main()
{
	Pegasus* pPeg = new Pegasus(Red, 5, true, 10, 2);

	// 从 Horse 访问 Animal 的 GetAge()，由于函数体内已表明访问路径，所以可以直接写函数名
	int age1 = pPeg->GetAge();	// 访问的是 Pegasus 的 GetAge()，该GetAge() 又访问 Animal 的 GetAge()
	cout << age1 << endl;		// 输出 2，(访问路径不一样得到的结果页不一样)

	// 从 Bird 访问 Animal 的 GetAge
	int age2 = pPeg->Bird::GetAge();	// 由于 Pegasus 里面没有函数指明访问路径，所以要标示出来。
	cout << age2 << endl;		// 5

	delete pPeg;
	return 0;
}