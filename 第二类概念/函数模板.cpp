#include <iostream.h>
#include <windows.h>
#include <conio.h>

// ����ģ���������� class �� typename
template < typename T, class S >
T func( T t, S s );


void main()
{
	int n = 10;
	func( n, "������" );
	getch();
}


template < typename T, class S >
T func( T t, S s )
{
	cout << t << endl << s << endl;
	return t;
}