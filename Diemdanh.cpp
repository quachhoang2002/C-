#include<iostream>
#include <math.h>
void mang(int *a,int n)
{ 
for(int i=0;i<n;i++)
 cin>>a[i];
}
int quicksort(int *a,int l,int 
{
   int i=l;int j=r;
   int x=a[(l+r)/2];
   while(i<=j) 
   {while(a[i]<x) i+=1;
   while(a[i]>x) j-=1;
   if(i<=j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
       i+=1;
       j-=1;

    } if(j>l) quicksort(a,l,r)
       if(r>i)quicksort(a,l,r) }}
