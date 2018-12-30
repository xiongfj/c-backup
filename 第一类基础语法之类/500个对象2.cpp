#include <iostream.h>
class CAT
{
public:
	CAT(){}
	~CAT(){cout <<"析构函数！\n";}
	int GetAge()const{return itsAge;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
};
int main()
{
	CAT p[500];//创建了500个对象p[0]--p[499]//储存在堆里//p是一个指向p[0]的指针
	int i;
	for(i=0;i<500;i++)
	{
		(p+i)->SetAge(2*i+1);//p+i指向弟i个对象的指针
	}
	for(i=0;i<500;i++)
	{
		cout <<(p+i)->GetAge()<<"-";
	}


	return 0;//结束时会调用500个析构函数
}
