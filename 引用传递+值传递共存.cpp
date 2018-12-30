#include <iostream.h>
typedef unsigned short int ushort;
enum errtrue{truee,err};//truee=0,err=1 //枚举型常量会产生一个新的类型 errtrue(该类型与int float等同样使用!!)
errtrue F(ushort,ushort&,ushort&);//申明了一个返回值类型是errtrue的函数!!1
int main()
{
	ushort number,squared,cubed;
	errtrue result;
	cout <<"输入0-20:";
	cin >>number;
	result=F(number,squared,cubed);
	if(result==truee)//也可以把truee写成0
	{
		cout <<number<<endl;  //输出还是原来的number 不会+1
		cout <<squared<<endl; //该值已被被调用函数F改变!!
		cout <<cubed<<endl;   //同上，已改变
	}
	else
		cout <<"error 输入!!";
	return 0;
}
errtrue F(ushort n, ushort &a, ushort &b)//后面两个形参使用引用传递，可以改变squared和cubed的原值!!
{
	if(n>20)
		return err;   //管你是1还是什么，只要返回的不是truue，if都不成立!!!
	else
	{
		n=n+1;//由于n使用的是纯粹的值传递，所以不改变n的原值!!
		a=n*n;
		b=n*n*n;
		return truee;//管你是0还是什么鬼，返回的是result==truee都能使if成立
	}
}


