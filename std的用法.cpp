#include <iostream>
int main()
{
	std::cout <<"enter two number: \n";
	int v1,v2;
	std::cin >>v1>>v2;//没有包含iostream.h；所以每个都必须注明使用的是std中的东西
	std::cout <<v1+v2<<std::endl;//或者在#include..下面加上一行(using namespace std;),就不用每处都写std了   
	return 0;
}