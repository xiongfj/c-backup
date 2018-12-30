#include <iostream.h>

class Cat
{
	double re, im;	// ����

public:
	Cat()	{ cout << "Cat����\n"; }
	~Cat()	{ cout << "Cat����\n"; }
	Cat( double r, double i ):	re(r), im(i)	{}
	Cat operator + ( Cat& );	// + ���Ƕ�Ԫ������������ǳ�Ա��������ǰ�������һԪ����������һԪ
	Cat operator * ( Cat& );	// ��Ԫ

	double getre()	{ return re; }
	double getim()	{ return im; }

	void setre( double r )	{ re = r; }
	void setim( double i )	{ im = i; }
};


// ������Ϊ�������Ա�����ø��ƹ��캯�� �� ��������
// ����������ò����Ļ���com �����������������������������������ù��캯����������Ϊ���ݵĶ���
Cat Cat::operator + ( Cat& com )
{
	Cat temp1;

	temp1.setre( re + com.getre() );
	temp1.setim( im + com.getim() );

	return temp1;
}


// a * b��this ����ָ�� a ��ָ�롣com ���� b �����á�ò�������⣬a ����Ҳ���ı���!!!
Cat Cat::operator * ( Cat& com )
{
	this->setre( re * com.getre() );
	this->setim( im * com.getim() );

	return *this;
}


// ���������ض�Ԫ�����
// ���ڲ��ǳ�Ա������û�ж������Ա���Ҫ����������
Cat operator - (Cat& a, Cat& b)
{
	Cat temp3;

	temp3.setre( a.getre() - b.getre() );
	temp3.setim( a.getim() - b.getim() );

	return temp3;
}


void main()
{
	// ������������д����a/b ����Ķ�����ô����� double �����Ĺ��캯����������Ĭ�Ϲ��캯��������������ǻ�������������ġ�
	Cat a = Cat(1, 2);
	Cat b(2, 4);

	// ��ʱ����� c��d ������ù��캯������Ϊ���ǲ���ʹ�ù��캯������ġ����������ʱ�������������
	// ���� + ����������д�������ʱ��������ʹ�� + ����ù��캯�������󷵻�����������ֵ�����������
	// �� * ���������ʹ�õ���ָ�� a ������ָ�� this����ʱ�� a ���ǵ�ǰ����ʵ��������ʡȥ����ĵ��ã���
	Cat c = a + b;
	Cat d = a.operator * (b);	// ��ʽ��д����
	cout << c.getre() << "-" << c.getim() << endl;
	cout << d.getre() << "-" << d.getim() << endl;

	c = a + Cat(1, 2);	// �����˹��캯��������Ҳ�����һ��������������ʵ�ϸô�����������������������֪��Ϊɶ
	cout << c.getre() << "-" << c.getim() << endl;

	Cat e = b - a;	// �� Cat e = operator - (b, a); ͬ��
	cout << e.getre() << "-" << e.getim() << endl;
}