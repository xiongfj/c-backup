#include <iostream.h>
int main()
{
	unsigned int i=0,j=1,n,counter=1;
		cout <<"��������Ҫ��ĵڼ�������:";
	    cin >>n;
	for(i;;)
	{ 
		if(n<3)
		{
			cout <<"Fibonacci����1,1,2,3,5,8�ĵ�"<<n<<"����Ϊ1\n";
			break;
		}
		i=i+j;
		counter++;
		if(n==counter)
		{
			cout <<"Fibonacci����1,1,2,3,5,8�ĵ�"<<n<<"����Ϊ��"<<i;
			break;
		}
		j=j+i;
		counter++;
		if(n==counter)
		{
		    cout <<"Fibonacci����1,1,2,3,5,8�ĵ�"<<n<<"����Ϊ��"<<j;
			break;
		}
	}
	return 0;
}