#include <iostream.h>
class CAT
{
public:
	CAT(){itsAge=1;itsWeight=5;}
	~CAT(){cout <<"��������-";}
	int GetAge()const{return itsAge;}
	int GetWeight()const{return itsWeight;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
	int itsWeight;
};
int main()
{
	CAT Family[500];//��500��ָ��Cat�����ָ��//������500�����ǿ�ָ��!!!!
	int i;
	for(i=0;i<500;i++)
	{
		Family[i].SetAge(2*i+1);
		
	}
	for(i=0;i<500;i++)
		cout <<Family[i].GetAge()<<"-";
	return 0;//ʹ����500�����󣬵���500����������
}