#include <iostream.h>

void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);

void main()
{
	// ������һ������ָ��
	void (*pFunc) (int&, int&);

	bool fQuit = false;
	int valOne = 1, valTwo = 2;
	int choice;

	while (fQuit == false)
	{
		cout << "0quit/1change/2square/3cube/4swap:";
		cin  >> choice;

		switch (choice)
		{
			// �������������һ��ָ�������ָ��
			case 1:		pFunc = GetVals;	break;
			case 2:		pFunc = Square;		break;
			case 3:		pFunc = Cube;		break;
			case 4:		pFunc = Swap;		break;
			default:	fQuit = true;		break;
		}

		if (fQuit)
			break;

		// ���ԭ��ֵ
		PrintVals(valOne, valTwo);

		// ֱ���ú���ָ�����ԭ�����������ɵ��øú���
		pFunc(valOne, valTwo);

		// ����ı���ֵ
		PrintVals(valOne, valTwo);
	}
}


// ���
void PrintVals(int x, int y)
{
	cout <<x << "-" << y << endl;
}


// ƽ��
void Square(int& rx, int& ry)
{
	rx *= rx;
	ry *= ry;
}


// ����
void Cube(int& rx, int& ry)
{
	int temp;
	
	temp = rx;
	rx *= rx;
	rx *= temp;

	temp = ry;
	ry *= ry;
	ry *= temp;
}


// ����
void Swap(int& rx, int& ry)
{
	int temp;

	temp = rx;
	rx = ry;
	ry =temp;
}


// ����
void GetVals(int& rval1, int& rval2)
{
	cout << "����one��";
	cin  >> rval1;

	cout << "���two��";
	cin  >> rval2;
}