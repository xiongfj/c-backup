#include <iostream.h>
int doubler(int);
int main()
{
	int result=0,input;
	cout <<"enter a number between 0 and 10,000 to double: \n";
	cin >> input;
	cout <<"before doubler is called...";
	cout <<"\ninput:"<<input<<"doubled:"<<result<<endl;
	result=doubler(input);
	cout <<"\nback from double...\n";
	cout <<"input"<<input<<"doubled:"<<result<<endl;
	return 0;
}
int doubler(int a)
{
	if(a<=10000)
	{
		return a*2;//���return������ͬһ���������棬��Ϊif else��Ե�ʣ�����û�ң�ֻ�ܱ��뵽һ��return�����������á�
	cout <<"���в��������";
	}
	else
		return a<10000;//���a����10000����ôdouble��ֵ��0����Ϊa<10000Ϊ�٣���a>10000�޷�����ȷ��ֵ������ֻ��Ϊ0��.
	cout <<"���л��������";
}
