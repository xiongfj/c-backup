#include <iostream.h>

class Counter
{
public:
	Counter();
	~Counter() {cout << "������������";}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	void Increament() {++itsVal;}

	// ʹ�� ++i ʵ�����ǵ������������������������ú����ĺ�����Ϊ�գ���ô��ʹ�� i++ ��ʲôҲ����ı䣡
	void operator ++ () {--itsVal;}	// ����ʲô������������ i ��ֻ��ʹ��ʲô�������

private:
	int itsVal;
};

Counter::Counter():

itsVal(111)

{
	cout << "���ǹ��캯��" <<endl;
}

int main()
{
	Counter i;
	cout << "The Value of i is " << i.GetItsVal() << endl;

	i.Increament();
	cout << i.GetItsVal() << endl;

	++i;		// ֻ���� ++i �� i++�������� --(�������ص���--)��Ҳ�����ø�����ʽ������������ֵ��
				//����COunter a = ++i; ���Ǵ���ģ���Ϊ�� void operator
	cout << i.GetItsVal() << endl;

	return 0;
}