#include <iostream.h>
int Area(int length,int width);//������һ������ԭ�ͣ����ֺţ������������������壬���߲�д��������
int main()
{
	int lengthofyard,widthofyard,areaofyard;
	cout <<"\nhow wide is your yard?";
	cin >> widthofyard;
	cout <<"\nhow long is your yard?";
	cin >> lengthofyard;
	areaofyard=Area(lengthofyard,widthofyard);//������ı�Ԫ���ݸ������ĺ���
	cout <<"\nyour yard is:"<<areaofyard;
	cout <<"square feel \n\n";
	return 0;
}
int Area(int yardlength,int yardwidth)//���庯���������ֺ�
{
	return yardlength*yardwidth;//���������ݣ���δ�����ܵ��ñ�������ʱ���庯���ı������������⣬���ø����ݹ����ı�Ԫ������ԭ����ı�������ͬ
}
