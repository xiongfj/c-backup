#include <iostream.h>
void myfunction();
int x=5,y=7;
int main()
{
	cout <<"x="<<x<<endl;
	cout <<"y="<<y<<endl;
	myfunction();
	cout <<"x=="<<x<<endl;
	cout <<"y=="<<y<<endl;
	return 0;
}
void myfunction()
{
	int y=10;//�����y����ȫ�ֱ�����yӰ��
	cout <<"x="<<x<<endl;
	cout <<"y="<<y<<endl;
}