#include <iostream.h>
void swap(int&x,int &y);
int main()
{
	int x=5,y=10;
	cout <<x<<y<<endl;
	swap(x,y);
	cout <<x<<y<<endl;
	return 0;
}
void swap(int &x,int &y)
{//接收变量的同时，引用了变量
	int temp;
	temp=x;
	x=y;
	y=temp;
}

