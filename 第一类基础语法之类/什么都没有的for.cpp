#include <iostream.h>
int main()
{
	int counter=0,max;
	cout <<"enter a number: ";
	cin >>max;
	for(;;)
	{
		if(counter<max)
		{
			cout <<"hello! ";
			counter++;
		}
		else//如果是多个语句 同样要使用大括号
		{
			cout <<"超过了!\n";
		break;
		}
	}
	return 0;
}
