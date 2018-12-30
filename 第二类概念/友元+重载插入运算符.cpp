#include <iostream.h>
#include <string.h>

class String
{
public:
	String();
	String( const char* const );	// 该构造函数负责把类外的 char 转换成本类的对象
	String( const String& );
	~String();

	char&			operator []		( int							);
	char			operator []		( int							) const;
	String			operator +		( const String&					);

	// 该函数是个类外友元函数!!!中间加个类域，即可设置那个类的那个函数为本类的友元函数!!!
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


// 该函数可以已类外的 char* 作为参数进行运算，也就是只能类外的 char 只能放在 + 号后面进行运算!!!

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

// 该函数使得可以使用 c1 + s1，否则只能使用 s1 + c1( 相当于s1.operator(c1) )

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

// 友元函数里面的对象可以直接调用本类的私有成员!!!

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

	cout << s1 << endl;			// 由于重载了插入运算符 <<，所以可以直接输出对象，而不必间接调用输出!!!
	cout << s2.GetString() << endl;
	cout << c1 << endl;

	s3 = s1 + s2;
	cout << s3 << endl;

	// c1 在 + 号后面调用的是 s1.operator( c1 )
	s4 = s1 + c1;	// c1 被合适的构造函数转换成了 String 类的对象
	cout << s4 << endl;

	s5 = c1 + s2;	// c1 在 + 号前面调用的是 operator( c1, s2 )
	cout << s5 << endl;
}