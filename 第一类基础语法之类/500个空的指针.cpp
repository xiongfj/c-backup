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
	CAT* Family[500];//有500个指向Cat对象的指针//但是这500个还是空指针!!!!//必须由p来传递指向
	int i;
	CAT* p;
	for(i=0;i<500;i++)
	{
		p=new CAT;//必须每次都新建一个p//对象创建在自由存储区
		p->SetAge(2*i+1);
		Family[i]=p;//指向指针的指针
	}
	for(i=0;i<500;i++)
	{
		cout <<Family[i]->GetAge()<<"-";
	}
	return 0;//采用指针指向对象来操作 就不会调用析构函数了
}
