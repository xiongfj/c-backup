#include <iostream>
using namespace std;

/********************************/

class TEST;

class Main
{

private:
	char* name;
	int age;

public:
	Main( const char* str )
	{
		age = 21;
		int len = strlen( str );
		name = new char[len + 1];
		strcpy( name, str );
	}

	friend TEST;			// ����һ���ӿڸ� TEST ����������к���
};


class TEST		// ��������ĺ��������ö���ֱ�ӷ���˽�����ݣ���
{
public:
	void Dance( Main& obj )
	{
		cout << obj.age << "---" << obj.name << endl;
	}
};

void main()
{
	Main obj("jack");
	TEST test;
	test.Dance( obj );
}