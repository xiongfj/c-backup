#include <iostream.h>
class CAT
{
public:
	CAT(){cout<<"我是打酱油的!\n";}
	CAT(const CAT&);
	~CAT(){cout <<"析构函数";}
	int GetAge()const{return  itsAge;}
	void SetAge(int age){itsAge=age;}
private:
	int itsAge;
};
CAT::CAT(const CAT& rhs)//rhs不能访问const的CAT成员。。
{
	itsAge=rhs.GetAge()+1;//或写成:*(rhs.itsAge)   ?
}
int main()
{
	CAT first;
	first.SetAge(111);

	CAT boots(first);//不管传递哪个对象,调用复制析构函数再由对象first(rhs是对first的引用)调用GetAge()赋给itsAge的值将丢到对象boots里!!!
	cout <<first.GetAge()<<endl;//
	cout <<boots.GetAge()<<endl<<endl;//

	
	CAT second(first);//用对象first里成员的值对second初始化
	cout <<first.GetAge()<<endl;
	cout <<boots.GetAge()<<endl;//
	cout <<second.GetAge()<<endl<<endl;//
    
	second.SetAge(333);//只改变first里itsAge的值

	CAT third(second);//复制构造函数里：second的引用调用GetAge()将second里itsAge的值赋给了third对象的itsAge!!
	cout <<first.GetAge()<<endl;//
	cout <<boots.GetAge()<<endl;//
	cout <<second.GetAge()<<endl;//
	cout <<third.GetAge()<<endl;//
	return 0;
}
