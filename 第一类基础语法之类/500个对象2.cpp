#include <iostream.h>
class CAT
{
public:
	CAT(){}
	~CAT(){cout <<"����������\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
};
int main()
{
	CAT p[500];//������500������p[0]--p[499]//�����ڶ���//p��һ��ָ��p[0]��ָ��
	int i;
	for(i=0;i<500;i++)
	{
		(p+i)->SetAge(2*i+1);//p+iָ���i�������ָ��
	}
	for(i=0;i<500;i++)
	{
		cout <<(p+i)->GetAge()<<"-";
	}


	return 0;//����ʱ�����500����������
}
