#include <iostream.h>
class DOG
{
	
};
class Cat
{
public:
	Cat(){cout <<"���캯��------\n";}
	Cat(Cat&){cout <<"���ƹ��캯��lllllllll\n";}
	~Cat(){cout <<"������������������\n";}
	DOG function(Cat a);
private:
	DOG dog;

};

DOG Cat::function(Cat a)
{
	return dog;//ֻ������һ����������----x����Ŀ������������
}//�����������󣨷�Cat��Ķ��󣩺��񲻵����κζ���????
int main()
{
	Cat x;
	x.function(x);//ֻ������һ�θ��ƹ��캯��
	return 0;
}
