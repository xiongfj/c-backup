#include <iostream.h>

// char** argv ��ʾָ��ָ���һ��ָ�룬������������һ��ָ�룬����һ��ָ�����һ���ַ���(���ո�ֿ���)
// ��һ��ָ��ͱ�ʾ��һ���ַ���(һ��ָ��ָ��һ���ַ���)

void main( int argc, char** argv )
{
	cout << argc << endl;		// �����ĸ��������е� 0 ���Զ�������Ϊ�ó���ģ�·������

	// �����в����ڣ�project>setting>debug>program arguments ���룬�ÿո��ʾ�ֿ�ÿ�� argv[i]
	for ( int i = 0; i < argc; i++ )
		cout << argv[i] << endl;
}