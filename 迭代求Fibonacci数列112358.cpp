#include <iostream.h>
double fib(unsigned int);
int main()
{
	unsigned int n;
	double N;
	cout <<"输入所要求的第几个数：";
	while(true)
	{
	cin >>n;
	N=fib(n);
	cout <<"第"<<n<<"个数="<<N<<endl;
	}
	return 0;
}
double fib(unsigned int n)
{
	unsigned int a=1,b=1,c=2;
	if(n<3)
		return 1;
	for(n-=3;n;n--)
	{
		a=b;
		b=c;
		c=a+b;
	}
	return c;
}