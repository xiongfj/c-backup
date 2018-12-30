#include <iostream.h>
int main()
{
	int counter,i=0;
	cout <<"有多少头阿凡达？";
	cin >>counter;
	do
	{
		cout <<"啊!阿凡达!快跑啊!\n";
		counter--;
		i++;
	}while(counter>0);//记得while条件之后要加上分号!!
	cout <<"天啊!好多兽兽!竟然有 "<<i<<"头那么多去!"<<endl;
	return 0;
}