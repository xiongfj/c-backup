#include <iostream.h>
int main()
{
	int a,b,c;
	cout <<"enter three number: \n";
	cin >> a;
	cin >> b;
	cin >> c;
	if(c=(a-b))//ֻ��һ���Ⱥ���ô���������ֵֻ�����ֿ��ܣ�0����1�������ٻ����档
		//ֻҪa=b����ִ��else��ֻҪa������b�������ִ��if����ġ�ͬʱҲ�����˸�ֵ���c=a-b,c��ֵҲ��ı䣻
	{
		cout <<"a:  ";
		cout <<a;
		cout <<"minus b:   ";
		cout <<b;
		cout <<"equals c: ";
		cout <<c<<endl;//
	}
	else
		cout <<"a-b don't equals c:    "<<endl;
	return 0;
}//