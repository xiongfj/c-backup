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
	CAT* p=new CAT[500];//创建了500个对象p[0]--p[499]
	int i;
	for(i=0;i<500;i++)
	{
		p[i].SetAge(2*i+1);
	}
	for(i=0;i<500;i++)
	{
		cout <<p[i].GetAge()<<"-";
	}
	delete[] p;//删除数组里面的所有对象!!每一次都会调用析构函数!!//不删除则不会调用?????????！！！！！！
	return 0;
}
