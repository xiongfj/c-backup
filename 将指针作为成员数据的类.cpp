#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat(int a,int b);
    ~SimpleCat();
	int GetAge()const{return *itsAge;}
	void SetAge(int age){*itsAge=age;}
	int GetWeight()const{return *itsWeight;}
	void SetWeight(int weight){*itsWeight=weight;}
private:
	int*itsAge;
	int*itsWeight;
};
SimpleCat::SimpleCat(int a,int b)
{
	itsAge=new int(a);
	itsWeight=new int(b);
}
SimpleCat::~SimpleCat()
{
	delete itsAge;     //��������������deleteָ�룬�ͷ��ڴ治���ٵ�����������
	delete itsWeight;
}               //�����ͷţ�����ֻҪ��delete���߷����ɴ洢���Ķ��󶼻������������������� delete˽�г�Ա����
int main()
{
	SimpleCat*first=new SimpleCat(2,5);//���캯�����в�������Ķ���Ķ����ʽ����
	cout <<first->GetAge()<<endl;
	cout <<first->GetWeight()<<endl;

	first->SetAge(9);
	first->SetWeight(10);
	cout <<first->GetAge()<<endl;
	cout <<(*first).GetWeight()<<endl;
	delete first;              //deleteָ�룬�ͷ����ڴ���9��10��ֵ����first��9,10���޹���

	first=new SimpleCat(90,100);  
	cout <<first->GetAge()<<endl;//��������delete��ָ��first�����������¶�����ָ��firstָ����ڴ棬���������������9��10��
	cout <<first->GetWeight()<<endl;
	delete first;

	SimpleCat xx(22,55);
	cout <<xx.GetAge()<<endl;
	cout <<xx.GetWeight()<<endl;

	SimpleCat yy(33,77);        //����yy���ù��캯������˽�г�Ա��ֵ����Ӱ�����xx��˽�г�Ա��ֵ
	cout <<xx.GetAge()<<endl;   //���22
	cout <<xx.GetWeight()<<endl;//���55

	xx.SetAge(88);
	xx.SetWeight(99); //������xx��������itsAge ��itsWeight��ֵ
	cout <<xx.GetAge()<<endl;
	cout <<xx.GetWeight()<<endl;

	return 0;
}

