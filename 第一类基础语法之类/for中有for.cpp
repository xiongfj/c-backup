#include <iostream.h>
int main()
{
	int rows,columns;
	char x;
	cout <<"输入数字：行  列，再输入字符：\n";
	cin>>rows>>columns>>x;//x的输入的只能一个字符，不能多
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)//循环完了这个for再回到上面的那个for接着循环
			cout <<x;
		cout <<endl;
	}
	return 0;
}