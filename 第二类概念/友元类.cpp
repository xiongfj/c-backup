#include <iostream.h>

class A
{
public:
	friend class B;
	A()	{ cout <<"fdasf\n"; }
	int get()	{ return age; }
	void set( int a )	{ age = a; }

private:
	int age;
};


class B
{
public:
	B()	{ p = new A; }
	void geta()			{ cout << p->age; }	// ��ʹ��˽�еĳ�ԱҲ����ֱ�ӷ���!!!
	void seta( int v )	{ p->set(v); }		// ������ A �Ľӿڲ��ܷ���(�����ָ��)!!!�е�����ݣ����ǰ��ݲ���ֱ�ӷ���˽�г�Ա!!!

private:
	A* p;
	int val;
};


void main()
{
	B b;
	b.seta( 100 );

//	b.get(); ���󣬷Ǽ̳в�����!!!

	b.geta();
}