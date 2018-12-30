#include <iostream.h>

class Cat
{
public:
	Cat(int age):	itsAge(age)	{HowManyCats++;}
	virtual ~Cat()	{HowManyCats--;}
	virtual int GetAge()	{return itsAge;}
	virtual void SetAge(int age)	{itsAge = age;}
	virtual int GetHowMany()	{return HowManyCats;}

private:
	int itsAge;

	// ��̬��Ա�����Ǹ������ж����еģ�
	// ����˵��������һ�����󽫴˾�̬��Ա���ݸ�ֵΪ10,
	// ��ô����ǰ���ж��ٸ������丳ֵΪ������ 10 ��ֵ��
	// ���ղ�������һ��������ú�������ȡ����
	// �õ���ֵ��Զ�� 10 (��Ȼǰ���� 10 ��������õ�ֵ)
	static int HowManyCats;
};

int Cat::HowManyCats = 0;


void main()
{
	Cat* CatHouse[5];

	for (int i = 0; i < 5; i++)
		CatHouse[i] = new Cat(i);

	for (int j = 0; j < 5; j++)
	{
		// ȥ��ɾ��ָ�����������ʼ����� 5
		cout << CatHouse[j]->GetHowMany() << endl;


		cout << CatHouse[j]->GetAge() + 2 << endl;

		//delete CatHouse[j];
		CatHouse[j] = 0;
	}
}