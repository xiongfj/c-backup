#include <iostream.h>

enum {kIsSmaller, kIsLarger, kIsSame};

//****************************************************************

// 储存数据的类

class Data
{
public:
	Data( int val ):	myValue( val )		{ cout << "Data构、";		}
	~Data()	{}

	int Compare( const Data& );	// const 引用是为了防止改变引用对应的本身值
	void Show()								{ cout << myValue << endl;	}

private:
	int myValue;
};

// 例：data1.Compare(data2)  比较的是 data1 与 data2 的 myValue 值
// this 指向 data1(即当前对象)

int Data::Compare( const Data& theOtherData )
{
	cout << "我com、";

	if ( myValue < theOtherData.myValue )
		return kIsSmaller;

	if ( myValue > theOtherData.myValue )
		return kIsLarger;
	else
		return kIsSame;
}


//****************************************************************

class Node;

class HeadNode;			// 这三个类都由 Node 派生而来
class TeilNode;
class InternalNode;

class LinkedList;

//****************************************************************

// 纯虚函数，说明当前类是一个抽象基类，无法生成对象，需要派生
// 没写 =0 则该类可以创建对象

class Node
{
public:
	Node()			{ cout << "Node构、";	}
	virtual ~Node() {						}

	virtual Node* Insert( Data* theData ) = 0;	// 纯虚函数
	virtual void Show() = 0;					// 纯虚函数可以没有函数实现(当然也可以有)。其作用就是强制派生类要重写该函数。


private:
};



// ***************************************************************

class InternalNode:public Node
{
public:
	InternalNode( Data* theData, Node* next );
	~InternalNode()			{ delete myNext; delete myData;	cout << "das";	}

	virtual Node* Insert( Data* theData );
	virtual void Show()		{ myData->Show(); myNext->Show();	}	// 最终调用 Show() 的时候，myNext 指向本类的对象


private:
	Data* myData;	// myData 只能指向 Data 类的对象，因为 Data 类没有派生其他的类
	Node* myNext;
};

//
InternalNode::InternalNode( Data* theData, Node* next ):

	myData( theData ),

	// 创建 ll 对象时，该 myNext 被 TailNode 的 Insert() 赋值为 this(HeadNode 的 myNext)，即指向 TailNode
	// 后面成员被本类的 Insert() 中 赋值为 this、myNext = myNext->Insert(); 这两者都指向 InternalNode
	myNext( next	)
{
	cout << "InternalNode构、";
}

//
Node* InternalNode::Insert( Data* theData )
{
	cout << "InternalNode的Insert、";

	// (由HeadNode 的 myNext指向的)myData 是旧数据，theData 是新数据
	int result = myData -> Compare( *theData );

	
	switch ( result )
	{

		case kIsSame:
		case kIsLarger:	// 如果新输入的数较小，就直接放在当前对象后面即可(因为当前对象总是指向最小的那个对象的 theData)
			{
				// this 是 HeadNode 的成员 myNext，指向 InternalNode 的对象
				// 就新建一个对象储存新数据 theData，并用 dataNode 指向新数据，dataNode 返回后又给 HeadNode 的成员 myNext 赋值，
				// 这样原本指向旧数据 myData 的 myNext，就指向了新数据 theData(此时新数据较小)

				// 同时本类的 myNext 被 this 赋值了，this 即原先指向旧数据 HeadNode 的 myNext
				// 这样 HeadNode 的 myNext 指向新对象的 theData，新对象的 myNext 又指向久对象的数据 theData，
				// 久对象的 myNext 又指向久久对象的 theData....直到直到 TailNode

				// 如果 theData 较小，就创建一个新对象储存(theData，myNext)
				// 新对象的 myNext 被 当前指针 this 赋值为指向较大的对象的 myData

				// 并将该新对象的地址返回给 HeadNode 的 myNext
				InternalNode* dataNode = new InternalNode( theData, this );

				return dataNode;
			}

		case kIsSmaller:	// 如果 theData 较大

			// 如果输入的数据大于 2 次，那么就调用函数 Insert 自身
			// 此时的 myNext 指向下一个 theData
			// 这样指向下一个对象的 theData 的指针调用 InternalNode::Insert() 又与新输入的数据比较....

			myNext = myNext->Insert( theData );

			return this;	// HeadNode 的 myNext 还是指向原来的对象
	}
	return this;
}


//****************************************************************


class TailNode:public Node
{
public:
	TailNode()			{ cout << "TailNode构、";	}
	~TailNode()			{							}

	virtual Node* Insert( Data* theData );
	virtual void Show()	{}

private:

};

//
Node* TailNode::Insert( Data* theData )
{
	InternalNode* dataNode = new InternalNode( theData, this );	// 谁调用了该函数，this 指针就指向谁(HeadNode 的 myNext)

	cout << "TailNode 的 Insert、";

	return dataNode;	// 该函数返回后，HeadNode 的成员指针 myNext 将指向 InternalNode
}


//****************************************************************


class HeadNode:public Node
{
public:
	HeadNode();
	~HeadNode()				{ delete myNext;  }

	virtual Node* Insert( Data* theData );
	virtual void Show()		{ myNext->Show(); }

private:
	Node* myNext;
};

//
HeadNode::HeadNode()
{
	// 创建 TailNode 的对象，该 TailNode 类又从 Node 类派生而来，所以先后调用 Node、TailNode 类的构造函数
	myNext = new TailNode;

	cout << "HeadNode构、";
}

//
Node* HeadNode::Insert( Data* theData )
{	
	// myNext 是 Node 的指针，由于 Node 的成员 Insert() 是纯虚函数，但是为毛第一次输入后访问的是 TailNode 的 Insert()？？？
	// 第二次输入以后访问的都是 InternalNode 的 Insert()?? （因为 myNext 被函数返回值赋值改变了方向）

	// 创建 ll 对象的时候，myNext 被指向 TailNode
	// 在调用完 TailNode 的 Insert() 后
	// Insert() 返回一个 InternalNode*，并赋值给了 myNext
	// 所以说创建 LinkeList 对象时，myNext 第一次指向 TailNode，后面都指向 InternalNode

	myNext = myNext->Insert( theData );	// myNext 永远指向最小的那个 theData

	return this;
}


//****************************************************************

// 链表
class LinkedList
{
public:
	LinkedList();
	~LinkedList()			{ delete myHead;  }

	void Insert( Data* theData );
	void ShowAll()			{ myHead->Show(); }

private:
	HeadNode* myHead;
};

//
LinkedList::LinkedList()
{
	// 该构造函数创建了一个 HeadNode 对象，该类 HeadNode 又从基类 Node 派生而来，所以先后调用 Node、HeadNode 的构造函数
	myHead = new HeadNode;

	cout << "LinkedList 的构造函数";
}

//
void LinkedList::Insert( Data* pData )
{
	// myHead 在构造函数中被赋值指向 HeadNode
	myHead->Insert( pData );
}


//****************************************************************


int main()
{
	Data* pData;
	int val;

	// 创建 ll 对象调用了5个构造函数，因为本身类的构造函数内又创建了其他类的对象、那个其他类的构造函数又创建了另一个类的对象！
	LinkedList ll;		// 这对象也叫局部链表

	for ( ;; )
	{
		cout << "what is value?";
		cin  >> val;

		if ( !val )
			break;

		pData = new Data( val );	// 在 new(堆) 中创建一个对象，调用 Data 的构造函数，pData 指向该对象.

		ll.Insert( pData );
	}


	ll.ShowAll();
	return 0;
}