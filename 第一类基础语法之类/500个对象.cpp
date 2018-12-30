#include <iostream.h>
class CAT
{
public:
	CAT(){itsAge=1;itsWeight=5;}
	~CAT(){cout <<"析构函数-";}
	int GetAge()const{return itsAge;}
	int GetWeight()const{return itsWeight;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
	int itsWeight;
};
int main()
{
	CAT Family[500];//有500个指向Cat对象的指针//但是这500个还是空指针!!!!
	int i;
	for(i=0;i<500;i++)
	{
		Family[i].SetAge(2*i+1);
		
	}
	for(i=0;i<500;i++)
		cout <<Family[i].GetAge()<<"-";
	return 0;//使用了500个对象，调用500次析构函数
}