#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void input(int*a,int n)
{
	for(int i=0;i<n;i++)
	cin>>a[i];
}
void output(int*a,int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i];
}
void insert(int *a,int &n,int value,int pos)
{n++;
for(int i=n;i>pos;i--)
{a[i]=a[i-1];  
              }
a[pos]=value;
                 }
    int binarysearch(int *a,int n,int value)
{
	int l=0,r=n-1,mid;
	while(l<=r){
		
	mid=(l+r)/2;
    if(a[mid]==value) return mid;
    if(a[mid]>value) r=mid-1;
    else l=mid+1;}
    return r;
	}
	
	void binaryinsertionsort(int *a,int n){
		for (int i=1;i<n;i++){
			int x=a[i];
			int k=binarysearch(a,i,x)+1;
			for(int j=k;j<i;j++)
			a[j+1]=a[j];
			a[k]=x;
		}
	}
	void binaryinsert(int *a,int &n,int value)
	{
		for(int i=1;i<n;i++)
		{int pos=binarysearch(a,n,value)+1;
	  for (int i=n;i>pos;i--){
		a[i]=a[i-1];  };
		a[pos]=value;
		n++;
		}
		
	}
int main()
{ int n ;
int *a=new int(n);
 n = sizeof(a)/sizeof(a[0]);
cin>>n;
input(a,n);

insert(a,n,5,2);
output(a,n);
cout<<endl;
cout<<binarysearch(a,n,8);
cout<<endl;

binaryinsertionsort(a,n);
output(a,n);
cout<<endl;
binaryinsert(a,n,6);
output(a,n);
}
