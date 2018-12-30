#include <iostream.h>
int main()
{
	int a,b,c;
	cout <<"enter three number: \n";
	cin >> a;
	cin >> b;
	cin >> c;
	if(c=(a-b))//只有一个等号那么括号里面的值只有两种可能：0或者1；即：假或者真。
		//只要a=b程序将执行else。只要a不等于b，程序就执行if下面的。同时也发生了赋值语句c=a-b,c的值也会改变；
	{
		cout <<"a:  ";
		cout <<a;
		cout <<"minus b:   ";
		cout <<b;
		cout <<"equals c: ";
		cout <<c<<endl;//
	}
	else
		cout <<"a-b don't equals c:    "<<endl;
	return 0;
}//