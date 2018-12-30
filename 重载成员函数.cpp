#include <iostream.h>
class Rectangle
{
public:
	Rectangle(int width,int height);
	~Rectangle(){}
	void DrawShape()const;
	void DrawShape(int aWidth,int aHeight)const;
private:
	int itsWidth;
	int itsHeight;
};
Rectangle::Rectangle(int width,int height):

itsWidth(width),
itsHeight(height)
{}//定义与初始化的另一种写法
void Rectangle::DrawShape()const
{
	DrawShape(itsWidth,itsHeight);
}
void Rectangle::DrawShape(int width,int height)const
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			cout <<"*";
		}
		cout <<endl;
	}
}
int main()
{
	Rectangle theRect(30,5);
	theRect.DrawShape();
	theRect.DrawShape(44,8);
	return 0;
}


