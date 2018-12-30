#include <iostream.h>

void f1();
void f2();
void f3(void (*) ());	// 以函数指针作为参数的申明写法


void main()
{
	void (*p) ();
	bool quit = false;
	int i;

	while (!quit)
	{
		cout << "输出1-2：";
		cin  >> i;

		switch (i)
		{
			case 1:	p = f1;	break;
			case 2:	p = f2;	break;
			default:	quit =true;	break;
		}
		f3(p);
	}
}

void f1()
{
	cout <<"我是f1" << endl;
}

void f2()
{
	cout <<"我是f2" << endl;
}


void f3(void (*pq) ())
{
	pq();
}