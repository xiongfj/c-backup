#include <iostream.h>
class Rectangle
{
public:
	Rectangle();
	~Rectangle(){}
	void SetWidth(int width){itsWidth=width;}
	int GetWidth()const{return itsWidth;}
private:
	int itsWidth;
};
Rectangle::Rectangle()
{

	itsWidth=5;
}
int main()
{
	Rectangle*p1=new Rectangle;//���ù��캯����˽�г�ԱitsWidth��ֵ5
	const Rectangle*p2=new Rectangle;//ָ��const�Ͷ����ָ��ֻ�ܷ���const�͵ĺ�������
	Rectangle*const p3=new Rectangle;//p3�ǳ���(����ָ���������ͣ�ֻ��ָ��Rectangle����)
//class Cat
//..
//..
//delete p3;
//Cat*p3=new Cat;��ʱ��p3�ǲ���ָ����������(Cat)��!
	cout <<p1->GetWidth()<<endl;
	cout <<p2->GetWidth()<<endl;
	cout <<p3->GetWidth()<<endl;

	p1->SetWidth(111);
	//p2->SetWidth(222);//����SetWidth����const�͵ģ�����p2���ܷ���
	p3->SetWidth(333);

	cout <<p1->GetWidth()<<endl;
	cout <<p2->GetWidth()<<endl;
	cout <<p3->GetWidth()<<endl;
	return 0;
}