#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=1;itsWeight=5;cout <<"M�Ĺ��캯��������\n";}
	Mammal(int age){itsAge=age;itsWeight=5;cout <<"M(int)���ع��캯��\n";}
	~Mammal(){cout <<"M����������\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	int GetWeight(){return itsWeight;}
	void SetWeight(int weight){itsWeight=weight;}

	void Speak()const {cout <<"������������";}
protected:
	int itsAge,itsWeight;
};


class Dog:public Mammal
{
public:
	Dog();
	Dog(int age);
	Dog(int age,int weight);
	Dog(int age,breed x);
	Dog(int age,int weight,breed x);
	~Dog(){cout <<"dog��������\n";}
	breed GetBreed()const{return itsBreed;}
	void SetBreed(breed a){itsBreed=a;}

	void WagTail()const {cout <<" С����..\n";}
private:
	breed itsBreed;
};
Dog::Dog():
Mammal(),//������ں���������ͷ��ڳ�ʼ���׶��ǲ�һ����!!!!
itsBreed(golden)
{ //Mammal();//�����һ���룬Ϊʲô��������������������?
   cout <<"dog���캯��1\n";
}

Dog::Dog(int age):
Mammal(age),//���ع��캯���Ų�������������??!!//�ܣ�����Ҳ���붨������ʼ�����ܷ���
itsBreed(golden)
{cout <<"dog���ع��캯��2\n";}//��Ա����û�м̳й��캯�������ƹ��캯�������������������������޷�ֱ��ʹ�����ǣ�����Dog x(*)����

Dog::Dog(int age,int weight):
Mammal(age),//�½�����ʱ����ʽ�ĵ��ò���ʼ������Ĺ��캯��(������߸��ƹ��죬��ѡ�����������ع��죬�Ͳ�����Ĭ�ϵĹ��캯����)
itsBreed(golden)
{
	itsWeight=weight;
	cout <<"dog���ع��캯��3\n";
}

Dog::Dog(int age,breed x):
Mammal(age),//��ʹ����ע�͵������ǻ���û����Ĭ�Ϲ��캯����!!
itsBreed(golden)
{cout <<"dog���ع��캯��5\n";}

Dog::Dog(int age,int weight,breed x)//��ʹûд�ɳ�ʼ����ʽ����main�����ø����ع��캯����firth��ʼ����ʱ����Ȼ����û����Ĭ�Ϲ��캯������Ȼ��û�в�����Ҳ�ᱻ���á�
{
    itsBreed=x;
	itsWeight=weight;
	cout <<"dog���ع��캯��4\n";
}




int main()
{
	Dog first;
	Dog second(100);//100ֻ�ḳ��dog�Ĺ��캯��
	Dog third(200,1);
	Dog forth(300,golden);//�����ʼ���׶β�ѡ����û�����ĸ����캯������ô�ͻ��Զ�����Ĭ�ϵĹ��캯��������
	Dog firth(400,2,doberman);//ÿ�ζ�����û���Ĺ��캯�������ڵ���Ĭ�Ϲ��캯���������ع��캯������������Ĺ��캯���ĳ�ʼ���׶�ѡ��
	first.Speak();
	second.WagTail();
	cout <<forth.GetAge()<<endl;
	cout <<firth.GetWeight()<<endl;
	return 0;//����������5�����󣬵���5�λ����������5�������������
}
