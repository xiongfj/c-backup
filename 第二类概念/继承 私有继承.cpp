#include <iostream.h>


class A
{
public:
	A()		{ cout << "�ұ�������"; }
	~A()	{}
	void set( int age )		{ itsage = age; }
	int getage()	{ return itsage; }
	void speaka()	{ cout << "�ұ�ʹ����\n"; }

private:
	int itsage;
};

class B : private A
{
public:
	void speak()	{ speaka(); }		// ֻ���ں������ڲ��ܷ��ʻ���ĺ���!!!
	int get()		{ return age; }

private:
	int age;
};


void main()
{
	B b;
	b.speak();

	//b.speaka();	����˽�м̳ж�������Ķ�����ֱ�ӷ��ʻ���ĺ���!!!
}