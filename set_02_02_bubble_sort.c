#include<stdio.h>
#include<stdio.h>
 int main(){
 	int i,j,flag=1,n,t;
 	int a[100];
 	printf("enter the size of array ");
 	scanf("%d",&n);
 	for(i = 0;i<n;i++){
 		printf("enter the element of array ");
 		scanf("%d",&a[i]);
	 }
	 for(j=0;j<n;j++)
	 {
	 	flag=1;
	 for(i=0;i<n-j-1;i++)
	 {
	 	if(a[i]>a[i+1])
	 	{
	 		t = a[i];
	 		a[i] = a[i+1];
	 		a[i+1] = t;
	 		flag = 0;
	 		
		 }
		 }
		 if(flag == 1)
		 break;
		 }
	 	printf("sorted list");
	 	for(i = 0;i<n;i++){
	 		printf("  %d", a[i]);
		 }
		 }
