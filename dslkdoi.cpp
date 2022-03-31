#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*pnext;
	struct node*prev;	
};
struct list{
	node*phead;
	node*ptail;
	
};
void khoitao(list &l)
{
	l.phead==NULL;
	l.ptail==NULL;
}
node*getnode(int x)
{   node*p=new node;
	if(p==NULL) return NULL;
	p->data=x;
	p->pnext=NULL;	
	p->prev=NULL;
		
	return p;
}
void addhead(list&l,node*p)
{
	if(l.phead==NULL) l.phead=l.ptail=p;
	else 
	p->pnext=l.phead;
	l.phead->prev=p;
	l.phead=p;
}
void addtail(list&l,node*p)
{
	if(l.phead==NULL) l.phead=l.ptail=p;
	else
	l.ptail->pnext=p;
	p->prev=l.ptail;
	l.ptail=p;
}
void input(list&l)
{
	int n;
	cout<<"nhap vao n ";cin>>n;
	khoitao(l);
	for(int i=1;i<=n;i++)
	{
		int x;
		cout<<"nhap gia tri cua node  " ;cin>>x;
		node*p=getnode(x);	
		addhead(l,p);
	}
}
void output(list&l)
{
	for(node*p=l.phead;p!=NULL;p->pnext)
	{
		cout<<p->data;
	}
}



int layphantudautien(list&l)
{
	return l.phead->data;
}
int main()
{
 list k;
 input(k);
 output(k);	
 system("pause");
 
}































