#include <iostream.h>
int f(int);
int main()
{
	int a,b,big,small;
	cout <<"����������Ȼ����";
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
	int i,sum=0;
	for(i=small;i<=big;i++)
		sum+=f(i);
	cout <<small<<"��"<<big<<"�ܺ�Ϊ��"<<sum<<endl;
	return 0;
}
int f(int x)
{
	return x*x;
}



