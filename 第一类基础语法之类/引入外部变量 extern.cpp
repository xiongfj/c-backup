#include <iostream.h>
#include "out_side.cpp"		// 在该文件中有 int out_side = 100;
// 如果out_side.cpp 文件定义是这样的：static int out_side = 100; 那么将无法引入该文件中！因为其限定了不可被引入

// 可以不写 int
extern	int out_side;		// 将 out_side.cpp 内的 out_side 变量作用域引入本文件


void main()
{
	cout << out_side;		// 将其他文件的变量引入了，所以可以获取那个文件中该变量的值。
}