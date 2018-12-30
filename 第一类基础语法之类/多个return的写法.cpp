#include <iostream.h>
int doubler(int);
int main()
{
	int result=0,input;
	cout <<"enter a number between 0 and 10,000 to double: \n";
	cin >> input;
	cout <<"before doubler is called...";
	cout <<"\ninput:"<<input<<"doubled:"<<result<<endl;
	result=doubler(input);
	cout <<"\nback from double...\n";
	cout <<"input"<<input<<"doubled:"<<result<<endl;
	return 0;
}
int doubler(int a)
{
	if(a<=10000)
	{
		return a*2;//多个return能用在同一个函数里面，因为if else的缘故，有你没我（只能编译到一个return），所以能用。
	cout <<"此行不能输出了";
	}
	else
		return a<10000;//如果a大于10000，那么double的值是0；因为a<10000为假，且a>10000无法给出确定值，所以只能为0了.
	cout <<"此行还能输出吗？";
}
