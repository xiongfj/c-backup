#include <iostream.h>
int main()
{
	int myage =39;
	int yourage =39;
	cout <<myage<<endl;
	cout <<yourage<<endl;
	myage++;
	++yourage;
	cout <<"one year"<<endl;

	cout <<myage<<endl;//40�������������ǰ�úͺ���++��䶼����ɼ�1
	cout <<yourage<<endl;//40,���������������+1����cout�ģ����Զ���40


	cout <<"another year"<<endl;

	cout <<myage++<<endl;//40������ֱ��cout��myage++������ȡ��40��ֵcout����+1��������֮���myage�Ѿ���41
	cout <<++yourage<<endl;//41������Ҳֱ��cout��yourage��+1֮����cout��������41


	cout <<"printf it again"<<endl;

	cout <<myage<<endl;//41��ǰ��cout��+1������Ҳ��41
	cout <<yourage<<endl;//41��ǰ������Ѿ�����������41
	return 0;
}

