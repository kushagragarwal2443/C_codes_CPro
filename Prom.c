#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
	int T;
	scanf("%d", &T);	

	for(int test=1;test<=T;test++)
	{
		 int n;
       		 scanf("%d", &n);


		 //creating array with all numbers from 1 to N and containing largest prime number as divisor


		 int arr[10001];
		 int arr1[10001];
		 int flag[10001];
		 
		 for(int i=2;i<=10000;i++)
		 {
			 flag[i]=0;
			 arr1[i]=-1;
			 arr[i]=i;
		 }
		 int s=1;
		 for(;s<=10000;)
		 {
			 s++;

			 if(arr1[s]==-1)
			 {
			 	for(int k=s;k<=10000;k+=s)
			 	{
					arr1[k]=s;
				}
			 }
			 
		 }


		 //filling array as given by user
		 
		 int query[n];
		 for(int m=0;m<n;m++)
		 {
			 scanf("%d", &query[m]);
		 }

		 
		 //checking which primes exist
		 
		 int q;int boy;int girl;
		 for(int j=0;j<n;j++)
		 {
			 q=query[j];
			 boy=q;

			 for(;boy>1;)
			 {
				 girl=arr1[boy];
				 flag[girl]=1;
				 boy=boy/girl;
			 }
		 }
		
		 //printing the count of primes

		 int count=0;
		 for(int j=2;j<=10000;j++)
		 {
			 if(flag[j]==1)
				 count++;
		 }

		 printf("%d \n", count);
	}
	return 0;
}




















