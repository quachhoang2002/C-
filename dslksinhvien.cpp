#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct sinhvien{
	char hoten[30];
	int avg;
};
struct node{
	sinhvien data;
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
node *getnode(sinhvien x)
{
	node*p=new node;
	if(p==NULL) return NULL;
	p->data=x;
	p->pnext=NULL;
	return p;
}
void addhead(list &l,node* p)
{
		if(l.phead == NULL)
	{
	l.phead=l.ptail=p;
	}
	else
	{
	p->pnext=l.phead;
	l.phead=p;
	}
}

void input(list&l)
{  
	int n;
	cout<<"nhap so phan tu ";
	cin>>n;
	init(l);
	for(int i=1;i<=n;i++)
	{ sinhvien x;
	cout<<"nhap ho ten ";   
	fflush(stdin);
	gets(x.hoten);
	cout<<"nhap diem trung binh ";  
	cin>>x.avg;			
	node*p=getnode(x);
	addhead(l,p);
	}
	
}
void output(list l)
{
	for(node* p = l.phead; p != NULL; p = p->pnext)
	{
		
	cout<<p->data.hoten<<" "<<p->data.avg<<endl;
	}
}


int min(list l)
{    int min=l.phead->data.avg;
	for(node* p = l.phead; p != NULL; p = p->pnext)
	{
		if(p->data.avg<min) min=p->data.avg;
	}
	return min;
}

int max(list l)
{    int max=l.phead->data.avg;
	for(node* p = l.phead; p != NULL; p = p->pnext)
	{
		if(p->data.avg>max) max=p->data.avg;
	}
	return max;
}


void diemtrungbinh(list&l)
{      float s=0,n=0;
		for(node* p = l.phead; p != NULL; p = p->pnext)
	{       n++;
			s=s+p->data.avg;
			
	}
	float(s=s/n);
	cout<<s;
}
void swap(int a , int b )
{
	int t=a;
	a=b;
	b=t;
}
void sapxep(list &l){
	for(node*p=l.phead;p!=NULL;p=p->pnext){
		for(node*q=p->pnext;q!=NULL;q=q->pnext)
			if(p->data.avg>q->data.avg)
		{
			swap(p->data,q->data);
		}
	}
	
}
void quicksort(list &l)
{
	list l1;list l2;
	node *tag, *p;
	if(l.phead==l.ptail) return;
	init(l1) ; init(l2);
	tag=l.phead;
	l.phead=l.phead->pnext;
	tag->pnext=NULL;
	while(l.phead!=NULL){
		p=l.phead;
		l.phead=l.phead->pnext;
		p->pnext=NULL;
		if(p->data.avg<=tag->data.avg) addhead(l1,p);
		else addhead(l2,p);
	}
	quicksort(l1);
	quicksort(l2);
	if(l1.phead!=NULL){
		l.phead=l1.phead;
		l1.ptail->pnext=tag;
	}
	else l.phead=tag;
	tag->pnext=l2.phead;
	if(l2.phead!=NULL)
	l.ptail=l2.ptail;
	else l.ptail=tag;
	
	
}
int main()
{
	list k;
	input(k);
     output(k);
     cout<<endl;
   cout<< min(k);
    cout<<endl;
    cout<<max(k);
    cout<<endl;
    diemtrungbinh(k);
    cout<<endl;
    sapxep(k);
    output(k);
    cout<<endl;
	quicksort(k);
	output(k);
}

