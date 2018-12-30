#include <iostream.h>
int main()
{
	int a,b,big,small;
	cout <<"输入两个整数：";
	cin >>a>>b;
	if(a>=b)
	{
		big=a;
		small=b;
	}
	else
	{
		big=b;
		small=a;
	}
	for(int i=small,count=1;i<=big;i++,count++)
	{
		cout <<i<<"-";
	if(count %10 ==0)
		cout <<endl;
	}
	return 0;
}

