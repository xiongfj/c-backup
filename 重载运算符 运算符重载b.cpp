#include <iostream.h>

class Cat
{
	int re, im;

public:
	Cat()	{ cout << "Cat����\n"; }
	~Cat()	{ cout << "Cat����\n"; }
	Cat( int r, int i ):	re(r), im(i)	{}

	// �޷������͵ĳ�Ա����ֻ��һ������Ҳ�������ض�Ԫ���������Ϊ�ж���
	// ����������������������û�������ͣ�ֻ��һ�����������޷����ض�Ԫ������ġ�
	void operator ++ ();			// һԪ�����
	Cat  operator ++ (int);				// ����++
	void operator += ( Cat& );		// ��Ԫ�����

	int getre()	{ return re; }
	int getim()	{ return im; }

	void set( int r, int i)	{ re = r; im = i; }
};


// ���ص���ǰ�������
void Cat::operator ++ ()
{
	re++;
	im++;
}

/* ���������ǰ�������Ҳ����д������
Cat Cat::operator ++ ()
{
	re++;
	im++;

	return *this;
}
*/


// ����++
// int ֻ��Ϊ����������� void
Cat Cat::operator ++ (int a)
{
	Cat temp(*this);	// �Լ�ǰ��ֵ���� temp

	re++;
	im++;

	return temp;
}




// a += b;	 ��ͬ�� a.operator += (b);
// this ָ��ָ��ǰ���� a
// ����û�з���ֵ�����ܽ� a+=b ��Ϊ����
// ��Ϊ a+=b ����ʽ�Ӹ�����ûֵ
// ���� *this �����òſ���
// ���������Ҳ����

void Cat::operator += ( Cat& com )
{
	// ��ʱֱ�ӷ��� im �� this->getim() ����ͬһ��˼
	// this ָ��ǰ����im ��ֵ���ǵ�ǰ�����ֵ
	int er = this->getre() + com.getre();
	int mi = im			   + com.getim();

	this->set(er, mi);
}


void main()
{
	Cat a = Cat(1, 2);
	Cat b(2, 4);

	a += b;	// ��ͬ�� a.operator += (b);
	cout << a.getre() << "-" << a.getim() << endl;

	++a;
	cout << a.getre() << "-" << a.getim() << endl;
	
}