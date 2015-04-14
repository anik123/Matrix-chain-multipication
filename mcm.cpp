#include<iostream>
#include<stdio.h>
#define max 500
#define max1 50
using namespace std;
int m[max1][max1],p[max],s[max1][max1],v,flag=1;
void mcm(int r)
{
   int n,i,k,l,j,sum;
   n=r-1;
   v=n;
   for(i=1;i<=n;i++)
	   m[i][i]=0;
   for(l=2;l<=n;l++)
   {
	   for(i=1;i<=n-l+1;i++)
	   {
		   j=i+l-1;
		   m[i][j]=999999;
		   for(k=i;k<=j-1;k++)
		   {
               sum=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			   if(sum<m[i][j])
			   {
				   m[i][j]=sum;
				   s[i][j]=k;
				   cout<< "for"<<i<<"and for "<<j <<" K is "<<k<<endl;
				   cout<<sum<<endl;
			   }
		   }
	   }
   }
   
}
void print(int i,int j){
	if(i==j){
        
             printf(" A%d x ",i);
	    flag=0;
	}
    else
    {
        flag=1;
		printf("(");
		flag=0;
		print(i,s[i][j]);
		print(s[i][j]+1,j);
  		printf(")");
	}
}
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i];
	mcm(n);
	print(1,n-1);
	cout<<m[1][n-1];
}