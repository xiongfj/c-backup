#include <iostream.h>
#include <string.h>

class String
{
public:
	String();
	String( const char* const );	// �ù��캯������������ char ת���ɱ���Ķ���
	String( const String& );
	~String();

	char&			operator []		( int							);
	char			operator []		( int							) const;
	String			operator +		( const String&					);

	// �ú����Ǹ�������Ԫ����!!!�м�Ӹ����򣬼��������Ǹ�����Ǹ�����Ϊ�������Ԫ����!!!
	friend String /* A::*/ operator +		( const String&, const String&	);

	//
	friend ostream& operator << ( ostream& L, String& S );

	void			operator +=		( const String&					);
	String&			operator =		( const String&					);

	int GetLen()			const	{ return itsLen;	}
	const char* GetString() const	{ return itsString; }

private:
	String( int );
	char* itsString;
	unsigned short itsLen;
};


String::String()
{
	itsString = new char[1];

	itsString[0] = '\0';
	itsLen = 0;
}


String::String( int len )
{
	itsString = new char[len + 1];

	for ( int i = 0; i < len + 1; i++ )
		itsString[i] = '\0';

	itsLen = len;
}


String::String( const char* const cString )
{
	itsLen = strlen( cString );
	itsString = new char[itsLen + 1];

	for ( int i = 0; i < itsLen; i++ )
		itsString[i] = cString[i];

	itsString[itsLen] = '\0';
}


String::String( const String& rhs )
{
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];

	for ( int i = 0; i < itsLen; i++ )
		itsString[i] = rhs[i];

	itsString[itsLen] = '\0';
}


String::~String()
{
	delete [] itsString;
	itsLen = 0;
}


String& String::operator = ( const String& rhs )
{
	if ( this == &rhs )
		return *this;

	delete [] itsString;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];

	for ( int i = 0; i < itsLen; i++ )
		itsString[i] = rhs[i];

	itsString[itsLen] = '\0';

	return *this;
}


char& String::operator [] ( int offset )
{
	if ( offset > itsLen )
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}


char String::operator [] ( int offset ) const
{
	if ( offset > itsLen )
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}


// �ú�������������� char* ��Ϊ�����������㣬Ҳ����ֻ������� char ֻ�ܷ��� + �ź����������!!!

String String:: operator + ( const String& rhs )
{
	int totalLen = itsLen + rhs.GetLen();
	String temp( totalLen );

	int i, j;
	for ( i = 0; i < itsLen; i++ )
		temp[i] = itsString[i];

	for ( j = 0, i = itsLen; j < rhs.GetLen(); j++, i++ )
		temp[i] = rhs[j];

	temp[totalLen] = '\0';
	return temp;
}

// �ú���ʹ�ÿ���ʹ�� c1 + s1������ֻ��ʹ�� s1 + c1( �൱��s1.operator(c1) )

String operator + ( const String& lhs, const String& rhs )
{
	int totalLen = lhs.GetLen() + rhs.GetLen();
	String temp( totalLen );

	int i, j;
	for ( i = 0; i < lhs.GetLen(); i++ )
		temp[i] = lhs[i];

	for ( j = 0, i = lhs.GetLen(); j < rhs.GetLen(); j++, i++ )
		temp[i] = rhs[j];

	temp[totalLen] = '\0';
	return temp;
}

// ��Ԫ��������Ķ������ֱ�ӵ��ñ����˽�г�Ա!!!

ostream& operator << ( ostream& l, String& s )
{
	l << s.itsString;
	return l;
}

void main()
{
	String s1( "String one" );
	String s2( "String two" );
	String s3, s4, s5;

	char* c1 = { "C ~ String one" };

	cout << s1 << endl;			// ���������˲�������� <<�����Կ���ֱ��������󣬶����ؼ�ӵ������!!!
	cout << s2.GetString() << endl;
	cout << c1 << endl;

	s3 = s1 + s2;
	cout << s3 << endl;

	// c1 �� + �ź�����õ��� s1.operator( c1 )
	s4 = s1 + c1;	// c1 �����ʵĹ��캯��ת������ String ��Ķ���
	cout << s4 << endl;

	s5 = c1 + s2;	// c1 �� + ��ǰ����õ��� operator( c1, s2 )
	cout << s5 << endl;
}