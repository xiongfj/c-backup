#include <iostream.h>
int main()
{
	int counter=0;//如果不初始化，将无限循环
	for(;counter<5;)
	{
		cout <<"looping!";
		counter+=1;
	}
	cout <<counter<<endl;
	return 0;
}