#include <iostream>
#include <iomanip>
using namespace std;

class CNode                          //节点
{
public:
	int data;
	CNode *next;
	CNode()
	{
		next=NULL;
	}	
};

class CList
{
private:
	CNode *head;                                                    //头节点
public:
	CList();
	void create();                                                     //创建链表
	void display() const;                                           //显示链表
	~CList();                                                            //销毁链表
	int getlen() const;                                              //获取链表长度
	bool isEmpty() const;                                         //判断链表是否为空
	bool find(const int e) const;                              //在链表中查找某个值
	CNode* getNode(int i) const;                            //返回第i个节点
	void insert(int i,const int e);                               //在第i个位置插入元素e
	void remove(const int e);                                     //删除一个元素e	
	void reverse();                                                   //链表逆置	
};

CList::CList()
{
	head=new CNode();
	head->next=NULL;	
}

void CList::create()
{
	CNode *p,*q;
	p=head;
	q=new CNode();
	cout<<"请输入值(按ctrl+d停止): "<<endl;
	while(cin>>q->data)
	{
		p->next=q;		
		p=q;
		q=new CNode();
	}
}

void CList::display() const             //显示链表
{
	CNode *p;
	p=head->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

CList::~CList()
{
	CNode *p;
	while(head)
	{
		p=head->next;
		delete head;
		head=p;
	}
}

int CList::getlen() const
{
	int length=0;
	CNode *p=head->next;
	while(p)
	{
		length++;
		p=p->next;
	}
	return length;
}

bool CList::isEmpty() const
{
	return (head->next==NULL);
}

bool CList::find(const int e) const
{
	CNode* p=head->next;
	while(p)
	{
		if(p->data==e)
			return true;
		p=p->next;
	}
	return false;
}

CNode* CList::getNode(int i) const
{
	if(i<0||i>getlen())                         //i不在链表范围内时，抛出异常
	{		
		throw i;
	}
	CNode* p=head;
	while(p&&i)
	{
		p=p->next;
		i--;
	}
	return p;
}

void CList::insert(int i,const int e)
{
	CNode *p;
	CNode *node=new CNode();
	node->data=e;
	if(i==1)                                       //在第一个位置插入节点
	{
		node->next=head->next;
		head->next=node;
	}
	else 
	{
		p=getNode(i-1);
		if(i==getlen())                         //在链表末位插入节点
			p->next=node;
		else
		{
			node->next=p->next;
			p->next=node;
		}
	}	
}

void CList::remove(const int e)
{
	if(!find(e))
	{
		cout<<"链表不包含值为"<<e<<"的节点!"<<endl;
		return;
	}
	CNode *p=head;
	CNode *q=head->next;
	while(q)
	{
		if(q->data==e)
		{
			break;
		}
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	return;
}

void CList::reverse()
{
	if(isEmpty())
	{
		cout<<"链表为空"<<endl;
		return;
	}
	CNode *p,*q;
	int len=getlen();
	int i=1;
	int j=len;
	while(i<j)
	{
		p=getNode(i);
		q=getNode(j);
		int temp=p->data;
		p->data=q->data;
		q->data=temp;
		++i;
		--j;
	}
}

int main()
{
	CList* link=new CList();
	link->create();
	link->display();
	cout << "length: " << link->getlen() << endl;
	cout << "is empty?" << link->isEmpty() << endl;
	cout << "contains 3?" << link->find(3) << endl;	
	try
	{
		cout<< (link->getNode(10))->data << endl;
	}catch(int)
	{
		cout << "所要获取的节点位置超出链表范围" << endl;
	}
	link->insert(1,888);
	link->insert(3,999);
	link->remove(6);
	link->display();	
	link->reverse();
	link->display();	
	return 0;
}
