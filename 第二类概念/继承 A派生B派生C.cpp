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
class sijiaoanimal:public Mammal
{
public:
	sijiaoanimal(){itsMao=200;cout <<"�ĽǶ���Ĺ��캯��\n";}
	~sijiaoanimal(){cout <<"˻�ж������������\n";}

	int GetMao()const{return itsMao;}
	void maomao()const{cout <<"����ëë������\n";}
protected:
	int itsMao;
};

class Dog:public sijiaoanimal
{
public:
	Dog(){itsBreed=golden;cout <<"Dog�Ĺ��캯��\n";}
	~Dog(){cout <<"Dog����������\n";}

	int GetBreed()const{return itsBreed;}
	void SetBreed(breed x){itsBreed=x;}
	int WagTail()const{return itsAge;}

private:
	breed itsBreed;
};
int main()
{
	Dog xx;     //�������ι��캯��
	xx.Speak();  //�м����һ���࣬һ���ķ��ʻ���Ļ��ࡣ����
	
	cout <<xx.GetAge()<<endl;
	cout <<xx.WagTail()<<endl;

	return 0;//����������������
}



