#include <iostream.h>
float convert(float);
int main()
{
	float tempfer,tempcel;
	cout <<"enter a �����¶ȣ�";
	cin >> tempfer;
	tempcel=convert(tempfer);//���ú����������������䴦����ٷ���
	cout <<"ת����������¶�Ϊ��";
	cout <<tempcel<<endl;
	return 0;
}
float convert(float b)//Ҳ�����ڴ���������ֻдһ�� return ((b-32)*5)/9;Ч����ͬ
{
	float a;//�����˾ֲ�������ֻ���������conver��Ч
	a=((b-32)*5)/9;
	return a;
}
