#include <iostream.h>
class CAT
{
public:
	CAT();
	CAT(const CAT&);
	~CAT();
	int GetAge()const{return * itsAge;}
	void SetAge(int age){*itsAge=age;}
private:
	int* itsAge;
};
CAT::CAT()
{
	itsAge=new int;
	*itsAge=5;
}
CAT::CAT(const CAT& rhs)//rhs不能访问非const的CAT成员。。
{
	itsAge=new int;
	*itsAge=rhs.GetAge();//或写成:*(rhs.itsAge)   ?
}
CAT::~CAT()
{
	delete itsAge;
	itsAge=0;
}
int main()
{
	CAT first;
	cout <<first.GetAge()<<endl;
	first.SetAge(111);

	CAT boots(first);
	cout <<first.GetAge()<<endl;
	cout <<boots.GetAge()<<endl;

	first.SetAge(222);
	cout <<first.GetAge()<<endl;
	cout <<boots.GetAge()<<endl;//111
	
	boots.SetAge(333);
    cout <<first.GetAge()<<endl;
	cout <<boots.GetAge()<<endl;
	return 0;
}
