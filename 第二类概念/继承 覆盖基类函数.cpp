#include <iostream.h>
class Mammal
{
public:
	Mammal(){cout <<"M���캯��\n";}
	~Mammal(){cout <<"M��������\n";}
	void Speak()const{cout <<"M������\n";}
protected:
	int itsAge;
};
class Dog:public Mammal
{
public:
	Dog(){cout <<"dog�Ĺ��캯��\n";}
	~Dog(){cout <<"dog����������\n";}
	void Speak()const{cout <<"����dog��speak!!\n";}
private:
	int weight;
};

int main()
{
	Mammal xx;//��Mammal����û�л��࣬����ֻ����M�Ĺ��캯��
	Dog yy;
	xx.Speak();//Mammal�Ķ�����ʵĺ�����Mammal�����..
	yy.Speak();//Dog�Ķ�����ʵ����speak��Dog����ģ�
	return 0;
}
