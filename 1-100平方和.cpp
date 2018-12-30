#include <iostream>
using namespace std;
int F(int);
int main()
{
	int i=1,sum=0;
	for(i;i<101;i++)
		sum+=F(i);
	cout <<"1-100平方和为："<<sum<<endl;
	return 0;
}
int F(int a)
{
	return a*a;
}