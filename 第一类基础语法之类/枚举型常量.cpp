#include <iostream.h>
int main()
{
	enum days {sunday,monday,tuesday,wednesday,thursday,friday,saturday};
        //Ĭ�ϴ����ҷ��ų���ֵΪ0,1,2,3,4....
	//����enum days {sunday=3,monday,tuesday=21,wednesday,thursday,friday,saturday=87};
	//Ϊ��ʼ���ķ��ų�����ֵ=ǰһ����ֵ+1������monday=4,wednesday=22,thursday=23,
	int choice;
	cout <<"enter a day(0-6): ";
	cin >> choice;
	if(choice ==sunday || choice ==saturday)
		cout <<"��������Ķȹ���ĩ�ڣ�\n";
	else
		cout <<"�Թԣ�����Ŭ���Ĺ����ɣ� \n";
	return 0;
}