#include <iostream.h>
int menu();
int main()
{
	bool exit=false;//false���Ի���0���������exit��ʼ��Ϊ���١�(���߲���ʼ��exit��exit������Ƿ�0��Ҳ�����棩)����ô������Ǹ�if(exit)����Զ��������ô�ͻ�ֱ��break��forѭ��!
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
		  continue;//Ҳ������break;����
	    case 5:
		  exit=true;//��exit����true��Ϊ�˺����if(exit)��ִ��break����ֹforѭ��
		  break;//���������continue���棬continueֱ�ӻص�for����ִ�������if��
		default:
		  cout <<"������ѡ�Χ!������ѡ�� \n";
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






