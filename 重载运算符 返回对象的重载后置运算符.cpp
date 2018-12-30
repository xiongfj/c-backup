#include <iostream.h>

class Counter
{
public:
	Counter();
	~Counter(){}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	const Counter& operator ++ ();		// ++i
	const Counter operator ++ (int);	// i++ ������������ ǰ��++ ����, ��ʹ��

private:
	int itsVal;
};


Counter::Counter():

itsVal(0)

{}


// ǰ�������ʵ��
const Counter& Counter::operator ++ ()	// �������ã������˶���ĺ�������
{
	++ itsVal;
	return *this;
}



// ���������ʵ��
const Counter Counter::operator ++ (int x)	// ��ʱ���ܷ������û�ָ�룬��Ϊ���ص�����ʱ���󡣷���֮����󶼲�����������ô�����أ�
{
	Counter temp(*this);	// ������һ�ָ�ֵд�����൱�� Counter temp = *this !
	++itsVal;
	return temp;
}


void main()
{
	Counter i;
	cout << i.GetItsVal() << endl;

	Counter a = ++i;
	cout << a.GetItsVal() << endl;

	a = i++;	// ֻҪ�㶨���˺��ã�ϵͳ���Զ����ö�Ӧ�ĺ�����
	cout << a.GetItsVal() << endl;
}