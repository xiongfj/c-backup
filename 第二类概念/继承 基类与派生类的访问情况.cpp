#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=100;cout <<"Mammal�Ĺ��캯��\n";}
	~Mammal(){cout <<"Mammal����������\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}

	void Speak()const{cout <<"����!!\n";}
	void Sleep()const{cout <<"zzz~zz~~~˯����!!\n";}
protected:    //�����ͳ�Ա���ڸ�����������ǿɼ���
	int itsAge;
};

class Dog:public Mammal//ֻ������������Է��ʻ���ĳ�Ա��û�л�����Է���������ĳ�Ա!!
{
public:
	Dog(){itsBreed=golden;cout <<"Dog�Ĺ��캯��\n";}
	~Dog(){cout <<"Dog����������\n";}

	int GetBreed()const{return itsBreed;}
	void SetBreed(breed x){itsBreed=x;}
	int WagTail()const{return itsAge;}//������ĳ�Ա�����ڿ��Է��ʻ���ı����ͺ͹��г�Ա������ֱ�ӷ���˽�е�(����)!

private:
	breed itsBreed;
};
int main()
{
	Dog xx;      //ֻ��������Ķ�����Է��ʻ���ĳ�Ա(��˽�еĳ�Ա���ǹ��죬���ƹ��죬����)��������Ķ������ܷ���������������ĳ�Ա(����ʲô��Ա)
	xx.Speak();  //������Dog�Ķ�����Է���Dog�Ļ���Ĺ��г�Ա�ͱ����ͳ�Ա
	xx.WagTail();//���xx����Mammal xx,��ɻ���Ķ�����ôxx�����ܷ���WagTail()
	cout <<xx.GetAge()<<endl;
	cout <<xx.WagTail()<<endl;
//  Mammal yy;��������ǵ��ú�����˳��Ϊ��Mammal�Ĺ��캯��>Dog�Ĺ��캯��>(�������������)>Dog����������>Mammal����������
	return 0;
}



