#include <iostream.h>
int main()
{
	int z,i=1;
	z=1+(++i)*i;//���д��(++i)*(++i)����2*3��!
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;
	z=z+(++i)*i;

	cout <<"1-10��ƽ����="<<z<<endl;
	return 0;
}