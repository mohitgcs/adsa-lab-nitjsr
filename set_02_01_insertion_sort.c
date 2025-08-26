#include<stdio.h>
 int main(){
 	int i,j,k,n,t;
 	
 	printf("enter the size of array");
 	scanf(" %d",&n);
 	int a[n];
 	for(i = 0;i<n;i++){
 		printf("enter the element of array");
 		scanf(" %d",&a[i]);
	 }
	 for(i=0;i<=n;i++){
	 	j =i;
	 	while(j>0 && a[j-i]>a[j])
	 	{
	 		t = a[j];
	 		a[j]= a[j-1];
	 		a[j-1] = t;
	 		j--;
	 		
		 }
	 }
	 printf("sorted list");
	 
	 	for(i = 0;i<n;i++){
	 		printf("  %d", a[i]);
		 }
	 
	  }
