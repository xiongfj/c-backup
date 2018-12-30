#include <iostream.h>
class Point
{
public:

	void SetX(int x){itsX=x;}
	void SetY(int y){itsY=y;}
	int GetX()const{return itsX;}
	int GetY()const{return itsY;}
private:
	int itsX;
	int itsY;
};

class Rectangle
{
public:
	Rectangle(int top,int left,int bottom,int right);
	Rectangle(Rectangle&){cout <<"复制构造函数-------\n";}
	~Rectangle(){cout <<"析构函数iiiiiiiiiiiiiiii\n";}

	int GetTop()const{return itsTop;}//访问或输出函数，作用是把私有成员变量的值返回给main函数
	int GetLeft()const{return itsLeft;}
	int GetBottom()const{return itsBottom;}
	int GetRight()const{return itsRight;}
	
	Point GetUpperLeft(Rectangle a) const {return itsUpperLeft;}//访问函数，为了访问并输出私有类成员itsUpperLeft等四个
	Point GetLowerLeft() const {return itsLowerLeft;}
	Point GetUpperRight() const {return itsUpperRight;}
	Point GetLowerRight() const {return itsLowerRight;}//类里面的类也可以访问，如此访问即可

	void SetUpperLeft(Point a) {itsUpperLeft=a;}//用对象a作为函数的参数，
	void SetLowerLeft(Point a) {itsLowerLeft=a;}//这些函数的作用是用对象设置私有的Point对象
	void SetUpperRgiht(Point a) {itsUpperRight=a;}
	void SetLowerRight(Point a) {itsLowerRight=a;}

	void SetTop(int a) {itsTop=a;}//设置私有的int成员变量
	void SetLeft(int a) {itsLeft=a;}
	void SetBottom(int a) {itsBottom=a;}
	void SetRight(int a) {itsRight=a;}

	int GetArea()const;

public:
	Point itsUpperLeft;
	Point itsUpperRight;
	Point itsLowerLeft;
	Point itsLowerRight;

	int itsTop;
	int itsLeft;
	int itsBottom;
	int itsRight;
};

Rectangle::Rectangle(int a,int b,int c,int d)
{
	itsTop=a;
	itsLeft=b;
	itsBottom=c;
	itsRight=d;

	itsUpperLeft.SetX(b);//设置的是itsUpperLeft对象里面itsX的值1
	itsUpperLeft.SetY(a);

	itsUpperRight.SetX(d);//设置的是itsUpperRight对象里面itsX的值2，用两个不同的对象给成员变量赋值，那么这个成员变量将有两个值!一个在类itsUpperLeft里面，一个在itsUpperRight里面！
    itsUpperRight.SetY(a);

	itsLowerLeft.SetX(b);
	itsLowerLeft.SetY(c);

	itsLowerRight.SetX(d);
	itsLowerRight.SetY(c);//这些对象只能写在构造函数Rectangle里面，不能写在外面，因为Rectangle与这些对象在同一个类里面，所以他可以访问这些对象
}
int Rectangle::GetArea()const
{
	int Width=itsRight-itsLeft;
	int Height=itsTop-itsBottom;
	return Width*Height;
}
int main()
{
	Rectangle MyRectangle(100,20,50,80);
	int Area=MyRectangle.GetArea();

	cout <<"Area:"<<Area<<endl;
	cout <<"Upper Left X Coordinate: ";
	cout <<MyRectangle.GetUpperLeft(MyRectangle).GetX()<<endl;//输出20.。//利用值传递方式传递对象是调用复制构造函数，传递过去的拷贝被丢弃是，调用析构函数//只对Rectangle的对象操作(好像是因为返回的是Point类的对象，所以不拷贝不调用。。。。。)
	cout <<MyRectangle.GetUpperRight().GetX()<<endl;//输出80
	//要cout出itsX，必须要写出是哪个对象里面的itsX
	return 0;
}//总观，要偷出私有的itsX要用到Point的对象，而四个Point的对象又成为了类Rectangle的私有成员数据，

//那就要用类Rectangle的对象调用里面的公有函数(这个公有函数必须是return Point对象;)才能访问

//Point的这四个对象，才能接着访问Point的公有函数return出itsX!