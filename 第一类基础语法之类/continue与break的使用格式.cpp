#include <iostream.h>
int main()
{
	int small,large,skip,target;
	cout <<"enter 小大小中的四个数字：";
	cin>>small>>large>>skip>>target;
	while(small<large && large>0 && small<65535)
	{
		small++;
		if(small%skip==0)
		{
			cout <<"不好意思，你被skip整除了! "<<small<<endl;
			continue;//不执行下面的代码，先回到while
		}
		if(large==target)
		{
			cout <<"哎呀，large,target你们相等了!"<<large<<endl;
			break;//循环结束了，跳出while的大括号回到循环外面继续		}
		large-=2;
	}
	cout <<"while 循环结束了!\n";
	cout <<"\nsmall="<<small<<"large="<<large<<endl;
	return 0;
}