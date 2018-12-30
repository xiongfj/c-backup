#include <iostream.h>


// ���д��麯������У�������*************************************************
class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}

	// ���麯���������ɴ���ֱ��������ȥ�Ķ�Ҫ���Ǹ�������д��麯����
	// ���麯�������ж���
	virtual long GetArea() = 0;
	virtual long GetPerim() = 0;
	virtual void Draw() = 0;

private:
};


//***********************************************************
class Circle:public Shape
{
public:
	Circle(int radius): itsRadius(radius) {}
	~Circle(){}

	long GetArea() {return 3 * itsRadius * itsRadius;}
	long GetPerim() {return 6 * itsRadius;}
	void Draw();
private:
	int itsRadius;
};

void Circle::Draw()
{
	cout <<"Cilcle��Draw��\n";
}


//***********************************************************
class Rectangle:public Shape
{
public:
	  Rectangle(int len, int width):
	  itsLength(len), itsWidth(width){}
	  virtual ~Rectangle() {}

	  // ���ǳ������еĴ��麯��
	  virtual long GetArea() {return itsLength * itsWidth;}
	  virtual long GetPerim() {return 2 * (itsLength + itsWidth);}
	  virtual void Draw();

	  virtual int GetLength() {return itsLength;}
	  virtual int GetWidth()	{return itsWidth;}

private:
	int itsLength, itsWidth;
};

void Rectangle::Draw()
{
	for (int i = 0; i < itsLength; i++)
	{
		for (int j = 0; j < itsWidth; j++)
			cout <<"x";
		cout << endl;
	}
	cout <<"Rectangle��Draw��\n";
}


// ���಻�Ǵӳ�����ֱ�������ģ����ø�����Щ���麯��*******************************
class Square:public Rectangle
{
public:
	Square(int len);
	Square(int len, int width);
	~Square(){}
	long GetPerim() {return 4 * GetLength();}
};

Square::Square(int len):
Rectangle(len, len)
{}

Square::Square(int len, int width):
Rectangle(len, width)
{
	if (GetLength() != GetWidth())
		cout <<"erroe��\n";
}


//********************************************
void main()
{
	int choice;
	bool fQuit = false;
	Shape* sp;			// �����಻�ܴ������󣬵��ǿ��Դ�����ָ��

	while (!fQuit)
	{
		cout <<"1Circle,2Rectangle,3sQuare,0Quit";
		cin >> choice;

		switch (choice)
		{
		case 0:	fQuit = true;	break;
		case 1:	sp	= new Circle(5);		break;
		case 2:	sp	= new Rectangle(4, 6);	break;
		case 3:	sp	= new Square(5);		break;
		default:
			cout << "error";
			continue;
		}

		if (!fQuit)
		{
			sp->Draw();
			delete sp;
		}

		cout << endl;
	}
}