#include <iostream.h>
double fib(unsigned int);
int main()
{
	unsigned int n;
	double N;
	cout <<"������Ҫ��ĵڼ�������";
	while(true)
	{
	cin >>n;
	N=fib(n);
	cout <<"��"<<n<<"����="<<N<<endl;
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