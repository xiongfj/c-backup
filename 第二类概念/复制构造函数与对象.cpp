#include <iostream.h>
class CAT
{
public:
	CAT(){cout<<"���Ǵ��͵�!\n";}
	CAT(const CAT&);
	~CAT(){cout <<"��������";}
	int GetAge()const{return  itsAge;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
};
CAT::CAT(const CAT& rhs)//rhs���ܷ���const��CAT��Ա����
{
	itsAge=rhs.GetAge()+1;//��д��:*(rhs.itsAge)   ?
}
int main()
{
	CAT first;
	first.SetAge(111);

	CAT boots(first);//���ܴ����ĸ�����,���ø��������������ɶ���first(rhs�Ƕ�first������)����GetAge()����itsAge��ֵ����������boots��!!!
	cout <<first.GetAge()<<endl;//
	cout <<boots.GetAge()<<endl<<endl;//

	
	CAT second(first);//�ö���first���Ա��ֵ��second��ʼ��
	cout <<first.GetAge()<<endl;
	cout <<boots.GetAge()<<endl;//
	cout <<second.GetAge()<<endl<<endl;//
    
	second.SetAge(333);//ֻ�ı�first��itsAge��ֵ

	CAT third(second);//���ƹ��캯���second�����õ���GetAge()��second��itsAge��ֵ������third�����itsAge!!
	cout <<first.GetAge()<<endl;//
	cout <<boots.GetAge()<<endl;//
	cout <<second.GetAge()<<endl;//
	cout <<third.GetAge()<<endl;//
	return 0;
}
