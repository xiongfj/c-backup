#include "string2.h"


// ���ܸ��Ǳ����ݵĶ������ĳ�Ա����!!!





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

	// String �������Ѿ���������������� = ������������Կ���ʹ String �Ķ������ = ������
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


// ���صȺ����������������Ϊ�������ܸ������������ֵ
Employee& Employee::operator = ( const Employee& rhs )
{
	if ( this == &rhs )
		return *this;

	// ��Щ���ǵ��� String ������� = �������
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
	Edie.SetFirstName("Edythe");	// ʹ�� this ָ��ָ�����صĶ���

	cout << Edie.GetFirstName().GetString() << endl;
	cout << Edie.GetLastName().GetString()	<< endl;
	cout << Edie.GetAddress().GetString()	<< endl;
	cout << Edie.GetSalary();*/
	const char c1[20] = "����s1";
	const char c2[20] = "����s2";

	String s1(c1);
	String s2(c2);

	s1 = s2;
	cout << s1.GetLen();
}