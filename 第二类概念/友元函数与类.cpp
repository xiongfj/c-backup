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

	friend TEST;			// 开了一个接口给 TEST 类里面的所有函数
};


class TEST		// 该类里面的函数可以用对象直接访问私有数据！！
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