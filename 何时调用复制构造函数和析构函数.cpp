#include <iostream.h>
class DOG
{
	
};
class Cat
{
public:
	Cat(int a);//�������캯��
	Cat(Cat&){cout <<"���ƹ��캯��------\n";}
	~Cat();//������������
	Cat function(Cat a){return a;}//ֵ���ݷ�ʽ������һ�����󣬴�����һ�������������˸��ƹ��캯����
	//����������a��a�Ŀ��������������������������������
	int GetAge();
	void SetAge(int a);
	void Meow();
private:
	DOG dog;
	int itsAge;
};


Cat::Cat(int b)//���캯���Ķ���.ǰ�治�ܼ��κη���ֵ����(int void ...)!
{
	itsAge=b;
}

Cat::~Cat()//�����������޲������޷���ֵ,ͬ�����ܼӷ���ֵ����!!
{
	cout <<"��������!!!!!!!!\n";
}

int Cat::GetAge()////�з���ֵ��һ����Ա������Ϊ�˰�ֵ���ص�main������
{
	return itsAge;
}
void Cat::SetAge(int c)//�޷���ֵ�ĳ�Ա���������ڶԳ�Ա������ֵ
{
	itsAge=c;
}
void Cat::Meow()
{
	cout <<"Meow: \n";
}

int main()
{
	Cat X(5);//���������ͬʱ��Ҳ�����˹��캯��Cat(int b)! Cat(int b)�ֶԳ�Ա������ʼ������ֵ����
	X.Meow();//����һ����ʡȥ��һ��X.SetAge(5);
	cout <<"X cat is: "<<X.GetAge()<<"years old! \n";
	X.Meow();
	X.SetAge(7);//���¸�itsAge��ֵ,����ֱ�ӵ��ù��캯��!X.Cat(7)�����д����Cat X(7)ͬ���Ǵ����д�������ܶ���������ͬ�Ķ��󣬰�x����y������������
	cout <<"now X cat is: "<<X.GetAge()<<"years old! \n";
	X.function(X);//ֵ���ݷ�ʽ������һ�����󣬴�����һ�������������˸��ƹ��캯��
	return 0;
}//��������ǰ���߸���Ķ�����������������Զ�����������������ʹ����ʽ��X.~Cat();�����ˣ������ǻ��ڵ���һ��!