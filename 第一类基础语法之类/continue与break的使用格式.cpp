#include <iostream.h>
int main()
{
	int small,large,skip,target;
	cout <<"enter С��С�е��ĸ����֣�";
	cin>>small>>large>>skip>>target;
	while(small<large && large>0 && small<65535)
	{
		small++;
		if(small%skip==0)
		{
			cout <<"������˼���㱻skip������! "<<small<<endl;
			continue;//��ִ������Ĵ��룬�Ȼص�while
		}
		if(large==target)
		{
			cout <<"��ѽ��large,target���������!"<<large<<endl;
			break;//ѭ�������ˣ�����while�Ĵ����Żص�ѭ���������		}
		large-=2;
	}
	cout <<"while ѭ��������!\n";
	cout <<"\nsmall="<<small<<"large="<<large<<endl;
	return 0;
}