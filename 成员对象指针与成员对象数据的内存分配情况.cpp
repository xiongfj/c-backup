#include <iostream.h>

class BB
{
public:
	BB()
	{
		cout << "caonima" << endl;
		s = 100;
	}
	int s;
};

class AA
{
public:
	BB* pb;
	BB b;// �����������Ķ�����ô�ڴ��� AA �Ķ����ʱ����Զ��������Ա������ڴ棬��������Ǹ�����Ĺ��캯��
};

void main()
{
	AA* pa = new AA();
	pa->pb = new BB();			// ���򲻻��Զ�������ĳ�Աָ����ڴ棡��
	cout << pa->pb->s;

	AA a;		// ����Ҳ����� BB �Ĺ��캯������Ϊ AA �г�Ա������ BB �Ķ��󡣡���
	cout << a.b.s;
}