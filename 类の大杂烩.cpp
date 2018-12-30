#include <iostream.h>
enum CHOICE {DrawRect=1,GetArea,GetPerim,ChangeDimensions,Quit};
class Rectangle
{
public:
	Rectangle(int width,int height);
	~Rectangle();

	int GetHeight()const{return itsHeight;}
	int GetWidth()const{return itsWidth;}
	int GetArea()const{return itsWidth*itsHeight;}
	int GetPerim()const{return 2*itsWidth+2*itsHeight;}
	void SetSize(int newWidth,int newHeight);

private:
	int itsWidth,itsHeight;
};


void Rectangle::SetSize(int newWidth,int newHeight)
{
	itsWidth=newWidth;
	itsHeight=newHeight;
}

Rectangle::Rectangle(int width,int height)
{
	itsWidth=width;
	itsHeight=height;
}
Rectangle::~Rectangle(){}

int DoMenu();
void DoDrawRect(Rectangle);
void DoGetArea(Rectangle);
void DoGetPerim(Rectangle);

int main()
{
	Rectangle theRect(30,5);  //����һ������theRect�����ù��캯��Rectangle
	int choice=DrawRect;      //��ʼ��=ö���ͱ���DrawRect=1
	int fQuit=false;          //Ϊ�ս�whileѭ����׼��

	while(!fQuit)
	{
		choice=DoMenu();                 //DoMenu()�����������г��˵�������ʾ�û�����ѡ��
		if(choice<DrawRect||choice>Quit) //�������ѡ�����Χ
		{
			cout <<"\n�Ƿ�ѡ��������������֣�";
			continue;                    //ֱ�ӻص�while����ѭ��
		}
		switch(choice)
		{
		case DrawRect:
			DoDrawRect(theRect);//
			break;
		case GetArea:
			DoGetArea(theRect);
			break;
		case GetPerim:
			DoGetPerim(theRect);
			break;
		case ChangeDimensions:
			int newLength,newWidth;
			cout <<"\nnew width:";
			cin>>newWidth;
			cout <<"new height:";
			cin>>newLength;
			theRect.SetSize(newWidth,newLength);//�ö���theRect���ù������ú���SetSize()���¸�˽�г�Ա������ֵ
			DoDrawRect(theRect);                //�����˽�г�Ա������ֵ�󣬵��ú���DoDrawRect(),�ú��������ö���theRect
			break;                               //(����)�ֱ�����˷��ʺ���GetWidth��GetHeight����ȡ˽�г�Ա������ֵ��
                                                          //(����)���в�����Rectangle XXX(newWidth,newLength);��������Ϊcase���治�ܳ�ʼ�����������
		case Quit:
			fQuit=true;
			cout <<"Exiting...\n\n";
			break;
		default:
			cout <<"���������!Exiting...\n";
			break;
		}
	}
	return 0;
}
int DoMenu()
{
	int choice;
	cout <<"\n\n******Menu******\n";
	cout <<"(1)Draw Rectangle \n";
	cout <<"(2)Area \n";
	cout <<"(3)Perimeter \n";
	cout <<"(4)Resize \n";
	cout <<"(5)Quit \n";
	cin>>choice;
	return choice;
}

void DoDrawRect(Rectangle theRect)
{
	int height=theRect.GetHeight();
	int width=theRect.GetWidth();
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
			cout <<"*";
		cout <<endl;
	}
}

void DoGetArea(Rectangle theRect)
{
	cout <<"Area:"<<theRect.GetArea()<<endl;
}
void DoGetPerim(Rectangle theRect)
{
	cout <<"Perimeter:"<<theRect.GetPerim()<<endl;
}






