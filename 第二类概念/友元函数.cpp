#include <iostream>
using namespace std;


/********************************/

class TestFriend
{
public:
	TestFriend( const char* );
	friend ostream& operator << ( ostream& fout, const TestFriend& tf );		// 最多只能有两个参数？！

private:
	char* p;
	unsigned int len;
	static char autor[40];
};
char TestFriend::autor[40];

/*********************************/

void main()
{
	TestFriend tf( "I am friend function() " );
	cout << tf << endl;
}

/*********************************/

//
TestFriend::TestFriend( const char* str )
{
	len = strlen( str );
	p = new char[ len + 1 ];

	for ( int i = 0; i < len; i++ )
		p[i] = str[i];

	p[len] = '\0';
	strcpy( autor, "\n---xiongfj test---" );
}

// 友元函数不属于类的成员!!，没有 this 指针，所以要用两个参数才能重载运算符

// 放在共有、私有部分没有什么区别

// 参数不能有三个以上？？！！
ostream& operator << ( ostream& fout, const TestFriend& tf )
{
	fout << tf.p;				// 即使是私有数据也可以直接用对象访问
	fout << TestFriend::autor << endl;						// 静态数据访问照常

	return fout;
}