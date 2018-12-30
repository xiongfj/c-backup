#include <iostream.h>


// �������***********************************	Shape
class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}
	virtual long GetArea() = 0;
	virtual long GetPerim() = 0;
	virtual void Draw() = 0;

private:
};

// ������ĺ�������ʹ�ø���Ŀ�ָ��ֱ�ӵ��ã���������������ĺ�������ʾ���ò���
void Shape::Draw()
{
	cout << "������Draw��\n";
}


//******************************************   Circle
class Circle:public Shape
{
public:
	Circle(int radius):itsRadius(radius){}
	virtual ~Circle(){}
	long GetArea() {return 3 * itsRadius * itsRadius;}
	long GetPerim() {return 9 * itsRadius;}
	void Draw();

private:
	int itsRadius;
};

void Circle::Draw()
{
	cout <<"Circle��Draw��\n";
	Shape::Draw();
}


//******************************************	Rectangle
class Rectangle:public Shape
{
public:
	Rectangle(int len, int width):	itsLength(len), itsWidth(width) {}
	virtual ~Rectangle() {}
	long GetArea() {return itsLength * itsWidth;}
	long GetPerim() {return 2 * itsLength + 2 * itsWidth;}
	virtual int GetLength() {return itsLength;}
	virtual int GetWidth() {return itsWidth;}
	void Draw();

private:
	int itsWidth;
	int itsLength;
};

void Rectangle::Draw()
{
	for (int i = 0; i < itsLength; i++)
	{
		for (int j = 0; j < itsWidth; j++)
			cout <<"x";
		cout << endl;
	}
	Shape::Draw();
}


//******************************************	Square
class Square:public Rectangle
{
public:
	Square(int len);
	Square(int len, int width);
	virtual ~Square(){}
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


//******************************************	main
void main()
{
	int choice;
	bool fQuit = false;
	Shape* sp;

	while (1)
	{
		cout << "1-circlr��2-rectangle��3,4-square��0-quit";
		cin >> choice;

		switch (choice)
		{
		case 1:	sp = new Circle(5);			break;
		case 2:	sp = new Rectangle(4, 6);	break;
		case 3:	sp = new Square(7);			break;
		case 4:	sp = new Square(3, 4);		break;
		default:	fQuit = true;			break;
		}

		if (fQuit)
			break;

		sp->Draw();	// ��� choice == 3��sp ���õ��� Recatngle �� Draw(),����Ľ��� 7 * 7 ������
		delete sp;

		cout <<"\n";
	}
}