// main
#include <graphics.h>
#include "list.h"

int main(void)
{
	list <IMAGE> s;			// 指定 list.h 里面的 T 代表 IMAGE 类型
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
	T t;			// 创建该类的对象的时候会自动根据 T 的具体类型分配内存空间
};
