#include <iostream.h>
#include <windows.h>
#include <conio.h>

// 函数模板申明可用 class 或 typename
template < typename T, class S >
T func( T t, S s );


void main()
{
	int n = 10;
	func( n, "草泥马" );
	getch();
}


template < typename T, class S >
T func( T t, S s )
{
	cout << t << endl << s << endl;
	return t;
}