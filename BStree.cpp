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
		cout<<t<<" ";
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
node*search(tree  &t,int x ){
	
if(t==NULL) return NULL;	
if(t){
	if(t->data==x) return t;
	if(t->data>x) return search(t->pleft,x);
	else return search(t->pright,x);
} 
return NULL;
	
}
//node co gia tri nho nhat
int LeftMostValue( tree&t )
{
    while ( t->pleft != NULL )
        t = t->pleft;
    return t->data;
}


// tim kiem node nho nhat
void searchStandFor(tree &p, tree&q){
	if(q->pleft) searchStandFor(p,q->pleft);
	else{
		p->data=q->data;
		p=q;
		q=q->pright;
	}
	cout<<q;
}
//xoa node 
int deleteNode2(tree &t,int x){
	if(!t) return 0;
	if(t->data>x) return deleteNode2(t->pleft,x);
	if(t->data<x) return deleteNode2(t->pright,x);
   
  else {
	node*p=t;
	if(!t->pleft) t=t->pright;
	else 
	if(!t->pright) t=t->pleft;
	else searchStandFor(p,t->pright);
	delete p;
	return 1;
}
}
//dem node
int count(tree &t){
	if(!t) return 0;
	else return 1+count(t->pleft)+count(t->pright);
	
}
//chieu dai cua cay
int heightoftree(node* n)
{
	if(n){
		int l=heightoftree(n->pleft);
		int r=heightoftree(n->pright);
		return ((l>r)?l:r)+1;
	}return 0;
}

int countleafNode(tree &t){
	if(!t) return 0 ;
     if(t->pleft ==NULL  && t->pright==NULL)
     return 1;
     return countleafNode(t->pleft)+countleafNode(t->pright);
	
}

//dem node co 2 node con
int countTwoChild(tree t){
	if(t==NULL) return 0;
	else {
		int count=0;
		if(t->pleft && t->pright) count++;
		countTwoChild(t->pleft);
		countTwoChild(t->pright);
		return count;
	}
}
int countLeftChildeNode(tree t){
	if(t==NULL) return 0;
	else{
		int count=0;
		if(t->pleft) count++;
		countTwoChild(t->pleft);
		countTwoChild(t->pright);
		return count;
	}
}
// xac dinh co phai cay tim kiem nhi phan hay khong
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
	getnode(T,5);
	getnode(T,2);
	getnode(T,6);
	getnode(T,4);
    getnode(T,10);
    getnode(T,12);
    getnode(T,3);
    xuatKetQua(T);
    LNR(T);

	deleteNode2(T,5);
	cout<<endl;
	searchStandFor();
	NLR(T);
	cout<<endl;
	
	if(search(T,20)) cout<<" co ton tai  "; else cout<<"khong ton tai node";cout<<endl;
	
	cout<<count(T);
	cout<<endl;
	
	cout<<heightoftree(T);
	cout<<endl;

	cout<<countleafNode;
	cout<<endl;

	cout<<countTwoChild(T);
	cout<<endl;
	cout<<countLeftChildeNode(T);
	
	
	
}
