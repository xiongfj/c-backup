#include <iostream.h>

// char** argv 表示指向指针的一堆指针，而数组名就是一个指针，所以一个指针代表一段字符串(被空格分开的)
// 而一堆指针就表示，一堆字符串(一个指针指向一段字符串)

void main( int argc, char** argv )
{
	cout << argc << endl;		// 参数的个数，其中第 0 个自动被设置为该程序的：路径名称

	// 命令行参数在：project>setting>debug>program arguments 输入，用空格表示分开每个 argv[i]
	for ( int i = 0; i < argc; i++ )
		cout << argv[i] << endl;
}