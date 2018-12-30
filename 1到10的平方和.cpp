#include <iostream.h>
int main()
{
	int z,i=1;
	z=1+(++i)*i;//如果写成(++i)*(++i)就是2*3了!
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;

	cout <<"1-10等平方和="<<z<<endl;
	return 0;
}