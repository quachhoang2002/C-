#include<iostream>
using namespace std;
#define LH -1 
#define EH 0 
#define RH 1 
typedef struct tagAVLNode {
char balFactor;
int data;
struct tagAVLNode* pLeft;
struct tagAVLNode* pRight;
}AVLNode;
typedef AVLNode *AVLTree;

void getnode(AVLTree&t,int x)
{	
	if(t==NULL){
	AVLNode*p=new AVLNode;
		p->data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p		;
	}
	
	else 
	{
		if(t->data<0)   getnode(t->pLeft,x);
		else if(t->data>0) getnode(t->pRight,x);
		 
	}
	
}

void NLR(AVLTree&t){
	
	if(t!=NULL){
		cout<<t->data<<" ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}



void rotateLL(AVLTree &T) 
{
AVLNode* T1 = T->pLeft;
T->pLeft = T1->pRight;
T1->pRight = T;
switch(T1->balFactor) {
case LH: T->balFactor = EH; 
T1->balFactor = EH; 
break;
case EH: T->balFactor = LH;
T1->balFactor = RH; 
break;
}
T = T1;
}

void rotateRR(AVLTree &T) 
{
AVLNode* T1 = T->pRight;
T->pRight = T1->pLeft;
T1->pLeft = T;
switch(T1->balFactor) {
case RH: T->balFactor = EH;
T1->balFactor= EH; 
break;
case EH: T->balFactor = RH; 
T1->balFactor= LH; 
break;
}
T = T1;
}

void rotateLR(AVLTree &T)
{ AVLNode* T1 = T->pLeft;
AVLNode* T2 = T1->pRight;
T->pLeft = T2->pRight;
T2->pRight = T;
T1->pRight = T2->pLeft;
T2->pLeft = T1;
switch(T2->balFactor) {
case LH: T->balFactor = RH; T1->balFactor = EH; break;
case EH: T->balFactor = EH; T1->balFactor = EH; break;
case RH: T->balFactor = EH; T1->balFactor = LH; break;
}
T2->balFactor = EH;
T = T2;
}


void rotateRL(AVLTree &T) 
{ AVLNode* T1 = T->pRight;
AVLNode* T2 = T1->pLeft;
T->pRight = T2->pLeft;
T2->pLeft = T;
T1->pLeft = T2->pRight;
T2->pRight = T1;
switch(T2->balFactor) {
case RH: T->balFactor = LH; T1->balFactor = EH; break;
case EH: T->balFactor = EH; T1->balFactor = EH; break;
case LH: T->balFactor = EH; T1->balFactor = RH; break;
}
T2->balFactor = EH;
T = T2;
}

int balanceLeft(AVLTree &T)
 
{
AVLNode* T1 = T->pLeft;
switch(T1->balFactor) {
case LH: rotateLL(T); return 2;
case EH: rotateLL(T); return 1;
case RH: rotateLR(T); return 2;
}
return 0;
}

int balanceRight(AVLTree &T )

{
AVLNode* T1 = T->pRight;
switch(T1->balFactor) {
case LH: rotateRL(T); return 2;
case EH: rotateRR(T); return 1;
case RH: rotateRR(T); return 2;
}
return 0;
}

void preorder_print(AVLNode *nod) {
  if (nod != NULL) {
    printf("%d ", nod->data);
    preorder_print(nod->pLeft);
    preorder_print(nod->pRight);
  }
}

int insertNode(AVLTree &T, int X)
{

T = new AVLNode;
if(T == NULL) return -1; //thi?u b? nh?
T->data = X; 
T->balFactor = EH;
T->pLeft = T->pRight = NULL;
return 2; // thành công, chi?u cao tang
}

AVLNode*nodeganzeronhat(AVLTree &T) {
     AVLNode*p;
	if(T) {
	if(p!=NULL){
		if(T-> data<p->data) p=T;
	} else p=T;
	nodeganzeronhat(T->pLeft);
	nodeganzeronhat(T->pRight);}
	return p;
}
int main(){
		AVLTree T;
	T=NULL;
	getnode(T,1);
	getnode(T,2);
	getnode(T,19);
	getnode(T,15);
    getnode(T,10);
    insertNode(T,5);
    insertNode(T,7);
    insertNode(T,6);
    insertNode(T,10);
    
   preorder_print(T);
}


