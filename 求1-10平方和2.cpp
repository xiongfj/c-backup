#include <iostream.h>
int sum(int);
int main()
{
	int i=1,z;
	z=sum(i);
	z=z+sum(i+2);
	z=z+sum(i+4);
	z=z+sum(6+i);
	z=z+sum(8+i);
	cout <<z<<endl;
	return 0;
}
int sum(int a)
{
	return (a*a+(++a)*a);
}