#include <iostream.h>



namespace Window_name_Space
{
	double x = 1.9, y = 2.9;
	int a = 200, b = 100;
}

namespace Space = Window_name_Space;	// 命名空间别名，简化代码

int a = 88, b = 22;		// 全局数据可以与 using 申明同存!!!

void main()
{
	//int a = 90;	错误!!无法覆盖使用申明的方式引入的 命名空间成员
	int x = 44;
	
	using Space::y;		// 只要同层作用域内没有该变量，就就可以用 using申明引入
	cout << y << endl;	// 并且，不会覆盖其内层作用域里面的相同数据 y
	{
		int y = 9;
		cout << y << endl;
	}

	// 使用申明的方式，在其作用于内(非全局)，不能在定义与其引入的成员的名称相同的数据!!!

	using Space::a;			// 这种写法叫 using申明，只引入了一个成员 a，其他成员无法直接使用
	cout << a << endl;
	cout << Space::b << endl;

	{
		using Space::x;		// using申明，可以覆盖其作用域外(包括全局变量)的相同数据!!!
		cout << x << endl;
	}
}