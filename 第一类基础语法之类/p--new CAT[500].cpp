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
	CAT* Family=new CAT[500];//ֻ��һ��ָ�롣����
	int i;
	CAT* p=Family;
	for(i=0;i<500;i++,p++)//p++ָ����һ������Family[i]
	{
		
		p->SetAge(2*i+1);
	
	}
	for(i=0;i<500;i++)
		cout <<Family[i].GetAge()<<"-";
	delete[] Family;//һ����new CAT[500],���������������������Ҫɾ�����ͷ��ڴ�
	return 0;
}