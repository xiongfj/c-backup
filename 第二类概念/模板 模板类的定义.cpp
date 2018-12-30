#include <iostream>
#include <string>
#include <tchar.h>
using namespace std;

typedef unsigned int u32_t;

template <class T> 
class LinkNode		// ˫������ + ѭ������
{
public:
	LinkNode();
	LinkNode( const T& );
	~LinkNode(){};

//	LinkNode* CreateLink( u32_t len );			// ����һ���� len ������
	LinkNode<T>* AddNext( const T& );				// ������Ԫ��
	LinkNode<T>* AddPrev( const T& );				// ��ǰ���Ԫ��

	void CoutString()
	{
		cout << str << endl;
	}
	LinkNode<T>* GetNext()				// ��ʹ��������ҲҪ���� <T>
	{
		return pNext;
	}

private:
	LinkNode<T>* pPrev;
	LinkNode<T>* pNext;
	T str;
};

/*********************/

void main()
{
	string s = "caddddd";
	LinkNode<string> link(s);			// �½�һ���������� link �Ĺ̶���

	link.AddNext( *(new string("�㰡���ȿռ������")) );

	LinkNode<string>* p = &link;
	for ( int i = 0; i < 2; i++ )
	{
		p->CoutString();
		p = p->GetNext();
	}
}

/*************************/

// ���ڴ�����һ��ָ������Ľڵ�
template<class T>
LinkNode<T>::LinkNode( const T& s )
{
	pPrev = pNext = this;
	str = s;
}

// ʹ�� this ָ���ڵ�ǰָ��λ�ú������Ԫ��
template<class T>
LinkNode<T>* LinkNode<T>::AddNext( const T& s )
{
	LinkNode<string>* p = new LinkNode<string>( s );
	p->pPrev = this;
	p->pNext = this->pNext;

	this->pNext->pPrev = p;
	this->pNext = p;
	return p;
}

// �ڵ�ǰλ�õ�ǰ�����Ԫ��
template< class T >
LinkNode<T>* LinkNode<T>::AddPrev( const T& s )
{
	LinkNode<string>* p = new LinkNode<string>( s );
	p->pNext = this;
	p->pPrev = this->pPrev;

	this->pPrev->pNext = p;
	this->pPrev = p;
	return p;
}


// ���бʼǱ����вݸ���ġͼ