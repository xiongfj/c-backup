#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(int age);
	~SimpleCat();
	void setage(int age){itsAge=age;}
	int getage()const{return itsAge;}
private:
	int itsAge;
};
SimpleCat::SimpleCat(int age)
{
	cout <<"���õĹ��캯��\n";
	itsAge=age;
}
SimpleCat::~SimpleCat()
{
	cout <<"��������������\n";
}
int main()
{
	cout <<"SimpleCat first����\n";
	SimpleCat first(7);            //��������ͬʱ����ù��캯��(ֻ����������Ķ����ں�������ʱ�Ż������������)
	cout <<first.getage()<<endl;

	cout <<"\n������һ������ָ�롣��\n";
	SimpleCat*p=new SimpleCat(9);   //�������Ĺ��캯������Ķ���Ĵ����������ɴ洢����������Ҳ�Ե��ù��캯�������Ǻ�������ʱ������ôζ������������������
    cout <<p->getage()<<endl;
	cout <<"\ndelete p������\n";
	delete p;                   //�ͷ�ָ��ָ����ڴ�ռ�ǰ��������������

	cout <<"����first���������������������������\n";
	return 0;                 //��������ǰ�������������������ɴ洢�����������ڽ������������������������
}
