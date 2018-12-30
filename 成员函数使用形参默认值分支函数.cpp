#include <iostream.h>
class Rectangle
{
public:
	Rectangle(int width,int height);
	~Rectangle(){}
	void DrawShape(int a,int b,bool c=false)const;
private:
	int itsWidth;
	int itsHeight;
};
Rectangle::Rectangle(int width,int height):
itsWidth(width),
itsHeight(height)
{}//�����������ʼ����Ա����һ��д��
void Rectangle::DrawShape(int a,int b,bool c)const
{
	int printWidth,printHeight;
	if(c==true)
	{
		printWidth=itsWidth;
		printHeight=itsHeight;
	}
	else
	{
		printWidth=a;
		printHeight=b;
	}
	for(int i=0;i<printHeight;i++)
	{
		for(int j=0;j<printWidth;j++)
		{
			cout <<"*";
		}
		cout <<endl;
	}
}
int main()
{
	Rectangle theRect(30,5);
	theRect.DrawShape(0,0,true);
	theRect.DrawShape(40,7);
	return 0;
}


