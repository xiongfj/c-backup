#include <iostream.h>
class Cat           
{
public:
	Cat(){cout <<"���캯��-------\n";}
	Cat(Cat&){cout <<"���ƹ��캯��llllllllllll\n";}//����д��Cat(Cat&)�������ܱ�����???
	~Cat(){cout <<"��������eeeeeeeee\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	const Cat* setage(const Cat *a);
private:        
	int itsAge;
};
const Cat* Cat::setage(const Cat *a)//����ָ��ָ��const�ͣ����Ժ����ķ������ͱ�����const�ģ�����ʹ��void�޷���ֵ!!
{
	//a.SetAge(111);
	return a;
}
int main()
{
	Cat x,y;//Ҳ������������������ͬ�Ķ���
	x.SetAge(5);
	y.SetAge(6);
	cout <<x.GetAge()<<"\n";
	cout <<y.GetAge()<<endl;
	
	y.setage(&x);   //ʹ�õ���ָ�봫�ݣ�������ù��캯��
	cout <<x.GetAge()<<endl;    //
	cout <<y.GetAge()<<endl;
	return 0;//����������x,y���������������������������!!
}
