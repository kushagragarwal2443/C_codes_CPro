#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long int arrX[1000009];
long long int arrY[1000009];
long long int FinalX[1000009];
long long int UnsortedY[1000009];
long long int SortedX[1000009];
long long int FinalY[1000009];
long long int arr1[1000009];
long long int arr2[1000009];
long long int arr3[1000009];
long long int arr4[1000009];
long long int dep1[1000009];
long long int dep2[1000009];

//creating MergeAddition

void mergeadd(long long int arr[],int lower,int middle,int upper)
{


	int length1=middle-lower+1;
	int length2=upper-middle;

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
}

//creating MergeDistribute

void merge(long long int arr[],int lower,int upper)
{
	int middle;
	if(lower<upper)
	{
		middle=lower+(upper-lower)/2;

		merge(arr,lower,middle);
		merge(arr,middle+1,upper);

		mergeadd(arr,lower,middle,upper);
	}
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
                if(arr3[x]<arr4[y])
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
		else
		{
			if(dep1[x]<=dep2[y])
			{
				arr[k]=arr3[x];
				dep[k]=dep1[x];
				x++;
			}
			else
			{
				arr[k]=arr4[y];
				dep[k]=dep2[y];
				y++;
			}
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
	long long int mod,N;
	scanf("%lld %lld", &N,&mod);

	for(int i=0;i<N;i++)
	{
		scanf("%lld %lld", &arrX[i], &arrY[i]);
	}

	for(int i=0;i<N;i++)
        {
               SortedX[i]=arrX[i];
	       UnsortedY[i]=arrY[i];
	}


	//Checking for duplicacies

	merge1(SortedX,UnsortedY,0,N-1);

	/*for(int i=0;i<N;i++)
	{
		printf("%lld ", SortedX[i]);
	}
    printf("\n");
    for(int i=0;i<N;i++)
    {
        printf("%lld ", UnsortedY[i]);
    }
    printf("\n");*/


	SortedX[N]=1234567899229;
	UnsortedY[N]=1234567899229;
	FinalX[N]=1234567899229;
	FinalY[N]=1234567899299;

	//int lower=0;
	//int upper=0;

	//for(int i=0;i<N;i++)
	//{
	//	if(SortedX[i]==SortedX[i+1])
	//	{
	//		upper++;
	//	}
	//	else
	//	{
	//		merge(UnsortedY,lower,upper);
	//		lower=i;
	//		upper=i;
	//	}
	//}

	int counts=0;
	for(int i=0;i<N;i++)
	{
		if((SortedX[i]!=SortedX[i+1])||(UnsortedY[i]!=UnsortedY[i+1]))
		{
			FinalX[counts]=SortedX[i];
			FinalY[counts]=UnsortedY[i];
			counts++;
		}
	}

    //printf("%d\n", counts);

//	for(int i=0;i<N;i++)
  //    	{
    //            printf("%lld ", FinalX[i]);
      //   }
//	printf("\n \n");
//	for(int i=0;i<N;i++)
//	{
  //              printf("%lld ", FinalY[i]);
    //    }
//	printf("\n \n");

	//Merge Sort algorithm

	merge(FinalX,0,N-1);

	merge(FinalY,0,N-1);

	/*for(int i=0;i<N;i++)
	{
	    printf("%lld ", FinalX[i]);
    }
	printf("\n \n");
	for(int i=0;i<N;i++)
	{
	    printf("%lld ", FinalY[i]);
	}
	printf("\n \n");*/

	//Finding repeatations in sorted X and Sorted Y


	    SortedX[counts]=1234567899229;
        UnsortedY[counts]=1234567899229;
        FinalX[counts]=1234567899229;
        FinalY[counts]=1234567899299;

	long long int sum;
	sum=(counts*(counts-1)*(counts-2))/(2*3);

	//printf("%lld \n",sum);

	long long int count=0;
	for(int j=0;j<counts;j++)
	{
		if(FinalX[j]==FinalX[j+1])
		{
			count++;
		}
		else if(FinalX[j]!=FinalX[j+1])
                {
			sum-=(count*(count-1)*(count-2))/(2*3);
                        count=1;
                }
        }

	count=0;
	for(int j=0;j<counts;j++)
        {
                if(FinalY[j]==FinalY[j+1])
                {
                        count++;
                }
                else if(FinalY[j]!=FinalY[j+1])
                {

                        sum-=(count*(count-1)*(count-2))/(2*3);
                        count=1;
                }
        }


	printf("%lld",sum%mod);
	return 0;
}


