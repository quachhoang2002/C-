#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *pnext;
};
struct list{
  node*phead;
  node*ptail;
};
void khoitao(list &l)
{
	l.phead=NULL;
	l.ptail==NULL;
}
node*getnode(int x)
{
	node*p=new node;
	if(p==NULL)
	return NULL;
	p->data=x;
	p->pnext=NULL;
	return p;
}
void themvaodau(list &l,node*p)
{
	if(l.phead==NULL){
	l.phead=l.ptail=p;}
	else{
		p->pnext=l.phead;
		l.phead=p;
	}
}
void themvaocuoi(list &l,node*p)
{
	if(l.phead==NULL)
	l.phead=l.ptail=p;
	else{
		l.ptail->pnext=p;
		l.ptail=p;
	}
}
void input(list &l)
{    
	khoitao(l);
	int n; cin>>n;
	khoitao(l);
	for(int i=1;i<=n;i++)
	{int a;
	cin>>a;
	node*p=getnode(a);
	themvaodau(l,p);
	
	}	
	
}
void output(list&l)
{
	for(node*p=l.phead;p!=NULL;p=p->pnext)
	cout<<p->data;
}
void themqvaop(list&l,node*p)
{
	int x;
	cout<<"nhap q";cin>>x;
	node*q=getnode(x);
	if(q->data==l.phead->data&&l.phead->pnext==NULL)
	{
		themvaocuoi(l,p);
	}
	else{
		for(node*k=l.phead;k!=NULL;k=k->pnext)
		if(q->data==k->data)
		{   
		    node*h=getnode(p->data);
			node*g=k->pnext;
			h->pnext=g;
			k->pnext=h;
			
		}
	}
}
void nhapvitrip(list l)
{int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			node *p = getnode(x);
		themqvaop(l, p);
	
}
int main()
{   
	list lst;
	input(lst);
	output(lst);
	cout<<endl;
	nhapvitrip(lst);
	output(lst);
    
    
}
