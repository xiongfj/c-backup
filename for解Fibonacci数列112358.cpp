#include <iostream.h>
int main()
{
	unsigned int i=0,j=1,n,counter=1;
		cout <<"输入你所要求的第几个数？:";
	    cin >>n;
	for(i;;)
	{ 
		if(n<3)
		{
			cout <<"Fibonacci数列1,1,2,3,5,8的第"<<n<<"个数为1\n";
			break;
		}
		i=i+j;
		counter++;
		if(n==counter)
		{
			cout <<"Fibonacci数列1,1,2,3,5,8的第"<<n<<"个数为："<<i;
			break;
		}
		j=j+i;
		counter++;
		if(n==counter)
		{
		    cout <<"Fibonacci数列1,1,2,3,5,8的第"<<n<<"个数为："<<j;
			break;
		}
	}
	return 0;
}