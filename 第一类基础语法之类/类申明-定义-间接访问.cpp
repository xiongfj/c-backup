#include <iostream.h>
class Cat           //������
{
public:             //�����ɹ���
	inline void GetAge(int);//Ҫ��Ϊ��Ƕ��ֻҪ���������ʱ������ǰ�����inline���ɣ������������ӣ���������ִ���
	int SetAge();
	void Meow();    //���ͣ�
private:        //���е��˽���������ı��˽��
	int itsAge;
};
void Cat::GetAge(int a)   //�ຯ���Ķ���
{
	itsAge=a;
}
int Cat::SetAge()
{
	return itsAge;
}
void Cat::Meow()
{
	cout <<"Meow: \n";
}
int main()
{
	Cat x,y;//Ҳ������������������ͬ�Ķ���
	x.GetAge(5);//���ʺ�����д��
	y.GetAge(6);
	x.Meow();
	cout <<"x is:"<<x.SetAge()<<"years old \n";//������cout�ֱ�������Ƕ���x�кͶ���y�е�iteAge
	cout <<"y is:"<<y.SetAge()<<endl;//����ʹ�ö���!������ΪiteAge�ڲ�ͬ�Ķ������в�ͬ��ֵ!
	x.Meow();
	return 0;
}