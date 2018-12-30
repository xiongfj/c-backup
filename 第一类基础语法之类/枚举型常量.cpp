#include <iostream.h>
int main()
{
	enum days {sunday,monday,tuesday,wednesday,thursday,friday,saturday};
        //默认从左到右符号常量值为0,1,2,3,4....
	//或者enum days {sunday=3,monday,tuesday=21,wednesday,thursday,friday,saturday=87};
	//为初始化的符号常量的值=前一个的值+1；如上monday=4,wednesday=22,thursday=23,
	int choice;
	cout <<"enter a day(0-6): ";
	cin >> choice;
	if(choice ==sunday || choice ==saturday)
		cout <<"你可以愉快的度过周末嘹！\n";
	else
		cout <<"乖乖，继续努力的工作吧！ \n";
	return 0;
}