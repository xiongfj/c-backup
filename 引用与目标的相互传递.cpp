#include <iostream.h>
int main()
{
	int a=11;
	int &A=a;
	cout <<a<<endl;
	cout <<A<<endl;
	cout <<&a<<endl;
	cout <<&A<<endl;

	a=22;
	cout <<a<<endl;
	cout <<A<<endl;
	cout <<&a<<endl;
	cout <<&A<<endl;

	A=33;//不管a或者A怎么被赋值，都不会改变它们原先的地址!!!!!//一般不建议重新给引用赋值
	cout <<a<<endl;
	cout <<A<<endl;
	cout <<&a<<endl;
	cout <<&A<<endl;

	return 0;
}