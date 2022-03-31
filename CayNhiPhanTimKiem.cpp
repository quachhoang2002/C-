#include<iostream>
using namespace std;
//khai bao cau truc node
struct node{
	int data;
	struct node*pleft;
	struct node*pright;
};
// cay chua node
typedef node*tree;

//tao node
void getnode(tree&t,int x)
{	
	if(t==NULL){
	node*p=new node;
		p->data=x;
		p->pleft=NULL;
		p->pright=NULL;
		t=p		;
	}
	
	else 
	{
		if(t->data>x)   getnode(t->pleft,x);
		else if(t->data<x) getnode(t->pright,x);
		 
	}
	
}
//duyet NLR
void NLR(tree&t){
	
	if(t!=NULL){
		cout<<t->data<<" ";
		NLR(t->pleft);
		NLR(t->pright);
	}
}
//duyet LNR
void LNR(tree&t){
	if(t!=NULL){
		LNR(t->pleft);
		cout<<t->data<<" ";
		LNR(t->pright);
	}
}
// DUYET LRN
void LRN(tree&t){
		if(t!=NULL){
		LNR(t->pleft);
		LNR(t->pright);
		cout<<t->data<<" ";
	}
}
//DUYET RNL
void RNL(tree&t)
{
	if(t!=NULL)
	{
	          RNL(t->pright);
	          cout<<t->data<<" ";
	          RNL(t->pleft);
	}
}
//tim kiem
node*search(tree  t,int x ){
	
if(t==NULL) return NULL;	
if(t){
	if(t->data==x) return t;
	if(t->data>x) return search(t->pleft,x);
	else return search(t->pright,x);
} 
return NULL;
	
}

int LeftMostValue( tree&t )
{
    while ( t->pleft != NULL )
        t = t->pleft;
    return t->data;
}



int heightoftree(node* n)
{
	if(n){
		int l=heightoftree(n->pleft);
		int r=heightoftree(n->pright);
		return ((l>r)?l:r)+1;
	}return 0;
}

//xoa node 
//int deleteNode2(tree &t,int x){
//	if(!t) return 0;
//	if(t->data>x) return deleteNode2(t->pleft,x);
//	if(t->data<x) return deleteNode2(t->pright,x);
//   
//  else {
//	node*p=t;
//	if(!t->pleft) t=t->pright;
//	else 
//	if(!t->pright) t=t->pleft;
//	else searchStandFor(p,t->pright);
//	delete p;
//	return 1;
//}
int isBST(tree &node)
{
	if (node == NULL)
    	      return 1;
  	
	if (node->pleft != NULL && node->pleft->data > node->data)
    	      return 0;
     
  	if (node->pright != NULL && node->pright->data < node->data)
    	      return 0;
   
  	if (!isBST(node->pleft) || !isBST(node->pright))
               return 0;
    
  	return 1;
}

void xuatKetQua(tree&node)
{
	if (isBST(node) == 1)
	           cout<<"Day la cay tim kiem nhi phan"<<endl;
	else 
	           cout<<"Khong phai la cay tim kiem nhi phan"<<endl;	
}
int main()
{
	tree T;
	T=NULL;
	getnode(T,9);
	getnode(T,5);
	getnode(T,3);
	getnode(T,4);
    getnode(T,8);
    getnode(T,12);
  
	NLR(T);
	cout<<endl;
	if(search(T,10)) cout<<" co ton tai  "; else cout<<"khong ton tai node";
	cout<<endl;	
	cout<<heightoftree(T);
	cout<<endl;
	cout<<LeftMostValue(T);
	
	}

