#include <iostream.h>

class Counter
{
public:
	Counter();
	Counter(int a);
	~Counter() {}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	Counter operator + (const Counter&);	// ˫Ŀ�������Ҫʹ�ò�������Ŀ���������Ҫʹ�ò��������ǿ����в�����

private:
	int itsVal;
};

Counter::Counter(int a)
{
	itsVal = a;
}

Counter::Counter()
{
	itsVal = 0;
}


Counter Counter::operator + (const Counter& rhs)
{
	return Counter(itsVal + rhs.GetItsVal());
}


void main()
{
	Counter one(2), two(3), three;
	three = one + two;	// ��֮������Զ������ʲô���㣬��Ҫ��������������������涨�壡��

	cout << one.GetItsVal() << endl;
	cout << two.GetItsVal() << endl;
	cout << three.GetItsVal() << endl;
}