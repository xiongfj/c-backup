#include <iostream.h>
int main()
{
	int counter=0,max;
	cout <<"enter a number: ";
	cin >>max;
	for(;;)
	{
		if(counter<max)
		{
			cout <<"hello! ";
			counter++;
		}
		else//����Ƕ����� ͬ��Ҫʹ�ô�����
		{
			cout <<"������!\n";
		break;
		}
	}
	return 0;
}
