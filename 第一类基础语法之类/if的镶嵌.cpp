#include <iostream.h>
int main()
{
	int a,b;
	cout <<"enter a:";
	cin >> a;
	cout <<"enter b:";
	cin >> b;
	cout <<endl;
	if(a>b)
		cout <<"good! \n";
	if(a<b)
	{
		cout <<"ah fuck! \n";
	    cout <<"you \n";//如果不加大括号，那么此行将永远输出
	}
	if(a==b)
	{
		cout <<"纳尼？！ 你有没有搞错，这怎么可能！";
		cout <<"从新输入b:";
		cin >> b;
		if(a>b)
			cout <<"soso. \n";
		if(a<b)
			cout <<"goooood.. \n";
		if(a==b)
			cout <<"oh summe a bitch! \n";
	}
	cout <<"谢谢惠顾 \n";
	return 0;
}



