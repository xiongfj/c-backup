// main
#include <graphics.h>
#include "list.h"

int main(void)
{
	list <IMAGE> s;			// ָ�� list.h ����� T ���� IMAGE ����
	IMAGE img;

	loadimage( &s.t, "mm.jpg" );
	initgraph(640,480);

	putimage(10, 10, &s.t );

	system("pause");
	closegraph();
	return 0;
}



//list.h
#include<stdio.h>
#include<stdlib.h>

template<class T>
class list
{
public: 
	T t;			// ��������Ķ����ʱ����Զ����� T �ľ������ͷ����ڴ�ռ�
};
