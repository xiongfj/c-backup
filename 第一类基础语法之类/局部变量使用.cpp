#include <iostream.h>
float convert(float);
int main()
{
	float tempfer,tempcel;
	cout <<"enter a 华氏温度：";
	cin >> tempfer;
	tempcel=convert(tempfer);//调用函数，将常量传给其处理后再返回
	cout <<"转化后的摄氏温度为：";
	cout <<tempcel<<endl;
	return 0;
}
float convert(float b)//也可以在大括号里面只写一句 return ((b-32)*5)/9;效果相同
{
	float a;//定义了局部变量，只在这个函数conver有效
	a=((b-32)*5)/9;
	return a;
}
