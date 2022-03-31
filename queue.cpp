#include<iostream>
#include<string>
using namespace std;
// khai bao cau truc node
struct node{
	int data;
	struct node*pnext;
};
// danh sach hang doi
struct queue{
	node*phead;
	node*ptail;
	
};
// khoi tao hang doi
void init(queue&q) {
	q.phead==NULL;
	q.ptail==NULL;
	
}
//tao node
node*getnode(int x){
	node*p=new node;
	if(p==NULL) return NULL;
	else {
		p->data=x;
		p->pnext=NULL;
	}return p;
} 
//kiem tra xem danh sach co rong hay khong
int isempty(queue&q) {
	return q.phead==NULL;
}

//kich thuoc hang doi
int size(queue q){
     int count=0;// bien dem = 0
	node*p=q.phead; // cho node p la phan tu vao dau tien
	while(p){           
		count++;             //duyet den cuoi hang doi va moi lan duyet lai tang bien dem len 1;
		p=p->pnext;  
	}
	return count;
}
//them du lieu vao 
void enqueue(queue &q,int x){
	node*p=getnode(x);
	if(isempty(q)) q.phead=q.ptail=p;//mang rong nen phead = ptail=p 
	else { 
		q.ptail->pnext=p; //  phan tu nao den sau them vao sau
		q.ptail=p;   // cap nhat lai vi tri ptail
	}
}
int dequeue(queue&q)
{ node*p=q.phead;// cho p la phan tu vao dau tien
q.phead=p->pnext;//can nhat lai phead
int x=p->data; //x luu gia tri cua node p
delete p; //xoa node p
return x;// tra ve gia tri x
	
}


int main()
{
	queue k;
	init(k);
	enqueue(k,3);
	enqueue(k,1);
	enqueue(k,2);
	enqueue(k,5);
	enqueue(k,4);
	cout<<dequeue(k)<<endl;
	cout<<dequeue(k)<<endl;
	cout<<size(k);
	
}
