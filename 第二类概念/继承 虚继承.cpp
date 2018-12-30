#include <iostream.h>

enum COLOR {Red, Green, Blue};


//***** 虚继承的基类 *********************************************
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


//****** 虚继承 ********************************************
class Horse:virtual public Animal
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

// 虚继承中，创建最后那个派生类的对象是，该初始化被忽略
Horse::Horse(COLOR color, int height, int age):

Animal(age),
itsColor(color),
itsHeight(height)
{
	cout <<"Horse构、\n";
}


//****** 虚继承 ********************************************
class Bird:virtual public Animal
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


// 虚继承中，创建最后那个派生类的对象是，该初始化被忽略
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


// 虚继承中的构造函数必须再最后的派生类的构造函数内初始化，创建该派生类对象时，将忽略其他类(非基类)的构造函数初始化部分
Pegasus::Pegasus(COLOR a, int b, bool c, long d, int e):

Animal(e * 2),	// 虚继承中，最后面那个派生的类要初始化基类！
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

	// 由于使用的是虚继承，所有不管Horse、Bird 的构造函数怎么初始化，都影响不到该类
	int age1 = pPeg->GetAge();
	cout << age1 << endl;		// 4

	int age2 = pPeg->Bird::GetAge();
	cout << age2 << endl;		// 4

	delete pPeg;
	return 0;
}