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
	CAT* p=new CAT[500];//������500������p[0]--p[499]
	int i;
	for(i=0;i<500;i++)
	{
		p[i].SetAge(2*i+1);
	}
	for(i=0;i<500;i++)
	{
		cout <<p[i].GetAge()<<"-";
	}
	delete[] p;//ɾ��������������ж���!!ÿһ�ζ��������������!!//��ɾ���򲻻����?????????������������
	return 0;
}
