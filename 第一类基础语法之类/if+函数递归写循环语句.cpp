#include <iostream.h>
int F(int);
int s=0;
int main()
{
	int sum,n=50;
	sum=F(n);
	cout <<"50�ӵ�100�ܺ�Ϊ��"<<sum<<endl;
	return 0;
}
int F(int n)
{
	if(n>100)
		return s;
	else
	{
		s=s+n;
		n++;
	}
	return F(n);
}
