#include "string2.h"


// 不能覆盖被包容的对象的类的成员函数!!!





class Employee
{
public:
	 Employee();
	 Employee( char*, char*, char*, long );
	 Employee( const Employee& );
	~Employee() {}

	Employee& operator = ( const Employee& );
	const String& GetFirstName()	const			{ return itsFirstName;		}
	const String& GetLastName()		const			{ return itsLastName;		}
	const String& GetAddress()		const			{ return itsAddress;		}
	long		  GetSalary()		const			{ return itsSalary;			}

	// String 类里面已经重载了它自身类的 = 号运算符，所以可以使 String 的对象进行 = 号运算
	void SetFirstName( const String& fName )		{ itsFirstName	= fName;	}
	void SetLastName ( const String& lName )		{ itsLastName	= lName;	}
	void SetAddress  ( const String& address )		{ itsAddress	= address;	}
	void SetSalary   ( long  salary )				{ itsSalary		= salary;	}

private:
	String	itsFirstName;
	String	itsLastName;
	String	itsAddress;
	long	itsSalary;
};

Employee::Employee():

	itsFirstName(""),
	itsLastName	(""),
	itsAddress	(""),
	itsSalary	(0 )
{}

Employee::Employee( char* a, char* b, char* c, long d ):

	itsFirstName(a),
	itsLastName(b),
	itsAddress(c),
	itsSalary(d)
{}

Employee::Employee( const Employee& rhs ):

	itsFirstName( rhs.GetFirstName()	),
	itsLastName	( rhs.GetLastName()		),
	itsAddress	( rhs.GetAddress()		),
	itsSalary	( rhs.GetSalary()		)
{}


// 重载等号运算符，用引用作为参数才能给左操作数本身赋值
Employee& Employee::operator = ( const Employee& rhs )
{
	if ( this == &rhs )
		return *this;

	// 这些都是调用 String 类的重载 = 号运算符
	itsFirstName = rhs.GetFirstName();
	itsLastName  = rhs.GetLastName();
	itsAddress	 = rhs.GetAddress();
	itsSalary	 = rhs.GetSalary();

	return *this;
}

void main()
{
/*	Employee Edie("Jane", "Doe", "1043 Shore Parkway", 2000);
	String LastName("Levine");

	Edie.SetSalary(50000);
	Edie.SetLastName(LastName);
	Edie.SetFirstName("Edythe");	// 使用 this 指针指向隐藏的对象

	cout << Edie.GetFirstName().GetString() << endl;
	cout << Edie.GetLastName().GetString()	<< endl;
	cout << Edie.GetAddress().GetString()	<< endl;
	cout << Edie.GetSalary();*/
	const char c1[20] = "我是s1";
	const char c2[20] = "我是s2";

	String s1(c1);
	String s2(c2);

	s1 = s2;
	cout << s1.GetLen();
}