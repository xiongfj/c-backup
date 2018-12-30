#include <iostream.h>
int sum(int);
int main()
{
	int i=1,z;
	z=sum(i++);
	z=z+sum(++i);
	i++;
	z=z+sum(++i);
	i++;
	z=z+sum(++i);
	i++;
	z=z+sum(++i);
	cout <<z<<endl;
	return 0;
}
int sum(int a)
{
	return (a*a+(++a)*a);
}