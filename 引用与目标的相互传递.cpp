#include <iostream.h>
int main()
{
	int a=11;
	int &A=a;
	cout <<a<<endl;
	cout <<A<<endl;
	cout <<&a<<endl;
	cout <<&A<<endl;

	a=22;
	cout <<a<<endl;
	cout <<A<<endl;
	cout <<&a<<endl;
	cout <<&A<<endl;

	A=33;//����a����A��ô����ֵ��������ı�����ԭ�ȵĵ�ַ!!!!!//һ�㲻�������¸����ø�ֵ
	cout <<a<<endl;
	cout <<A<<endl;
	cout <<&a<<endl;
	cout <<&A<<endl;

	return 0;
}