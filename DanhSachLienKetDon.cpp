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

void addtail(list&l,node*new_ele){
	if(l.phead==NULL){
		l.phead=new_ele;
		l.ptail=l.phead;
	}
	else{
		l.ptail->pnext=new_ele;
		l.ptail=new_ele;
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
	addtail(l,p);}
	
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
		if(p->data>max)
		max=p->data;
	} return max;
}
int main()
{
	list k;int n;
	input(k);
	output(k);
	cout<<endl;
    cin>>n;
    int x=maxmin(k);
    cout<<maxmin(k);
    cout<<endl;
    if(x==n) cout<<"tim thay gia tri";  else	cout<<" khong ton tai trong danh sach hoac khong phai la phan tu lon nhat"<<endl;
	return 0;
}

