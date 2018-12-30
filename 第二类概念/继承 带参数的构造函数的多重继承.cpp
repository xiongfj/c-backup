// easyx 201209��

#include <iostream.h>


enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

//***********************************************************

class Horse
{
public:
	Horse(COLOR color, int height);
	virtual ~Horse() {cout <<"Horse����\n";}
	virtual void Whinny() const {cout <<"Whinny��";}
	virtual int GetHeight() const {return itsHeight;}
	virtual COLOR GetColor() const {return itsColor;}

private:
	int itsHeight;
	COLOR itsColor;
};

Horse::Horse(COLOR color, int height):
itsColor(color), itsHeight(height)
{
	cout <<"Horse����";
}


//**********************************************************
class Bird
{
public:
	Bird(COLOR color, bool migrates);
	virtual ~Bird() {cout <<"Bird����";}
	virtual void Chirp() const {cout <<"Chirp��";}
	virtual void Fly() const
	{
		cout <<"����Fly��";
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
	cout <<"Bird����\n";
}


//**************************************************************
class Pegasus:public Horse, public Bird
{
public:
	void Chirp() const {Whinny();}
	Pegasus(COLOR, int, bool, long);
	~Pegasus() {cout <<"Pegasus����\n";}
	virtual long GetNumberBelievers() const
	{
		return itsNumberBelievers;
	}

private:
	long itsNumberBelievers;
};


// ���м̳й�ϵ�����У�������캯���в�������ʹ��������ʽ���幹�캯��
// ���ؼ̳��жԶ�����๹�캯����ʼ��д������������������Ĺ��캯�����ڳ�ʼ�����ǣ����ұ����ǳ�ʼ��д����
Pegasus::Pegasus(COLOR a, int b, bool c, long d):
Horse(a, b),	// �����ٺ������ڳ�ʼ�����캯����
Bird(a, c),
itsNumberBelievers(d)
{
	cout <<"Pegasus����\n";
}


//*************************************************************
int main()
{
	// �����������캯��
	Pegasus* pPeg = new Pegasus(Yellow, 5, true, 10);

	pPeg->Fly();		// ���� Bird ��
	pPeg->Whinny();		// ���� Horse ��

	cout << pPeg->GetHeight();

	if (pPeg->GetMigration())	// true
		cout <<"Gettrue";
	else
		cout <<"getfalse";

	cout <<pPeg->GetNumberBelievers() << endl;


//	COLOR c = pPeg->GetColor();	�������д����Ϊ���������ж��иú��� GetColor()���������޷����֣�

	COLOR c = pPeg->Bird::GetColor();
	cout << c;
	
	delete pPeg;	// ɾ��ָ��ǰ����������������
	return 0;
}