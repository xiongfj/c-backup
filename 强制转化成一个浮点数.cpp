#include <iostream.h>
void intdiv(int x,int y)
{
	int z=x/y;
	cout <<"z:"<<z<<endl;
}

void floatdiv(int x,int y)
{
	float a=(float)x;
	float b=static_cast<float>(y);
	float c=a/b;
	cout <<"c:"<<c<<endl;
}
int main()
{
	int x=5,y=3;
	intdiv(x,y);
	floatdiv(x,y);
	return 0;
}