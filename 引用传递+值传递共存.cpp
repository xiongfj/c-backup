#include <iostream.h>
typedef unsigned short int ushort;
enum errtrue{truee,err};//truee=0,err=1 //ö���ͳ��������һ���µ����� errtrue(��������int float��ͬ��ʹ��!!)
errtrue F(ushort,ushort&,ushort&);//������һ������ֵ������errtrue�ĺ���!!1
int main()
{
	ushort number,squared,cubed;
	errtrue result;
	cout <<"����0-20:";
	cin >>number;
	result=F(number,squared,cubed);
	if(result==truee)//Ҳ���԰�trueeд��0
	{
		cout <<number<<endl;  //�������ԭ����number ����+1
		cout <<squared<<endl; //��ֵ�ѱ������ú���F�ı�!!
		cout <<cubed<<endl;   //ͬ�ϣ��Ѹı�
	}
	else
		cout <<"error ����!!";
	return 0;
}
errtrue F(ushort n, ushort &a, ushort &b)//���������β�ʹ�����ô��ݣ����Ըı�squared��cubed��ԭֵ!!
{
	if(n>20)
		return err;   //������1����ʲô��ֻҪ���صĲ���truue��if��������!!!
	else
	{
		n=n+1;//����nʹ�õ��Ǵ����ֵ���ݣ����Բ��ı�n��ԭֵ!!
		a=n*n;
		b=n*n*n;
		return truee;//������0����ʲô�����ص���result==truee����ʹif����
	}
}


