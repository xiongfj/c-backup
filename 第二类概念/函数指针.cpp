#include <iostream.h>

void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);

void main()
{
	// 申明了一个函数指针
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
			// 函数名本身就是一个指向自身的指针
			case 1:		pFunc = GetVals;	break;
			case 2:		pFunc = Square;		break;
			case 3:		pFunc = Cube;		break;
			case 4:		pFunc = Swap;		break;
			default:	fQuit = true;		break;
		}

		if (fQuit)
			break;

		// 输出原来值
		PrintVals(valOne, valTwo);

		// 直接用函数指针代替原来函数名即可调用该函数
		pFunc(valOne, valTwo);

		// 输出改变后的值
		PrintVals(valOne, valTwo);
	}
}


// 输出
void PrintVals(int x, int y)
{
	cout <<x << "-" << y << endl;
}


// 平方
void Square(int& rx, int& ry)
{
	rx *= rx;
	ry *= ry;
}


// 立方
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


// 交换
void Swap(int& rx, int& ry)
{
	int temp;

	temp = rx;
	rx = ry;
	ry =temp;
}


// 更换
void GetVals(int& rval1, int& rval2)
{
	cout << "输入one：";
	cin  >> rval1;

	cout << "输出two：";
	cin  >> rval2;
}