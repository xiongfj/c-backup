#include <iostream.h>
enum breed{golden,cairn,dandie,shetland,doberman,lab};
class Mammal
{
public:
	Mammal(){itsAge=100;cout <<"Mammal�Ĺ��캯��\n";}
	Mammal(int a){itsAge=a;cout<<"�ұ���������?\n";}
	~Mammal(){cout <<"Mammal����������\n";}
	int GetAge()const{return itsAge;}
	void Speak()const{cout <<"����..!!\n";}
protected:    
	int itsAge;
};

class Dog:public Mammal//
{
public:
	Dog(int age,breed a);
	~Dog(){cout <<"Dog����������\n";}
	int GetBreed()const{return itsBreed;}
	int WagTail()const{return itsAge;}

private:
	breed itsBreed;
};
Dog::Dog(int age,breed a):
//Mammal(age),//������һ�䣬�ڴ�������xx��ʱ��Ͳ������Ĭ�Ϲ��캯���ˣ�������дʲô���캯����ֻ����ʲô���캯����
itsBreed(a)
{
	cout <<"Dog�Ĺ��캯��\n";
}
int main()
{
	Dog xx(200,lab);//���ݵĲ����Ǹ�������Ĺ��캯���ģ�ͬʱ������ע�ͳ�д����ʱ������õ��ĸ����๹�캯������д�Ļ������û����Ĭ�Ϲ��캯����      
	xx.Speak();
	xx.WagTail();
	cout <<xx.GetAge()<<endl;
	cout <<xx.WagTail()<<endl;
	return 0;
}//�������Ҫ��Ϊ�ˣ�����ֻ���ʼ���ö���(xx)��������ĳ�Ա(itsBreed)�������ʼ���ö���ӻ���̳еĳ�Ա����(itsAge),��ô���ڵ�һ�е�ע�ͳ�д��һ���޲����Ĺ��캯�����ɣ����߲�д(ֻҪ�������������캯������ô�����д��Ĭ�Ϲ��캯��!!)



