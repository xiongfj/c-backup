#include <iostream.h>
#include "out_side.cpp"		// �ڸ��ļ����� int out_side = 100;
// ���out_side.cpp �ļ������������ģ�static int out_side = 100; ��ô���޷�������ļ��У���Ϊ���޶��˲��ɱ�����

// ���Բ�д int
extern	int out_side;		// �� out_side.cpp �ڵ� out_side �������������뱾�ļ�


void main()
{
	cout << out_side;		// �������ļ��ı��������ˣ����Կ��Ի�ȡ�Ǹ��ļ��иñ�����ֵ��
}