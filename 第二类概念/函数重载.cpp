#include <iostream.h>
int Double1(int);//数字1234有没有都无所谓。。。看个人爱好
long Double2(long);
float Double3(float);
double Double4(double);
int main()
{
	int myInt=6500;
	long myLong=65000;
	float myFloat=6.5F;
	double myDouble=6.5e20;

	int doubledInt;
	long doubledLong;
	float doubledFloat;
	double doubledDouble;

	cout <<myInt<<endl;
	cout <<myLong<<endl;
	cout <<myFloat<<endl;
	cout <<myDouble<<endl;

	doubledInt=Double1(myInt);//1234
	doubledLong=Double2(myLong);
	doubledFloat=Double3(myFloat);
	doubledDouble=Double4(myDouble);
		
	cout <<doubledInt<<endl;
	cout <<doubledLong<<endl;
	cout <<doubledFloat<<endl;
	cout <<doubledDouble<<endl;
	return 0;
}

int Double1(int a)//1234
{
	return 2*a;
}
long Double2(long a)
{
	return 2*a;
}
float Double3(float a)
{
	return 2*a;
}
double Double4(double a)
{
	return 2*a;
}


//什么函数重载？！ 只是省下了我们思考函数名的那么一丁点儿时间。


