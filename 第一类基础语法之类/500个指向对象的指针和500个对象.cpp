#include <iostream.h>
class CAT
{
public:
	CAT(){itsAge=1;itsWeight=5;}
	~CAT(){cout <<"析构函数\n";}
	int GetAge()const{return itsAge;}
	int GetWeight()const{return itsWeight;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
	int itsWeight;
};
int main()
{
	CAT* Family[500];//有500个指向Cat对象的指针//但是未初始化，也就是CAT的对象还没存在
	CAT a[500];//创建对象为了给那500个指针指。。。
	int i;
	for(i=0;i<500;i++)
	{
		Family[i]=&a[i];//给指针指向。。
		Family[i]->SetAge(2*i+1);
		cout <<Family[i]->GetAge()<<"-";//指向指针的指针
	}
	return 0;//结束是会调用500个析构函数
}
