#include<iostream>
#include<math.h>
using namespace std;
// ham gop 2 mang
void Merge(int *a,int left,int mid,int right){
int i,j,k;// khoi tao bien i j k 
int n1=mid-left+1;//cac phan tu nam nua trai cua mang
int n2=right-mid;//cac phan tu nam nua phai cua mang
//tao mang tam
int L[n1],R[n2]; //khoi tao 2 mang tam
 for (i = 0; i < n1; i++) // cho vong lap chay tu i-> n1
        L[i] = a[left + i];// gan mang L[i] = nua mang ben trai
    for (j = 0; j < n2; j++) //cho vong lap  chay tu j->n2
        R[j] = a[mid + 1+ j];//gan mang R[j]=nua mang  ben phai
//gop 2 mang tam vao mang a        
	i=0;// khoi tao chi so bat dau mang con dau tien 
	j=0;// khoi tao chi so bat dau mang con thu 2
	k=left;// gang left = k
	   while (i < n1 && j < n2) // khi i<n1 va j<n2 ta  thuc hien
    {
        if (L[i] <= R[j]) //so sanh nua mang con ben trai voi ben phai voi nhau
        {
            a[k] = L[i];//neu mang ben trai be hon thi gan mang L[i] vao mang a[k]
            i++;//tang i len 1 don vi
        }
        else
        {
            a[k] = R[j]; // neu mang phai be hon thi gang R[J] vao mang a[k]
            j++; // tang j len mot don vi
        }
        k++;// sau khi gang L[i] hoac R[j] vao mang a[k] ta tang k len 1 don vi
    }
    
    //gang cac phan tu con lai vao mang a[k]
     while (i < n1)   //khi i van con nho hon n1 ta thuc hien
    {
        a[k] = L[i]; //gan mang a[k] =L[i]
        i++;// tang i len 1 dong vi neu i 
        k++;// tang k len 1 don vi 
    }
 while (j < n2)//khi j van con nho hon n1 ta thuc hien
    {
        a[k] = R[j]; //gan mang a[k] =L[i]
        j++; // tang i len 1 dong vi neu i
        k++; // tang k len 1 don vi 
    }
}
// goi de quy
void MergeSort(int*a,int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;//tim phan tu o giua
		MergeSort(a,left,mid);//goi de quy nua ben trai cua mang
		MergeSort(a,mid+1,right);//goi de quy nua ben phai cua mang
		Merge(a,left,mid,right);//gop 2 mang lai vao nhau
		
	}

}
//nhap mang
void inputArray(int *a,int n){
	for(int i=0;i<n;i++)
	cin>>a[i];
	
}
//xuat mang
void outputArray(int*a,int n){
	for(int i=0;i<n;i++)
	cout<<a[i];
}



int main()
{
	int n;
	int *a=new int[n];
	cout<<"nhap n " ;cin>>n;
	inputArray(a,n);
	MergeSort(a,0,n-1);
	outputArray(a,n);
    return 0;
}
