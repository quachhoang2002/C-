#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*pnext;
};
struct list{
	node*phead;
	node*ptail;
};
void init(list &l)
{
	l.phead=NULL;
	l.ptail=NULL;
}
node *getnode(int x)
{
	node*p=new node;
	if(p==NULL) return NULL;
	p->data=x;
	p->pnext=NULL;
	return p;
}
void addhead(list&l,node*new_ele)
{
		if(l.phead == NULL)
	{
		l.phead = new_ele;
		l.ptail =l.phead;
	}
	else
	{
		new_ele->pnext = l.phead;
		l.phead = new_ele;
	}
}

void input(list&l)
{  
	int n;
	cin>>n;
	init(l);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
	
	node*p=getnode(x);
	addhead(l,p);}
	
}
void output(list l)
{
	for(node* p = l.phead; p != NULL; p = p->pnext)
	{
		
		cout<<p->data;
	}
}
int maxmin(list l)
{
	int max=l.phead->data;
	for(node*p=l.phead;p!=NULL;p=p->pnext){
		if(p->data>max&&p->data<0)
		max=p->data;
	} return max;
}
int tongdaucuoi(list l)
{
	int s;
	s=l.phead->data+l.ptail->data;
	return s;
}
int tongdaucuoi2(list l)
{
	node*a=l.phead->pnext;
	node*b=NULL;
	node*p=l.phead;
	while(p!=l.ptail)
	{
		b=p;
		p=p->pnext;
	}
	return a->data+b->data;
}
int isempty(list l)
{
return l.phead==NULL;
}
addtail(list l,node*new_ele)
{
	if(l.phead==NULL){
    l.phead=new_ele;
    l.ptail=l.phead;}
    else{
    l.ptail->pnext=new_ele;
    l.ptail=new_ele;}
}
void appendlist(list l,list l1)
{
	if(l.phead==NULL) l=l1;
	else{
		l.ptail->pnext=l1.phead;
		if(l1.phead!=NULL)l.ptail=l1.ptail;
	}
}
void tachlink1(list &l,list &l1,list &l2)
{
	node*q;
	int dem=0;
	init(l1);
	init(l2);

	for(node*p=l.phead;p!=NULL;p=p->pnext)
	{ q=getnode(p->data);
		if(dem<n/2)
		{
		addhead(l1,q);
			dem++;
		}
		else {
			addhead(l2,q);
			dem++;
		}
	}
}
void tachdanhsachamduong(list l,list &l1,list &l2)
{
	node *q;
	init(l1);init(l2);
	for(node*p=l.phead;p!=NULL;p=p->pnext)
	{
		q=getnode(p->data);
		if(p->data>0) addhead(l1,q);
		else addhead(l2,q);
	}
}

int xoapantudau(list &l)
{
	node*p=l.phead;
	if(isempty(l)) return -1;
	l.phead=p->pnext;
	if(l.phead==NULL)l.ptail==NULL;
	p->pnext=NULL;
	delete p;
	return 1;
}
int main()
{
	list k;
	input(k);
	output(k);
    cout<<endl;
	cout<<maxmin(k);
	cout<<endl;
	cout<<tongdaucuoi(k);
	cout<<endl;
	cout<<tongdaucuoi2(k);
	cout<<endl;
	check(k);
	
	return 0;
}


