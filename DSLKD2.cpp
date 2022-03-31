#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//khai bao cau truc node
struct node{
	int data;             //khai bao du lieu
	struct node*pnext;
};
//khai bao danh sach lien ket 
struct list{
	node*phead;    //phan tu dau tien
	node*ptail;    //phan tu cuoi cung (khong co cung duoc)
};
//khoi tao danh sach lien ket
void init(list &l)
{
	l.ptail=NULL;   // khoi tao danh sach rong  
	l.phead=NULL;   
} 
//tao node
node *getnode(int x)
{
	node*p=new node;
	if(p==NULL) return NULL;
	p->data=x;      //x la gi tri cua node p
	p->pnext=NULL;//node vua tao chua them vao dau ca nen cho bang NULL
	return p;
}
//kiem tra danh sach co rong hay khong 
int isEmpty(list l){
return (l.phead==NULL);
}
//them vao dau danh sach
void addhead(list&l,node*new_ele)
{
		if(l.phead == NULL)           //xem danh sach co rong hay khong
	{
		l.phead = new_ele;       
		l.ptail =l.phead;         //neu rong thi phead voi ptail = voi node them vao
	}
	else
	{ 
		new_ele->pnext = l.phead;   //node them vao lien ket voi phead  
		l.phead = new_ele;            //cap nhat lai phead = node moi them vao
	}
} 
//them vao cuoi danh sach
void addtail(list&l,node*new_ele){
	if(l.phead==NULL){             //xem danh sach co rong hay khong   
		l.phead=new_ele;              //ney rong thi phead = ptail = voi node them vao
		l.ptail=l.phead;    
	}
	else{
		l.ptail->pnext=new_ele;    //cho ptail lien ket voi node them vao
		l.ptail=new_ele;          //cap nhat lai ptail = node moi them vao 
	}
	
}

//them gia tri q vao p
void thempvaoq(list&l,node*p)
{
	int x;
	cout<<"nhap vi tri q ";cin>>x;  // nhap vi tri gia tri q muon them vao
	node*q=getnode(x);

	if(q->data==l.phead->data&&l.phead->pnext==NULL)  //neu danh sach co 1 phan tu
	{
		addtail(l,p);  //them vao cuoi
	}
	else{
		for(node*k=l.phead;k!=NULL;k=k->pnext)  // cho k duyet de nhet danh sach
		if(q->data==k->data)               // tim duoc vi tri can them vao sau
		{   
		    node*h=getnode(p->data);    // tao node h vao sau node q
			node*g=k->pnext;          // cho node g tro den node sau node q
			h->pnext=g;               // tao moi lien nket giua h voi g 
			k->pnext=h;               // tao moi lien ket giua k voi h
			
		}
	}
}
//mhap gia tri p can them vao
void nhapvitrip(list l)
{int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			node *p = getnode(x);
		thempvaoq(l, p);
	
}
//xoa node o dau
int removeNodeAtHead(list &l){
node *p = l.phead; //gan node p = phead
l.phead = p->pnext;//cap nhat lai phead
if(l.phead==NULL)l.ptail=NULL; // danh sach rong
p->pnext = NULL;// cho p tro den gia tri NULL
delete p; //xoa p
return 1;
}
//xoa node o cuoi
int removeNodeAtTail(list &l){
node *p = l.phead;
node *q = NULL;
while(p!=l.ptail){ //duyet tu dau den cuoi mang q la node  ke cuoi
q = p;  
p = p->pnext;
}
if(!p) return -1; //khong ton tai p  
if(q){    
q->pnext = NULL; // cho con tro q tro den NULL;
l.ptail = q; // cap nhat lai ptail la q
}
else {
l.phead = l.ptail = NULL; // danh sach rong
}
delete p; //xoa p
return 1;
}

//tim kiem node
node* searchNode(list l, int x){
node* p = l.phead;             
if(p==NULL) return NULL;     
while (p){       //duyet het danh sach       
if(p->data == x)return p;//tim thay gia tri can tim tra ve p
 p = p->pnext;//chua tiep thay lai tiep tuc duyet tiep
}
return NULL;//neu khong co tra ve null
}
 
// tong node dau va cuoi
int tongdaucuoi(list l)
{
	int s;
	s=l.phead->data+l.ptail->data;
	return s;
}
void swap(int &a , int &b )
{
	int t=a;
	a=b;
	b=t;
}
//sap xep truc tiep
void interchangesort(list &l){
	for(node*p=l.phead;p!=NULL;p=p->pnext){
		for(node*q=p->pnext;q!=NULL;q=q->pnext)
			if(p->data>q->data) // so sanh tung phan tu roi sap xep lai
		{
			swap(p->data,q->data); 
		}
	}
	
} 
//tim gia tri lon nhat trong danh sach
int maxmin(list l)
{
	int max=l.phead->data;
	for(node*p=l.phead;p!=NULL;p=p->pnext){
		if(p->data>max)
		max=p->data;
	} return max;
}
//nhap dslk
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
//xuat dslk
void output(list l)
{
	for(node* p = l.phead; p != NULL; p = p->pnext)
	{
		
		cout<<p->data;
	}
}
int main()
{    
	list k;

	input(k);
	output(k);	
  cout<<endl;
	cout<<maxmin(k);
	cout<<endl;
	int x=maxmin(k);
	int n;
	cin>>n; 
	if(x==n) cout<<"tim thay gia tri";  else	cout<<" khong ton tai trong danh sach hoac khong phai la phan tu lon nhat"<<endl;
	
	cout<<endl;
	cout<<tongdaucuoi(k);
	cout<<endl;
	searchNode(k,2);
	cout<<endl;
	if(searchNode(k,2)) cout<<"tim thay ";else cout<<"khong tim thay ";
	
	nhapvitrip(k);
	output(k);
	cout<<endl;
	
	removeNodeAtHead(k);
	output(k);
	cout<<endl;
	
	removeNodeAtTail(k);
	output(k);
	cout<<endl;
		
	interchangesort(k);
	output(k);
	cout<<endl;
	

	return 0;
}


