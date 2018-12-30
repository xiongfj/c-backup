#include <iostream>
using namespace std;


/********************************/

class TestFriend
{
public:
	TestFriend( const char* );
	friend ostream& operator << ( ostream& fout, const TestFriend& tf );		// ���ֻ����������������

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

// ��Ԫ������������ĳ�Ա!!��û�� this ָ�룬����Ҫ�����������������������

// ���ڹ��С�˽�в���û��ʲô����

// �����������������ϣ�������
ostream& operator << ( ostream& fout, const TestFriend& tf )
{
	fout << tf.p;				// ��ʹ��˽������Ҳ����ֱ���ö������
	fout << TestFriend::autor << endl;						// ��̬���ݷ����ճ�

	return fout;
}