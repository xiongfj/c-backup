#include <iostream.h>
int menu();
int main()
{
	bool exit=false;//false可以换成0，如果不把exit初始化为‘假’(或者不初始化exit（exit本身就是非0，也就是真）)，那么后面的那个if(exit)就永远成立，那么就会直接break掉for循环!
	for(;;)
	{
		int choice=menu();
	    switch(choice)
		{
		case 1:
		  cout <<"Task One! \n";
		  break;
	    case 2:
		  cout <<"Task Two! \n";
	   	  break;
	    case 3:
		  cout <<"Task Three! \n";
		  break;
	    case 4:
		  continue;//也可以用break;代替
	    case 5:
		  exit=true;//让exit代表true，为了后面的if(exit)能执行break，终止for循环
		  break;//这个不能用continue代替，continue直接回到for，不执行下面的if了
		default:
		  cout <<"超出了选项范围!请重新选择。 \n";
		  break;
		}
	    if(exit)
		  break;
	}
	return 0;
}
int menu()
{
	int choice;
	cout <<"******Menu******\n\n";
	cout <<"(1) choice one.\n";
	cout <<"(2) choice two.\n";
	cout <<"(3) choice three.\n";
	cout <<"(4) replay Menu. \n";
	cout <<"(5) Quit. \n\n";
	cout <<":";
	cin>>choice;
	return choice;
}






