#include<iostream>
#include<string>

using namespace std;
struct node{
	int data;
	struct node*pnext;
};
struct stack{
	node*phead;
	node*ptail;	
};
void khoitao(stack&s)
{
	s.phead==NULL;
	s.ptail==NULL;
}
int isempty(stack&s){
	
	return s.phead==NULL;	
}
int size(stack s){
    int count =0;
	node*p=s.phead;
   while(p){
   	count++;
   	p=p->pnext;
   }
   return count;
}

node*getnode(int x)
{
	node*p=new node;
    if(p==NULL) return NULL;
	p->data=x;
	p->pnext=NULL;	
	return p;
}
void push(stack &s,int x)
{   node*p=getnode(x);
	if(isempty(s)) s.phead=s.ptail=p;
	else
	{p->pnext=s.phead;
	s.phead=p;
}
}
int pop(stack &s)
{
	node*p=s.phead;
	int x=p->data;
	s.phead=p->pnext;
	delete p;
	return x;
}

int fibo(int n){
	if(n==0||n==1) return 1;
	return fibo(n-1)+fibo(n-2);
}
int fibo2(stack &s,int n){
int a,b;
push(s,1);
push(s,1);
for(int i=1;i<n;i++){
  a=pop(s);
  b=pop(s);
  push(s,a);
  push(s,a+b);
}

return pop(s);	}

void dec(int n){
	stack s;
	khoitao(s);
	while(n>0) {
		push(s,n%2);
		n=n/2;
	}
	while(!isempty(s)){
		cout<<pop(s);
	}
}
string dec(int &n){
	stack s;
	khoitao(s);
	char k[10];
	int dem=0;
	while(n>0)
	{
		push(s,n%2);
		n=n/2;
	}
	while(!isempty)
	{
		k[dem]=pop(s);
		dem++;
	}return k;
}
int main()
{
	stack a;
    khoitao(a);
   	push(a,5);
	push(a,4);
	push(a,2);
	push(a,3);
    push(a,6);   
   cout<<pop(a)<<endl;
   cout<<pop(a)<<endl;
    cout<<pop(a)<<endl;
   	cout<<size(a);
  	cout<<endl;
  	cout<<fibo2(a,3);
  	cout<<endl;
  	dec(8);
}
