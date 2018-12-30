#include <iostream.h>

class Counter
{
public:

	Counter();
	Counter(int x) {itsVal = x;}
	~Counter(){}
	int GetItsVal() const {return itsVal;}
	void SetItsVal(int x) {itsVal = x;}
	void Increment() {++itsVal;}
	Counter operator ++ ();

private:

	int itsVal;
};

Counter::Counter():

itsVal(0)

{
	cout << "���ǹ��캯��";
}


// ����һ�������� ++i ���Ը���������ֵ
Counter Counter::operator ++ ()
{
	++itsVal;

	Counter temp;
	temp.SetItsVal(itsVal);
	return temp;

	//return Counter(itsVal);	// ʹ��������ʱ����ǰ������ʹ��ֵ��Ϊ���������ع��캯�������þ�ɻ������������
					// ��һ����ͬ���ú������صĶ�����ʱ�����ڷ��غ���Щ����Ͳ������ˣ����Ըú����ķ������Ͳ��������ã���ָ�룡
}

int main()
{
	Counter i;
	cout << i.GetItsVal() << endl;

	i.Increment();
	cout << i.GetItsVal() << endl;

	++i;	// ��� operator() �ĺ������ж����¶�����ô�ͻ���ù��캯��
	cout << i.GetItsVal() << endl;

	Counter a = ++i;	// �з������͵� operator() ���Խ�����ֵ�������൱�� ++i ��������Ϊ Counter
						// ��ʱ����� a ͬʱ��ֵ��������ù��캯�����ֿ��Ż���á�

						// ++i ���� i++ Ҳ��һ���� a.GetItsVal() = 3;
						// ��Ϊ������������� operator() ֻ������ǰ�� ++i��û�и������� i++(��Ӧ�û���һ�����غ��������ĺ���������ȡ i���� ++i������)
	cout << a.GetItsVal() << endl;
	cout << i.GetItsVal() << endl;

	return 0;
}