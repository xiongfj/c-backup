#include <iostream.h>
void swap(int *a,int *b);
int main()
{
	int x=5,y=10;
	cout <<x<<"  "<<y<<endl;
	swap(&x,&y);
	cout <<x<<"  "<<y<<endl;
	return 0;
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
