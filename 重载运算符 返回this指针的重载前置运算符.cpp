#include <iostream.h>

class Counter
{
public:
	Counter();
	~Counter() {}
	int GetItsVal() const {return itsVal;}
	void SetItaVal(int x) {itsVal = x;}
	const Counter& operator ++ ();

private:
	int itsVal;
};


Counter::Counter():

itsVal(111)

{};

const Counter& Counter::operator ++ ()	// ȥ������Ҳ���ԣ��������ص��Ƕ��󣬷������󴫵ݣ�����ø�ֵ���캯��
{
	++itsVal;
	return *this;	// this ָ��ʽָ������
}

int main()
{
	Counter i;
	cout << i.GetItsVal() << endl;

	++i;
	cout << i.GetItsVal() << endl;

	Counter a = ++i;
	cout << i.GetItsVal() << endl;
	return 0;
}
