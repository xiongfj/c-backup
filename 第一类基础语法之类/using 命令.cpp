#include <iostream.h>



namespace Space
{
	double x = 1.9, y = 2.9;
	int a = 200, b = 100;
}

int a = 88, b = 22;			// ����֪�������ĸ�!!��Ϊû�оֲ�������ͬʱ������������!!

void main()
{
	//int a = 1, b = 2;		// ���ע�͵����оͻ���� error !! ��Ϊȫ�ֱ����������ռ䲻������ͬ�ı�����!!

	{
		using namespace Space;
		cout << a << endl << b << endl;		// a��b �ᱻ�ֲ��������ǵ�!!!
	}

	{
		using namespace Space;
		cout << x << endl << y << endl;		// 1.9   2.9
	}

	//cout << x << y;		���� �ó����δ���������ռ�
}