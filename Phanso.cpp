#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct phanso {
	int tu;
	int mau;
};
	
struct node {
	phanso data;
	struct node* pnext;
};
struct list {
	node* phead;
	node* ptail;
};
void khoitao(list& l)
{
	l.phead = NULL;
	l.ptail = NULL;
}
node* getnode(phanso x){
	node * p = new node;
	if (p == 0) return NULL;
	else  p->data.tu = x.tu;
	      p->data.mau = x.mau;
	     
		  p->pnext = NULL;
	
		  return p;
}



void addhead(list& l,node*p)
{
	if (l.phead == NULL) l.phead = l.ptail = p;
	else
		p->pnext = l.phead;
	l.phead = p;
}
void input(list& l) {
	int n;
	cin >> n;
	khoitao(l);
	for (int i = 1; i <= n; i++) {
		phanso x;
		cout << "nhap tu mau ";
		cin >> x.tu;cin>> x.mau;
		node* p = getnode(x);
		addhead(l, p);
	}
}
void output(list& l) {
	for (node* p = l.phead; p != NULL; p = p->pnext)
		
		cout << p->data.tu <<   "/"  << p->data.mau<<"   ";
	cout << endl;
	
}
int ucln(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
void sum(list& l)
{
	phanso s;
	s.tu = 0;
	s.mau = 1;
		for (node* p = l.phead; p != NULL; p = p->pnext)
		{
			s.tu = p->data.tu * s.mau + s.tu * p->data.mau;
				s.mau = s.mau * p->data.mau;
	}
		int uc = ucln(s.tu, s.mau);
		s.tu = s.tu / uc;
		s.mau = s.mau / uc;
		cout << s.tu << "/" << s.mau<<" ";

}
void sum2node(list& l) {
	node* a = l.phead->pnext;
	node* b = NULL;
	node* p = l.phead;
	while (p != l.ptail)
	{
		b = p;
		p = p->pnext;
	}
	phanso c;
	c.tu = a->data.tu * b->data.mau + b->data.tu * a->data.mau;
	c.mau = a->data.mau * b->data.mau;
	int uc = ucln(c.tu, c.mau);
	c.tu = c.tu / uc;
	c.mau = c.mau / uc;
	cout << c.tu << "/" << c.mau<<"  ";

}
phanso min(list&l)
{
	phanso min;
	min.tu = l.phead->data.tu;
	min.mau = l.phead->data.mau;
	for (node* p = l.phead; p != NULL; p = p->pnext)
	{
	 if (p->data.tu * min.mau < p->data.mau * min.tu)
		min.tu = p->data.tu;
		min.mau = p->data.mau;
	}
	return min;

}
phanso max(list&l)
{
	phanso max;
	max.tu = l.phead->data.tu;
	max.mau = l.phead->data.mau;
	for (node* p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->data.tu*max.mau>p->data.mau*max.tu)
			max.tu = p->data.tu;
		max.mau = p->data.mau;
	}
	return max;

}

int main()
{
	list a;
	input(a);
	output(a);
	cout << endl;
	 sum(a);
	 cout << endl;
	 sum2node(a);
	 cout << endl;
	 cout<<max(a).tu<<"/"<<min(a).mau;
	 cout << endl;
	 cout<<min(a).tu<<"/"<<min(a).mau;
	 cout << endl;}
	
