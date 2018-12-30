#include <iostream.h>

class cat
{
public:
	cat( int a):	age( a )		{ cout << "我打酱油、\n";   }
	~cat()							{ cout << "我被调用了、\n"; }
	int getage()					{ return  age;				}

private:
	int age;
};


class eat
{
public:
	eat( cat* a ):	e( a )	{ cout <<"eat的构、\n";			}
	~eat()					{ delete e; cout << "ljksd、\n";}

	cat* gete()				{ return e;						}

private:
	cat* e;
};


void main()
{
	// 在 new 中创建的对象在程序结束时不会自动调用析构函数，只有 delete 后才会调用析构函数
	cat* p = new cat( 100 );
	eat* a = new eat( p );

	cout << a -> gete() -> getage();

	delete a;	// 此时删除的 a 指针也会调用 cat 的析构函数
}