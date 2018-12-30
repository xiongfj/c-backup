// easyx 201209版

#include <iostream.h>


enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

//***********************************************************

class Horse
{
public:
	Horse(COLOR color, int height);
	virtual ~Horse() {cout <<"Horse析、\n";}
	virtual void Whinny() const {cout <<"Whinny、";}
	virtual int GetHeight() const {return itsHeight;}
	virtual COLOR GetColor() const {return itsColor;}

private:
	int itsHeight;
	COLOR itsColor;
};

Horse::Horse(COLOR color, int height):
itsColor(color), itsHeight(height)
{
	cout <<"Horse构、";
}


//**********************************************************
class Bird
{
public:
	Bird(COLOR color, bool migrates);
	virtual ~Bird() {cout <<"Bird析、";}
	virtual void Chirp() const {cout <<"Chirp、";}
	virtual void Fly() const
	{
		cout <<"我是Fly、";
	}
	virtual COLOR GetColor() const {return itsColor;}
	virtual bool GetMigration() const {return itsMigration;}

private:
	COLOR itsColor;
	bool itsMigration;
};

Bird::Bird(COLOR color, bool migrates):
itsColor(color), itsMigration(migrates)
{
	cout <<"Bird构、\n";
}


//**************************************************************
class Pegasus:public Horse, public Bird
{
public:
	void Chirp() const {Whinny();}
	Pegasus(COLOR, int, bool, long);
	~Pegasus() {cout <<"Pegasus构、\n";}
	virtual long GetNumberBelievers() const
	{
		return itsNumberBelievers;
	}

private:
	long itsNumberBelievers;
};


// 在有继承关系的类中，如果构造函数有参数必须使用如下形式定义构造函数
// 多重继承中对多个基类构造函数初始化写法，（依次在派生类的构造函数体内初始化他们，而且必须是初始化写法）
Pegasus::Pegasus(COLOR a, int b, bool c, long d):
Horse(a, b),	// 不能再函数体内初始化构造函数！
Bird(a, c),
itsNumberBelievers(d)
{
	cout <<"Pegasus构、\n";
}


//*************************************************************
int main()
{
	// 调用三个构造函数
	Pegasus* pPeg = new Pegasus(Yellow, 5, true, 10);

	pPeg->Fly();		// 调用 Bird 的
	pPeg->Whinny();		// 调用 Horse 的

	cout << pPeg->GetHeight();

	if (pPeg->GetMigration())	// true
		cout <<"Gettrue";
	else
		cout <<"getfalse";

	cout <<pPeg->GetNumberBelievers() << endl;


//	COLOR c = pPeg->GetColor();	不能如此写，因为两个基类中都有该函数 GetColor()，编译器无法区分！

	COLOR c = pPeg->Bird::GetColor();
	cout << c;
	
	delete pPeg;	// 删除指针前调用三个析构函数
	return 0;
}