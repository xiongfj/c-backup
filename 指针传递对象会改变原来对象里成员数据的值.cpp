#include <iostream.h>
class Cat           
{
public:
	Cat(){cout <<"���캯��-------\n";}
	Cat(Cat&){cout <<"���ƹ��캯��llllllllllll\n";}//����д��Cat(Cat&)�������ܱ�����???
	~Cat(){cout <<"��������eeeeeeeee\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
	Cat* setage(Cat *a){a->SetAge(111);return a;}//���ص���ָ�룬������ø��ƹ��캯��
private:        
	int itsAge;
};
int main()
{
	Cat x,y;//Ҳ������������������ͬ�Ķ���
	x.SetAge(5);
	y.SetAge(6);
	cout <<x.GetAge()<<"\n";
	cout <<y.GetAge()<<endl;
	
	y.setage(&x);   //ʹ�õ���ָ�봫�ݣ�������ù��캯��
	cout <<x.GetAge()<<endl;    //�������111������5
	cout <<y.GetAge()<<endl;
	return 0;//����������x,y���������������������������!!
}
