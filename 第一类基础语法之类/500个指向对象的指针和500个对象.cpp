#include <iostream.h>
class CAT
{
public:
	CAT(){itsAge=1;itsWeight=5;}
	~CAT(){cout <<"��������\n";}
	int GetAge()const{return itsAge;}
	int GetWeight()const{return itsWeight;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
	int itsWeight;
};
int main()
{
	CAT* Family[500];//��500��ָ��Cat�����ָ��//����δ��ʼ����Ҳ����CAT�Ķ���û����
	CAT a[500];//��������Ϊ�˸���500��ָ��ָ������
	int i;
	for(i=0;i<500;i++)
	{
		Family[i]=&a[i];//��ָ��ָ�򡣡�
		Family[i]->SetAge(2*i+1);
		cout <<Family[i]->GetAge()<<"-";//ָ��ָ���ָ��
	}
	return 0;//�����ǻ����500����������
}
