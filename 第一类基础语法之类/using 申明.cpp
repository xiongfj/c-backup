#include <iostream.h>



namespace Window_name_Space
{
	double x = 1.9, y = 2.9;
	int a = 200, b = 100;
}

namespace Space = Window_name_Space;	// �����ռ�������򻯴���

int a = 88, b = 22;		// ȫ�����ݿ����� using ����ͬ��!!!

void main()
{
	//int a = 90;	����!!�޷�����ʹ�������ķ�ʽ����� �����ռ��Ա
	int x = 44;
	
	using Space::y;		// ֻҪͬ����������û�иñ������;Ϳ����� using��������
	cout << y << endl;	// ���ң����Ḳ�����ڲ��������������ͬ���� y
	{
		int y = 9;
		cout << y << endl;
	}

	// ʹ�������ķ�ʽ��������������(��ȫ��)�������ڶ�����������ĳ�Ա��������ͬ������!!!

	using Space::a;			// ����д���� using������ֻ������һ����Ա a��������Ա�޷�ֱ��ʹ��
	cout << a << endl;
	cout << Space::b << endl;

	{
		using Space::x;		// using���������Ը�������������(����ȫ�ֱ���)����ͬ����!!!
		cout << x << endl;
	}
}