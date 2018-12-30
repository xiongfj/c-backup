#include <iostream.h>
int main()
{
	int a,b;
	cout <<"hello，大家好！很高心你们能来到我的vc窗口！现在请按照提示操作。\n";
	cout <<"请随便输入一个数字：\n";
	cin >> a;
	cout <<"嗯嗯，真是乖乖！哇啊哈哈！请继续往下操作。\n";
	cout <<"now 继续输入第二个你的幸运数字：\n";
	cin >> b;
	cout <<endl;
	if(a>=b)
	{
		if((a%b)==0)
		{
			if(a==b)
			{
				cout <<"奶奶的 你怎么可以输入两个相同的数字！\n";
				cout <<"再来 ，从新输入！";
					cin >> b;
				if(a==b)
					cout <<"喵了个咪的，都说不能输入两个相同的了，嚓嚓嚓！\n";
				else
					cout <<"嗯嗯，这样才对嘛！乖乖摸摸 \n";
			}
			else
				cout <<"oh 真tm巧了，你的幸运数字被楼上的整除了，你以后将霉运连连! \n";
		}
		else
			cout <<"很好很好！你的幸运数字没有被楼上的整除掉!你的人品将会一如既往的好! \n";
	}
	else
		cout <<"偶买噶，好大好大！大大滴大！ \n";
	return 0;
}