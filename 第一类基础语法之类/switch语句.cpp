#include <iostream.h>
int main()
{
	int number;
	cout <<"enter a number1-5:";
	cin>>number;
	switch(number)//�����ſ�ʼ
	{
	case 0: cout <<"̫С��!";
			break;//����break��ֹͣ������switch��ִ��return
	case 5: cout <<5<<endl;//�������5����ôִ������δ���󻹻����ִ������case,ֱ������break����switch
	case 4:cout <<"good!"<<endl;
	case 3: cout <<"better!"<<endl;
	case 2: cout <<"well!"<<endl;
		    break;
	case 1: cout <<"soso!"<<endl;
			break;
	default:cout <<"̫����!"<<endl;//����Ĭ�Ϸ�֧��������������case����ֵ����ȣ���ô��ֱ��ִ�и�Ĭ�����
		    break;//���break���Բ�д�����˴˲��Զ�������switch
	}
	return 0;
}

