#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long int P[100002];
long long int Q[100002];
long long int arr1[100002];
long long int arr2[100002];
long long int arr3[100002];
long long int arr4[100002];
long long int dep1[100002];
long long int dep2[100002];

//creating MergeAddition

long long int mergeadd(long long int arr[],int lower,int middle,int upper)
{


        int length1=middle-lower+1;
        int length2=upper-middle;
	long long int count=0;

        for(int x=0;x<length1;x++)
                arr1[x]=arr[x+lower];
        for(int x=0;x<length2;x++)
                arr2[x]=arr[middle+1+x];

        int x,y,k;

	for(x=0,y=0,k=lower;x<length1&&y<length2;k++)
        {
                if(arr1[x]<=arr2[y])
                {
                        arr[k]=arr1[x];
                        x++;
                }
                else
                {
                        arr[k]=arr2[y];
                        y++;
			count+=(length1-x);

                }
        }

        for(;x<length1;k++)
        {
                arr[k]=arr1[x];
                x++;
        }

        for(;y<length2;k++)
        {
                arr[k]=arr2[y];
                y++;
        }
	return count;
}

//creating MergeDistribute

long long int merge(long long int arr[],int lower,int upper)
{
        int middle;
	long long int count=0;
        if(lower<upper)
        {
                middle=lower+(upper-lower)/2;

               count=merge(arr,lower,middle);
               count+= merge(arr,middle+1,upper);

               count+= mergeadd(arr,lower,middle,upper);
        }
	return count;
}

//creating MergeAddition

void mergeadd1(long long int arr[],long long int dep[],int lower,int middle,int upper)
{


        int length1=middle-lower+1;
        int length2=upper-middle;

        for(int x=0;x<length1;x++)
        {
                arr3[x]=arr[x+lower];
                dep1[x]=dep[x+lower];
        }
        for(int x=0;x<length2;x++)
        {
                arr4[x]=arr[middle+1+x];
		        dep2[x]=dep[middle+1+x];
        }

        int x,y,k;

        for(x=0,y=0,k=lower;x<length1&&y<length2;k++)
        {
                if(arr3[x]<=arr4[y])
                {
                        arr[k]=arr3[x];
                        dep[k]=dep1[x];
                        x++;

                }
                else if(arr4[y]<arr3[x])
                {
                        arr[k]=arr4[y];
                        dep[k]=dep2[y];
                        y++;
                }
	}

         for(;x<length1;k++)
        {
                arr[k]=arr3[x];
                dep[k]=dep1[x];
                x++;
        }

        for(;y<length2;k++)
        {
                arr[k]=arr4[y];
                dep[k]=dep2[y];
                y++;
        }
}

//creating MergeDistribute

void merge1(long long int arr[],long long int dep[],int lower,int upper)
{
        int middle;
	        if(lower<upper)
        {
                middle=lower+(upper-lower)/2;

                merge1(arr,dep,lower,middle);
                merge1(arr,dep,middle+1,upper);

                mergeadd1(arr,dep,lower,middle,upper);
        }
}

int main(void)
{

	int T;

	scanf("%d", &T);

	for(int i=1;i<=T;i++)
	{
		int N;
		scanf("%d", &N);
		

		for(int j=0;j<N;j++)
		{
			scanf("%lld %lld", &P[j], &Q[j]);
		}


		//SortP and paste Q accordingly
		

		merge1(P,Q,0,N-1);

		//Now Sort Q
		long long int answer=merge(Q,0,N-1);
		printf("%lld \n",answer);
	}
	return 0;
}




