#include <iostream.h>

enum {kIsSmaller, kIsLarger, kIsSame};

//****************************************************************

// �������ݵ���

class Data
{
public:
	Data( int val ):	myValue( val )		{ cout << "Data����";		}
	~Data()	{}

	int Compare( const Data& );	// const ������Ϊ�˷�ֹ�ı����ö�Ӧ�ı���ֵ
	void Show()								{ cout << myValue << endl;	}

private:
	int myValue;
};

// ����data1.Compare(data2)  �Ƚϵ��� data1 �� data2 �� myValue ֵ
// this ָ�� data1(����ǰ����)

int Data::Compare( const Data& theOtherData )
{
	cout << "��com��";

	if ( myValue < theOtherData.myValue )
		return kIsSmaller;

	if ( myValue > theOtherData.myValue )
		return kIsLarger;
	else
		return kIsSame;
}


//****************************************************************

class Node;

class HeadNode;			// �������඼�� Node ��������
class TeilNode;
class InternalNode;

class LinkedList;

//****************************************************************

// ���麯����˵����ǰ����һ��������࣬�޷����ɶ�����Ҫ����
// ûд =0 �������Դ�������

class Node
{
public:
	Node()			{ cout << "Node����";	}
	virtual ~Node() {						}

	virtual Node* Insert( Data* theData ) = 0;	// ���麯��
	virtual void Show() = 0;					// ���麯������û�к���ʵ��(��ȻҲ������)�������þ���ǿ��������Ҫ��д�ú�����


private:
};



// ***************************************************************

class InternalNode:public Node
{
public:
	InternalNode( Data* theData, Node* next );
	~InternalNode()			{ delete myNext; delete myData;	cout << "das";	}

	virtual Node* Insert( Data* theData );
	virtual void Show()		{ myData->Show(); myNext->Show();	}	// ���յ��� Show() ��ʱ��myNext ָ����Ķ���


private:
	Data* myData;	// myData ֻ��ָ�� Data ��Ķ�����Ϊ Data ��û��������������
	Node* myNext;
};

//
InternalNode::InternalNode( Data* theData, Node* next ):

	myData( theData ),

	// ���� ll ����ʱ���� myNext �� TailNode �� Insert() ��ֵΪ this(HeadNode �� myNext)����ָ�� TailNode
	// �����Ա������� Insert() �� ��ֵΪ this��myNext = myNext->Insert(); �����߶�ָ�� InternalNode
	myNext( next	)
{
	cout << "InternalNode����";
}

//
Node* InternalNode::Insert( Data* theData )
{
	cout << "InternalNode��Insert��";

	// (��HeadNode �� myNextָ���)myData �Ǿ����ݣ�theData ��������
	int result = myData -> Compare( *theData );

	
	switch ( result )
	{

		case kIsSame:
		case kIsLarger:	// ��������������С����ֱ�ӷ��ڵ�ǰ������漴��(��Ϊ��ǰ��������ָ����С���Ǹ������ theData)
			{
				// this �� HeadNode �ĳ�Ա myNext��ָ�� InternalNode �Ķ���
				// ���½�һ�����󴢴������� theData������ dataNode ָ�������ݣ�dataNode ���غ��ָ� HeadNode �ĳ�Ա myNext ��ֵ��
				// ����ԭ��ָ������� myData �� myNext����ָ���������� theData(��ʱ�����ݽ�С)

				// ͬʱ����� myNext �� this ��ֵ�ˣ�this ��ԭ��ָ������� HeadNode �� myNext
				// ���� HeadNode �� myNext ָ���¶���� theData���¶���� myNext ��ָ��ö�������� theData��
				// �ö���� myNext ��ָ��þö���� theData....ֱ��ֱ�� TailNode

				// ��� theData ��С���ʹ���һ���¶��󴢴�(theData��myNext)
				// �¶���� myNext �� ��ǰָ�� this ��ֵΪָ��ϴ�Ķ���� myData

				// �������¶���ĵ�ַ���ظ� HeadNode �� myNext
				InternalNode* dataNode = new InternalNode( theData, this );

				return dataNode;
			}

		case kIsSmaller:	// ��� theData �ϴ�

			// �����������ݴ��� 2 �Σ���ô�͵��ú��� Insert ����
			// ��ʱ�� myNext ָ����һ�� theData
			// ����ָ����һ������� theData ��ָ����� InternalNode::Insert() ��������������ݱȽ�....

			myNext = myNext->Insert( theData );

			return this;	// HeadNode �� myNext ����ָ��ԭ���Ķ���
	}
	return this;
}


//****************************************************************


class TailNode:public Node
{
public:
	TailNode()			{ cout << "TailNode����";	}
	~TailNode()			{							}

	virtual Node* Insert( Data* theData );
	virtual void Show()	{}

private:

};

//
Node* TailNode::Insert( Data* theData )
{
	InternalNode* dataNode = new InternalNode( theData, this );	// ˭�����˸ú�����this ָ���ָ��˭(HeadNode �� myNext)

	cout << "TailNode �� Insert��";

	return dataNode;	// �ú������غ�HeadNode �ĳ�Աָ�� myNext ��ָ�� InternalNode
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
	// ���� TailNode �Ķ��󣬸� TailNode ���ִ� Node �����������������Ⱥ���� Node��TailNode ��Ĺ��캯��
	myNext = new TailNode;

	cout << "HeadNode����";
}

//
Node* HeadNode::Insert( Data* theData )
{	
	// myNext �� Node ��ָ�룬���� Node �ĳ�Ա Insert() �Ǵ��麯��������Ϊë��һ���������ʵ��� TailNode �� Insert()������
	// �ڶ��������Ժ���ʵĶ��� InternalNode �� Insert()?? ����Ϊ myNext ����������ֵ��ֵ�ı��˷���

	// ���� ll �����ʱ��myNext ��ָ�� TailNode
	// �ڵ����� TailNode �� Insert() ��
	// Insert() ����һ�� InternalNode*������ֵ���� myNext
	// ����˵���� LinkeList ����ʱ��myNext ��һ��ָ�� TailNode�����涼ָ�� InternalNode

	myNext = myNext->Insert( theData );	// myNext ��Զָ����С���Ǹ� theData

	return this;
}


//****************************************************************

// ����
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
	// �ù��캯��������һ�� HeadNode ���󣬸��� HeadNode �ִӻ��� Node ���������������Ⱥ���� Node��HeadNode �Ĺ��캯��
	myHead = new HeadNode;

	cout << "LinkedList �Ĺ��캯��";
}

//
void LinkedList::Insert( Data* pData )
{
	// myHead �ڹ��캯���б���ֵָ�� HeadNode
	myHead->Insert( pData );
}


//****************************************************************


int main()
{
	Data* pData;
	int val;

	// ���� ll ���������5�����캯������Ϊ������Ĺ��캯�����ִ�����������Ķ����Ǹ�������Ĺ��캯���ִ�������һ����Ķ���
	LinkedList ll;		// �����Ҳ�оֲ�����

	for ( ;; )
	{
		cout << "what is value?";
		cin  >> val;

		if ( !val )
			break;

		pData = new Data( val );	// �� new(��) �д���һ�����󣬵��� Data �Ĺ��캯����pData ָ��ö���.

		ll.Insert( pData );
	}


	ll.ShowAll();
	return 0;
}