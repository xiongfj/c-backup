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
	Rectangle(Rectangle&){cout <<"���ƹ��캯��-------\n";}
	~Rectangle(){cout <<"��������iiiiiiiiiiiiiiii\n";}

	int GetTop()const{return itsTop;}//���ʻ���������������ǰ�˽�г�Ա������ֵ���ظ�main����
	int GetLeft()const{return itsLeft;}
	int GetBottom()const{return itsBottom;}
	int GetRight()const{return itsRight;}
	
	Point GetUpperLeft(Rectangle a) const {return itsUpperLeft;}//���ʺ�����Ϊ�˷��ʲ����˽�����ԱitsUpperLeft���ĸ�
	Point GetLowerLeft() const {return itsLowerLeft;}
	Point GetUpperRight() const {return itsUpperRight;}
	Point GetLowerRight() const {return itsLowerRight;}//���������Ҳ���Է��ʣ���˷��ʼ���

	void SetUpperLeft(Point a) {itsUpperLeft=a;}//�ö���a��Ϊ�����Ĳ�����
	void SetLowerLeft(Point a) {itsLowerLeft=a;}//��Щ�������������ö�������˽�е�Point����
	void SetUpperRgiht(Point a) {itsUpperRight=a;}
	void SetLowerRight(Point a) {itsLowerRight=a;}

	void SetTop(int a) {itsTop=a;}//����˽�е�int��Ա����
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

	itsUpperLeft.SetX(b);//���õ���itsUpperLeft��������itsX��ֵ1
	itsUpperLeft.SetY(a);

	itsUpperRight.SetX(d);//���õ���itsUpperRight��������itsX��ֵ2����������ͬ�Ķ������Ա������ֵ����ô�����Ա������������ֵ!һ������itsUpperLeft���棬һ����itsUpperRight���棡
    itsUpperRight.SetY(a);

	itsLowerLeft.SetX(b);
	itsLowerLeft.SetY(c);

	itsLowerRight.SetX(d);
	itsLowerRight.SetY(c);//��Щ����ֻ��д�ڹ��캯��Rectangle���棬����д�����棬��ΪRectangle����Щ������ͬһ�������棬���������Է�����Щ����
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
	cout <<MyRectangle.GetUpperLeft(MyRectangle).GetX()<<endl;//���20.��//����ֵ���ݷ�ʽ���ݶ����ǵ��ø��ƹ��캯�������ݹ�ȥ�Ŀ����������ǣ�������������//ֻ��Rectangle�Ķ������(��������Ϊ���ص���Point��Ķ������Բ����������á���������)
	cout <<MyRectangle.GetUpperRight().GetX()<<endl;//���80
	//Ҫcout��itsX������Ҫд�����ĸ����������itsX
	return 0;
}//�ܹۣ�Ҫ͵��˽�е�itsXҪ�õ�Point�Ķ��󣬶��ĸ�Point�Ķ����ֳ�Ϊ����Rectangle��˽�г�Ա���ݣ�

//�Ǿ�Ҫ����Rectangle�Ķ����������Ĺ��к���(������к���������return Point����;)���ܷ���

//Point�����ĸ����󣬲��ܽ��ŷ���Point�Ĺ��к���return��itsX!