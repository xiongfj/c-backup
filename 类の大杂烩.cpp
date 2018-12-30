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
	Rectangle theRect(30,5);  //定义一个对象theRect，调用构造函数Rectangle
	int choice=DrawRect;      //初始化=枚举型变量DrawRect=1
	int fQuit=false;          //为终结while循环做准备

	while(!fQuit)
	{
		choice=DoMenu();                 //DoMenu()函数包含：列出菜单，并提示用户输入选项
		if(choice<DrawRect||choice>Quit) //当输入的选项超出范围
		{
			cout <<"\n非法选项，请重新输入数字：";
			continue;                    //直接回到while重新循环
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
			theRect.SetSize(newWidth,newLength);//用对象theRect调用公有设置函数SetSize()重新给私有成员参数赋值
			DoDrawRect(theRect);                //上面给私有成员参数赋值后，调用函数DoDrawRect(),该函数内又用对象theRect
			break;                               //(接上)分别调用了访问函数GetWidth和GetHeight来获取私有成员参数的值，
                                                          //(接上)上行不能用Rectangle XXX(newWidth,newLength);好像是因为case里面不能初始化对象或其他
		case Quit:
			fQuit=true;
			cout <<"Exiting...\n\n";
			break;
		default:
			cout <<"错误的输入!Exiting...\n";
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






