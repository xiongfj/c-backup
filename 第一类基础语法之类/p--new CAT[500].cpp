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
	CAT* Family=new CAT[500];//只有一个指针。。。
	int i;
	CAT* p=Family;
	for(i=0;i<500;i++,p++)//p++指向下一个对象Family[i]
	{
		
		p->SetAge(2*i+1);
	
	}
	for(i=0;i<500;i++)
		cout <<Family[i].GetAge()<<"-";
	delete[] Family;//一般有new CAT[500],在自由区创建了数组对象都要删除，释放内存
	return 0;
}