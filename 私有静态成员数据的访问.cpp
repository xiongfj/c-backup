#include <iostream.h>

class Cat
{
public:
	Cat(int age):	itsAge(age)	{HowManyCats++;}
	virtual ~Cat()	{HowManyCats--;}
	virtual int GetAge()	{return itsAge;}
	virtual void SetAge(int age)	{itsAge = age;}
	virtual int GetHowMany()	{return HowManyCats;}

private:
	int itsAge;

	// 静态成员数据是该类所有对象共有的！
	// 就是说如果最后有一个对象将此静态成员数据赋值为10,
	// 那么不管前面有多少个对象将其赋值为其他非 10 的值，
	// 最终不管用哪一个对象调用函数来获取它，
	// 得到的值永远是 10 (当然前提是 10 是最后设置的值)
	static int HowManyCats;
};

int Cat::HowManyCats = 0;


void main()
{
	Cat* CatHouse[5];

	for (int i = 0; i < 5; i++)
		CatHouse[i] = new Cat(i);

	for (int j = 0; j < 5; j++)
	{
		// 去掉删除指针操作，改行始终输出 5
		cout << CatHouse[j]->GetHowMany() << endl;


		cout << CatHouse[j]->GetAge() + 2 << endl;

		//delete CatHouse[j];
		CatHouse[j] = 0;
	}
}