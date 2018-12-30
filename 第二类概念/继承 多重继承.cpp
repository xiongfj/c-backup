


#include <iostream.h>

class Horse
{
public:
	Horse() {cout << "Horse构、";}
	virtual ~Horse() {cout << "Horse析、";}
	virtual void Whinny() const {cout <<"Whinny!";}
private:
	int itsAge;
};

class Bird
{
public:
	Bird() {cout << "Bird构、";}
	virtual ~Bird() {cout << "Bird析、";}
	virtual void Chirp() const {cout <<"Chirp";}	// 如果是一个指向 Bird* p = new Pegasus 的指针访问该函数，最终访问的是 Pegasus 里面的 Chirp()
	virtual void Fly() const
	{
		cout <<"我是fly";
	}
private:
	int itsWeight;
};

class Pegasus:public Horse, public Bird
{
public:
	void Chirp() const {Whinny();}
	Pegasus() {cout << "Pegasus构、";}
	~Pegasus() {cout <<"Pegasus析、";}
};

const int MagicNumber = 2;
int main()
{
	Horse* Ranch[MagicNumber];
	Horse* pHorse;

	Bird* Aviary[MagicNumber];
	Bird* pBird;

	Pegasus* p = new Pegasus;	// 该对象可以访问两个基类的非私有成员
	int choice, i;

	for (i = 0; i < MagicNumber; i++)
	{
		cout << "\n(1)Hore(2)Pegasus:";
		cin >> choice;
		if(choice == 2)
			pHorse = new Pegasus;	// 创建一个Peagsus对象将依次调用horse，brid，Pegasus的构造函数
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}

	for (i = 0; i < MagicNumber; i++)
	{
		cout << "\n(1)Bird(2)Pegasus:";
		cin >> choice;
		if (choice == 2)
			pBird = new Pegasus;
		else
			pBird = new Bird;
		Aviary[i] = pBird;
	}

	cout <<endl;
	for (i = 0; i < MagicNumber; i++)
	{
		cout << i;
		Ranch[i]->Whinny();
		delete Ranch[i];
	}

	for (i = 0; i < MagicNumber; i++)
	{
		cout << i;

		// Aviary 始终是指向 Bird 的指针，如果它被 Pegasus 的对象赋地址的话，那么就可以用本来指向 Bird 的它访问 Pegasus 的 Chirp()
		// 当然前提是 Chrip() 在 Bird 中是虚函数且在 Pegasus 中被覆盖
		// 如果赋予 Aviary 的是 Bird 对象的地址，那么访问的是 Bird 类里面的 Chirp()
		Aviary[i]->Chirp();
		Aviary[i]->Fly();
		delete Aviary[i];
	}
	return 0;
}