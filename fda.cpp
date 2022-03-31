#include<iostream>
#include<math.h>
using namespace std;
float tb(int a[100][100],int n, int m)
{ int s=0,d=0;
for(int i=0;i<n;i++)
 {
 	for (int j=0;j<m;j++) 
 	{
	s +=a[i][j];
 	d++;
 }
 } return (float)(s/d);
}
int close(int a[100][100],int n,int m)
{float t=tb(a,n,m);
 int check=a[0][0];
 for(int i=0;i<n;i++)
 {
 	for (int j=0;j<m;j++) {
 		float min=abs(a[i][j]-tb(a,n,m));
 		if(min<t){ check =a[i][j];
 		t=min;
		 }
	 } return check;
}}
