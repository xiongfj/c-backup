#include <iostream.h>
int main()
{
	int sum=0,i=1;
	for(i;i<=10;i++)//for里面的++是在循环回来后再加1
		sum=sum+i;
	cout <<"1-10和="<<sum<<endl;
	return 0;
}
