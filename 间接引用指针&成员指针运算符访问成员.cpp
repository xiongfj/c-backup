#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(){itsAge=2;}
	~SimpleCat();
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
};
SimpleCat::~SimpleCat()
{
	cout <<"���ֱ������ˣ�cccc\n";
}
int main()
{
	SimpleCat*p=new SimpleCat;
	cout <<p->GetAge()<<endl;
	p->SetAge(7);    //��Աָ���������->������
	cout <<(*p).GetAge()<<endl;
	(*p).SetAge(9);  //�������ָ��*����
	cout <<p->GetAge()<<endl;
	delete p;

	SimpleCat xx;
	xx.SetAge(100);
	cout <<"\n"<<xx.GetAge()<<endl<<endl;

	SimpleCat yy;
	yy.SetAge(200);
	cout <<yy.GetAge()<<endl; //���д��xx.GetAge()����ô����Ľ���100��������200��ÿһ����������˽�г�Ա��ֵ��������!��
	return 0;      //��������ǰ����Ϊ���������������ɴ洢���Ķ������Ի����������������
}            //�������������ɴ洢���Ķ�����ô��������֮ǰ�����������������!
