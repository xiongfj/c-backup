#include <iostream.h>


// ʹ��ĳ���ݣ�������������֮�����ʹ�ã�������������ǰ��ʹ��

namespace Window
{
	int a = 10;
	int geta1()	{ return a; }
	int geta2();

	namespace ChildWindow
	{
		int b;
		enum FILK { IF, LUCKY, LYDIA, MEMORIES };

		void Value()	{ b = a; }		// �ڲ����ֱ�ӷ���(���)��(����)�ĳ�Ա
		void Showb()	{ cout << b + Window::a; }	// Ҳ�����޶�
	}

	class Cat
	{
	public:
		Cat():	age(111)	{}
		int Get()	{ return age; }
		void Set()	{ age = a; }

	private:
		int age;
		ChildWindow::FILK name;		// ��Ҫʹ����������ռ�����ĳ�Ա�������������ÿռ�
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

//	cout << Window::Cat::age << endl;	����!!!

	Window::ChildWindow::Value();
	Window::ChildWindow::Showb();
}