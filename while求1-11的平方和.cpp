#include <iostream.h>
int F(int);
int main()
{
	int i=1,sum=0;
	while(i<=11)
	{
		sum+=F(i);
		i++;
	}
	cout <<"1-10平方和为："<<sum<<endl;
	return 0;
}
int F(int a)
{
	return a*a;
}