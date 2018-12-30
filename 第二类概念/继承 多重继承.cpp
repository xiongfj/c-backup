


#include <iostream.h>

class Horse
{
public:
	Horse() {cout << "Horse����";}
	virtual ~Horse() {cout << "Horse����";}
	virtual void Whinny() const {cout <<"Whinny!";}
private:
	int itsAge;
};

class Bird
{
public:
	Bird() {cout << "Bird����";}
	virtual ~Bird() {cout << "Bird����";}
	virtual void Chirp() const {cout <<"Chirp";}	// �����һ��ָ�� Bird* p = new Pegasus ��ָ����ʸú��������շ��ʵ��� Pegasus ����� Chirp()
	virtual void Fly() const
	{
		cout <<"����fly";
	}
private:
	int itsWeight;
};

class Pegasus:public Horse, public Bird
{
public:
	void Chirp() const {Whinny();}
	Pegasus() {cout << "Pegasus����";}
	~Pegasus() {cout <<"Pegasus����";}
};

const int MagicNumber = 2;
int main()
{
	Horse* Ranch[MagicNumber];
	Horse* pHorse;

	Bird* Aviary[MagicNumber];
	Bird* pBird;

	Pegasus* p = new Pegasus;	// �ö�����Է�����������ķ�˽�г�Ա
	int choice, i;

	for (i = 0; i < MagicNumber; i++)
	{
		cout << "\n(1)Hore(2)Pegasus:";
		cin >> choice;
		if(choice == 2)
			pHorse = new Pegasus;	// ����һ��Peagsus�������ε���horse��brid��Pegasus�Ĺ��캯��
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

		// Aviary ʼ����ָ�� Bird ��ָ�룬������� Pegasus �Ķ��󸳵�ַ�Ļ�����ô�Ϳ����ñ���ָ�� Bird �������� Pegasus �� Chirp()
		// ��Ȼǰ���� Chrip() �� Bird �����麯������ Pegasus �б�����
		// ������� Aviary ���� Bird ����ĵ�ַ����ô���ʵ��� Bird ������� Chirp()
		Aviary[i]->Chirp();
		Aviary[i]->Fly();
		delete Aviary[i];
	}
	return 0;
}