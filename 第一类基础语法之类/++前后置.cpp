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

	cout <<myage<<endl;//40，上上面的两个前置和后置++语句都已完成加1
	cout <<yourage<<endl;//40,我们是在它们完成+1后再cout的，所以都是40


	cout <<"another year"<<endl;

	cout <<myage++<<endl;//40，我们直接cout了myage++，所以取了40的值cout后再+1，这段语句之后的myage已经是41
	cout <<++yourage<<endl;//41，我们也直接cout了yourage，+1之后再cout，所以是41


	cout <<"printf it again"<<endl;

	cout <<myage<<endl;//41，前面cout后+1，所以也是41
	cout <<yourage<<endl;//41，前面语句已经结束，还是41
	return 0;
}

