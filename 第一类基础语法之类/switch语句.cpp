#include <iostream.h>
int main()
{
	int number;
	cout <<"enter a number1-5:";
	cin>>number;
	switch(number)//大括号开始
	{
	case 0: cout <<"太小了!";
			break;//遇到break才停止，跳出switch，执行return
	case 5: cout <<5<<endl;//如果输入5，那么执行了这段代码后还会接着执行下面case,直到遇到break结束switch
	case 4:cout <<"good!"<<endl;
	case 3: cout <<"better!"<<endl;
	case 2: cout <<"well!"<<endl;
		    break;
	case 1: cout <<"soso!"<<endl;
			break;
	default:cout <<"太大了!"<<endl;//这是默认分支，如果输入的数与case给的值不相等，那么就直接执行该默认语句
		    break;//这个break可以不写，到了此步自动会跳出switch
	}
	return 0;
}

