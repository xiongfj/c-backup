#include <iostream>
#include <string>
#include <tchar.h>
using namespace std;

typedef unsigned int u32_t;

template <class T> 
class LinkNode		// 双向链表 + 循环相连
{
public:
	LinkNode();
	LinkNode( const T& );
	~LinkNode(){};

//	LinkNode* CreateLink( u32_t len );			// 产生一个长 len 的链表
	LinkNode<T>* AddNext( const T& );				// 向后添加元素
	LinkNode<T>* AddPrev( const T& );				// 向前添加元素

	void CoutString()
	{
		cout << str << endl;
	}
	LinkNode<T>* GetNext()				// 即使在类里面也要加上 <T>
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
	LinkNode<string> link(s);			// 新建一个链表，保持 link 的固定性

	link.AddNext( *(new string("姐啊三度空间挥洒的")) );

	LinkNode<string>* p = &link;
	for ( int i = 0; i < 2; i++ )
	{
		p->CoutString();
		p = p->GetNext();
	}
}

/*************************/

// 用于创建第一个指向自身的节点
template<class T>
LinkNode<T>::LinkNode( const T& s )
{
	pPrev = pNext = this;
	str = s;
}

// 使用 this 指针在当前指针位置后面添加元素
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

// 在当前位置的前面添加元素
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


// 高中笔记本里有草稿描摹图