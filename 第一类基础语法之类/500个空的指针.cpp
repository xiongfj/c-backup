#include <iostream.h>
class CAT
{
public:
	CAT(){itsAge=1;itsWeight=5;}
	~CAT(){}
	int GetAge()const{return itsAge;}
	int GetWeight()const{return itsWeight;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
	int itsWeight;
};
int main()
{
	CAT* Family[500];//��500��ָ��Cat�����ָ��//������500�����ǿ�ָ��!!!!//������p������ָ��
	int i;
	CAT* p;
	for(i=0;i<500;i++)
	{
		p=new CAT;//����ÿ�ζ��½�һ��p//���󴴽������ɴ洢��
		p->SetAge(2*i+1);
		Family[i]=p;//ָ��ָ���ָ��
	}
	for(i=0;i<500;i++)
	{
		cout <<Family[i]->GetAge()<<"-";
	}
	return 0;//����ָ��ָ����������� �Ͳ����������������
}
