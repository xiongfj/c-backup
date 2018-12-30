#include <iostream>
using namespace std;
int F(int);
int main()
{
	int i=1,sum=0;
	for(i;i<=11;i++)
		sum+=F(i);
	cout <<"1-10平方和为："<<sum<<endl;
	return 0;
}
int F(int a)
{
	return a*a;
}