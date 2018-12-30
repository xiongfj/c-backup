#include <iostream.h>


// 使用某数据，必须在其申明之后才能使用，不可在其申明前面使用

namespace Window
{
	int a = 10;
	int geta1()	{ return a; }
	int geta2();

	namespace ChildWindow
	{
		int b;
		enum FILK { IF, LUCKY, LYDIA, MEMORIES };

		void Value()	{ b = a; }		// 内层可以直接访问(外层)或(本层)的成员
		void Showb()	{ cout << b + Window::a; }	// 也可以限定
	}

	class Cat
	{
	public:
		Cat():	age(111)	{}
		int Get()	{ return age; }
		void Set()	{ age = a; }

	private:
		int age;
		ChildWindow::FILK name;		// 需要使用这个命名空间里面的成员，必须先申明该空间
	};
}


int Window::geta2()
{
	return a;
}



void main()
{
	Window::Cat cat;

	cat.Set();

	cout << cat.Get() << endl;
	cout << Window::geta2() << endl;

//	cout << Window::Cat::age << endl;	错误!!!

	Window::ChildWindow::Value();
	Window::ChildWindow::Showb();
}