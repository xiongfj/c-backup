#include <conio.h>
#include <iostream.h>

class TEXT
{
public:
	int value;
	TEXT* Next;

	TEXT( int m )
	{
		value = m;
	}
};

void Change( TEXT* pt );

void main()
{
	TEXT* p1 = new TEXT(1);
	TEXT* p2 = new TEXT(2);
	TEXT* p3 = new TEXT(3);

	p1->Next = p2;
	p2->Next = p3;
	p3->Next = NULL;

	Change( p1 );
	cout << p1->value << endl;		// ��� 1

	getch();
}

void Change( TEXT* p )			// p �� main ���� p1 ��һ��������ֻ�����Ǹտ�ʼ��ʱ��ָ��ͬһ�����ݶ���
{
	p = p->Next;
	cout << p->value << endl;		// ��� 2
}