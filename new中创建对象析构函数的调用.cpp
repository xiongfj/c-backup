#include <iostream.h>

class cat
{
public:
	cat( int a):	age( a )		{ cout << "�Ҵ��͡�\n";   }
	~cat()							{ cout << "�ұ������ˡ�\n"; }
	int getage()					{ return  age;				}

private:
	int age;
};


class eat
{
public:
	eat( cat* a ):	e( a )	{ cout <<"eat�Ĺ���\n";			}
	~eat()					{ delete e; cout << "ljksd��\n";}

	cat* gete()				{ return e;						}

private:
	cat* e;
};


void main()
{
	// �� new �д����Ķ����ڳ������ʱ�����Զ���������������ֻ�� delete ��Ż������������
	cat* p = new cat( 100 );
	eat* a = new eat( p );

	cout << a -> gete() -> getage();

	delete a;	// ��ʱɾ���� a ָ��Ҳ����� cat ����������
}