#include <iostream.h>



namespace Space
{
	double x = 1.9, y = 2.9;
	int a = 200, b = 100;
}

int a = 88, b = 22;			// 否则不知道该用哪个!!因为没有局部变量来同时覆盖他们两个!!

void main()
{
	//int a = 1, b = 2;		// 如果注释掉这行就会出现 error !! 因为全局变量与命名空间不能有相同的变量名!!

	{
		using namespace Space;
		cout << a << endl << b << endl;		// a，b 会被局部变量覆盖掉!!!
	}

	{
		using namespace Space;
		cout << x << endl << y << endl;		// 1.9   2.9
	}

	//cout << x << y;		错误！ 该程序块未引入命名空间
}