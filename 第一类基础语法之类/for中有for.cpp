#include <iostream.h>
int main()
{
	int rows,columns;
	char x;
	cout <<"�������֣���  �У��������ַ���\n";
	cin>>rows>>columns>>x;//x�������ֻ��һ���ַ������ܶ�
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)//ѭ���������for�ٻص�������Ǹ�for����ѭ��
			cout <<x;
		cout <<endl;
	}
	return 0;
}