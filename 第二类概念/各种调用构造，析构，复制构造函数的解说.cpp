#include <iostream.h>
class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();
};
SimpleCat::SimpleCat()
{
	cout <<"���캯��---!\n";
}
SimpleCat::SimpleCat(SimpleCat&)
{
	cout <<"���ƹ��캯��...........!\n";
}
SimpleCat::~SimpleCat()
{
	cout <<"��������iiiiiiiiii\n";
}
SimpleCat functionone(SimpleCat theCat);
SimpleCat *functiontwo(SimpleCat *theCat);
int main()
{
	SimpleCat first;//���ù��캯��
	functionone(first);//����ֵ���ݷ�ʽ��functionone�����˶���first�Ŀ�����ȥ(functionone������и���һ�������Ķ���first�������˸��ƹ��캯��!
	functiontwo(&first);//��ȡ���ô��ݵķ�ʽ���ᴴ������Ҳ��������κκ���!!!
	return 0;//����������first���������������������������
}
SimpleCat functionone(SimpleCat theCat)
{
	return theCat;//��ȡֵ���ݵķ�ʽ����SimpleCat���󣬽���first�ĵڶ����������ظ����������ø��ƹ��캯��
}//���øú������������������������������������������ʱ���õ�����������������!!

SimpleCat *functiontwo(SimpleCat *theCat)
{
	return theCat;
}


