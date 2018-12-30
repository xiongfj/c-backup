#include <iostream.h>
int Area(int length,int width);//申明了一个函数原型，带分号，这两个参量名无意义，或者不写参量名。
int main()
{
	int lengthofyard,widthofyard,areaofyard;
	cout <<"\nhow wide is your yard?";
	cin >> widthofyard;
	cout <<"\nhow long is your yard?";
	cin >> lengthofyard;
	areaofyard=Area(lengthofyard,widthofyard);//将输入的变元传递给申明的函数
	cout <<"\nyour yard is:"<<areaofyard;
	cout <<"square feel \n\n";
	return 0;
}
int Area(int yardlength,int yardwidth)//定义函数，不带分号
{
	return yardlength*yardwidth;//函数的内容，如何处理接受到得变量，此时定义函数的变量的名字任意，不用跟传递过来的变元名或函数原型里的变量名相同
}
